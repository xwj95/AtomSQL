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
	//写入记录
	int writeData(BufPageManager* bpm, int fileID, Column &header, std::vector<Data> &data) {
		int pageID = 1;
		int index;
		BufType b;
		for (int i = 0; i < data.size(); ++i) {
			while (true) {
				if (pageID > header.pages) {
					//需要申请新的页面
					header.pages = header.pages + 1;
					//修改存储表的信息的页面
					int header_index;
					BufType header_b = bpm->getPage(fileID, 0, header_index);
					header_b = header_b + ((TABLE_HEADER_SCHEMA_BITS + 3) / 4 * 4 + TABLE_HEADER_MAJOR_SIZE) / sizeof(uint);
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
						Data _data = data[i];
						//查找下一个空槽
						uint _next;
						io->readUint(b + header.size, _next);
						//next指针暂时指向自己
						b = io->writeUint(b, 1);
						//写入rid值
						b = io->writeUlong(b, _data.rid);
						//写入每一列项是否为空
						uint _isnull = 0;
						for (int j = 0; j < _data.isNull.size(); ++j) {
							_isnull = _isnull + ((ull) _data.isNull[j] << (TABLE_ITEM_NULL_BITS * j));
							if (((j + 1) % 32 == 0) || (j == _data.isNull.size() - 1)) {
								b = io->writeUint(b, _isnull);
								_isnull = 0;
							}
						}
						//写入每一列项的数据
						for (int j = 0; j < _data.data.size(); ++j) {
							b = _data.data[j].write(b, io);
						}
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
	int deleteData(BufPageManager* bpm, int fileID, Column &header, Data &data) {
		int index;
		BufType b;
		for (int pageID = 1; pageID <= header.pages; pageID++) {
			b = bpm->getPage(fileID, pageID, index);
			bpm->access(index);
			uint _empty;
			b = io->readUint(b, _empty);
			if (_empty >= header.count) {
				continue;
			}
			uint count = header.count;
			while (count > 0) {
				Data _data = Data();
				uint _next;
				b = io->readUint(b, _next);
				b = io->readUlong(b, _data.rid);
				for (int i = 0; i < (header.type.size() + 31) / 32; ++i) {
					uint _isnull;
					b = io->readUint(b, _isnull);
					for (int j = i * 32; j < (i + 1) * 32; ++j) {
						if (j >= header.type.size()) {
							break;
						}
						_data.isNull.push_back(_isnull % (1 << TABLE_ITEM_NULL_BITS));
						_isnull = _isnull >> TABLE_ITEM_NULL_BITS;
					}
				}
				for (int i = 0; i < header.type.size(); ++i) {
					Types item = Types(header.type[i], 0);
					item.length = header.length[i];
					b = item.read(b, io);
					_data.data.push_back(item);
					item.print();
					cout << " ";
				}
				cout << endl;
				count--;
			}
		}
		return 0;
	}
	//生成表的信息
	void writeHeader(BufPageManager *bpm, int fileID, int pageID, Column &column) {
		int index;
		//申请信息页，并依次写入模式信息、主键、页数
		BufType b = bpm->allocPage(fileID, pageID, index, true);
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
		bpm->markDirty(index);
	}
	//读取表的信息
	Column readHeader(BufPageManager *bpm, int fileID, int pageID) {
		int index;
		//读取信息页，并依次读取模式信息、主键、页数
		BufType b = bpm->getPage(fileID, pageID, index);
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
	int getIndexs(Column &column, Column &header, std::vector<int> &indexs, bool checkNull) {
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
	int getWriteData(Column &column, Column &header, std::vector<int> &indexs, std::vector<Data> &data, std::vector<Data> &_data) {
		_data.clear();
		//检查每一行数据
		for (int da = 0; da < data.size(); ++da) {
			std::vector<Types> _data_row = data[da].data;
			std::vector<bool> _isNull_row = data[da].isNull;
			//插入列表项初始化，初始全部为空
			std::vector<Types> _data_row_write;
			std::vector<bool> _isNull_row_write;
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
