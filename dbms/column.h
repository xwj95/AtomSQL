/*
 * column.h
 *
 *  Created on: 2015年10月26日
 *      Author: Xwj95
 */

#ifndef DBMS_COLUMN_H_
#define DBMS_COLUMN_H_

#include "../type/type.h"
#include "dbmsdef.h"
#include <vector>
#include <string>

class Column {
public:
	std::string schema;
	std::vector<uint> type;
	std::vector<uint> length;
	std::vector<bool> canNull;
	std::vector<std::string> name;
	uint major;
	uint pages;
	uint size;
	uint count;
	Column() {
		schema = "";
		major = 0;
		pages = 0;
		size = 0;
		count = 0;
		type.clear();
		length.clear();
		canNull.clear();
		name.clear();
	}
	uint countSize() {
		size = TABLE_ITEM_NEXT_SIZE + TABLE_ITEM_RID_SIZE;
		size = size + (type.size() * TABLE_ITEM_NULL_BITS + 31) / 32 * 4;
		for (int i = 0; i < type.size(); ++i) {
			switch (type[i]) {
			case Type::Char:
				break;
			case Type::Int:
				size = size + TABLE_ITEM_INT_SIZE;
				break;
			case Type::Longint:
				size = size + TABLE_ITEM_LONGINT_SIZE;
				break;
			case Type::Varchar:
				size = size + (uint) ((length[i] + 3) / 4 * 4 * TABLE_ITEM_CHAR_SIZE);
				break;
			default:
				break;
			}
		}
		count = (PAGE_SIZE - TABLE_ITEM_NEXT_SIZE - TABLE_ITEM_EMPTY_SIZE) / size;
		return size;
	}
};

#endif /* DBMS_COLUMN_H_ */
