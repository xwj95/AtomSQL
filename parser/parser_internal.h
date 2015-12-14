/*
 * parser_internal.h: internal declarations for the REDBASE parser
 * 
 * Huang Huan
 * CST, Tsinghua University
 */

#ifndef PARSER_INTERNAL_H
#define PARSER_INTERNAL_H

#include <iostream>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <cctype>
#include <algorithm>
#include "execute.h"
// #include "bison.tab.h"


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
#define N_QUIT 28

/*
 * all the available kinds of nodes
 */
/*
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
*/

/*
 * the prompt
 */
#define PROMPT	"\nAtomSQL >> "

#define YY_SKIP_YYWRAP 1
// #define yywrap() 1
void yyerror(const char *);

//
// Return codes
//
typedef int RC;

//nodes.c
/*
 * total number of nodes available for a given parse-tree
 */
#define MAXNODE		100
static NODE nodepool[MAXNODE];
static int nodeptr = 0;
/*
static node *nodepool = NULL;
static int MAXNODE = 256;
static int nodeptr = 0;
*/

//scanhelp.c
#define MAXCHAR		5000

/*
 * buffer for string allocation
 */
static char charpool[MAXCHAR];
static int charptr = 0;

/*
 * reset_charptr: releases all memory allocated in preparation for the
 * next query.
 *
 * No return value.
 */
void reset_charptr(void)
{
	charptr = 0;
}

static void (*cleanup_func)() = NULL;

/*
 * new_query: prepares for a new query by releasing all resources used
 * by previous queries.
 *
 * No return value.
 */
void new_query(void)
{
    nodeptr = 0;
    reset_charptr();
    if(cleanup_func != NULL)
	(*cleanup_func)();
}


/*
 * function prototypes
 */
/*
node *newnode(int kind);
node *create_table_node(char *relname, node *attrlist, node *keydeclist);
node *create_index_node(char *relname, char *attrname);
node *create_database_node(char *dbname);
node *drop_table_node(char *relname);
node *drop_index_node(char *relname, char *attrname);
node *drop_database_node(char *dbname);
node *use_database_node(char *dbname);
node *desc_table_node(char *relname);
node *show_table_node(char *relname);
node *select_node(node *query, char *combo, node *select);
node *query_node(char *optdistinct, node *selectclause, node *tablelist, node *conditionlist, 
                 node *order_relattr, node *group_relattr);
node *insert_node(char *relname, node *valuelist);
node *delete_node(char *relname, node *conditionlist);
node *update_node(char *relname, node *relattr, node *value, node *conditionlist);
node *relattr_node(char *relname, char *attrname);
node *order_attr_node(node *relattr, char *optasc);
node *aggrelattr_node(char *a, char *relname, char *attrname);
node *condition_node(node *lhsRelattr, char *op, node *rhsRelattrOrValue);
node *condition_list_node(node *boolterm, char *boolop, node *condlist);
node *value_node(char *type, void *value);
node *relattr_or_value_node(node *relattr, node *value);
node *attrtype_node(char *attrname, char *type, int length, bool canNull);
node *relation_node(char *relname);
node *list_node(node *n);
node *opt_alias_node(node *exprplus, char *alias);
node *expr_node(node *expleft, char *exprop, node *expright);
node *table_list_node(char *relname, char *alias);
node *in_node(node *relattr, node *instatement);
node *prepend(node *n, node *list);
node *quit_node();
*/


/*
 * newnode: allocates a new node of the specified kind and returns a pointer
 * to it on success.  Returns NULL on error.
 */

//node *newnode(NODEKIND kind)
node *newnode(int kind)
{
    node *n;

    // if we've used up all of the nodes then error 
    if(nodeptr == MAXNODE){
    	fprintf(stderr, "out of memory\n");
    	exit(1);
    }

    // get the next node 
    n = nodepool + nodeptr;
    ++nodeptr;

    // initialize the `kind' field 
    n -> kind = kind;
    return n;
}
/*
node *newnode(NODEKIND kind)
{
    //首次使用时申请MAXNODE个节点
    if(nodepool == NULL){
        nodepool = (node *)malloc(sizeof(NODE)*MAXNODE);
        assert(nodepool);
    }

    assert(nodeptr <= MAXNODE);
    //当节点个数等于MAXNODE时realloc扩展为原来的两倍节点
    if (nodeptr == MAXNODE){
        MAXnode *= 2;
        node *newpool = 
(node *)realloc(nodepool,sizeof(NODE)*MAXNODE) ; 
        assert(newpool);
        nodepool = newpool;
    }
    
    // get the next node 
    node *n = nodepool + nodeptr;
    ++nodeptr;
    
    // initialize the `kind' field 
    n->kind = kind ;

    return n;
}
*/

/*
 * create_table_node: allocates, initializes, and returns a pointer to a new
 * create table node having the indicated values.
 */
node *create_table_node(char *relname, node *attrlist, node *keydeclist)
{
    node *n = newnode(N_CREATETABLE);

    n -> u.CREATETABLE.relname = relname;
    n -> u.CREATETABLE.attrlist = attrlist;
    n -> u.CREATETABLE.keydeclist = keydeclist;
    return n;
}

/*
 * create_index_node: allocates, initializes, and returns a pointer to a new
 * create index node having the indicated values.
 */
node *create_index_node(char *relname, char *attrname)
{
    node *n = newnode(N_CREATEINDEX);

    n -> u.CREATEINDEX.relname = relname;
    n -> u.CREATEINDEX.attrname = attrname;
    return n;
}

/*
 * create_database_node: allocates, initializes, and returns a pointer to a new
 * create database node having the indicated values.
 */
node *create_database_node(char *dbname)
{
    node *n = newnode(N_CREATEDATABASE);

    n -> u.CREATEDATABASE.dbname = dbname;
    return n;
}

/*
 * quit_node: allocates, initializes, and returns a pointer to a new
 * quit node having the indicated values.
 */
node *quit_node()
{
    node *n = newnode(N_QUIT);

    return n;
}

/*
 * drop_table_node: allocates, initializes, and returns a pointer to a new
 * drop table node having the indicated values.
 */
node *drop_table_node(char *relname)
{
    node *n = newnode(N_DROPTABLE);

    n -> u.DROPTABLE.relname = relname;
    return n;
}

/*
 * drop_index_node: allocates, initializes, and returns a pointer to a new
 * drop index node having the indicated values.
 */
node *drop_index_node(char *relname, char *attrname)
{
    node *n = newnode(N_DROPINDEX);

    n -> u.DROPINDEX.relname = relname;
    n -> u.DROPINDEX.attrname = attrname;
    return n;
}

/*
 * drop_database_node: allocates, initializes, and returns a pointer to a new
 * drop database node having the indicated values.
 */
node *drop_database_node(char *dbname)
{
    node *n = newnode(N_DROPDATABASE);

    n -> u.DROPDATABASE.dbname = dbname;
    return n;
}

/*
 * use_database_node: allocates, initializes, and returns a pointer to a new
 * use database node having the indicated values.
 */
node *use_database_node(char *dbname)
{
    node *n = newnode(N_USEDATABASE);

    n -> u.USEDATABASE.dbname = dbname;
    return n;
}

/*
 * desc_table_node: allocates, initializes, and returns a pointer to a new
 * desc table node having the indicated values.
 */
node *desc_table_node(char *relname)
{
    node *n = newnode(N_DESCTABLE);

    n -> u.DESCTABLE.relname = relname;
    return n;
}

/*
 * show_table_node: allocates, initializes, and returns a pointer to a new
 * show table node having the indicated values.
 */
node *show_table_node(char *relname)
{
    node *n = newnode(N_SHOWTABLE);

    n -> u.SHOWTABLE.relname = relname;
    return n;
}

/*
 * query_node: allocates, initializes, and returns a pointer to a new
 * query node having the indicated values.
 */
node *query_node(char *optdistinct, node *selectclause, node *tablelist, node *conditionlist, 
                 node *order_relattr, node *group_relattr)
{
    node *n = newnode(N_QUERY);

    n->u.QUERY.optdistinct = optdistinct;
    n->u.QUERY.selectclause = selectclause; //relattrlist
    n->u.QUERY.tablelist = tablelist;       //rellist
    n->u.QUERY.conditionlist = conditionlist;
    n->u.QUERY.orderrelattr = order_relattr;
    n->u.QUERY.grouprelattr = group_relattr;
    return n;
}

node *opt_alias_node(node *exprplus, char *alias)
{
    node *n = newnode(N_OPTALIAS);

    n->u.OPTALIAS.exprplus = exprplus;
    n->u.OPTALIAS.alias = alias;
    return n;
}

node *expr_node(node *expleft, char *exprop, node *expright)
{
    node *n = newnode(N_EXPR);

    n->u.EXPR.expleft = expleft;
    n->u.EXPR.exprop = exprop;
    n->u.EXPR.expright = expright;
    return n;
}

node *table_list_node(char *relname, char *alias)
{
    node *n = newnode(N_TABLELIST);

    n->u.TABLELIST.relname = relname;
    n->u.TABLELIST.alias = alias;
    return n;
}


/*
 * select_node: allocates, initializes, and returns a pointer to a new
 * select node having the indicated values.
 */
node *select_node(node *query, char *combo, node *select)
{
    node *n = newnode(N_SELECT);

    n->u.SELECT.query = query;
    n->u.SELECT.combo = combo;
    n->u.SELECT.select = select;
    return n;
}

/*
 * insert_node: allocates, initializes, and returns a pointer to a new
 * insert node having the indicated values.
 */
node *insert_node(char *relname, node *valuelist)
{
    node *n = newnode(N_INSERT);

    n->u.INSERT.relname = relname;
    n->u.INSERT.valuelist = valuelist;
    return n;
}

/*
 * delete_node: allocates, initializes, and returns a pointer to a new
 * delete node having the indicated values.
 */
node *delete_node(char *relname, node *conditionlist)
{
    node *n = newnode(N_DELETE);

    n->u.DELETE.relname = relname;
    n->u.DELETE.conditionlist = conditionlist;
    return n;
}

/*
 * update_node: allocates, initializes, and returns a pointer to a new
 * update node having the indicated values.
 */
node *update_node(char *relname, node *relattr, node *relorvalue, 
		  node *conditionlist)
{
    node *n = newnode(N_UPDATE);

    n->u.UPDATE.relname = relname;
    n->u.UPDATE.relattr = relattr;
    n->u.UPDATE.relorvalue = relorvalue;
    n->u.UPDATE.conditionlist = conditionlist;
    return n;
}


/*
 * orderattr_node: allocates, initializes, and returns a pointer to a new
 * relattr node having the indicated values.
 */
node *order_attr_node(node *relattr, char *optasc)
{
    node *n = newnode(N_ORDERATTR);

    n -> u.ORDERATTR.optasc = optasc;
    n -> u.ORDERATTR.relattr = relattr;
    return n;
}

/*
 * relattr_node: allocates, initializes, and returns a pointer to a new
 * relattr node having the indicated values.
 */
node *relattr_node(char *relname, char *attrname)
{
    node *n = newnode(N_RELATTR);

    n -> u.RELATTR.relname = relname;
    n -> u.RELATTR.attrname = attrname;
    return n;
}


/*
 * aggrelattr_node: allocates, initializes, and returns a pointer to a new
 * relattr node having the indicated values.
 */
node *aggrelattr_node(char *a, char *relname, char *attrname)
{
    node *n = newnode(N_AGGRELATTR);

    n -> u.AGGRELATTR.func = a;
    n -> u.AGGRELATTR.relname = relname;
    n -> u.AGGRELATTR.attrname = attrname;
    return n;
}

/*
 * condition_node: allocates, initializes, and returns a pointer to a new
 * condition node having the indicated values.
 */
node *condition_node(node *lhsRelattr, char *op, node *rhsRelattrOrValue)
{
    node *n = newnode(N_CONDITION);

    n->u.CONDITION.lhsRelattr = lhsRelattr;
    n->u.CONDITION.op = op;
    n->u.CONDITION.rhsRelattr = 
      rhsRelattrOrValue->u.RELATTR_OR_VALUE.relattr;
    n->u.CONDITION.rhsValue = 
      rhsRelattrOrValue->u.RELATTR_OR_VALUE.value;
    return n;
}

/*
 * condition_list_node: allocates, initializes, and returns a pointer to a new
 * condition list node having the indicated values.
 */
node *condition_list_node(node *boolterm, char *boolop, node *condlist)
{
    node *n = newnode(N_CONDITIONLIST);

    n->u.CONDITIONLIST.boolterm = boolterm;
    n->u.CONDITIONLIST.boolop = boolop;
    n->u.CONDITIONLIST.condlist = condlist;
    return n;
}

/*
 * value_node: allocates, initializes, and returns a pointer to a new
 * value node having the indicated values.
 */
node *value_node(char *type, void *value)
{
    node *n = newnode(N_VALUE);

    n->u.VALUE.type = type;
    if (!strcmp(type, "int"))  n->u.VALUE.ival = *(int *)value;
    else if (!strcmp(type, "float")) n->u.VALUE.rval = *(float *)value;
    else if (!strcmp(type, "string")) n->u.VALUE.sval = (char *)value;
    else  {}
    return n;
}

/*
 * relattr_or_valuenode: allocates, initializes, and returns a pointer to 
 * a new relattr_or_value node having the indicated values.
 */
node *relattr_or_value_node(node *relattr, node *value)
{
    node *n = newnode(N_RELATTR_OR_VALUE);

    n->u.RELATTR_OR_VALUE.relattr = relattr;
    n->u.RELATTR_OR_VALUE.value = value;
    return n;
}

/*
 * attrtype_node: allocates, initializes, and returns a pointer to a new
 * attrtype node having the indicated values.
 */
node *attrtype_node(char *attrname, char *type, int length, bool canNull)
{
    node *n = newnode(N_ATTRTYPE);

    n -> u.ATTRTYPE.attrname = attrname;
    n -> u.ATTRTYPE.type = type;
    n -> u.ATTRTYPE.length = length;
    n -> u.ATTRTYPE.canNull = canNull;
    return n;
}

/*
 * relation_node: allocates, initializes, and returns a pointer to a new
 * relation node having the indicated values.
 */
node *relation_node(char *relname)
{
    node *n = newnode(N_RELATION);

    n->u.RELATION.relname = relname;
    return n;
}

/*
 * list_node: allocates, initializes, and returns a pointer to a new
 * list node having the indicated values.
 */
node *list_node(node *n)
{
    node *list = newnode(N_LIST);

    list -> u.LIST.curr = n;
    list -> u.LIST.next = NULL;
    return list;
}

/*
 * in_node: allocates, initializes, and returns a pointer to a new
 * in node having the indicated values.
 */
node *in_node(node *relattr, node *instatement)
{
    node *n = newnode(N_IN);

    n->u.IN.relattr = relattr;
    n->u.IN.instatement = instatement;
    return n;
}

/*
 * prepends node n onto the front of list.
 *
 * Returns the resulting list.
 */
node *prepend(node *n, node *list)
{
    node *newlist = newnode(N_LIST);

    newlist -> u.LIST.curr = n;
    newlist -> u.LIST.next = list;
    return newlist;
}


// void new_query(void);
int  yylex(void);
int  yyparse(void);

/* if input not coming from a terminal, then echo the query */
// static void echo_query(node *n);

/*
 * interp: interprets parse trees
 *
 */
// RC interp(FILE* fp, node *n) {
RC interp(node *n) {
	RC errval = 0;			/* returned error value		*/

	/* if input not coming from a terminal, then echo the query */
	// if(!isatty(0))
	// 	echo_query(n);

	switch(n -> kind){

		case N_CREATETABLE:				/* for CreateTable() */
			{
				/* Make the call to create table */
                                                    Columns header = Columns();
                                                    node *attrlist = n -> u.CREATETABLE.attrlist;
                                                    while (attrlist) {
                                                        Column column = Column();
                                                        node *n = attrlist -> u.LIST.curr;
                                                        string type = string(n -> u.ATTRTYPE.type);
                                                        if (type == "int") {
                                                            column.type = TYPE_LONGINT;
                                                        }
                                                        else if (type == "varchar") {
                                                            column.type = TYPE_VARCHAR;
                                                        }
                                                        else {
                                                            column.type = TYPE_NONE;
                                                        }
                                                        column.length = n -> u.ATTRTYPE.length;
                                                        column.canNull = n -> u.ATTRTYPE.canNull;
                                                        column.name = n -> u.ATTRTYPE.attrname;
                                                        header.column.push_back(column);
                                                        attrlist = attrlist -> u.LIST.next;
                                                    }
                                                    node *keydeclist = n -> u.CREATETABLE.keydeclist;
                                                    header.calSize();
                                                    exe_create_table(n -> u.CREATETABLE.relname, header);
				break;
			}

		case N_CREATEINDEX:				/* for CreateIndex() */
			{
				/* Make the call to create index */
				break;
			}

		case N_CREATEDATABASE:				/* for CreateDatabase() */
			{
				/* Make the call to create database */
                                                    exe_create_database(n -> u.CREATEDATABASE.dbname);
				break;
			}

		case N_DROPINDEX:				/* for DropIndex() */
			{
				/* Make the call to drop index */
				break;
			}

		case N_DROPTABLE:				/* for DropTable() */
			{
				/* Make the call to drop table */
				break;
			}

		case N_DROPDATABASE:				/* for DropDatabase() */
			{
				/* Make the call to drop database */
                                                     
                                                     exe_drop_database(n -> u.DROPDATABASE.dbname);
				break;
			}

		case N_SELECT:				/* for Select() */
			{
				/* Make the call to select */
				break;
			}

		case N_INSERT:				/* for Insert() */
			{
				/* Make the call to insert */
				break;
			}

		case N_DELETE:				/* for Delete() */
			{
				/* Make the call to delete */
				break;
			}

		case N_UPDATE:				/* for Update() */
			{
				/* Make the call to update */
				break;
			}

		case N_USEDATABASE:				/* for UseDatabase() */
			{
				/* Make the call to use database */
                                                    exe_use_database(n -> u.USEDATABASE.dbname);
				break;
			}

		case N_DESCTABLE:				/* for DescTable() */
			{
				/* Make the call to desc table */
				break;
			}

		case N_SHOWTABLE:				/* for ShowTable() */
			{
				/* Make the call to show table */
                                                    exe_show_table();
				break;
			}

                            case N_QUIT:
                                {
                                    /* Make the call to quit */
                                    errval = -1;
                                    break;
                                }

		default:	// should never get here
			break;
	}

	return (errval);
}

#endif
