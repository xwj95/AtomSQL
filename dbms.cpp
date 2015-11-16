#include "dbms/dbms.h"
#include <iostream>

using namespace std;

Column sampleColumn() {
	Column column;
	column.schema = "create table table1(column1 int(10), column 2 char(100) NOT NULL)";
	column.name.push_back("column1");
	column.type.push_back(Type::Longint);
	column.canNull.push_back(true);
	column.length.push_back(10);
	column.name.push_back("column2");
	column.type.push_back(Type::Varchar);
	column.canNull.push_back(false);
	column.length.push_back(100);
	return column;
}
vector<Data> sampleData() {
	vector<Data> sample_data;
	sample_data.clear();
	Data _data = Data();
	_data.data.push_back(Types(Type::Longint, 1020));
	_data.data.push_back(Types(Type::Varchar, "iloveyou!", 100));
	_data.isNull.push_back(false);
	_data.isNull.push_back(false);
	_data.rid = 60;
	sample_data.push_back(_data);
	_data.data[0] = Types(Type::Longint, 65540);
	_data.rid = 61;
	sample_data.push_back(_data);
	_data.data[0] = Types(Type::Longint, 4294967299);
	_data.rid = 64;
	sample_data.push_back(_data);
	_data.data[0] = Types(Type::Longint, 13);
	_data.rid = 66;
	sample_data.push_back(_data);
	return sample_data;
}
vector<int> sampleInt(int i) {
	vector<int> sample_int;
	sample_int.clear();
	sample_int.push_back(i);
	return sample_int;
}
vector<int> samplePage() {
	vector<int> sample_page;
	sample_page.clear();
	sample_page.push_back(1);
	return sample_page;
}
vector<Data> sampleUpdate() {
	vector<Data> sample_data;
	Data _data = Data();
	_data.data.push_back(Types(Type::Longint, 2333));
	_data.data.push_back(Types(Type::Varchar, "ohsqlsqlsql", 100));
	_data.isNull.push_back(false);
	_data.isNull.push_back(false);
	_data.rid = 404;
	sample_data.push_back(_data);
	return sample_data;
}
void test1(Dbms *dbms) {
	dbms->showTables();
	dbms->descTable("table1");
	dbms->useDatabase("database4");					//数据库不存在
	dbms->useDatabase("database1");
	dbms->dropTable("table1");
	dbms->dropDatabase("database1");
	dbms->dropTable("table1");						//没有指定数据库
	dbms->useDatabase("database2");
	dbms->dropTable("table2");						//表不存在
	dbms->dropDatabase("database2");
	dbms->dropDatabase("not_exist_database");		//数据库不存在
}
void test2(Dbms *dbms) {
	vector<Data> sample_data = sampleData();
	dbms->descTable("table1");
	dbms->insertData("table1", sample_data, Column());	//插入四个元组 (1020,love) (65540, love) (429467299, love) (13, love)
	dbms->useDatabase("database2");
	dbms->useDatabase("database1");
	dbms->showTables();
	vector<int> sample_index0 = sampleInt(0);
	vector<int> sample_index1 = sampleInt(1);
	vector<int> sample_index2 = sampleInt(2);
	vector<int> sample_index3 = sampleInt(3);
	vector<int> sample_index4 = sampleInt(4);
	vector<int> sample_index5 = sampleInt(5);
	vector<int> sample_index10 = sampleInt(10);
	vector<int> sample_page = samplePage();
	vector<Data> sample_update = sampleUpdate();
	cout << "-------" << endl;
	dbms->updateData("table1", sample_page, sample_index1, sample_update);	//将第二个元组更新为 (2333, sql)
	cout << "-------" << endl;
	dbms->deleteData("table1", sample_page, sample_index2);					//删除第三个元组
	cout << "-------" << endl;
	dbms->updateData("table1", sample_page, sample_index4, sample_update);	//超出范围，无效，仅输出
	cout << "-------" << endl;
	dbms->deleteData("table1", sample_page, sample_index0);					//删除第一个元组
	cout << "-------" << endl;
	dbms->updateData("table1", sample_page, sample_index5, sample_update);	//超出范围，无效，仅输出
	cout << "-------" << endl;
	dbms->insertData("table1", sample_data, Column());						//再插入四个元组
	cout << "-------" << endl;
	dbms->updateData("table1", sample_page, sample_index10, sample_update);	//超出范围，无效，仅输出
	cout << "-------" << endl;
}

int main() {
	MyBitMap::initConst();
	Dbms *dbms = new Dbms();
	//测试样例
	Column column = sampleColumn();
	dbms->createDatabase("database1");
	dbms->createDatabase("database2");
	dbms->createDatabase("database3");
	dbms->useDatabase("database1");
	dbms->dropTable("table1");
	dbms->dropTable("table2");
	dbms->createTable("table1", column);
	dbms->createTable("table2", column);
	test1(dbms);							//系统管理模块测试
//	test2(dbms);							//记录管理模块测试
	delete dbms;
	cout << "Successful!" << endl;
	return 0;
}
