/*
 * sql.l: lex spec for SQL
 * flex sql.l
 * flex -P"json2tdata_" -o sql.l.cpp sql.l
 * -p "json2tdata_"是给语法分析器加一个前缀。
 * 有这个选项，就会生成json2tdata_parse等以json2tdata开头的函数。
 * 
 * Huang Huan
 * CST, Tsinghua University
 */

/*
本lex的生成文件是lex.yy.c 
lex文件由3段组成，用2个%%行把这3段隔开。 
第1段是声明段，包括： 
	1-C代码部分：include头文件、函数、类型等声明，这些声明会原样拷到生成的.c文件中。 
	2-状态声明，如%x COMMENT。 
	3-正则式定义，如digit ([0-9])。 
第2段是规则段，是lex文件的主体，包括每个规则(如identifier)是如何匹配的，以及匹配后要执行的C代码动作。 
第3段是C函数定义段，如yywrap()的定义，这些C代码会原样拷到生成的.c文件中。该段内容可以为空
*/

/* part1 : copy to .c file 原封不动的复制到flex的生成代码中 */
%{
#include <iostream>
#include <math.h>
#include <string.h>
#include "main.h"
#include "parser_internal.h"
#include "y.tab.h"

extern int yydebug;
int comment_start_lineno;

static int get_id(char *s);   /* defined in scanhelp.c */
static char *get_qstring(char *qstring, int len);
%}

%x BLOCK_COMMENT
%x LINE_COMMENT

/* 规则段 */
/* part2 : 用正则表达式定义了一些数据类型 */
%%
create			{ return CREATE;		}
database		{ return DATABASE;		}
drop			{ return DROP;			}
use				{ return USE;			}
show			{ return SHOW;			}
tables			{ return TABLES;		}
table			{ return TABLE;			}
not 			{ return NOT;			}
null			{ return TOKEN_NULL;	}
primary 		{ return PRIMARY;		}
key				{ return KEY;			}
desc			{ return DESC;			}
insert			{ return INSERT;		}
into			{ return INTO;			}
values			{ return VALUES;		}
delete			{ return DELETE;		}
from			{ return FROM;			}
where			{ return WHERE;			}
update 			{ return UPDATE;		}
set 			{ return SET;			}
select			{ return SELECT;		}
index			{ return INDEX;			}
check			{ return CHECK;			}
group			{ return GROUP;			}
by				{ return BY;			}
like			{ return LIKE;			}

order			{ return ORDER;			}
having			{ return HAVING;		}
# foreign			{ return FOREIGN;		}
# default			{ return DEFAULT;		}
as				{ return AS;			}
distinct		{ return DISTINCT;		}
all				{ return ALL;			}
# references		{ return REFERENCES;	}
# jion			{ return JION;			}
# inner 			{ return INNER;			}
# outer			{ return OUTER;			}
# full			{ return FULL;			}
# left			{ return LEFT;			}
# right			{ return RIGHT;			}
# natural			{ return NATURAL;		}
# union			{ return UNION;			}
# auto_increment	{ return AUTO_INCREMENT;}
asc				{ return ASC;			}
# unique			{ return UNIQUE;		}
in 				{ return IN;			}
# on 				{ return ON;			}
# using			{ return USING;			}

# true			{ return TRUE;			}
# false			{ return FALSE;			}
# when			{ return WHEN;			}
# bit				{ return BIT;			}

and				{ return AND;			}
or				{ return OR;			}

sum				{ return SUM;			}
avg				{ return AVG;			}
max				{ return MAX;			}
min 			{ return MIN;			}
count			{ return COUNT;			}

"+"				{ return PLUS;			}
"-"				{ return MINUS;			}	# MINUS / NEG
"*"				{ return MULTIPLY;		}	# MULTIPLE / STAR
"/"				{ return DIVIDE;		}

"="				{ return EQU;			}
"!="			{ return NEQ;			}
"<>"			{ return NEQ;			}
"<"				{ return LSS;			}
">"				{ return GTR;			}
"<="			{ return LEQ;			}
">="			{ return GEQ;			}
"||"			{ return CONCAT;		}

int 			{ return INT;			}
integer			{ return INT;			}
longint			{ return LONGINT;		}
double			{ return DOUBLE;		}
char			{ return CHAR;			}
varchar			{ return VARCHAR;		}
# text			{ return TEXT;			}

\/\*							{ BEGIN(BLOCK_COMMENT); comment_start_lineno = yylineno; }
<BLOCK_COMMENT>\*\/ 			{ BEGIN(INITIAL); }
<BLOCK_COMMENT><<EOF>>			{ fprintf(stderr, "Warning: unclosed comment beginning on line %d\n",
												 ++comment_start_lineno); return EOF; }
<BLOCK_COMMENT>\n 				{ yylineno++; }
<BLOCK_COMMENT>.				{ /* ignore */ }
"--"							{ BEGIN(LINE_COMMENT); }
<LINE_COMMENT>\n 				{ BEGIN(INITIAL); yylineno++; }
<LINE_COMMENT>.					{ /* ignore */ }
[a-zA-Z][a-zA-Z0-9_]* 			{ yylval.strval = strdup(yytext); 
									if (yydebug) printf("lexed identifier '%s'\n", yytext); 
									return IDENTIFIER; }
((\"[^\"]*\")|(\'[^\']*\'))		{ yylval.strval = strndup(yytext+1, strlen(yytext) - 2); return STRING_LITERAL; }
[+-]?[0-9]+ 					{ yylval.ival = atoi(yytext); return INT_LITERAL; }
([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)		{ yylval.dval = atof(yytext); return DOUBLE_LITERAL; }
[ \t\r]+						{ /* ignore */ }
\n 								{ yylineno++; }
. 								{ if (yydebug) printf("lexed single character '%c'\n", yytext[0]); 
									return yytext[0]; }


%%
/* 用户代码段 */
/* part3 : 定义了词法分析器在解析的处理动作 */
#include "sacnhelp.c"
/*
void main() {
	yylex();
}
*/


	