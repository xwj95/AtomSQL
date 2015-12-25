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
	int init(string file1, string file2, Columns &header1, Columns &header2) {
		if (file1 == table_name) {
			table_index = 1;
			column_index = header1.column.size();
			for (int i = 0; i < header1.column.size(); ++i) {
				if (header1.column[i].name == column_name) {
					column_index = i;
					break;
				}
			}
			if (column_index == header1.column.size()) {
				return -15;
			}
		}
		else {
			table_index = 2;
			column_index = header2.column.size();
			for (int i = 0; i < header2.column.size(); ++i) {
				if (header2.column[i].name == column_name) {
					column_index = i;
					break;
				}
			}
			if (column_index == header2.column.size()) {
				return -15;
			}
		}
		return 0;
	}
	int cal(Row &record) {
		var = record.items[column_index].var;
		return 0;
	}
	int cal(Row &record1, Row &record2) {
		if (table_index == 1) {
			var = record1.items[column_index].var;
		}
		else {
			var = record2.items[column_index].var;
		}
	}
};

#endif
