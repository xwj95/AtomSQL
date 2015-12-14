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
#include "node_def.h"
//#include "parser_internal.h"
#include "bison.tab.h"

// int my_yyinput(char * buf, int max_size); /* defined in scanhelp.c */
/* Flex uses the macro YY_INPUT to read input data. YY_INPUT needs to be 
*  redefined for input redirection. 
*  For more information please see pages 156-157 of:  
        Lex & Yacc
        by John R. Levine, Tony Mason, Doug Brown
        Reilly & Associates; ISBN: 1565920007
        (Available in the Stanford MATH/CS Library)
*/
// #undef YY_INPUT
// #define YY_INPUT(buffer, result, max_size) (result = my_yyinput(buffer, max_size))

%}

letter               [A-Za-z]
digit                [0-9]
num                  {digit}+
s_num                [+\-]?{num}
%x comment
%x shell_cmd

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
order			{ return ORDER;			}
as				{ return AS;			}
distinct		{ return DISTINCT;		}
all				{ return ALL;			}
asc				{ return ASC;			}
in 				{ return IN;			}
except    { return EXCEPT;  }
intersect { return INTERSECT;}
union     { return UNION;   }
quit      { return QUIT;      }

and				{ return AND;			}
or				{ return OR;			}

sum				{ return SUM;			}
avg				{ return AVG;			}
max				{ return MAX;			}
min 			{ return MIN;			}
count			{ return COUNT;			}

"+"				{ return PLUS;			}
"-"				{ return MINUS;			}
"*"				{ return MULTIPLY;		}
"/"				{ return DIVIDE;		}

"="				{ return EQU;			}
"!="			{ return NEQ;			}
"<>"			{ return NEQ;			}
"<"				{ return LSS;			}
">"				{ return GTR;			}
"<="			{ return LEQ;			}
">="			{ return GEQ;			}
"||"			{ return CONCAT;		}
like			{ return LIKE;			}
is 				{ return IS;			}

int       { return INTEGER;     }
char      { return CHAR;    }
float     { return FLOAT;   }
varchar   { return VARCHAR; }

"/*"                 {BEGIN(comment);}
<comment>[^*]        {/* ignore the text of the comment */}
<comment>"*/"        {BEGIN(INITIAL);}
<comment>\*          {/* ignore *'s that aren't part of */}
[ \n\t]              {/* ignore spaces, tabs, and newlines */}
{s_num}              {yylval.ival = atoi(yytext);
                      return INT_LITERAL;}
{s_num}\.{num}       {yylval.rval = atof(yytext);
                      return FLOAT_LITERAL;}
{s_num}\.{num}[Ee]{s_num}   {sscanf(yytext, "%f", &yylval.rval);
                             return FLOAT_LITERAL;}
((\"[^\"]*\")|(\'[^\']*\'))      {yylval.sval = strndup(yytext+1, strlen(yytext) - 2);
                            return STRING_LITERAL;}
{letter}({letter}|{digit}|_)*   {yylval.sval = strdup(yytext);
								 return IDENTIFIER;}
!                    {BEGIN(shell_cmd);}
<shell_cmd>[^\n]*    {yylval.sval = yytext; return T_SHELL_CMD;}
<shell_cmd>\n        {BEGIN(INITIAL);}
[*/+\-=<>:;,.|&()]  {return yytext[0];}
<<EOF>>              {return T_EOF;}
.                    {printf("illegal character [%c]\n", yytext[0]);}

%%
/* 用户代码段 */
/* part3 : 定义了词法分析器在解析的处理动作 */

/*
void main() {
	yylex();
}
*/


	
