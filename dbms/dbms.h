#ifndef DBMS_DBMS_H_
#define DBMS_DBMS_H_

#include "../filesystem/filesystem.h"
#include "../table/columns.h"
#include "../table/row.h"
#include "../utils/document.h"
#include "../utils/io.h"

class Dbms {

	Document *document;

public:

	Dbms() {
		MyBitMap::initConst();
		document = new Document();
	}
	~Dbms() {
		if (document != NULL) {
			delete document;
		}
	}

	//创建数据库
	int createDatabase(string dbName) {
		return document->createDirectory(dbName);
	}

	//删除数据库
	int dropDatabase(string dbName) {
		int result = document->removeDirectory(dbName);
		if (result == -1) {
			cout << dbName << " does not exist." << endl;
		}
	}

	//切换数据库
	int useDatabase(string dbName) {
		int result = document->useDirectory(dbName);
		if (result == -1) {
			cout << dbName << " does not exist." << endl;
		}
		return result;
	}

	//列出当前数据库所有表
	int showTables() {

	}

	//列出表的模式信息
	int descTable(string tableName) {

	}

	//创建表
	int createTable(string tableName, Columns &header) {
		int result = document->createFile(tableName, header);
		if (result == -2) {
			cout << "Please specify an existing database." << endl;
			return result;
		}
		if (result == -3) {
			cout << tableName + dbtype << " already exists." << endl;
			return result;
		}
	}

	//删除表
	int dropTable(string tableName) {

	}

	//插入记录
	int insertRow(string tableName, Row &row) {

	}

	//删除记录
	int deleteRow(string tableName, int delta) {

	}

	//更新记录
	int updateRow(string tableName, int delta, Row &row) {

	}

	//查找记录
	int selectRow(string tableName) {

	}

};

#endif
