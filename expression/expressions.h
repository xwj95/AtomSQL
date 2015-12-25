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
	int init(string file1, string file2, Columns &header1, Columns &header2) {
		for (int i = 0; i < expressions.size(); ++i) {
			int result = expressions[i].init(file1, file2, header1, header2);
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
	int cal(Row &record1, Row &record2) {
		if (expressions.size() == 0) {
			for (int i = 0; i < record1.items.size(); ++i) {
				record1.items[i].var->print();
				cout << " ";
			}
			for (int i = 0; i < record2.items.size(); ++i) {
				record2.items[i].var->print();
				cout << " ";
			}
			cout << endl;
			return 0;
		}
		for (int i = 0; i < expressions.size(); ++i) {
			int result = expressions[i].cal(record1, record2);
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
