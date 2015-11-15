/*
 * dbmsdef.h
 *
 *  Created on: 2015年10月26日
 *      Author: Xwj95
 */

#ifndef DBMS_DBMSDEF_H_
#define DBMS_DBMSDEF_H_

#define BUFFER_SIZE 1001

#define TABLE_HEADER_SCHEMA_BITS 1000
#define TABLE_HEADER_MAJOR_SIZE 4
#define TABLE_HEADER_PAGES_SIZE 4
#define TABLE_HEADER_TYPES_BITS 8
#define TABLE_HEADER_LENGTH_BITS 23
#define TABLE_HEADER_NULL_BITS 1
#define TABLE_HEADER_NAME_BITS 400

#define TABLE_ITEM_NULL_BITS 1
#define TABLE_ITEM_EMPTY_SIZE 4
#define TABLE_ITEM_NEXT_SIZE 4
#define TABLE_ITEM_RID_SIZE 8
#define TABLE_ITEM_INT_SIZE 4
#define TABLE_ITEM_LONGINT_SIZE 8
#define TABLE_ITEM_CHAR_SIZE 1

const std::string separator = "/";
const std::string dbtype = ".db";

#endif /* DBMS_DBMSDEF_H_ */
