/*
 * longint.h
 *
 *  Created on: 2015年10月28日
 *      Author: Xwj95
 */

#ifndef TYPE_LONGINT_H_
#define TYPE_LONGINT_H_

#include "types.h"

class Longint : public Types {
public:
	long long longint_value;
	Longint(long long value) {
		longint_value = value;
		type = Type::Longint;
	}
	int size() {
		return sizeof(long long);
	}
};

#endif /* TYPE_LONGINT_H_ */
