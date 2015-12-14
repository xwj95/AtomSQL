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
void exe_drop_database(const char* db_name) {
	dbms->dropDatabase(db_name);
}
void exe_end() {
	if (dbms == NULL) {
		delete dbms;
	}
}

#endif
