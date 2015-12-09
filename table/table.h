#ifndef DBMS_TABLE_H_
#define DBMS_TABLE_H_

#include "columns.h"
#include "rows.h"

class Table {

public:
	string schema;
	Columns header;
	Rows rows;
};

#endif
