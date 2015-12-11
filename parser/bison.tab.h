/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CREATE = 258,
    DROP = 259,
    USE = 260,
    SHOW = 261,
    SELECT = 262,
    DESC = 263,
    INSERT = 264,
    DELETE = 265,
    UPDATE = 266,
    TABLES = 267,
    DATABASE = 268,
    TABLE = 269,
    INDEX = 270,
    SET = 271,
    WHERE = 272,
    FROM = 273,
    ORDER = 274,
    GROUP = 275,
    CHECK = 276,
    BY = 277,
    INTO = 278,
    VALUES = 279,
    AS = 280,
    DISTINCT = 281,
    ALL = 282,
    PRIMARY = 283,
    KEY = 284,
    ASC = 285,
    IN = 286,
    AND = 287,
    OR = 288,
    EXCEPT = 289,
    INTERSECT = 290,
    UNION = 291,
    NOT = 292,
    TOKEN_NULL = 293,
    MAX = 294,
    MIN = 295,
    SUM = 296,
    AVG = 297,
    COUNT = 298,
    EQU = 299,
    NEQ = 300,
    LSS = 301,
    GTR = 302,
    LEQ = 303,
    GEQ = 304,
    CONCAT = 305,
    IS = 306,
    LIKE = 307,
    T_EOF = 308,
    PLUS = 309,
    MINUS = 310,
    MULTIPLY = 311,
    DIVIDE = 312,
    INT = 313,
    CHAR = 314,
    FLOAT = 315,
    VARCHAR = 316,
    INT_LITERAL = 317,
    FLOAT_LITERAL = 318,
    STRING_LITERAL = 319,
    IDENTIFIER = 320,
    T_SHELL_CMD = 321,
    CONTAC = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 47 "bison.y" /* yacc.c:1909  */

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

#line 135 "bison.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
