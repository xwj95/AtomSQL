#ifndef DBMS_COLUMN_H_
#define DBMS_COLUMN_H_

#include "../var/typedef.h"

class Column {

public:
	uint type;
	uint length;
	bool canNull;
	string name;
};

#endif
