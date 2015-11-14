/*
 * dbms.h
 *
 *  Created on: 2015年10月26日
 *      Author: Xwj95
 */

#ifndef DBMS_DBMS_H_
#define DBMS_DBMS_H_

#include "../type/integer.h"
#include "io.h"
#include "data.h"
#include "column.h"
#include "dbmsdef.h"
#include <algorithm>
#include <string>
#include <map>

class Dbms {
	FileManager* fm;
	BufPageManager* bpm;
	IO io;
	map<std::string, int> files;
	map<std::string, Column> headers;
	std::string directory;
	const std::string separator = "/";
	const std::string dbtype = ".db";
	int writeData(int fileID, Column column, std::vector<Data> data) {
		Column header = readHeader(fileID, 0);
		int pageID = 1;
		int index;
		BufType b;
		if (pageID <= header.pages) {
			b = bpm->getPage(fileID, pageID, index);
			bpm->access(index);
			bpm->markDirty(index);
		}
		for (int i = 0; i < data.size(); ++i) {
			while (pageID > header.pages) {
				header.pages = header.pages + 1;
				int header_index;
				BufType header_b = bpm->getPage(fileID, 0, header_index);
				header_b = header_b + TABLE_HEADER_SCHEMA_BITS / 4 + TABLE_HEADER_MAJOR_SIZE;
				header_b = io.writeInt(header_b, header.pages);
				bpm->markDirty(header_index);
				b = bpm->allocPage(fileID, pageID, index, true);
				BufType _b;
				for (int i = 0; i < PAGE_SIZE / column.size; ++i) {
					if (i < PAGE_SIZE / column.size - 1) {
						_b = io.writeInt(_b, 1);
					}
					else {
						_b = io.writeInt(_b, 0);
					}
					_b = _b + (column.size - (TABLE_ITEM_NULL_BITS + TABLE_ITEM_NEXT_BITS) / 8) / sizeof(uint);
				}
				bpm->markDirty(index);
			}
			int next = b[0] & ((1 << TABLE_ITEM_NEXT_BITS) - 1);
			if (next > 0) {
				//
			}
		}
	}
	void writeHeader(int fileID, int pageID, Column column) {
		int index;
		BufType b = bpm->allocPage(fileID, pageID, index, true);
//		BufType c = b;
		b = io.writeChar(b, column.schema, TABLE_HEADER_SCHEMA_BITS);
		b = io.writeInt(b, column.major);
		b = io.writeInt(b, column.pages);
		for (int i = 0; i < column.type.size(); ++i) {
			uint x = column.type[i];
			x = x << TABLE_HEADER_LENGTH_BITS;
			x = x + (column.length[i] & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x << TABLE_HEADER_NULL_BITS;
			x = x + column.canNull[i];
			b = io.writeInt(b, x);
			b = io.writeChar(b, column.name[i], TABLE_HEADER_NAME_BITS);
		}
//		for (int i = 0; i < 2048; ++i) {
//			cout << c[i] << ' ';
//		}
//		cout << " write end" << endl;
		bpm->markDirty(index);
	}
	Column readHeader(int fileID, int pageID) {
		int index;
		BufType b = bpm->getPage(fileID, pageID, index);
		bpm->access(index);
//		for (int i = 0; i < 2048; ++i) {
//			cout << b[i] << ' ';
//		}
//		cout << " read end" << endl;
		Column column;
		b = io.readChar(b, column.schema, TABLE_HEADER_NAME_BITS);
		int major;
		b = io.readInt(b, major);
		column.major = (uint) major;
		int pages;
		b = io.readInt(b, pages);
		column.pages = (uint) pages;
		while (true) {
			int _x;
			b = io.readInt(b, _x);
			uint x = (uint) _x;
			if (x == 0) {
				break;
			}
			column.canNull.push_back(x & ((1 << TABLE_HEADER_NULL_BITS) - 1));
			x = x >> TABLE_HEADER_NULL_BITS;
			column.length.push_back(x & ((1 << TABLE_HEADER_LENGTH_BITS) - 1));
			x = x >> TABLE_HEADER_LENGTH_BITS;
			column.type.push_back(x & (1 << TABLE_HEADER_TYPES_BITS) - 1);
			std::string name;
			b = io.readChar(b, name, TABLE_HEADER_NAME_BITS);
			column.name.push_back(name);
		}
		return column;
	}
	int useDirectory(std::string directory) {
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = std::string(direntp->d_name);
			if ((file.length() >= dbtype.length()) && (file.substr(file.length() - dbtype.length(), dbtype.length()) == dbtype)) {
				file = file.substr(0, file.length() - dbtype.length());
				int fileID;
				fm->openFile(file.c_str(), fileID);
				files[file] = fileID;
				headers[file] = readHeader(fileID, 0);
			}
		}
		closedir(dirp);
		return 0;
	}
	int removeDirectory(std::string directory) {
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = std::string(direntp->d_name);
			if ((file != ".") && (file != "..")) {
				file = directory + separator + file;
				int result = remove(file.c_str());
			}
		}
		closedir(dirp);
		return 0;
	}
	int showDirectory(std::string directory) {
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = std::string(direntp->d_name);
			if ((file.length() >= dbtype.length()) && (file.substr(file.length() - dbtype.length(), dbtype.length()) == dbtype)) {
				cout << file.substr(0, file.length() - dbtype.length()) << endl;
			}
		}
		return 0;
	}
	int openTable(std::string tableName) {
		if (opendir(directory.c_str())) {
			std::string file = directory + tableName + dbtype;
			if (files.find(tableName) == files.end()) {
				cout << file << " does not exist." << endl;
				return -1;
			}
		}
		else {
			cout << "Please specify an existing database." << endl;
			return -1;
		}
		return 0;
	}
	int findName(std::vector<std::string> &names, std::string name) {
		std::vector<std::string>::iterator iter = find(names.begin(), names.end(), name);
		if (iter == names.end()) {
			cout << "Cannot find column " << name << endl;
			return -1;
		}
		return iter - names.begin();
	}
	int findIndex(std::vector<int> &indexs, int index) {
		std::vector<int>::iterator iter = find(indexs.begin(), indexs.end(), index);
		if (iter == indexs.end()) {
			return -1;
		}
		return iter - indexs.begin();
	}
	int getIndexs(Column column, Column _column, std::vector<int> &indexs, bool checkNull) {
		if (column.name.size() < 1) {
			column.name = _column.name;
			column.canNull.clear();
			for (int i = 0; i < column.name.size(); ++i) {
				column.canNull.push_back(true);
			}
		}
		indexs.clear();
		for (int i = 0; i < column.name.size(); ++i) {
			int _index = findName(_column.name, column.name[i]);
			if (_index < 1) {
				return -1;
			}
			indexs.push_back(_index);
		}
		if (checkNull) {
			for (int i = 0; i < _column.name.size(); ++i) {
				if ((!_column.canNull[i]) && (findIndex(indexs, i) < 0)) {
					cout << "Column " << _column.name[i] << " cannot be null." << endl;
					return -1;
				}
			}
		}
		return 0;
	}
	int getWriteData(Column column, Column _column, std::vector<int> &indexs, std::vector<Data> &data, std::vector<Data> &_data) {
		_data.clear();
		for (int da = 0; da < data.size(); ++da) {
			std::vector<Types> _data_row = data[da].data;
			std::vector<bool> _isNull_row = data[da].isNull;
			std::vector<Types> _data_row_write;
			std::vector<bool> _isNull_row_write;
			for (int i = 0; i < column.name.size(); ++i) {
				_data_row_write.push_back(Integer(0));
				_isNull_row_write.push_back(true);
			}
			for (int i = 0; i < _data.size(); ++i) {
				int index = indexs[i];
				if (_isNull_row[index] && !_column.canNull[index]) {
					cout << "Cannot insert null in column " << _column.name[index] << "." << endl;
					return -1;
				}
				if (!_isNull_row[index]) {
					_isNull_row_write[index] = false;
					_data_row_write[index] = _data_row[index];
				}
			}
			Data _data_write;
			_data_write.data = _data_row_write;
			_data_write.isNull = _isNull_row_write;
			_data.push_back(_data_write);
		}
		return 0;
	}
	void clear() {
		if (bpm != NULL) {
			delete bpm;
			bpm = NULL;
		}
		if (fm != NULL) {
			delete fm;
			fm = NULL;
		}
	}
public:
	Dbms() {
		fm = NULL;
		bpm = NULL;
		files.clear();
		headers.clear();
		io = IO();
		directory = "";
	}
	~Dbms() {
		clear();
	}
	int createDatabase(std::string dbName) {
		int result = mkdir(dbName.c_str(), S_IRWXU);
		return result;
	}
	int dropDatabase(std::string dbName) {
		if (directory == dbName + separator) {
			directory = "";
			files.clear();
			headers.clear();
			clear();
		}
		if (removeDirectory(dbName)) {
			cout << dbName << " does not exist." << endl;
			return -1;
		}
		int result = rmdir(dbName.c_str());
		return result;
	}
	int useDatabase(std::string dbName) {
		std::string _directory = dbName + separator;
		if (directory != _directory) {
			if (!opendir(_directory.c_str())) {
				cout << dbName << " does not exist." << endl;
				return -1;
			}
			directory = _directory;
			files.clear();
			headers.clear();
			clear();
			fm = new FileManager();
			bpm = new BufPageManager(fm);
		}
		return 0;
	}
	int createTable(std::string tableName, Column column) {
		if (!openTable(tableName)) {
			return -1;
		}
		if (column.type.size() < 1) {
			cout << "Empty table cannot be created." << endl;
			return -1;
		}
		if (column.type.size() > MAX_COL_NUM) {
			cout << "Column number cannot exceed " << MAX_COL_NUM << "." << endl;
		}
		std::string file = directory + tableName + dbtype;
		fm->createFile(file.c_str());
		int fileID;
		fm->openFile(file.c_str(), fileID);
		column.canNull[column.major] = false;
		column.countSize();
		files[tableName] = fileID;
		headers[tableName] = column;
		//create header page
		writeHeader(fileID, 0, column);
		return 0;
	}
	int dropTable(std::string tableName) {
		if (openTable(tableName)) {
			return -1;
		}
		fm->closeFile(files[tableName]);
		files.erase(tableName);
		headers.erase(tableName);
		std::string file = directory + tableName + dbtype;
		int result = remove(file.c_str());
		return 0;
	}
	int showTables() {
		if (opendir(directory.c_str())) {
			showDirectory(directory);
			return 0;
		}
		else {
			cout << "Please specify an existing database." << endl;
			return -1;
		}
	}
	int descTable(std::string tableName) {
		if (!openTable(tableName)) {
			return -1;
		}
		Column column = headers[tableName];
		cout << column.schema << endl;
		return 0;
	}
	int insertData(std::string tableName, std::vector<Data> data, Column column) {
		if (!openTable(tableName)) {
			return -1;
		}
		Column _column = headers[tableName];
		std::vector<int> indexs;
		if (getIndexs(column, _column, indexs, true)) {
			return -1;
		}
		std::vector<Data> _data;
		if (getWriteData(column, _column, indexs, data, _data)) {
			return -1;
		}
		std::string file = directory + tableName + dbtype;
		int fileID;
		fm->openFile(file.c_str(), fileID);
		if (writeData(fileID, _column, _data)) {
			return -1;
		}
		return 0;
	}
	int deleteData(std::string tableName, Data data) {
		return 0;
	}
	int updateData(std::string tableName, Data data) {
		return 0;
	}
	int selectData(std::string tableName, Data data, Data &result) {
		return 0;
	}
};

#endif /* DBMS_DBMS_H_ */
