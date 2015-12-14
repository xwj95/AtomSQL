#ifndef __EXECUTE_H__
#define __EXECUTE_H__

#ifndef __cplusplus
extern "C" {
#endif

#include "../dbms/dbms.h"

Dbms *dbms;

void exe_start() {
	dbms = new Dbms();
}
void exe_create_database(const char *db_name) {
	dbms->createDatabase(db_name);
}
void exe_drop_database(const char *db_name) {
	dbms->dropDatabase(db_name);
}
void exe_use_database(const char *db_name) {
	dbms->useDatabase(db_name);
}
void exe_stop() {
	if (dbms == NULL) {
		delete dbms;
	}
}

#endif
