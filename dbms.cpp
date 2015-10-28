#include "dbms/dbms.h"
#include <iostream>

using namespace std;

int main() {
	Dbms *dbms = new Dbms();
	//test example
	dbms->createDatabase("database1");
	dbms->createDatabase("database2");
	dbms->createDatabase("database3");
	dbms->useDatabase("database1");
	Column column;
	column.schema = "create table table1(column1 int(10), column 2 char(100) NOT NULL)";
	column.name.push_back("column1");
	column.type.push_back(Type::Int);
	column.canNull.push_back(true);
	column.length.push_back(10);
	column.name.push_back("column2");
	column.type.push_back(Type::Char);
	column.canNull.push_back(false);
	column.length.push_back(100);
	dbms->createTable("table1", column);
	dbms->createTable("table2", column);
	dbms->showTables();
	dbms->descTable("table1");
	dbms->useDatabase("database4");					//database not exist
	dbms->useDatabase("database1");
	dbms->dropTable("table1");
	dbms->dropDatabase("database1");
	dbms->dropTable("table1");						//not specify a database
	dbms->useDatabase("database2");
	dbms->dropTable("table2");						//table2 not exist
	dbms->dropDatabase("database2");
	dbms->dropDatabase("not_exist_database");		//database not exist
	delete dbms;
	cout << "Successful!" << endl;
	return 0;
}
