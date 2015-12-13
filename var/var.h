#ifndef DBMS_VAR_H_
#define DBMS_VAR_H_

#include "../utils/io.h"
#include "typedef.h"

class Var {

public:
	virtual ~Var() {

	}

	virtual uint size() {
		return 0;
	}

	virtual uint type() {
		return TYPE_NONE;
	}

	virtual void print() {

	}

	virtual BufType write(BufType b, IO *io) {
		return b;
	}

	virtual BufType read(BufType b, IO *io) {
		return b;
	}
};

#endif
