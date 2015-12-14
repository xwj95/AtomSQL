/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "bison.y" /* yacc.c:339  */

	/* 声明 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "node_def.h"
#include "parser_internal.h"
#include "bison.tab.h"

//%code requires { #include "parser_internal.h" }


using namespace std;

//sql-master
#define YYERROR_VERBOSE
void yyerror(const char *s);
int yylex(void);
//extern int yylineno;
#define YYDEBUG 0
int yydebug=0;
//sql-master

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


#line 110 "bison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.h".  */
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
    QUIT = 267,
    TABLES = 268,
    DATABASE = 269,
    TABLE = 270,
    INDEX = 271,
    SET = 272,
    WHERE = 273,
    FROM = 274,
    ORDER = 275,
    GROUP = 276,
    CHECK = 277,
    BY = 278,
    INTO = 279,
    VALUES = 280,
    AS = 281,
    DISTINCT = 282,
    ALL = 283,
    PRIMARY = 284,
    KEY = 285,
    ASC = 286,
    IN = 287,
    AND = 288,
    OR = 289,
    EXCEPT = 290,
    INTERSECT = 291,
    UNION = 292,
    NOT = 293,
    TOKEN_NULL = 294,
    MAX = 295,
    MIN = 296,
    SUM = 297,
    AVG = 298,
    COUNT = 299,
    EQU = 300,
    NEQ = 301,
    LSS = 302,
    GTR = 303,
    LEQ = 304,
    GEQ = 305,
    CONCAT = 306,
    IS = 307,
    LIKE = 308,
    T_EOF = 309,
    PLUS = 310,
    MINUS = 311,
    MULTIPLY = 312,
    DIVIDE = 313,
    INTEGER = 314,
    CHAR = 315,
    FLOAT = 316,
    VARCHAR = 317,
    INT_LITERAL = 318,
    FLOAT_LITERAL = 319,
    STRING_LITERAL = 320,
    IDENTIFIER = 321,
    T_SHELL_CMD = 322,
    CONTAC = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 59 "bison.y" /* yacc.c:355  */

	int ival;
	float rval;
	char *sval;
	bool bval;
	NODE *n;

#line 227 "bison.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "bison.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      70,    71,    74,     2,    72,     2,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   129,   147,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   170,   174,   178,   182,   186,
     193,   200,   201,   202,   206,   207,   208,   212,   216,   220,
     224,   228,   235,   242,   249,   250,   254,   262,   263,   267,
     268,   269,   270,   274,   275,   279,   280,   284,   288,   292,
     300,   301,   302,   315,   319,   323,   327,   328,   329,   333,
     334,   338,   342,   346,   350,   351,   352,   356,   360,   367,
     371,   378,   382,   389,   393,   397,   404,   405,   412,   413,
     417,   418,   419,   420,   421,   422,   423,   424,   432,   433,
     434,   444,   448,   449,   453,   454,   458,   459,   463,   464,
     468,   469,   470,   479,   480,   484,   488,   492,   496,   503,
     504,   505,   509,   510,   511,   512,   513,   517,   521,   525,
     526,   530,   534,   541,   542,   549,   550,   551,   555
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CREATE", "DROP", "USE", "SHOW",
  "SELECT", "DESC", "INSERT", "DELETE", "UPDATE", "QUIT", "TABLES",
  "DATABASE", "TABLE", "INDEX", "SET", "WHERE", "FROM", "ORDER", "GROUP",
  "CHECK", "BY", "INTO", "VALUES", "AS", "DISTINCT", "ALL", "PRIMARY",
  "KEY", "ASC", "IN", "AND", "OR", "EXCEPT", "INTERSECT", "UNION", "NOT",
  "TOKEN_NULL", "MAX", "MIN", "SUM", "AVG", "COUNT", "EQU", "NEQ", "LSS",
  "GTR", "LEQ", "GEQ", "CONCAT", "IS", "LIKE", "T_EOF", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "INTEGER", "CHAR", "FLOAT", "VARCHAR",
  "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "T_SHELL_CMD", "CONTAC", "';'", "'('", "')'", "','", "'.'", "'*'",
  "$accept", "start", "command", "quit", "use", "desc", "show", "update",
  "drop", "create", "create_database", "drop_database", "drop_table",
  "database_name", "create_index", "drop_index", "create_table",
  "column_dec_list", "column_dec", "can_null", "column_type",
  "opt_key_dec_list", "key_dec_list", "key_dec", "select", "select_combo",
  "select_statement", "opt_distinct", "opt_where_condition",
  "where_condition", "opt_group_by_clause", "opt_order_by_clause",
  "opt_asc_desc", "condition", "bool_term", "relattr_or_value", "relattr",
  "in_statement", "bool_op", "comp_op", "expression_list", "expression",
  "expr_plus", "mulexp", "oprt_plus", "oprt_mul", "primary", "term",
  "opt_alias", "function_name", "column_name", "table_name", "table",
  "table_ref", "insert", "values_list", "literal_value", "delete", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    59,
      40,    41,    44,    46,    42
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    44,    52,   -39,    38,    54,   -36,    15,    50,    -3,
    -119,  -119,  -119,     9,    72,     6,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      61,  -119,  -119,   -39,   -36,   -36,   -39,   -36,   -36,  -119,
    -119,  -119,   -36,  -119,  -119,    63,  -119,  -119,   -36,   -36,
      77,    49,  -119,  -119,  -119,  -119,  -119,     9,  -119,    60,
      62,  -119,  -119,    64,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    82,    58,    82,  -119,     2,  -119,    29,    43,  -119,
    -119,    66,  -119,    69,    90,   121,    78,  -119,  -119,    79,
      79,    79,  -119,   -21,   -36,    82,    80,  -119,  -119,  -119,
      82,  -119,  -119,  -119,    82,   -33,    79,    73,    78,  -119,
      74,   104,  -119,    81,  -119,   -15,    89,    92,  -119,    -4,
       8,  -119,  -119,  -119,    43,  -119,    93,    94,    95,  -119,
      45,  -119,    53,   109,    -1,    27,    -5,    96,  -119,  -119,
    -119,  -119,    99,  -119,  -119,  -119,   -36,    91,  -119,  -119,
    -119,    79,  -119,  -119,  -119,    42,  -119,  -119,  -119,    78,
     100,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      27,  -119,  -119,   121,  -119,  -119,   120,  -119,   101,  -119,
    -119,    88,  -119,   143,   148,   152,   153,   105,  -119,    45,
    -119,    13,  -119,  -119,   107,   146,   108,    78,    78,  -119,
    -119,  -119,  -119,   110,    56,    79,  -119,   140,    17,  -119,
    -119,  -119,   111,   141,  -119,  -119,  -119,  -119,  -119,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
      15,     4,     3,     0,     0,     0,    14,    11,    13,    12,
      10,     9,     5,    26,    23,    21,    25,    22,    24,     6,
      48,     7,     8,     0,     0,     0,     0,     0,     0,    30,
      16,    18,     0,    56,    57,     0,   118,    17,     0,     0,
       0,     0,     1,     2,    52,    51,    50,     0,    27,     0,
       0,    28,    29,     0,    19,   103,   116,   115,   113,   114,
     112,     0,   117,     0,    90,     0,    88,   111,    93,    95,
     102,     0,   104,     0,     0,     0,     0,    55,    49,     0,
       0,     0,   101,     0,     0,     0,     0,    96,    97,   110,
       0,    91,    98,    99,     0,     0,     0,     0,     0,   128,
      75,     0,   117,    44,    34,     0,     0,     0,   100,   111,
      60,   119,    89,   109,    92,    94,     0,     0,     0,   105,
       0,    61,    67,     0,     0,     0,     0,     0,    39,    41,
      40,    42,     0,    31,    32,   121,     0,     0,    59,   108,
     106,     0,   125,   126,   127,     0,   123,    78,    79,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    70,
       0,    74,    73,    60,    71,    72,     0,    35,    43,    45,
      33,     0,   120,     0,     0,     0,     0,     0,   122,     0,
      68,     0,    69,    20,     0,     0,     0,     0,     0,    54,
      53,   107,   124,     0,     0,     0,    46,    38,    66,    62,
      77,    76,     0,     0,    36,    64,    65,    63,    47,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,     4,  -119,  -119,  -119,  -119,    47,  -119,
    -119,  -119,  -119,   -11,   -56,  -119,   172,  -119,    14,   103,
       0,     5,  -119,    30,  -119,    21,   -81,  -119,  -119,  -119,
    -119,    97,   122,    98,  -119,  -119,   -48,  -119,    75,  -119,
     -87,    -6,  -119,    51,  -119,    10,  -118,  -119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    40,    26,    27,    28,   113,   114,   214,
     142,   137,   178,   179,    29,    57,    30,    45,   147,   148,
     185,   186,   217,   131,   132,   173,   133,   169,   159,   170,
      75,    76,    77,    78,   100,   104,    79,    80,   101,    81,
      82,    83,   120,   121,    31,   155,   156,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    88,   115,   116,   117,   111,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     5,   175,   127,   129,
       5,    94,    96,    92,   176,   215,   108,    39,    59,    60,
      46,    62,    63,    72,    97,    98,    64,    58,   171,    48,
      61,   126,    84,    85,   138,   139,   140,   141,   216,   115,
     118,    41,   175,    42,   174,    96,   125,    11,    33,    34,
      35,   112,    99,    50,   187,   172,    36,    37,    38,    49,
      12,   202,    52,    13,    95,    53,   152,   153,   154,    13,
     146,    43,    44,    13,    97,    98,   157,   158,   119,   174,
     152,   153,   154,   110,    86,    99,    54,    55,    56,   128,
     102,   103,    65,    66,    67,    68,    69,    70,   152,   153,
     154,   183,   184,   188,   189,   107,   208,   209,   212,    71,
      87,    65,    66,    67,    68,    69,    70,   211,   189,    72,
      89,  -118,    90,    73,    91,   203,   105,    74,    71,   108,
     119,   160,   106,   130,   110,   112,   123,   134,    72,   135,
     194,   196,    73,   136,   161,   162,   163,   164,   165,   166,
     143,   167,   168,   144,   149,   150,   197,   180,   151,   181,
     191,   198,   183,   195,   184,   176,   201,   205,   213,   207,
     219,   210,   218,   177,   206,    51,   200,   193,   109,   190,
     199,   192,   122,     0,   145,    93,     0,   182,   124,     0,
       0,   204
};

static const yytype_int16 yycheck[] =
{
       6,    57,    89,    90,    91,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     7,   135,   105,   106,
       7,    19,    26,    71,    29,     8,    18,    66,    34,    35,
      66,    37,    38,    66,    55,    56,    42,    33,    39,    24,
      36,    74,    48,    49,    59,    60,    61,    62,    31,   136,
      71,    13,   170,    15,   135,    26,   104,    54,    14,    15,
      16,    66,    66,    66,   151,    66,    14,    15,    16,    19,
      67,   189,     0,    70,    72,    69,    63,    64,    65,    70,
      72,    27,    28,    70,    55,    56,    33,    34,    94,   170,
      63,    64,    65,    66,    17,    66,    35,    36,    37,   105,
      57,    58,    39,    40,    41,    42,    43,    44,    63,    64,
      65,    20,    21,    71,    72,    25,   197,   198,   205,    56,
      71,    39,    40,    41,    42,    43,    44,    71,    72,    66,
      70,    73,    70,    70,    70,   191,    70,    74,    56,    18,
     146,    32,    73,    70,    66,    66,    66,    73,    66,    45,
      30,    63,    70,    72,    45,    46,    47,    48,    49,    50,
      71,    52,    53,    71,    71,    71,    23,    71,    73,    70,
      70,    23,    20,    72,    21,    29,    71,    70,    38,    71,
      39,    71,    71,   136,   195,    13,   186,   173,    85,   159,
     185,   170,    95,    -1,   119,    73,    -1,   146,   100,    -1,
      -1,   191
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    54,    67,    70,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    89,    90,    91,    99,
     101,   129,   132,    14,    15,    16,    14,    15,    16,    66,
      88,    13,    15,    27,    28,   102,    66,   126,    24,    19,
      66,   101,     0,    69,    35,    36,    37,   100,    88,   126,
     126,    88,   126,   126,   126,    39,    40,    41,    42,    43,
      44,    56,    66,    70,    74,   115,   116,   117,   118,   121,
     122,   124,   125,   126,   126,   126,    17,    71,    99,    70,
      70,    70,   121,   117,    19,    72,    26,    55,    56,    66,
     119,   123,    57,    58,   120,    70,    73,    25,    18,   104,
      66,   111,    66,    92,    93,   125,   125,   125,    71,   126,
     127,   128,   116,    66,   118,   121,    74,   125,   126,   125,
      70,   108,   109,   111,    73,    45,    72,    96,    59,    60,
      61,    62,    95,    71,    71,   123,    72,   103,   104,    71,
      71,    73,    63,    64,    65,   130,   131,    33,    34,   113,
      32,    45,    46,    47,    48,    49,    50,    52,    53,   112,
     114,    39,    66,   110,   111,   131,    29,    93,    97,    98,
      71,    70,   128,    20,    21,   105,   106,   125,    71,    72,
     108,    70,   110,   103,    30,    72,    63,    23,    23,   106,
     105,    71,   131,    99,   130,    70,    98,    71,   111,   111,
      71,    71,   125,    38,    94,     8,    31,   107,    71,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    80,    81,    81,
      82,    83,    83,    83,    84,    84,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    92,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    97,    98,    99,    99,
     100,   100,   100,   101,   101,   101,   102,   102,   102,   103,
     103,   104,   105,   106,   107,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   124,   125,   126,   127,
     127,   128,   129,   130,   130,   131,   131,   131,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     3,
       7,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     6,     6,     7,     1,     3,     6,     2,     0,     1,
       1,     1,     1,     2,     0,     1,     3,     5,     1,     3,
       1,     1,     1,     8,     8,     3,     1,     1,     0,     1,
       0,     2,     3,     4,     1,     1,     0,     1,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     2,     1,     1,     1,     3,     4,     6,     4,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     7,     1,     3,     1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 125 "bison.y" /* yacc.c:1646  */
    {
			parse_tree = (yyvsp[-1].n);
			YYACCEPT;
		}
#line 1493 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "bison.y" /* yacc.c:1646  */
    {
			if (!isatty(0)) {
				cout << ((yyvsp[0].sval)) << "\n";
				cout.flush();
			}
			system((yyvsp[0].sval));
			parse_tree = NULL;
			YYACCEPT;
		}
#line 1507 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "bison.y" /* yacc.c:1646  */
    {
			parse_tree = NULL;
			bExit = 1;
			YYACCEPT;
		}
#line 1517 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 170 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = quit_node(); }
#line 1523 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 174 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = use_database_node((yyvsp[0].sval)); }
#line 1529 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 178 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = desc_table_node((yyvsp[0].sval)); }
#line 1535 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 183 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = show_table_node(NULL);
		}
#line 1543 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 187 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = show_table_node((yyvsp[0].sval));
		}
#line 1551 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = update_node((yyvsp[-5].sval), (yyvsp[-3].n), (yyvsp[-1].n), (yyvsp[0].n));
		}
#line 1559 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = create_database_node((yyvsp[0].sval)); }
#line 1565 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = drop_database_node((yyvsp[0].sval)); }
#line 1571 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 220 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = drop_table_node((yyvsp[0].sval)); }
#line 1577 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 224 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 1583 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 229 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = create_index_node((yyvsp[-3].sval), (yyvsp[-1].sval)); 
		}
#line 1591 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 236 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = drop_index_node((yyvsp[-3].sval), (yyvsp[-1].sval));
		}
#line 1599 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = create_table_node((yyvsp[-4].sval), (yyvsp[-2].n), (yyvsp[-1].n));
		}
#line 1607 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 249 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = list_node((yyvsp[0].n)); }
#line 1613 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[0].n), (yyvsp[-2].n)); }
#line 1619 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 255 "bison.y" /* yacc.c:1646  */
    { 
			/*printf("column '%s' (%d)\n", $1, $2);*/
			(yyval.n) = attrtype_node((yyvsp[-5].sval), (yyvsp[-4].sval), (yyvsp[-2].ival), (yyvsp[0].bval));
		}
#line 1628 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "bison.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 1634 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 263 "bison.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 1640 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 267 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"int"; }
#line 1646 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 268 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"float"; }
#line 1652 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 269 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"char"; }
#line 1658 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"varchar"; }
#line 1664 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 274 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1670 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 1676 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 279 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1682 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 280 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[0].n), (yyvsp[-2].n)); }
#line 1688 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 284 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = relation_node((yyvsp[-1].sval)); }
#line 1694 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 289 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = select_node((yyvsp[0].n), NULL, NULL);
		}
#line 1702 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = select_node((yyvsp[-2].n), (yyvsp[-1].sval), (yyvsp[0].n));
		}
#line 1710 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"union"; }
#line 1716 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 301 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"intersect"; }
#line 1722 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 302 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"except"; }
#line 1728 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 316 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = query_node((yyvsp[-6].sval), (yyvsp[-5].n), (yyvsp[-3].n), (yyvsp[-2].n), (yyvsp[-1].n), (yyvsp[0].n));
		}
#line 1736 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = query_node((yyvsp[-6].sval), (yyvsp[-5].n), (yyvsp[-3].n), (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].n));
		}
#line 1744 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 323 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 1750 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 327 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"distinct"; }
#line 1756 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 328 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"all"; }
#line 1762 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 329 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 1768 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 333 "bison.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1774 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 334 "bison.y" /* yacc.c:1646  */
    {(yyval.n) = NULL;}
#line 1780 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 338 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1786 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 342 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1792 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 346 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = order_attr_node((yyvsp[-1].n), (yyvsp[0].sval)); }
#line 1798 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 350 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"desc"; }
#line 1804 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 351 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"asc"; }
#line 1810 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 352 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"asc"; }
#line 1816 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 357 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = list_node((yyvsp[0].n));
		}
#line 1824 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 361 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = condition_list_node((yyvsp[-2].n), (yyvsp[-1].sval), (yyvsp[0].n)); 
		}
#line 1832 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 368 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = condition_node((yyvsp[-2].n), (yyvsp[-1].sval), (yyvsp[0].n));
		}
#line 1840 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 372 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = in_node((yyvsp[-1].n), (yyvsp[0].n));
		}
#line 1848 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 379 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_or_value_node((yyvsp[0].n), NULL);
		}
#line 1856 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 383 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_or_value_node(NULL, (yyvsp[0].n));
		}
#line 1864 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 390 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node((yyvsp[-2].sval), (yyvsp[0].sval));
		}
#line 1872 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 394 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node((yyvsp[-2].sval), NULL);	/* can this ok? */
		}
#line 1880 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 398 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node(NULL, (yyvsp[0].sval));
		}
#line 1888 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 404 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 1894 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 406 "bison.y" /* yacc.c:1646  */
    {
   		fprintf(stderr, "****WARNING: IN SELECT statement not yet supported\n");
   	}
#line 1902 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 412 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"and"; }
#line 1908 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 413 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"or"; }
#line 1914 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"="; }
#line 1920 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 418 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"<>"; }
#line 1926 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 419 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"<"; }
#line 1932 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 420 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)">"; }
#line 1938 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 421 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"<="; }
#line 1944 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 422 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)">="; }
#line 1950 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 423 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"is"; }
#line 1956 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 424 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"like"; }
#line 1962 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 432 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = list_node((yyvsp[0].n)); }
#line 1968 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 433 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[0].n), (yyvsp[-2].n)); }
#line 1974 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 435 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = list_node(aggrelattr_node(NULL, NULL, (char*)"*"));
		}
#line 1982 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 444 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = opt_alias_node((yyvsp[-1].n), (yyvsp[0].sval)); }
#line 1988 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 448 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = expr_node((yyvsp[-2].n), (yyvsp[-1].sval), (yyvsp[0].n)); }
#line 1994 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 449 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2000 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 453 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = expr_node((yyvsp[-2].n), (yyvsp[-1].sval), (yyvsp[0].n)); }
#line 2006 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 454 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2012 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 458 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"+"; }
#line 2018 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 459 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"-"; }
#line 2024 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 463 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)'*'; }
#line 2030 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 464 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)'/'; }
#line 2036 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 468 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 2042 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 469 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = expr_node(NULL, (char*)"-", (yyvsp[0].n)); }
#line 2048 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 470 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2054 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 479 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 2060 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 481 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = aggrelattr_node(NULL, NULL, (yyvsp[0].sval));
		}
#line 2068 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 485 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = aggrelattr_node(NULL, (yyvsp[-2].sval), (yyvsp[0].sval));
		}
#line 2076 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 489 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = aggrelattr_node((yyvsp[-3].sval), NULL, (yyvsp[-1].sval));
		}
#line 2084 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 493 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = aggrelattr_node((yyvsp[-5].sval), (yyvsp[-3].sval), (yyvsp[-1].sval));
		}
#line 2092 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 497 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = aggrelattr_node((yyvsp[-3].sval), NULL, (char*)"*");
		}
#line 2100 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 503 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2106 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 504 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2112 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 505 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 2118 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 509 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"count"; }
#line 2124 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 510 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"sum"; }
#line 2130 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 511 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"avg"; }
#line 2136 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 512 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"min"; }
#line 2142 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 513 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (char*)"max"; }
#line 2148 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 517 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2154 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 521 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2160 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 526 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[0].n), (yyvsp[-2].n)); }
#line 2166 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 530 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = table_list_node((yyvsp[-1].sval), (yyvsp[0].sval));}
#line 2172 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 535 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = insert_node((yyvsp[-4].sval), (yyvsp[-1].n));
		}
#line 2180 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 541 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = list_node((yyvsp[0].n)); }
#line 2186 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 543 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = prepend((yyvsp[0].n), (yyvsp[-2].n)); 
		}
#line 2194 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 549 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node((char*)"int", (void *)& (yyvsp[0].ival)); }
#line 2200 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 550 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node((char*)"float", (void *)& (yyvsp[0].rval)); }
#line 2206 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 551 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node((char*)"string", (void *) (yyvsp[0].sval)); }
#line 2212 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 556 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = delete_node((yyvsp[-1].sval), (yyvsp[0].n));
		}
#line 2220 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 2224 "bison.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 563 "bison.y" /* yacc.c:1906  */

/* 用户子程序 */
/* part3 : 语法的推导过程 */
/*
 * Required by yacc
 */

/* the output of the parser goes to the output file */
// extern FILE * outputFilePtr; 
RC AtomSQLparse()
{
	RC rc;
	bExit = 0;
	exe_start();
	while (!bExit) {
		/* Reset parser and scanner for a new query */
    	new_query();
//#if 0
    	/* Print a prompt : AtomSQL */
    	cout << PROMPT;

    	/* Get the prompt to actually show up on the screen */
    	cout.flush(); 

//#endif
    	/* If a query was successfully read, interpret it */
    	if(yyparse() == 0 && parse_tree != NULL) {
    		if ((rc = interp(parse_tree))) {
    		// if ((rc = interp(outputFilePtr, parse_tree))) {
        		// PrintError(rc);
            	if (rc < 0) {
            		bExit = true;
            	}
        	}
        	exe_stop();
        }
	}
	return rc;
}

int main(int argc, char const *argv[])
{
	// RC rc;
	// rc = openDB("dbname");
	// error(rc);

	AtomSQLparse();

	// closeDB();

	return 0;
}

void yyerror(const char *s) {
	puts(s);
	fprintf(stdout, "yyError!\n");
}

extern "C"{
/*
 * Sometimes required
 */
int yywrap(void)
{
   return 1;
}
};
