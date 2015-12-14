#include "dbms/dbms.h"
#include <iostream>

#include "var/varfactory.h"
#include "table/columns.h"
#include "table/rows.h"

using namespace std;

Dbms *dbms;
Columns header;
Rows records;
Rows update;
vector<int> update_index;

Columns sampleHeader() {
	Columns header;
	header.schema = "create table table1(column1 int(10), column 2 char(100) NOT NULL)";
	header.major = 1;
	header.pages = 0;
	Column column;
	column.type = TYPE_LONGINT;
	column.length = 10;
	column.canNull = true;
	column.name = "column1";
	header.column.push_back(column);
	column.type = TYPE_VARCHAR;
	column.length = 100;
	column.canNull = false;
	column.name = "column2";
	header.column.push_back(column);
	header.calSize();
	return header;
}

Item sampleInt(ll i) {
	Item item;
	item.var = VarFactory::get(i, 10);
	item.isNull = false;
	return item;
}

Item sampleString(string s) {
	Item item;
	item.var = VarFactory::get(s, 100);
	item.isNull = false;
	return item;
}

Rows sampleRecords() {
	Rows records;
	Row record;

	record.items.push_back(sampleInt(47));
	record.items.push_back(sampleString("I love you"));
	records.rows.push_back(record);

	record.items.clear();
	record.items.push_back(sampleInt(99));
	record.items.push_back(sampleString("I need you"));
	records.rows.push_back(record);

	record.items.clear();
	record.items.push_back(sampleInt(4294967299));
	record.items.push_back(sampleString("I'm so happy"));
	records.rows.push_back(record);

	record.items.clear();
	record.items.push_back(sampleInt(13));
	record.items.push_back(sampleString("I found you"));
	records.rows.push_back(record);
	return records;
}

Rows sampleUpdate() {
	Rows records;
	Row record;

	record.items.push_back(sampleInt(374));
	record.items.push_back(sampleString("Update!!Update!!Update!!"));
	records.rows.push_back(record);

	record.items.clear();
	record.items.push_back(sampleInt(272));
	record.items.push_back(sampleString("Curry!!!Curry!!!"));
	records.rows.push_back(record);
	return records;
}

vector<int> sampleIndex() {
	vector<int> index;
	index.push_back(1);
	index.push_back(3);
	return index;
}

void init() {
	dbms->createDatabase("database1");
	dbms->createDatabase("database2");
	dbms->createDatabase("database3");
	dbms->useDatabase("database1");
	dbms->showTables();
	dbms->dropTable("table1");
	dbms->dropTable("table2");
	dbms->useDatabase("database1");
	dbms->createTable("table1", header);
	dbms->createTable("table2", header);
}

void test1() {
	dbms->showTables();
	dbms->descTable("table1");
	dbms->useDatabase("database4");					//数据库不存在
	dbms->useDatabase("database1");
	dbms->dropTable("table1");
//	dbms->dropDatabase("database1");
	dbms->dropTable("table1");						//没有指定数据库
	dbms->useDatabase("database2");
	dbms->dropTable("table2");						//表不存在
	dbms->dropDatabase("database2");
	dbms->dropDatabase("database100");				//数据库不存在
}

void test2() {
	dbms->insertRows("table1", records);
	dbms->deleteRows("table1", update_index);
	dbms->insertRows("table1", records);
	dbms->updateRows("table1", update_index, update);
}

int main() {
	dbms = new Dbms();
	header = sampleHeader();
	records = sampleRecords();
	update = sampleUpdate();
	update_index = sampleIndex();
	init();
//	test1();										//系统管理模块测试
	test2();										//记录管理模块测试
	cout << "Successful!" << endl;
	delete dbms;
	return 0;
}
