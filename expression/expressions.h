#ifndef DBMS_EXPRESSIONS_H_
#define DBMS_EXPRESSIONS_H_

#include "../table/row.h"
#include "../table/columns.h"
#include "expression.h"
#include <vector>

class Expressions {

public:
	vector<Expression> expressions;

	int init(Columns &header) {
		for (int i = 0; i < expressions.size(); ++i) {
			int result = expressions[i].init(header);
			if (result) {
				return result;
			}
		}
		return 0;
	}
	int cal(Row &record) {
		if (expressions.size() == 0) {
			for (int i = 0; i < record.items.size(); ++i) {
				record.items[i].var->print();
				cout << " ";
			}
			cout << endl;
			return 0;
		}
		for (int i = 0; i < expressions.size(); ++i) {
			int result = expressions[i].cal(record);
			if (result) {
				cout << endl;
				return result;
			}
			expressions[i].var->print();
			cout << " ";
		}
		cout << endl;
		return 0;
	}
};

#endif
