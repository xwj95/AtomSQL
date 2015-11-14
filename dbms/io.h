/*
 * io.h
 *
 *  Created on: 2015年11月14日
 *      Author: Xwj95
 */

#ifndef DBMS_IO_H_
#define DBMS_IO_H_

#include "../filesystem/filesystem.h"

class IO {
public:
	BufType writeInt(BufType b, int integer) {
		memcpy(b, &integer, sizeof(int));
		return (uint*) b + 1;
	}
	BufType readInt(BufType b, int &integer) {
		integer = b[0];
		return (uint*) b + 1;
	}
	BufType writeLong(BufType b, long long longinteger) {
		ull longint = longinteger;
		ull mod = 1;
		mod = (mod << 32) - 1;
		uint low = longint & mod;
		uint high = longint >> 32;
		b = writeInt(b, (int) high);
		b = writeInt(b, (int) low);
		return b;
	}
	BufType readLong(BufType b, long long &longint) {
		int high, low;
		b = readInt(b, high);
		b = readInt(b, low);
		longint = ((ull) high << 32) + (ull) low;
		return b;
	}
	BufType writeChar(BufType b, std::string str, int length = 0) {
		if (length == 0) {
			length = str.length();
		}
		uint x = 0;
		for (int i = 0; i < (length + 3) / 4 * 4; ++i) {
			x = x << 8;
			if (i < length) {
				if (i < str.length()) {
					x = x + (uint) str[i];
				}
			}
			if ((i & 3) == 3) {
				memcpy(b, &x, sizeof(uint));
				b = (uint*) b + 1;
				x = 0;
			}
		}
		return b;
	}
	BufType readChar(BufType b, std::string &str, int length) {
		int i = 0;
		str = std::string(length, '\0');
		while (true) {
			uint x = b[0];
			for (int d = 3; d >= 0; --d) {
				str[i + d] = x & ((1 << 8) - 1);
				if ((str[i + d] == 0) && (length > i + d)) {
					length = i + d;
				}
				x = x >> 8;
			}
			b = (uint*) b + 1;
			i = i + 4;
			if (i >= length) {
				str = str.substr(0, length);
				return b;
			}
		}
	}
};

#endif /* DBMS_IO_H_ */
