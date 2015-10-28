/*
 * varchar.h
 *
 *  Created on: 2015年10月28日
 *      Author: Xwj95
 */

#ifndef TYPE_VARCHAR_H_
#define TYPE_VARCHAR_H_

#include "types.h"
#include <string>

class Varchar : public Types {
public:
	std::string varchar_value;
	Varchar(std::string value) {
		varchar_value = value;
		type = Type::Varchar;
	}
	int size() {
		return varchar_value.length() * sizeof(char);
	}
};

#endif /* TYPE_VARCHAR_H_ */
