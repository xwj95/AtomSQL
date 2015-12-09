#include "dbms/dbms.h"
#include <iostream>

#include "var/varfactory.h"
#include "table/columns.h"
#include "table/row.h"

using namespace std;

Dbms *dbms;
Columns header;

Columns sampleHeader() {
	Columns header;
	return header;
}

void init() {
	dbms->createDatabase("database1");
	dbms->createDatabase("database2");
	dbms->createDatabase("database3");
	dbms->useDatabase("database1");
	// dbms->dropTable("table1");
	// dbms->dropTable("table2");
	dbms->createTable("table1", header);
	dbms->createTable("table2", header);
}

void test1() {
//	dbms->showTables();
//	dbms->descTable("table1");
//	dbms->useDatabase("database4");					//数据库不存在
//	dbms->useDatabase("database1");
//	dbms->dropTable("table1");
//	dbms->dropDatabase("database1");
//	dbms->dropTable("table1");						//没有指定数据库
//	dbms->useDatabase("database2");
//	dbms->dropTable("table2");						//表不存在
//	dbms->dropDatabase("database2");
//	dbms->dropDatabase("database100");				//数据库不存在
}

void test2() {

}

int main() {
	dbms = new Dbms();
	header = sampleHeader();
	init();
	test1();										//系统管理模块测试
//	test2();										//记录管理模块测试
	cout << "Successful!" << endl;
	return 0;
}
