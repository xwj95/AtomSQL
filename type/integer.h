/*
 * integer.h
 *
 *  Created on: 2015年10月28日
 *      Author: Xwj95
 */

#ifndef TYPE_INTEGER_H_
#define TYPE_INTEGER_H_

#include "types.h"

class Integer : public Types {
public:
	int int_value;
	Integer(int value) {
		int_value = value;
		type = Type::Int;
	}
	int size() {
		return sizeof(int);
	}
};

#endif /* TYPE_INTEGER_H_ */
