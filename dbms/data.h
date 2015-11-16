/*
 * data.h
 *
 *  Created on: 2015年10月25日
 *      Author: Xwj95
 */

#ifndef DBMS_DATA_H_
#define DBMS_DATA_H_

#include "../type/types.h"
#include "io.h"
#include <vector>
#include <string>

class Data {
public:
	vector<Types> data;
	vector<bool> isNull;
	vector<string> names;
	ull rid;
	Data() {
		clear();
	}
	void clear() {
		data.clear();
		isNull.clear();
		names.clear();
		rid = 0;
	}
	//写记录
	BufType write(BufType b, IO *io, uint _next = 1) {
		//next指针默认指向自己
		b = io->writeUint(b, _next);
		//写入rid值
		b = io->writeUlong(b, rid);
		//写入每一列项是否为空
		uint _isnull = 0;
		for (int i = 0; i < isNull.size(); ++i) {
			_isnull = _isnull + ((ull) isNull[i] << (TABLE_ITEM_NULL_BITS * i));
			if (((i + 1) % 32 == 0) || (i == isNull.size() - 1)) {
				b = io->writeUint(b, _isnull);
				_isnull = 0;
			}
		}
		//写入每一列项的数据
		for (int i = 0; i < data.size(); ++i) {
			b = data[i].write(b, io);
		}
		return b;
	}
	//读记录
	BufType read(BufType b, IO *io, Column &header) {
		uint _next;
		b = io->readUint(b, _next);
		//空槽
		if (_next == 1) {
			b = b + (header.size - TABLE_ITEM_NEXT_SIZE) / sizeof(uint);
			return b;
		}
		//读入rid值
		b = io->readUlong(b, rid);
		//读入每一列项是否为空
		for (int i = 0; i < (header.type.size() + 31) / 32; ++i) {
			uint _isnull;
			b = io->readUint(b, _isnull);
			for (int j = i * 32; j < (i + 1) * 32; ++j) {
				if (j >= header.type.size()) {
					break;
				}
				isNull.push_back(_isnull % (1 << TABLE_ITEM_NULL_BITS));
				_isnull = _isnull >> TABLE_ITEM_NULL_BITS;
			}
		}
		//读入每一列项的数据
		for (int i = 0; i < header.type.size(); ++i) {
			Types item = Types(header.type[i], 0);
			item.length = header.length[i];
			b = item.read(b, io);
			data.push_back(item);
			//输出
			item.print();
			cout << "-";
		}
		cout << endl;
		return b;
	}
	//移除记录
	BufType remove(BufType b, IO *io, int zeros) {
		//将next指针指向自己，表明该槽为空
		b = io->writeUint(b, 1);
		//填充指定个数的零
		for (int i = 0; i < zeros; ++i) {
			b = io->writeUint(b, 0);
		}
		return b;
	}
	//更新记录
	BufType update(BufType b, IO *io) {
		uint _next;
		//维持next指针不变，只更新数据部分
		io->readUint(b, _next);
		b = write(b, io, _next);
		return b;
	}
};

#endif /* DBMS_DATA_H_ */
