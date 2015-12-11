#ifndef DBMS_ROWS_H_
#define DBMS_ROWS_H_

#include "row.h"

class Rows {

public:
	vector<Row> rows;

	//写记录
	BufType write(BufType b, IO *io) {
		return b;
	}

	//读记录
	BufType read(BufType b, IO *io) {
		return b;
	}
};

#endif
