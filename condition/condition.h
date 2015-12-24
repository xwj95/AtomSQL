#ifndef DBMS_CONDITION_H_
#define DBMS_CONDITION_H_

#include "../table/row.h"
#include "../table/columns.h"
#include "boolTerm.h"
#include "conditionOp.h"
#include <vector>

class Condition {

public:
	vector<int> bool_op;
	vector<BoolTerm> bool_terms;
	int getOp(string op) {
		if (op == "and") {
			return BOOL_OP_AND;
		}
		if (op == "or") {
			return BOOL_OP_OR;
		}
		return BOOL_OP_NULL;
	}
	int cal(Row &row, bool &term) {
		term = false;
		for (int i = 0; i < bool_terms.size(); ++i) {
			int result = bool_terms[i].cal(row, term);
			if (result) {
				return result;
			}
			if (i >= bool_terms.size() - 1) {
				continue;
			}
			if (bool_op[i] == BOOL_OP_AND) {
				if (term == false) {
					return 0;
				}
			}
			if (bool_op[i] == BOOL_OP_OR) {
				if (term == true) {
					return 0;
				}
			}
		}
		return 0;
	}
	int init(Columns &column) {
		for (int i = 0; i < bool_terms.size(); ++i) {
			int result = bool_terms[i].init(column);
			if (result) {
				return result;
			}
		}
		return 0;
	}
};

#endif
