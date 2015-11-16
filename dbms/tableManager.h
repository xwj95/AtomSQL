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
	BufPageManager *bpm;
	IO *io;
public:
	tableManager(BufPageManager *_bpm, IO *_io) {
		bpm = _bpm;
		io = _io;
	}
	~tableManager() {
	}
	//写入记录
	int writeData(int fileID, Column &header, vector<Data> &data_insert) {
		int pageID = 1;
		int index;
		BufType b;
		for (int i = 0; i < data_insert.size(); ++i) {
			while (true) {
				if (pageID > header.pages) {
					//需要申请新的页面
					header.pages = header.pages + 1;
					//修改表的元数据
					int header_index;
					BufType header_b = bpm->getPage(fileID, 0, header_index);
					header_b = header_b + ((TABLE_HEADER_SCHEMA_BITS + 3) / 4 * 4 + TABLE_HEADER_MAJOR_SIZE) / sizeof(uint);
					//只修改页数
					header_b = io->writeUint(header_b, header.pages);
					bpm->markDirty(header_index);
					//申请新的页面
					b = bpm->allocPage(fileID, pageID, index, true);
					BufType next_b = b;
					//初始化空槽数
					next_b = io->writeUint(next_b, header.count);
					//初始化每个槽的next指针
					for (int i = 0; i < header.count; ++i) {
						//next指针指向下一个槽
						next_b = io->writeUint(next_b, 1);
						next_b = next_b + (header.size - TABLE_ITEM_NEXT_SIZE) / sizeof(uint);
					}
					//最后一个next指针指向空
					next_b = io->writeUint(next_b, 0);
					bpm->markDirty(index);
				}
				if (pageID <= header.pages) {
					b = bpm->getPage(fileID, pageID, index);
					BufType next_b = b;
					//读取空槽数
					uint _empty;
					b = io->readUint(b, _empty);
					//查找第一个空槽
					uint next = b[0];
					if (next > 0) {
						//当前页面未满，将当前记录写入空槽
						b = b + (next - 1) * header.size / sizeof(uint);
						//查找下一个空槽
						uint _next;
						io->readUint(b + header.size, _next);
						//写入记录
						Data _data = data_insert[i];
						b = _data.write(b, io);
						//更新空槽数
						_empty = _empty - 1;
						next_b = io->writeUint(next_b, _empty);
						//更新next指针
						io->readUint(b, _next);
						while (next > 0) {
							if (_next != 0) {
								next_b = io->writeUint(next_b, _next + next);
							}
							//后面已经没有空槽了
							else {
								next_b = io->writeUint(next_b, 0);
							}
							next_b = next_b + (header.size - TABLE_ITEM_NEXT_SIZE) / sizeof(uint);
							next = next - 1;
						}
						bpm->markDirty(index);
						break;
					}
					else {
						//当前页面已满，查看下一页
						pageID = pageID + 1;
					}
				}
			}
		}
		return 0;
	}
	//删除记录
	int deleteData(int fileID, Column &header, vector<int> &page_delete, vector<int> &index_delete) {
		int index;
		BufType b;
		int pageID = 1;
		int del = 0;
		while (pageID <= header.pages) {
			if (pageID != page_delete[del]) {
				pageID++;
				continue;
			}
			b = bpm->getPage(fileID, pageID, index);
			uint _empty;
			b = io->readUint(b, _empty);
			if (_empty >= header.count) {
				continue;
			}
			bpm->access(index);
			uint count = 0;
			while (count < header.count) {
				Data _data = Data();
				b = _data.read(b, io, header);
				if (index_delete[del] == count) {
					//删除记录
					del++;
					if (del >= index_delete.size()) {
						return 0;
					}
					if (pageID != page_delete[del]) {
						break;
					}
				}
				count++;
			}
			pageID++;
		}
		return 0;
	}
	//更新记录
	int updateData(int fileID, Column &header, vector<int> &page_update, vector<int> &index_update, vector<Data> &data_update) {
		int index;
		BufType b;
		int pageID = 1;
		int upd = 0;
		while (pageID <= header.pages) {
			if (pageID != page_update[upd]) {
				pageID++;
				continue;
			}
			b = bpm->getPage(fileID, pageID, index);
			uint _empty;
			b = io->readUint(b, _empty);
			if (_empty >= header.count) {
				continue;
			}
			bpm->access(index);
			uint count = 0;
			while (count < header.count) {
				Data _data = Data();
				BufType data_b = _data.read(b, io, header);
				if (index_update[upd] == count) {
					//更新记录
					data_b = data_update[upd].update(b, io);
					bpm->markDirty(index);
					upd++;
					if (upd >= index_update.size()) {
						return 0;
					}
					if (pageID != page_update[upd]) {
						break;
					}
				}
				count++;
			}
			pageID++;
		}
		return 0;
	}
	//生成表的元数据
	void writeHeader(int fileID, int pageID, Column &column, bool alloc = true) {
		int index;
		//申请元数据页，并依次写入模式信息、主键、页数
		BufType b;
		if (alloc) {
			b = bpm->allocPage(fileID, pageID, index, true);
		}
		else {
			b = bpm->getPage(fileID, pageID, index);
		}
//		BufType c = b;
		b = io->writeChar(b, column.schema, TABLE_HEADER_SCHEMA_BITS);
		b = io->writeUint(b, column.major);
		b = io->writeUint(b, column.pages);
		//写入列项，依次写入类型、大小、是否可空、名字
		for (int i = 0; i < column.type.size(); ++i) {
			uint x = column.type[i];
			x = x << TABLE_HEADER_LENGTH_BITS;
			x = x + (column.length[i] & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x << TABLE_HEADER_NULL_BITS;
			x = x + column.canNull[i];
			b = io->writeUint(b, x);
			b = io->writeChar(b, column.name[i], TABLE_HEADER_NAME_BITS);
		}
//		io->print(c);
		bpm->markDirty(index);
	}
	//读取表的元数据
	Column readHeader(int fileID, int pageID) {
		int index;
		//读取元数据页，并依次读取模式信息、主键、页数
		BufType b = bpm->getPage(fileID, pageID, index);
		//BufType b = bpm->allocPage(fileID, pageID, index, true);
//		io->print(b);
		bpm->access(index);
		Column column;
		b = io->readChar(b, column.schema, TABLE_HEADER_SCHEMA_BITS);
		b = io->readUint(b, column.major);
		b = io->readUint(b, column.pages);
		//读取列项，依次读取类型、大小、是否可空、名字
		while (true) {
			uint x;
			b = io->readUint(b, x);
			if (x == 0) {
				break;
			}
			column.canNull.push_back(x & ((1 << TABLE_HEADER_NULL_BITS) - 1));
			x = x >> TABLE_HEADER_NULL_BITS;
			column.length.push_back(x & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x >> TABLE_HEADER_LENGTH_BITS;
			column.type.push_back(x & (1 << TABLE_HEADER_TYPES_BITS) - 1);
			string name;
			b = io->readChar(b, name, TABLE_HEADER_NAME_BITS);
			column.name.push_back(name);
		}
		column.countSize();
		return column;
	}
	//根据列名查找对应下标
	int findName(vector<string> &names, string name) {
		vector<string>::iterator iter = find(names.begin(), names.end(), name);
		if (iter == names.end()) {
			cout << "Cannot find column " << name << endl;
			return -1;
		}
		return iter - names.begin();
	}
	//查找给定整数在给定整数向量中的位置
	int findIndex(vector<int> &indexs, int index) {
		vector<int>::iterator iter = find(indexs.begin(), indexs.end(), index);
		if (iter == indexs.end()) {
			return -1;
		}
		return iter - indexs.begin();
	}
	//获取待插入的列项的列数，并检查是否有非法情况
	int getIndexs(Column &column, Column &header, vector<int> &indexs, bool checkNull) {
		//待插入列项为空，默认为插入全部列项
		if (column.name.size() < 1) {
			column.name = header.name;
			column.canNull.clear();
			for (int i = 0; i < column.name.size(); ++i) {
				column.canNull.push_back(true);
			}
		}
		indexs.clear();
		//依次寻找每一个列项下标
		for (int i = 0; i < column.name.size(); ++i) {
			int index = findName(header.name, column.name[i]);
			//列项没有找到
			if (index < 0) {
				return -1;
			}
			indexs.push_back(index);
		}
		if (checkNull) {
			//检查是否有不可空的列项为空
			for (int i = 0; i < header.name.size(); ++i) {
				if ((!header.canNull[i]) && (findIndex(indexs, i) < 0)) {
					cout << "Column " << header.name[i] << " cannot be null." << endl;
					return -1;
				}
			}
		}
		return 0;
	}
	//将记录转化为文件中存储格式，并检查是否有非法情况
	int getWriteData(Column &column, Column &header, vector<int> &indexs, vector<Data> &data, vector<Data> &_data) {
		_data.clear();
		//检查每一行数据
		for (int da = 0; da < data.size(); ++da) {
			vector<Types> _data_row = data[da].data;
			vector<bool> _isNull_row = data[da].isNull;
			//插入列表项初始化，初始全部为空
			vector<Types> _data_row_write;
			vector<bool> _isNull_row_write;
			for (int i = 0; i < column.name.size(); ++i) {
				switch (header.type[i]) {
				case Type::Char:
					break;
				case Type::Int:
				case Type::Longint:
					_data_row_write.push_back(Types(header.type[i], 0));
					break;
				case Type::Varchar:
					_data_row_write.push_back(Types(header.type[i], "", header.length[i]));
					break;
				default:
					break;
				}
				_isNull_row_write.push_back(true);
			}
			//检查每一列属性
			for (int i = 0; i < _data_row.size(); ++i) {
				int index = indexs[i];
				//插入空值但该列不能为空
				if (_isNull_row[index] && !header.canNull[index]) {
					cout << "Cannot insert null in column " << header.name[index] << "." << endl;
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
			_data_write.rid = data[da].rid;
			_data.push_back(_data_write);
		}
		return 0;
	}
};

#endif /* DBMS_TABLEMANAGER_H_ */
