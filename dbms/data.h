/*
 * data.h
 *
 *  Created on: 2015年10月25日
 *      Author: Xwj95
 */

#ifndef DBMS_DATA_H_
#define DBMS_DATA_H_

#include "../type/types.h"
#include <vector>
#include <string>

class Data {
public:
	std::vector<Types> data;
	std::vector<bool> isNull;
	std::vector<std::string> names;
	ull rid;
	Data() {
		clear();
	}
	void clear() {
		data.clear();
		isNull.clear();
		names.clear();
		rid = 0;
	}
};

#endif /* DBMS_DATA_H_ */
