/*
 * tableManager.h
 *
 *  Created on: 2015年11月15日
 *      Author: Xwj95
 */

#ifndef DBMS_TABLEMANAGER_H_
#define DBMS_TABLEMANAGER_H_

#include "io.h"
#include "column.h"
#include "data.h"
#include "dbmsdef.h"

class tableManager {
	IO *io;
public:
	tableManager(IO *_io) {
		io = _io;
	}
	~tableManager() {
	}
	int writeData(BufPageManager* bpm, int fileID, Column header, std::vector<Data> data) {
		int pageID = 1;
		int index;
		BufType b;
		for (int i = 0; i < data.size(); ++i) {
			while (pageID <= header.pages) {
				b = bpm->getPage(fileID, pageID, index);
				//查找第一个空槽
				int next = b[0] & (((uint) 1 << TABLE_ITEM_NEXT_BITS) - 1);
				if (next > 0) {
					//当前页面未满，将当前记录写入页面
					//Code
					bpm->access(index);
					bpm->markDirty(index);
				}
				else {
					//当前页面已满，查看下一页
					pageID = pageID + 1;
				}
			}
			while (pageID > header.pages) {
				//需要申请新的页面
				header.pages = header.pages + 1;
				//修改存储表的信息的页面
				int header_index;
				BufType header_b = bpm->getPage(fileID, 0, header_index);
				header_b = header_b + TABLE_HEADER_SCHEMA_BITS / 4 + TABLE_HEADER_MAJOR_SIZE;
				header_b = io->writeInt(header_b, header.pages);
				bpm->markDirty(header_index);
				//申请新的页面
				b = bpm->allocPage(fileID, pageID, index, true);
				//以下更新每个槽的next指针
				BufType next_b = b;
				for (int i = 0; i < PAGE_SIZE / header.size; ++i) {
					if (i < PAGE_SIZE / header.size - 1) {
						//next指针指向下一个槽
						next_b = io->writeInt(next_b, 1);
					}
					else {
						//当前槽为最后一个槽
						next_b = io->writeInt(next_b, 0);
					}
					next_b = next_b + (header.size - (TABLE_ITEM_NULL_BITS + TABLE_ITEM_NEXT_BITS) / 8) / sizeof(uint);
				}
				bpm->markDirty(index);
			}
		}
		return 0;
	}
	//生成表的信息
	void writeHeader(BufPageManager *bpm, int fileID, int pageID, Column column) {
		int index;
		//申请信息页，并依次写入模式信息、主键、页数
		BufType b = bpm->allocPage(fileID, pageID, index, true);
		b = io->writeChar(b, column.schema, TABLE_HEADER_SCHEMA_BITS);
		b = io->writeInt(b, column.major);
		b = io->writeInt(b, column.pages);
		//写入列项，依次写入类型、大小、是否可空、名字
		for (int i = 0; i < column.type.size(); ++i) {
			uint x = column.type[i];
			x = x << TABLE_HEADER_LENGTH_BITS;
			x = x + (column.length[i] & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x << TABLE_HEADER_NULL_BITS;
			x = x + column.canNull[i];
			b = io->writeInt(b, x);
			b = io->writeChar(b, column.name[i], TABLE_HEADER_NAME_BITS);
		}
		bpm->markDirty(index);
	}
	//读取表的信息
	Column readHeader(BufPageManager *bpm, int fileID, int pageID) {
		int index;
		//读取信息页，并依次读取模式信息、主键、页数
		BufType b = bpm->getPage(fileID, pageID, index);
		bpm->access(index);
		Column column;
		b = io->readChar(b, column.schema, TABLE_HEADER_NAME_BITS);
		int major;
		b = io->readInt(b, major);
		column.major = (uint) major;
		int pages;
		b = io->readInt(b, pages);
		column.pages = (uint) pages;
		//读取列项，依次读取类型、大小、是否可空、名字
		while (true) {
			int _x;
			b = io->readInt(b, _x);
			uint x = (uint) _x;
			if (x == 0) {
				break;
			}
			column.canNull.push_back(x & ((1 << TABLE_HEADER_NULL_BITS) - 1));
			x = x >> TABLE_HEADER_NULL_BITS;
			column.length.push_back(x & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x >> TABLE_HEADER_LENGTH_BITS;
			column.type.push_back(x & (1 << TABLE_HEADER_TYPES_BITS) - 1);
			std::string name;
			b = io->readChar(b, name, TABLE_HEADER_NAME_BITS);
			column.name.push_back(name);
		}
		return column;
	}
	//根据列名查找对应下标
	int findName(std::vector<std::string> &names, std::string name) {
		std::vector<std::string>::iterator iter = find(names.begin(), names.end(), name);
		if (iter == names.end()) {
			cout << "Cannot find column " << name << endl;
			return -1;
		}
		return iter - names.begin();
	}
	//查找给定整数在给定整数向量中的位置
	int findIndex(std::vector<int> &indexs, int index) {
		std::vector<int>::iterator iter = find(indexs.begin(), indexs.end(), index);
		if (iter == indexs.end()) {
			return -1;
		}
		return iter - indexs.begin();
	}
	//获取待插入的列项的列数，并检查是否有非法情况
	int getIndexs(Column column, Column _column, std::vector<int> &indexs, bool checkNull) {
		//待插入列项为空，默认为插入全部列项
		if (column.name.size() < 1) {
			column.name = _column.name;
			column.canNull.clear();
			for (int i = 0; i < column.name.size(); ++i) {
				column.canNull.push_back(true);
			}
		}
		indexs.clear();
		//依次寻找每一个列项下标
		for (int i = 0; i < column.name.size(); ++i) {
			int _index = findName(_column.name, column.name[i]);
			//列项没有找到
			if (_index < 1) {
				return -1;
			}
			indexs.push_back(_index);
		}
		if (checkNull) {
			//检查是否有不可空的列项为空
			for (int i = 0; i < _column.name.size(); ++i) {
				if ((!_column.canNull[i]) && (findIndex(indexs, i) < 0)) {
					cout << "Column " << _column.name[i] << " cannot be null." << endl;
					return -1;
				}
			}
		}
		return 0;
	}
	int getWriteData(Column column, Column _column, std::vector<int> &indexs, std::vector<Data> &data, std::vector<Data> &_data) {
		_data.clear();
		//检查每一行数据
		for (int da = 0; da < data.size(); ++da) {
			std::vector<Types> _data_row = data[da].data;
			std::vector<bool> _isNull_row = data[da].isNull;
			//插入列表项初始化，初始全部为空
			std::vector<Types> _data_row_write;
			std::vector<bool> _isNull_row_write;
			for (int i = 0; i < column.name.size(); ++i) {
				_data_row_write.push_back(Integer(0));
				_isNull_row_write.push_back(true);
			}
			//检查每一列属性
			for (int i = 0; i < _data.size(); ++i) {
				int index = indexs[i];
				//插入空值但该列不能为空
				if (_isNull_row[index] && !_column.canNull[index]) {
					cout << "Cannot insert null in column " << _column.name[index] << "." << endl;
					return -1;
				}
				//若该列非空，则更新数据
				if (!_isNull_row[index]) {
					_isNull_row_write[index] = false;
					_data_row_write[index] = _data_row[index];
				}
			}
			//该行通过检测
			Data _data_write;
			_data_write.data = _data_row_write;
			_data_write.isNull = _isNull_row_write;
			_data.push_back(_data_write);
		}
		return 0;
	}
};

#endif /* DBMS_TABLEMANAGER_H_ */
