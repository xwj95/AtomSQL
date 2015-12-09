#ifndef DBMS_COLUMNS_H_
#define DBMS_COLUMNS_H_

#include "column.h"
#include "tabledef.h"
#include "../var/typedef.h"
#include "../filesystem/filesystem.h"
#include <vector>

class Columns {

public:
	string schema;
	vector<Column> column;
	uint major;
	uint size;
	uint num;

	uint calSize() {
		size = TABLE_ITEM_NEXT_BYTE + TABLE_ITEM_RID_BYTE;
		size += (column.size() * TABLE_ITEM_NULL_BIT + 31) / 32;
		for (int i = 0; i < column.size(); ++i) {
			uint type = column[i].type;
			if (type == TYPE_LONGINT) {
				size += TABLE_ITEM_LONGINT_BYTE;
			} else if (type == TYPE_VARCHAR) {
				size += (uint) ((column[i].length + 3) / 4 * 4 * TABLE_ITEM_CHAR_BYTE);
			}
		}
		num = (PAGE_SIZE - TABLE_ITEM_NEXT_BYTE - TABLE_ITEM_EMPTY_BYTE) / size;
		return size;
	}
};

#endif
