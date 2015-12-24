#ifndef DBMS_EXPRESSION_H_
#define DBMS_EXPRESSION_H_

#include "../table/row.h"
#include "../table/columns.h"
#include "exprterm.h"

class Expression {

public:
	int expr_op;
	Expression *expr_left;
	Expression *expr_right;
	ExprTerm *term_left;
	ExprTerm *term_right;
	Var *value_left;
	Var *value_right;
	Var *var_left;
	Var *var_right;
	Var *var;
	int getOp(string op) {
		if (op == "+") {
			return EXPR_OP_PLUS;
		}
		if (op == "-") {
			return EXPR_OP_MINUS;
		}
		if (op == "*") {
			return EXPR_OP_MULTIPLY;
		}
		if (op == "/") {
			return EXPR_OP_DIVIDE;
		}
		return EXPR_OP_NULL;
	}
	int init(Columns &header) {
		if (expr_left != NULL) {
			int result = expr_left->init(header);
			if (result) {
				return result;
			}
		}
		if (expr_right != NULL) {
			int result = expr_right->init(header);
			if (result) {
				return result;
			}
		}
		if (term_left != NULL) {
			int result = term_left->init(header);
			if (result) {
				return result;
			}
		}
		if (term_right != NULL) {
			int result = term_right->init(header);
			if (result) {
				return result;
			}
		}
		return 0;
	}
	int cal(Row &record) {
		var_left = NULL;
		var_right = NULL;
		var = NULL;
		if (expr_left != NULL) {
			int result = expr_left->cal(record);
			if (result) {
				return result;
			}
			var_left = expr_left->var;
		}
		if (expr_right != NULL) {
			int result = expr_right->cal(record);
			if (result) {
				return result;
			}
			var_right = expr_right->var;
		}
		if (term_left != NULL) {
			int result = term_left->cal(record);
			if (result) {
				return result;
			}
			var_left = term_left->var;
		}
		if (term_right != NULL) {
			int result = term_right->cal(record);
			if (result) {
				return result;
			}
			var_right = term_right->var;
		}
		if (value_left != NULL) {
			var_left = value_left;
		}
		if (value_right != NULL) {
			var_right = value_right;
		}
		if (expr_op != EXPR_OP_NULL) {
			if (var_right == NULL) {
				return -20;
			}
			if (var_right->type() == TYPE_NULL) {
				var = var_right;
				return 0;
			}
			if (var_right->type() != TYPE_LONGINT) {
				return -21;
			}
			if (var_left == NULL) {
				if (expr_op == EXPR_OP_MINUS) {
					ll l2 = ((Longint*) var_right)->get();
					var = VarFactory::get(-l2, var_right->len());
					return 0;
				}
				return -21;
			}
			if (var_left->type() == TYPE_NULL) {
				var = var_left;
				return 0;
			}
			if (var_left->type() != TYPE_LONGINT) {
				return -21;
			}
			ll l1 = ((Longint*) var_left)->get();
			ll l2 = ((Longint*) var_right)->get();
			ll l = 0;
			if (expr_op == EXPR_OP_PLUS) {
				l = l1 + l2;
			}
			if (expr_op == EXPR_OP_MINUS) {
				l = l1 - l2;
			}
			if (expr_op == EXPR_OP_MULTIPLY) {
				l = l1 * l2;
			}
			if (expr_op == EXPR_OP_DIVIDE) {
				if (l2 != 0) {
					l = l1 / l2;
				}
			}
			uint len_left = var_left->len();
			uint len_right = var_right->len();
			uint len = len_left;
			if (len_left < len_right) {
				len_right = len;
			}
			var = VarFactory::get(l, len);
		}
		else {
			var = var_right;
		}
		return 0;
	}
};

#endif
