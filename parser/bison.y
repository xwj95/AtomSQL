/*
 * sql.y: yacc specification for SQL
 * bison -d sql.y
 * bison -d -o sql.y.cpp sql.l -p"json2tdata_"
 * -p "json2tdata_"是给语法分析器加一个前缀。
 * 有这个选项，就会生成json2tdata_parse等以json2tdata开头的函数。
 * 
 * Huang Huan
 * CST, Tsinghua University
 */
 
 /* part1 : copy to .c file 原封不动的复制到flex的生成代码中 */
%{
	/* 声明 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "main.h"
#include "parser_internal.h"

using namespace std;

/*
#ifndef yyrestart
void yyrestart(FILE*);
#endif
*/

/*
 * string representation of tokens; provided by scanner
 */
extern char *yytext;

/*
 * points to root of parse tree
 */
static NODE *parse_tree;

int bExit;                 // when to return from RBparse

int bQueryPlans;           // When to print the query plans


%}
/* 辅助定义 */
%union {
	int ival;
	CompOp cval;
	Operator oprt;
	AggFun aval;
	AttrType tval;
	SelectCombo combo;
	float rval;
	char *sval;
	bool bval;
	NODE *n;
}

/* part2 : 声明在flex中定义的那些TOKEN */
%token CREATE DROP USE SHOW SELECT DESC INSERT DELETE UPDATE
%token TABLES DATABASE TABLE INDEX 
%token SET WHERE FROM ORDER GROUP CHECK BY INTO VALUES AS DISTINCT ALL
%token PRIMARY KEY ASC IN
%token AND OR EXCEPT INTERSECT UNION
%token NOT TOKEN_NULL
%token MAX MIN SUM AVG COUNT
%token EQU NEQ LSS GTR LEQ GEQ CONCAT IS LIKE T_EOF
%token PLUS MINUS MULTIPLY DIVIDE
%token INT CHAR FLOAT VARCHAR
%token <ival> INT_LITERAL
%token <rval> FLOAT_LITERAL
%token <sval> STRING_LITERAL IDENTIFIER T_SHELL_CMD

%type <cval> comp_op
%type <aval> function_name
%type <sval> opt_alias database_name table_name column_name
%type <ival> opt_asc_desc opt_distinct
%type <bval> can_null
%type <tval> column_type
%type <combo> select_combo bool_op
%type <oprt> oprt
%type <n> command
%type <n> create select insert delete drop update use show desc
%type <n> create_database create_table create_index
%type <n> select_statement
%type <n> drop_database drop_table drop_index
%type <n> opt_where_condition where_condition condition in_statement
%type <n> expression_list expression expr_plus mulexp primary term
%type <n> table table_ref
%type <n> opt_group_by_clause opt_order_by_clause
%type <n> values_list literal_value
%type <n> bool_term relattr_or_value relattr
%type <n> column_dec_list column_dec
%type <n> opt_key_dec_list key_dec_list key_dec

%left OR CONTAC
%left AND
%nonassoc EQU NEQ
%nonassoc LSS GTR LEQ GEQ
%left  PLUS MINUS
%left  MULTIPLY DIVIDE

%%
/* 语法规则 */

/* Bison能够完全支持LR(1)文法。*/
/* 这种文法的特点是只要多向前看一个TOKEN，就能够决定如何解析。*/
/* bison用$$表示规则左边的对象，用$1 $2 $3 等依次表示规则右边的对象。*/

start
	: command ';'
		{
			parse_tree = $1;
			YYACCEPT;
		}
	| T_SHELL_CMD
		{
			if (!isatty(0)) {
				cout << ($1) << "\n";
				cout.flush();
			}
			system($1);
			parse_tree = NULL;
			YYACCEPT;
		}
/*	| error
		{
			
			reset_scanner();
			parse_tree = NULL;
			YYACCEPT;
			
		}*/
	| T_EOF
		{
			parse_tree = NULL;
			bExit = 1;
			YYACCEPT;
		}
	;

command
	: create
	| select
	| insert
	| delete
	| drop
	| update
	| use
	| show
	| desc
	/*| /* empty */
	;

use
	: USE database_name { $$ = use_database_node($2); }
	;

desc
	: DESC table_name { $$ = desc_table_node($2); }
	;

show
	: SHOW TABLES
		{
			$$ = show_table_node(NULL);
		}
	| SHOW TABLE table_name
		{
			$$ = show_table_node($3);
		}
	;

update
	: UPDATE IDENTIFIER SET relattr EQU relattr_or_value opt_where_condition
		{
			$$ = update_node($2, $4, $6, $7);
		}
	;

drop
	: drop_table
	| drop_index
	| drop_database
	;

create
	: create_table
	| create_index
	| create_database
	;

create_database
	: CREATE DATABASE database_name { $$ = create_database_node($3); }
	;

drop_database
	: DROP DATABASE database_name { $$ = drop_database_node($3); }
	;

drop_table
	: DROP TABLE table_name { $$ = drop_table_node($3); }
	;

database_name
	: IDENTIFIER { $$ = $1; }
	;

create_index
	: CREATE INDEX table_name '(' column_name ')'
		{ 
			$$ = create_index_node($3, $5); 
		}
	;

drop_index
	: DROP INDEX table_name '(' column_name ')'
		{
			$$ = drop_index_node($3, $5);
		}
	;

create_table
	: CREATE TABLE table_name '(' column_dec_list opt_key_dec_list ')' 
		{
			$$ = create_table_node($3, $5, $6);
		}
	;

column_dec_list
	: column_dec { $$ = list_node($1); }
	| column_dec ',' column_dec_list { $$ = prepend($1, $3); }
	;

column_dec
	: column_name column_type '(' INT_LITERAL ')' can_null 
		{ 
			/*printf("column '%s' (%d)\n", $1, $2);*/
			$$ = attrtype_node($1, $2, $4, $6);
		}
	;

can_null
	: NOT TOKEN_NULL { $$ = false; }
	| /* empty */	{ $$ = true; }
	;

column_type
	: INT 			{ $$ = INT_TYPE; }
	| FLOAT 		{ $$ = FLOAT_TYPE; }
	| CHAR 			{ $$ = CHAR_TYPE; }
	| VARCHAR 		{ $$ = VARCHAR_TYPE; }
	;

opt_key_dec_list
	: ',' key_dec_list { $$ = $2; }
	| /* empty */ { $$ = NULL; }
	;

key_dec_list
	: key_dec { $$ = $1; }
	| key_dec ',' key_dec_list { $$ = prepend($1, $3); }
	;

key_dec
	: PRIMARY KEY '(' column_name ')' { $$ = relation_node($4); }
	;

select
	: select_statement
		{
			$$ = select_node($1, NULL, NULL);
		}
	| select_statement select_combo select 
		{ 
			$$ = select_node($1, $2, $3);
		}
	;

/* combo : 组合 */
select_combo
	: UNION { $$ = UNION_COMBO; }
	| INTERSECT { $$ = INTERSECT_COMBO; }
	| EXCEPT { $$ = EXCEPT_COMBO; }
	;

/*
		****  select_statement  --  select_node (query)  ****
	opt_distinct		:	opt_distinct (distinct | all | nothing)
	expression_list		:	select_clause_node (non_mt_select_clause)
	table 				:	table_list_node (non_mt_relation_list)
	opt_where_condition	:	condition_list_node (opt_where_clause)
	opt_order_by_clause	:	orderrelattr (order_by_node)
	opt_group_by_clause	:	grouprelattr (group_by_node)
*/
select_statement
	: SELECT opt_distinct expression_list FROM table opt_where_condition opt_order_by_clause opt_group_by_clause
		{
			$$ = query_node($2, $3, $5, $6, $7);
		}
	| SELECT opt_distinct expression_list FROM table opt_where_condition opt_group_by_clause opt_order_by_clause
		{
			$$ = query_node($2, $3, $5, $7, $6);
		}
	| '(' select_statement ')' { $$ = $2; }
	;

opt_distinct
	: DISTINCT { $$ = -1; }
	| ALL { $$ = 1; }
	| /* empty */ { $$ = 0; }
	;

opt_where_condition
	: where_condition {$$ = $1;}
	| /* empty */		{$$ = NULL;}
	;

where_condition
	: WHERE condition { $$ = $2; }
	;

opt_group_by_clause
	: GROUP BY relattr { $$ = $3; } 
	;

opt_order_by_clause
	: ORDER BY relattr opt_asc_desc	{ $$ = order_by_node($3, $4); }
	;

opt_asc_desc
	: DESC { $$ = -1; }
	| ASC { $$ = 1; }
	| /* empty */ { $$ = 1; }
	;

condition
	: bool_term
		{
			$$ = list_node($1);
		}
	| bool_term bool_op condition 
		{ 
			$$ = condition_list_node($1, $2, $3); 
		}
	;

bool_term
	: relattr comp_op relattr_or_value
		{
			$$ = condition_node($1, $2, $3);
		}
	| relattr in_statement
		{
			$$ = in_node($1, $2);
		}
	;

relattr_or_value
	: relattr
		{
			$$ = relattr_or_value_node($1, NULL);
		}
	| literal_value
		{
			$$ = relattr_or_value_node(NULL, $1);
		}
	;

relattr
	: IDENTIFIER '.' IDENTIFIER
		{
			$$ = relattr_node($1, $3);
		}
	| IDENTIFIER '.' TOKEN_NULL
		{
			$$ = relattr_node($1, NULL);	/* can this ok? */
		}
	| IDENTIFIER
		{
			$$ = relattr_node(NULL, $1);
		}
	;

in_statement
	:  IN '(' values_list ')' { $$ = $3; }
	|	IN '(' select ')'
   	{
   		fprintf(stderr, "****WARNING: IN SELECT statement not yet supported\n");
   	}
   ;

bool_op
	: AND { $$ = AND_COMBO; } 
	| OR { $$ = OR_COMBO; }
	;

/*
	"="		{ return EQU;	}
	"!="	{ return NEQ;	}
	"<>"	{ return NEQ;	}
	"<"		{ return LSS;	}
	">"		{ return GTR;	}
	"<="	{ return LEQ;	}
	">="	{ return GEQ;	}
*/
comp_op
	: EQU { $$ = EQU_OP; } 
	| NEQ { $$ = NEQ_OP; }
	| LSS { $$ = LSS_OP; } 
	| GTR { $$ = GTR_OP; } 
	| LEQ { $$ = LEQ_OP; } 
	| GEQ { $$ = GEQ_OP; } 
	| IS { $$ = IS_OP; } 
	| LIKE { $$ = LIKE_OP; }
	;

/* 聚合函数 (aggregate function) */
/*
	expression_list	: select_clause_node (non_mt_select_clause)
*/
expression_list
	: expression { $$ = list_node($1); }
	| expression_list ',' expression { $$ = prepend($1, $3); }
	| '*'
		{
			$$ = list_node(aggrelattr_node(NO_F, NULL, (char*)"*"));
		}
	;

/*
	opt_alias	:	AS IDENTIFIER
*/
expression
	: expr_plus opt_alias	{ $$ = opt_alias_node($1, $2); }
	;

expr_plus
	: expr_plus oprt mulexp { $$ = expr_node($1, $2, $3); }
	| mulexp { $$ = $1; }
	;

mulexp
	: mulexp oprt primary 	{ $$ = expr_node($1, $2, $3); }
	| primary 		{ $$ = $1; }
	;

oprt
  : PLUS { $$ = PLUS_OP; }
  | MINUS { $$ = MINUS_OP; }
  | MULTIPLY { $$ = MULTIPLY_OP; }
  | DIVIDE { $$ = DIVIDE_OP; }
  | CONCAT { $$ = CONCAT_OP; }
  ;

primary
	: '(' expr_plus ')' 	{ $$ = $2; }
	| MINUS primary 		{ $$ = expe_node(NULL, MINUS_OP, $2); }
	| term 			{ $$ = $1; } 
	;

/*
	expression 	:	(aggrelattr)
	function 	:	count | sum | avg | min |max
	NO_F		:	no function
*/
term
	: TOKEN_NULL { $$ = NULL; }
	| column_name
		{
			$$ = aggrelattr_node(NO_F, NULL, $1);
		}
	| table_name '.' column_name
		{
			$$ = aggrelattr_node(NO_F, $1, $3);
		}
	| function_name '(' column_name ')'
		{
			$$ = aggrelattr_node($1, NULL, $3);
		}
	| function_name '(' table_name '.' column_name ')'
		{
			$$ = aggrelattr_node($1, $3, $5);
		}
	| function_name '(' '*' ')'
		{
			$$ = aggrelattr_node($1, NULL, (char*)"*");
		}
	;

opt_alias
	: AS IDENTIFIER { $$ = $2; }
	| IDENTIFIER { $$ = $1; }
	| /* empty */ { $$ = NULL; }
	;

function_name
	: COUNT { $$ = COUNT_F; }
	| SUM { $$ = SUM_F; }
	| AVG { $$ = AVG_F; }
	| MIN { $$ = MIN_F; }
	| MAX{ $$ = MAX_F; }
	;

column_name
	: IDENTIFIER { $$ = $1; }
	;

table_name
	: IDENTIFIER { $$ = $1; }
	;

table
	: table_ref ',' table { $$ = prepend($1, $3); }
	;

table_ref
	: table_name opt_alias { $$ = table_list_node($1, $2);}
	;

insert
	: INSERT INTO table_name VALUES '(' values_list ')'
		{
			$$ = insert_node($3, $6);
		}
	;

values_list
	: literal_value { $$ = list_node($1); }
	| literal_value ',' values_list
		{ 
			$$ = prepend($1, $3); 
		}
	;

literal_value
	: INT_LITERAL { $$ = value_node(INT_TYPE, (void *)& $1); }
	| FLOAT_LITERAL { $$ = value_node(FLOAT_TYPE, (void *)& $1); }
	| STRING_LITERAL { $$ = value_node(STRING_TYPE, (void *) $1); }/* have & or not ?*/
	;

delete
	: DELETE FROM table_name where_condition
		{
			$$ = delete_node($3, $4);
		}
	;



%%
/* 用户子程序 */
/* part3 : 语法的推导过程 */
/*
 * Required by yacc
 */

int main(int argc, char const *argv[])
{
	yyparse();

	return 0;
}

/*

//
// Functions for printing the various structures to an output stream
//
ostream &operator<<(ostream &s, const AttrInfo &ai)
{
   return
      s << " attrName=" << ai.attrName
      << " attrType=" << 
      (ai.attrType == INT ? "INT" :
       ai.attrType == FLOAT ? "FLOAT" : "STRING")
      << " attrLength=" << ai.attrLength;
}

ostream &operator<<(ostream &s, const RelAttr &qa)
{
   return
      s << (qa.relName ? qa.relName : "NULL")
      << "." << qa.attrName;
}

ostream &operator<<(ostream &s, const AggRelAttr &qa)
{
  if(qa.func == NO_F)
   return 
      s << (qa.relName ? qa.relName : "NULL")
      << "." << qa.attrName;
  else
   return
      s << qa.func << "(" << (qa.relName ? qa.relName : "NULL")
        << "." << qa.attrName << ")";
}

ostream &operator<<(ostream &s, const Condition &c)
{
   s << "\n      lhsAttr:" << c.lhsAttr << "\n"
      << "      op=" << c.op << "\n";
   if (c.bRhsIsAttr)
      s << "      bRhsIsAttr=TRUE \n      rhsAttr:" << c.rhsAttr;
   else
      s << "      bRshIsAttr=FALSE\n      rhsValue:" << c.rhsValue;
   return s;
}

ostream &operator<<(ostream &s, const Value &v)
{
   s << "AttrType: " << v.type;
   switch (v.type) {
      case INT:
         s << " *(int *)data=" << *(int *)v.data;
         break;
      case FLOAT:
         s << " *(float *)data=" << *(float *)v.data;
         break;
      case STRING:
         s << " (char *)data=" << (char *)v.data;
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const AggFun &func)
{
   switch(func){
      case MIN_F:
         s << " MIN";
         break;
      case MAX_F:
         s << " MAX";
         break;
      case AVG_F:
         s << " AVG";
         break;
      case SUM_F:
         s << " SUM";
         break;
      case COUNT_F:
         s << " COUNT";
         break;
      default:
         // case NO_F:
         s << " ";
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const CompOp &op)
{
   switch(op){
      case EQ_OP:
         s << " =";
         break;
      case NE_OP:
         s << " <>";
         break;
      case LT_OP:
         s << " <";
         break;
      case LE_OP:
         s << " <=";
         break;
      case GT_OP:
         s << " >";
         break;
      case GE_OP:
         s << " >=";
         break;
      case NO_OP:
         s << " NO_OP";
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const AttrType &at)
{
   switch(at){
      case INT:
         s << "INT";
         break;
      case FLOAT:
         s << "FLOAT";
         break;
      case STRING:
         s << "STRING";
         break;
   }
   return s;
}

*/

void yyerror(const char *s) {
	puts(s);
	fprintf(stdout, "yyError!\n");
}

#if 0
/*
 * Sometimes required
 */
int yywrap(void)
{
   return 1;
}
#endif
