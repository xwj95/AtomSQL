#ifndef DBMS_EXPRTERM_H_
#define DBMS_EXPRTERM_H_

#include "../table/row.h"
#include "../table/columns.h"
#include "expressionOp.h"
#include "../var/varfactory.h"

class ExprTerm {

public:
	int term_func;
	string table_name;
	string column_name;
	int table_index;
	int column_index;
	Var *var;
	int getFunc(string func) {
		if (func == "count") {
			return FUNC_OP_COUNT;
		}
		if (func == "sum") {
			return FUNC_OP_SUM;
		}
		if (func == "avg") {
			return FUNC_OP_AVG;
		}
		if (func == "max") {
			return FUNC_OP_MAX;
		}
		if (func == "min") {
			return FUNC_OP_MIN;
		}
		return FUNC_OP_NULL;
	}
	int init(Columns &header) {
		table_index = 1;
		column_index = header.column.size();
		for (int i = 0; i < header.column.size(); ++i) {
			if (header.column[i].name == column_name) {
				column_index = i;
				break;
			}
		}
		if (column_index == header.column.size()) {
			return -15;
		}
		return 0;
	}
	int cal(Row &record) {
		var = record.items[column_index].var;
		return 0;
	}
};

#endif
