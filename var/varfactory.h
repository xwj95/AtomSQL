#ifndef DBMS_VARFACTORY_H_
#define DBMS_VARFACTORY_H_

#include "longint.h"
#include "varchar.h"

class VarFactory {

public:

	static BufType get(BufType b, IO *io, Var **var, uint type, uint length) {
		if (type == TYPE_LONGINT) {
			*var = new Longint(0, length);
			b = (*var)->read(b, io);
		} else if (type == TYPE_VARCHAR) {
			*var = new Varchar("", length);
			b = (*var)->read(b, io);
		}
		return b;
	}

	static Var* get(ll value, uint length) {
		return new Longint(value, length);
	}

	static Var* get(string value, uint length) {
		return new Varchar(value, length);
	}

	static void set(Var *var, uint length) {
		var->length = length;
	}
};

#endif
