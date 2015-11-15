/*
 * types.h
 *
 *  Created on: 2015年10月28日
 *      Author: Xwj95
 */

#ifndef TYPE_TYPES_H_
#define TYPE_TYPES_H_

#include "type.h"
#include "../dbms/io.h"

class Types
{
public:
	Type type;
	int int_value;
	ll longint_value;
	std::string varchar_value;
	uint length;
	Types(uint _type, ll value) {
		type = (Type) _type;
		switch (type) {
		case Type::Int:
			int_value = value;
			break;
		case Type::Longint:
			longint_value = value;
			break;
		default:
			break;
		}
	}
	Types(uint _type, std::string value, uint len) {
		type = (Type) _type;
		switch (type) {
		case Type::Varchar:
			varchar_value = value;
			length = len;
			break;
		default:
			break;
		}
	}
	int size() {
		switch (type) {
		case Type::Char:
			break;
		case Type::Int:
			return sizeof(int);
			break;
		case Type::Longint:
			return sizeof(ll);
			break;
		case Type::Varchar:
			return varchar_value.length() * sizeof(char);
			break;
		default:
			break;
		}
		return 0;
	}
	BufType write(BufType b, IO *io) {
		switch (type) {
		case Type::Char:
			break;
		case Type::Int:
			return io->writeInt(b, int_value);
			break;
		case Type::Longint:
			return io->writeLong(b, longint_value);
			break;
		case Type::Varchar:
			return io->writeChar(b, varchar_value, length);
			break;
		default:
			break;
		}
		return b;
	}
	BufType read(BufType b, IO *io) {
		switch (type) {
		case Type::Char:
			break;
		case Type::Int:
			return io->readInt(b, int_value);
			break;
		case Type::Longint:
			return io->readLong(b, longint_value);
			break;
		case Type::Varchar:
			return io->readChar(b, varchar_value, length);
			break;
		default:
			break;
		}
		return b;
	}
};

#endif /* TYPE_TYPES_H_ */
