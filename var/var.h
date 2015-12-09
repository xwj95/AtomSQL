#ifndef DBMS_VAR_H_
#define DBMS_VAR_H_

#include "../utils/io.h"
#include "typedef.h"

class Var {

public:
	virtual uint size();
	virtual uint type();
	virtual void print();
	virtual BufType write(BufType b, IO *io);
	virtual BufType read(BufType, IO *io);
};

#endif
