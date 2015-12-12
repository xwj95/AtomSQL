/*
 * parser_internal.h: internal declarations for the REDBASE parser
 * 
 * Huang Huan
 * CST, Tsinghua University
 */


#ifndef PARSER_INTERNAL_H
#define PARSER_INTERNAL_H

// #include "parser.h"

/*
 * use double for real
 */
// typedef real float;
// typedef float real;

/*
 * the prompt
 */
#define PROMPT	"\nAtomSQL >> "

/*
 * REL_ATTR: describes a qualified attribute (relName.attrName)
 */

//typedef struct{
//    char *relName;      /* relation name        */
//    char *attrName;     /* attribute name       */
//} REL_ATTR;

/*
 * ATTR_VAL: <attribute, value> pair
 */
//typedef struct{
//    char *attrName;     /* attribute name       */
//    AttrType valType;   /* type of value        */
//    int valLength;      /* length if type = STRING */
//    void *value;        /* value for attribute  */
//} ATTR_VAL;

/*
#define N_CREATETABLE 0
#define N_CREATEINDEX 1
#define N_CREATEDATABASE 2
#define N_DROPTABLE 3
#define N_DROPINDEX 4
#define N_DROPDATABASE 5
#define N_USEDATABASE 6
#define N_DESCTABLE 7
#define N_SHOWTABLE 8
#define N_SELECT 9
#define N_QUERY 10
#define N_INSERT 11
#define N_DELETE 12
#define N_UPDATE 13
#define N_RELATTR 14
#define N_ORDERATTR 15
#define N_AGGRELATTR 16
#define N_CONDITION 17
#define N_CONDITIONLIST 18
#define N_RELATTR_OR_VALUE 19
#define N_ATTRTYPE 20
#define N_VALUE 21
#define N_RELATION 22
#define N_LIST 23
#define N_OPTALIAS 24
#define N_EXPR 25
#define N_TABLELIST 26
#define N_IN 27
*/

/*
 * all the available kinds of nodes
 */
//typedef enum{
enum NODEKIND {
    N_CREATETABLE,
    N_CREATEINDEX,
    N_CREATEDATABASE,
    N_DROPTABLE,
    N_DROPINDEX,
    N_DROPDATABASE,
    N_USEDATABASE,
    N_DESCTABLE,
    N_SHOWTABLE,
    N_SELECT,
    N_QUERY,
    N_INSERT,
    N_DELETE,
    N_UPDATE,
    N_RELATTR,
    N_ORDERATTR,
    N_AGGRELATTR,
    N_CONDITION,
    N_CONDITIONLIST,
    N_RELATTR_OR_VALUE,
    N_ATTRTYPE,
    N_VALUE,
    N_RELATION,
    N_LIST,
    N_OPTALIAS,
    N_EXPR,
    N_TABLELIST,
    N_IN
};
//} NODEKIND;


/*
 * structure of parse tree nodes
 */
typedef struct node{
//   NODEKIND kind;
   int kind;

   union{
      /* SM component nodes */
      /* create table node */
      struct{
         char *relname;
         struct node *attrlist;
         struct node *keydeclist;
      } CREATETABLE;

      /* create index node */
      struct{
         char *relname;
         char *attrname;
      } CREATEINDEX;

      /* create database node */
      struct{
      	char *dbname;
      } CREATEDATABASE;

      /* drop table node */
      struct{
         char *relname;
      } DROPTABLE;

      /* drop index node */
      struct{
         char *relname;
         char *attrname;
      } DROPINDEX;

      /* drop database node */
      struct{
      	char *dbname;
      } DROPDATABASE;

      /* use database node */
      struct{
      	char *dbname;
      } USEDATABASE;

      /* desc table node */
      struct{
         char *relname;
      } DESCTABLE;

      /* show table node -- as func "print"*/
      struct{
         char *relname;
      } SHOWTABLE;

      /* QL component nodes */
      /* query node */
      struct{
      	int optdistinct;
         struct node *selectclause;
         struct node *tablelist;
         struct node *conditionlist;
         struct node *orderrelattr; 
         struct node *grouprelattr; 
      } QUERY;

      /* select node */
      struct{
      	struct node *query;
      	int combo;
      	struct node *select;
      } SELECT;

      /* insert node */
      struct{
         char *relname;
         struct node *valuelist;
      } INSERT;

      /* delete node */
      struct{
         char *relname;
         struct node *conditionlist;
      } DELETE;

      /* update node */
      struct{
         char *relname;
         struct node *relattr;
         struct node *relorvalue;
         struct node *conditionlist;
      } UPDATE;

      /* command support nodes */
      /* relation attribute node */
      struct{
         char *relname;
         char *attrname;
      } RELATTR;

      /* order + relation attribute node */
      struct{
         int order;
         struct node *relattr;
      } ORDERATTR;

      /* agg func + relation attribute node */
      struct{
         AggFun func;
         char *relname;
         char *attrname;
      } AGGRELATTR;

      /* condition node */
      struct{
         struct node *lhsRelattr;
         CompOp op;
         struct node *rhsRelattr;
         struct node *rhsValue;
      } CONDITION;

      /* condition list node */
      struct{
         struct node *boolterm;
         int boolop;
         struct node *condlist;
      } CONDITIONLIST;

      /* relation-attribute or value */
      struct{
         struct node *relattr;
         struct node *value;
      } RELATTR_OR_VALUE;

      /* <attribute, type> pair */
      struct{
         char *attrname;
         char *type;
         int length;
         bool canNull;
      } ATTRTYPE;

      /* <value, type> pair */
      struct{
         AttrType type;
         int  ival;
         float rval;
         char *sval;
      } VALUE;

      /* relation node */
      struct{
         char *relname;
      } RELATION;

      /* list node */
      struct{
         struct node *curr;
         struct node *next;
      } LIST;

      /* opt alias node */
      struct{
      	struct node *exprplus;
      	char *alias;
      } OPTALIAS;

      /* expr node */
      struct{
      	struct node *expleft;
      	int exprop;	//operator
      	struct node *expright;
      } EXPR;

      /* table list node */
      struct{
      	char *relname;
      	char *alias;
      } TABLELIST;

      /* in node */
      struct{
      	struct node *relattr;
      	struct node *instatement;
      } IN;
   } u;
} NODE;


/*
 * function prototypes
 */
//NODE *newnode(int kind);

NODE *newnode(NODEKIND kind);
NODE *create_table_node(char *relname, NODE *attrlist, NODE *keydeclist);
NODE *create_index_node(char *relname, char *attrname);
NODE *create_database_node(char *dbname);
NODE *drop_table_node(char *relname);
NODE *drop_index_node(char *relname, char *attrname);
NODE *drop_database_node(char *dbname);
NODE *use_database_node(char *dbname);
NODE *desc_table_node(char *relname);
NODE *show_table_node(char *relname);
NODE *select_node(NODE *query, int combo, NODE *select);
NODE *query_node(int optdistinct, NODE *selectclause, NODE *tablelist, NODE *conditionlist, 
                 NODE *order_relattr, NODE *group_relattr);
NODE *insert_node(char *relname, NODE *valuelist);
NODE *delete_node(char *relname, NODE *conditionlist);
NODE *update_node(char *relname, NODE *relattr, NODE *value, NODE *conditionlist);
NODE *relattr_node(char *relname, char *attrname);
NODE *orderattr_node(int order, NODE *relattr);
NODE *aggrelattr_node(AggFun a, char *relname, char *attrname);
NODE *condition_node(NODE *lhsRelattr, CompOp op, NODE *rhsRelattrOrValue);
NODE *condition_list_node(NODE *boolterm, int boolop, NODE *condlist);
NODE *value_node(AttrType type, void *value);
NODE *relattr_or_value_node(NODE *relattr, NODE *value);
NODE *attrtype_node(char *attrname, int type, int length, bool canNull);
NODE *relation_node(char *relname);
NODE *list_node(NODE *n);
NODE *opt_alias_node(NODE *exprplus, char *alias);
NODE *expr_node(NODE *expleft, int exprop, NODE *expright);
NODE *table_list_node(char *relname, char *alias);
NODE *in_node(NODE *relattr, NODE *instatement);
NODE *prepend(NODE *n, NODE *list);

void new_query(void);
RC   interp(NODE *n);
int  yylex(void);
int  yyparse(void);

#endif
