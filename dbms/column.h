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
	Column() {
		schema = "";
		major = 0;
		pages = 0;
		size = 0;
		type.clear();
		length.clear();
		canNull.clear();
		name.clear();
	}
	uint countSize() {
		size = (TABLE_ITEM_NULL_BITS + TABLE_ITEM_NEXT_BITS) / 8 + TABLE_ITEM_RID_SIZE;
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
		return size;
	}
};

#endif /* DBMS_COLUMN_H_ */
