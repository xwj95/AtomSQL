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

#define YYERROR_VERBOSE
#define YYDEBUG 0

void yyerror(const char *s);
int yylex(void);
extern int yylineno;

int yydebug=0;
int to_print = 0;
int num_stmts = 0;
%}
/* 辅助定义 */
%union {
	double dval;
	int ival;
	char *strval;
	Literal_t *lval;
	Constraint_t *constr;
	ForeignKeyRef_t fkeyref;
	Column_t *col;
	KeyDec_t *kdec;
	StrList_t *slist;
	Insert_t *ins;
	Condition_t *cond;
	Expression_t *expr;
	ColumnReference_t *colref;
	Delete_t *del;
	SRA_t *sra;
	ProjectOption_t *opt;
	TableReference_t *tref;
	Table_t *tbl;
	JoinCondition_t *jcond;
	Index_t *idx;
	Create_t *cre;
}

/* part2 : 声明在flex中定义的那些TOKEN */
%token CREATE TABLE INSERT INTO SELECT FROM WHERE FULL
%token PRIMARY FOREIGN KEY DEFAULT CHECK NOT TOKEN_NULL
%token AND OR NEQ GEQ LEQ REFERENCES ORDER BY DELETE
%token AS INT DOUBLE CHAR VARCHAR TEXT USING CONSTRAINT
%token JOIN INNER OUTER LEFT RIGHT NATURAL CROSS UNION
%token VALUES AUTO_INCREMENT ASC DESC UNIQUE IN ON
%token COUNT SUM AVG MIN MAX INTERSECT EXCEPT DISTINCT
%token CONCAT TRUE FALSE CASE WHEN DECLARE BIT GROUP
%token INDEX
%token <strval> IDENTIFIER
%token <strval> STRING_LITERAL
%token <dval> DOUBLE_LITERAL
%token <ival> INT_LITERAL

%type <ival> column_type bool_op comp_op select_combo
%type <ival> function_name opt_distinct join
%type <strval> column_name table_name opt_alias 
%type <strval> index_name column_name_or_star
%type <slist> column_names_list opt_column_names
%type <constr> can_null opt_constraints constraints constraint
%type <lval> literal_value values_list in_statement
/*%type <fkeyref> references_stmt*/
%type <col> column_dec column_dec_list
%type <kdec> key_dec opt_key_dec_list key_dec_list
%type <ins> insert
%type <cond> condition bool_term where_condition opt_where_condition
%type <expr> expression mulexp primary expression_list term
%type <colref> column_reference
%type <del> delete
%type <sra> select select_statement table
%type <opt> order_by group_by opt_options
%type <tref> table_ref
%type <tbl> create_table
%type <jcond> join_condition opt_join_condition
%type <idx> create_index
%type <cre> create

%start sql_queries

%%
/* 语法规则 */

/* Bison能够完全支持LR(1)文法。*/
/* 这种文法的特点是只要多向前看一个TOKEN，就能够决定如何解析。*/
/* bison用$$表示规则左边的对象，用$1 $2 $3 等依次表示规则右边的对象。*/

sql_queries
	: sql_query
	| sql_queries sql_query
	;

sql_query
	: sql_line ';' { /*printf("parsed %d valid SQL statements\n", ++num_stmts);*/ }
	;

sql_line
	: create
	| select
	| insert
	| delete
	| drop
	| update
	| use
	| show
	| desc
	| /* empty */
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
	: SHOW TABLE table_name
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
	: INT 			{ $$ = TYPE_INT; }
	| DOUBLE 		{ $$ = TYPE_DOUBLE; }
	| CHAR 			{ $$ = TYPE_CHAR; }
	| VARCHAR 		{ $$ = TYPE_TEXT; }
	| TEXT 			{ $$ = TYPE_TEXT; }
/*	| column_type '(' INT_LITERAL ')' 
		{ 
			$$ = $1;
			if ($3 <= 0) {
				fprintf(stderr, "Error: sizes must be greater than 0 (line %d).\n", yylineno);
				exit(1);
			}
			Column_setSize($3);
		}*/
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
	: PRIMARY KEY '(' column_name ')' { $$ = $4; }
	;

opt_constraints
	: constraints
	| /* empty */ { $$ = NULL; }
	;

constraints
	: constraint { $$ = Constraint_append(NULL, $1); 
						/*printf("new constraint:");
						Constraint_print($1);
						printf("created a vector of constraints\n");
						Constraint_printList($$);*/
					 }
	| constraint constraints { $$ = Constraint_append($2, $1); 
										/*printf("appended a constraint\n");
										Constraint_printList($$);*/
									}
	;

constraint
	: NOT TOKEN_NULL { $$ = false; }
	| UNIQUE { $$ = Unique(); }
	| PRIMARY KEY 	{ $$ = PrimaryKey(); }
	| DEFAULT literal_value { $$ = Default($2); }
	| CHECK condition { $$ = Check($2); }
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

select_combo
	: UNION {$$ = UNION;}
	| INTERSECT {$$ = INTERSECT;}
	| EXCEPT {$$ = EXCEPT;}
	;

/*
****	select_statement	:	select_node (query)		****
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
	: DISTINCT { $$ = DISTINCT; }
	: ALL { $$ = ALL; }
	| /* empty */ { $$ = 0; }
	;

opt_options
	: order_by {$$ = $1; }
	| group_by {$$ = $1; }
	| order_by group_by {$$ = ProjectOption_combine($1, $2);}
	| group_by order_by {$$ = ProjectOption_combine($1, $2);}
	| /* empty */ { $$ = NULL; }
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
	: ORDER BY relattr 		{ $$ = order_by_node($3, NO); }
	| ORDER BY relattr ASC 	{ $$ = order_by_node($3, $4); }
	| ORDER BY relattr DESC { $$ = order_by_node($3, $4); }
	;

condition
	: bool_term { $$ = list_node($1); /*printf("Found condition: \n"); Condition_print($$); puts(""); */}
	| bool_term bool_op condition 
   	{ 
   		$$ = condition_list_node($1, $2, $3); 
   		/* printf("Found condition: \n"); Condition_print($$); puts(""); */
   	}
   ;

// bool_term
//    : expression comp_op expression 
//    	{
//    		$$ = ($2 == '=') ? Eq($1, $3) :
//    			  ($2 == '>') ? Gt($1, $3) :
//    			  ($2 == '<') ? Lt($1, $3) :
//    			  ($2 == GEQ) ? Leq($1, $3) :
//    			  ($2 == LEQ) ? Geq($1, $3) :
//    			  Not(Eq($1, $3));
//    	}
//    | expression in_statement { $$ = In($1, $2); }
//    | '(' condition ')' 	{ $$ = $2; }
//    | NOT bool_term 		{ $$ = Not($2); }
//    ;

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
			$$ = relattr_node($1, NULL);/* can this ok? */
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
	: AND { $$ = AND; } 
	| OR { $$ = OR; }
	;

/*
"="				{ return EQU;			}
"!="			{ return NEQ;			}
"<>"			{ return NEQ;			}
"<"				{ return LSS;			}
">"				{ return GTR;			}
"<="			{ return LEQ;			}
">="			{ return GEQ;			}
*/
comp_op
	: EQU { $$ = EQU; } 
	| NEQ { $$ = NEQ; }
	| LSS { $$ = LSS; } 
	| GTR { $$ = GTR; } 
	| LEQ { $$ = LEQ; } 
	| GEQ { $$ = GEQ; } 
	| IS { $$ = IS; } 
	| LIKE { $$ = LIKE; }
	;

/* 聚合函数 (aggregate function) */
/*
expression_list		:	select_clause_node (non_mt_select_clause)
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
	: expr_plus PLUS mulexp { $$ = expr_node($1, $2, $3); }
	| expr_plus MINUS mulexp { $$ = expr_node($1, $2, $3); }
	| mulexp { $$ = $1; }
	;

mulexp
	: mulexp MULTIPLY primary 	{ $$ = expr_node($1, $2, $3); }
	| mulexp DIVIDE primary 	{ $$ = expr_node($1, $2, $3); }
	| mulexp CONCAT primary { $$ = expr_node($1, $2, $3); }
	| primary 		{ $$ = $1; }
	;

primary
	: '(' expr_plus ')' 	{ $$ = $2; }
	| DIVIDE primary 		{ $$ = expe_node(NULL, $2, $3); }
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
	: COUNT { $$ = FUNC_COUNT; }
	| SUM { $$ = FUNC_SUM; }
	| AVG { $$ = FUNC_AVG; }
	| MIN { $$ = FUNC_MIN; }
	| MAX{ $$ = FUNC_MAX; }
	;

column_name
	: IDENTIFIER { $$ = $1; }
	;

table_name
	: IDENTIFIER { $$ = $1; }
	;

table
	: table_ref ',' table { $$ = prepend($1, $3); }
	// | table default_join table_ref opt_join_condition { $$ = SRAJoin($1, SRATable($3), $4); }
	// | table join table_ref opt_join_condition
	// 	{
	// 		switch ($2) {
	// 			case SRA_NATURAL_JOIN:
	// 				$$ = SRANaturalJoin($1, SRATable($3)); 
	// 				if ($4) {
	// 					fprintf(stderr, 
	// 							  "Line %d: WARNING: a NATURAL join cannot have an ON "
	// 							  "or USING clause. This will be ignored.\n", yylineno);
	// 				}
	// 				break;
	// 			case SRA_LEFT_OUTER_JOIN:
	// 				$$ = SRALeftOuterJoin($1, SRATable($3), $4); break;
	// 			case SRA_RIGHT_OUTER_JOIN:
	// 				$$ = SRARightOuterJoin($1, SRATable($3), $4); break;
	// 			case SRA_FULL_OUTER_JOIN:
	// 				$$ = SRAFullOuterJoin($1, SRATable($3), $4); break;
	// 		}
	// 	}
	;

// opt_join_condition
// 	: join_condition
// 	| /* empty */	  { $$ = NULL; }
// 	;

// join_condition
// 	: ON condition { $$ = On($2); }
// 	| USING '(' column_names_list ')' { $$ = Using($3); }
// 	;

table_ref
	: table_name opt_alias { $$ = table_list_node($1, $2);}
	;

// join
// 	: LEFT opt_outer JOIN {$$ = SRA_LEFT_OUTER_JOIN; }
// 	| RIGHT opt_outer JOIN { $$ = SRA_RIGHT_OUTER_JOIN; }
// 	| FULL opt_outer JOIN { $$ = SRA_FULL_OUTER_JOIN; }
// 	| NATURAL JOIN { $$ = SRA_NATURAL_JOIN; }
// 	;

// default_join
// 	: ',' | JOIN | CROSS JOIN | INNER JOIN
// 	;

// opt_outer
// 	: OUTER
// 	| /* empty */
// 	;

insert
	: INSERT INTO table_name VALUES '(' values_list ')'
		{
			$$ = insert_node($3, $6);
		}
	;

opt_column_names
	: '(' column_names_list ')' { $$ = $2; }
	| /* empty */		 { $$ = NULL; }
	;

column_names_list
	: column_name { $$ = StrList_make($1); }
	| column_names_list ',' column_name { $$ = StrList_append($1, StrList_make($3)); }
	;

values_list
	: literal_value { $$ = list_node($1); }
	| literal_value ',' values_list
		{ 
			$$ = prepend($1, $3); 
		}
	;

literal_value
	: INT_LITERAL { $$ = value_node(INT, (void *)& $1); }
	| DOUBLE_LITERAL { $$ = value_node(FLOAT, (void *)& $1); }
	| STRING_LITERAL { $$ = value_node(STRING, (void *) $1); }/* have & or not ?*/
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
void yyerror(const char *s) {
	fprintf(stdout, "Error: %s (line %d)\n", s, yylineno);
}

List_t *tables = NULL;

int main(int argc, char const *argv[])
{
	int i;
	puts("Welcome to chiSQL! :)");
	puts("calling init");
	mock_db_init();
	for (i=1; i<argc; ++i) {
		FILE *fp = fopen(argv[i], "r");
		if (fp) {
			printf("Parsing file '%s'...\n", argv[i]);
			stdin = fp;
			if (!yyparse())
				printf("Parsed successfully!\n");
			else
				printf("Please check your code.\n");
			fclose(fp);
		} else {
			char buf[100];
			sprintf(buf, "Error opening file '%s'", argv[i]);
         perror(buf);
		}
	}
	puts("We have the following tables:");
	show_tables();
	List_t cols = columns_in_common_str("Foo", "Bar");
	printf("tables Foo and Bar have %lu %s in common\n", 
		cols.size, 
		cols.size > 1 ? "cols" : "col");

	puts("Thanks for using chiSQL :)\n");
	return 0;
}
