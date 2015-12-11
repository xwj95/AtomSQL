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



#line 100 "bison.tab.c" /* yacc.c:339  */

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
#line 47 "bison.y" /* yacc.c:355  */

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

#line 221 "bison.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 236 "bison.tab.c" /* yacc.c:358  */

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      69,    70,    73,     2,    71,     2,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    68,
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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   117,   135,   144,   146,   147,   148,   149,
     150,   151,   152,   157,   161,   165,   169,   176,   183,   184,
     185,   189,   190,   191,   195,   199,   203,   207,   211,   218,
     225,   232,   233,   237,   245,   246,   250,   251,   252,   253,
     257,   258,   262,   263,   267,   316,   317,   321,   339,   343,
     350,   354,   361,   365,   372,   376,   380,   387,   395,   396,
     409,   410,   411,   412,   413,   414,   415,   416,   507,   511,
     523,   530,   531,   538,   539,   540,   544
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CREATE", "DROP", "USE", "SHOW",
  "SELECT", "DESC", "INSERT", "DELETE", "UPDATE", "TABLES", "DATABASE",
  "TABLE", "INDEX", "SET", "WHERE", "FROM", "ORDER", "GROUP", "CHECK",
  "BY", "INTO", "VALUES", "AS", "DISTINCT", "ALL", "PRIMARY", "KEY", "ASC",
  "IN", "AND", "OR", "EXCEPT", "INTERSECT", "UNION", "NOT", "TOKEN_NULL",
  "MAX", "MIN", "SUM", "AVG", "COUNT", "EQU", "NEQ", "LSS", "GTR", "LEQ",
  "GEQ", "CONCAT", "IS", "LIKE", "T_EOF", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "INT", "CHAR", "FLOAT", "VARCHAR", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER", "T_SHELL_CMD", "CONTAC",
  "';'", "'('", "')'", "','", "'.'", "'*'", "$accept", "start", "command",
  "use", "desc", "show", "update", "drop", "create", "create_database",
  "drop_database", "drop_table", "database_name", "create_index",
  "drop_index", "create_table", "column_dec_list", "column_dec",
  "can_null", "column_type", "opt_key_dec_list", "key_dec_list", "key_dec",
  "opt_where_condition", "where_condition", "condition", "bool_term",
  "relattr_or_value", "relattr", "in_statement", "bool_op", "comp_op",
  "column_name", "table_name", "insert", "values_list", "literal_value",
  "delete", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,    59,    40,
      41,    44,    46,    42
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,    34,    43,   -52,    50,   -46,    15,    19,   -24,   -63,
     -63,    44,    -5,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -52,   -46,   -46,
     -52,   -46,   -46,   -63,   -63,   -63,   -46,   -63,   -63,   -46,
     -46,    35,   -63,   -63,   -63,    -2,     0,   -63,   -63,     1,
     -63,    48,    56,     9,    10,    10,    10,     7,     9,   -63,
       5,    36,   -63,     8,    11,   -43,    13,    16,    -3,   -63,
      -8,   -17,   -26,   -42,    53,    17,    10,   -63,   -63,   -63,
     -63,    20,   -63,   -63,   -63,   -63,   -63,    18,    21,   -63,
     -63,     9,    22,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -42,   -63,   -63,    56,   -63,   -63,    49,   -63,
      23,   -63,   -63,    28,   -63,    -3,   -63,    -3,   -63,   -63,
     -63,    24,    53,    25,   -63,    26,    10,   -63,    47,   -63,
      27,    60,   -63,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       3,     0,     0,    10,    12,    11,     9,     8,     5,    23,
      20,    18,    22,    19,    21,     6,     7,     0,     0,     0,
       0,     0,     0,    27,    13,    15,     0,    69,    14,     0,
       0,     0,     1,     2,    24,     0,     0,    25,    26,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      56,     0,    68,    41,    31,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,     0,     0,    36,    38,    37,
      39,     0,    28,    29,    73,    74,    75,     0,    71,    58,
      59,     0,     0,    60,    61,    62,    63,    64,    65,    66,
      67,    51,     0,    55,    54,    46,    52,    53,     0,    40,
      42,    30,    32,     0,    70,     0,    49,     0,    50,    17,
      45,     0,     0,     0,    72,     0,     0,    43,    35,    57,
       0,     0,    33,    44,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,     6,   -63,   -63,   -63,    29,   -63,   -63,   -63,
     -63,   -37,   -63,   -63,    -6,    12,   -63,     2,   -47,   -63,
     -63,   -63,   -55,    14,   -63,   -49,   -62,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    34,    22,    23,    24,    63,    64,   132,    81,
      75,   109,   110,   119,    59,    69,    70,   105,    71,   101,
      91,   102,    65,    38,    25,    87,    88,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    67,     1,     2,     3,     4,    61,     5,     6,     7,
       8,   107,   103,    33,    92,    77,    78,    79,    80,    37,
      84,    85,    86,    60,    89,    90,   106,    93,    94,    95,
      96,    97,    98,    44,    99,   100,    47,    40,    39,   104,
     107,    41,    45,    46,    42,    48,    49,    27,    28,    29,
      50,    53,     9,    51,    52,   106,    30,    31,    32,    84,
      85,    86,    35,    43,    36,    10,   124,    54,   125,    55,
      56,   130,    57,    58,    60,    62,    68,    72,   121,    74,
      73,   108,    76,    82,   131,   127,    83,   111,   114,   113,
     123,   117,   115,   126,   122,   128,   129,   133,   134,   120,
       0,     0,     0,   116,   118,   112
};

static const yytype_int8 yycheck[] =
{
      55,    56,     3,     4,     5,     6,    53,     8,     9,    10,
      11,    73,    38,    65,    31,    58,    59,    60,    61,    65,
      62,    63,    64,    65,    32,    33,    73,    44,    45,    46,
      47,    48,    49,    27,    51,    52,    30,    18,    23,    65,
     102,    65,    28,    29,     0,    31,    32,    13,    14,    15,
      36,    16,    53,    39,    40,   102,    13,    14,    15,    62,
      63,    64,    12,    68,    14,    66,   115,    69,   117,    69,
      69,   126,    24,    17,    65,    65,    69,    72,    29,    71,
      44,    28,    71,    70,    37,   122,    70,    70,    70,    69,
      62,    69,    71,    69,    71,    70,    70,    70,    38,   105,
      -1,    -1,    -1,    91,   102,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    53,
      66,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    87,    88,    89,   108,   111,    13,    14,    15,
      13,    14,    15,    65,    86,    12,    14,    65,   107,    23,
      18,    65,     0,    68,    86,   107,   107,    86,   107,   107,
     107,   107,   107,    16,    69,    69,    69,    24,    17,    98,
      65,   102,    65,    90,    91,   106,   106,   106,    69,    99,
     100,   102,    72,    44,    71,    94,    71,    58,    59,    60,
      61,    93,    70,    70,    62,    63,    64,   109,   110,    32,
      33,   104,    31,    44,    45,    46,    47,    48,    49,    51,
      52,   103,   105,    38,    65,   101,   102,   110,    28,    95,
      96,    70,    90,    69,    70,    71,    99,    69,   101,    97,
      98,    29,    71,    62,   109,   109,    69,    95,    70,    70,
     106,    37,    92,    70,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    79,    79,    80,    81,    81,
      81,    82,    82,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    90,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    97,    97,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   107,
     108,   109,   109,   110,   110,   110,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     7,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     6,     6,
       7,     1,     3,     6,     2,     0,     1,     1,     1,     1,
       2,     0,     1,     3,     5,     1,     0,     2,     1,     3,
       3,     2,     1,     1,     3,     3,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     1,     3,     1,     1,     1,     4
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
#line 113 "bison.y" /* yacc.c:1646  */
    {
			parse_tree = (yyvsp[-1].n);
			YYACCEPT;
		}
#line 1420 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "bison.y" /* yacc.c:1646  */
    {
			if (!isatty(0)) {
				cout << ((yyvsp[0].sval)) << "\n";
				cout.flush();
			}
			system((yyvsp[0].sval));
			parse_tree = NULL;
			YYACCEPT;
		}
#line 1434 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 136 "bison.y" /* yacc.c:1646  */
    {
			parse_tree = NULL;
			bExit = 1;
			YYACCEPT;
		}
#line 1444 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 157 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = use_database_node((yyvsp[0].sval)); }
#line 1450 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 161 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = desc_table_node((yyvsp[0].sval)); }
#line 1456 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = show_table_node(NULL);
		}
#line 1464 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = show_table_node((yyvsp[0].sval));
		}
#line 1472 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = update_node((yyvsp[-5].sval), (yyvsp[-3].n), (yyvsp[-1].n), (yyvsp[0].n));
		}
#line 1480 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = create_database_node((yyvsp[0].sval)); }
#line 1486 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = drop_database_node((yyvsp[0].sval)); }
#line 1492 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 203 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = drop_table_node((yyvsp[0].sval)); }
#line 1498 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 207 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 1504 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 212 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = create_index_node((yyvsp[-3].sval), (yyvsp[-1].sval)); 
		}
#line 1512 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = drop_index_node((yyvsp[-3].sval), (yyvsp[-1].sval));
		}
#line 1520 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 226 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = create_table_node((yyvsp[-4].sval), (yyvsp[-2].n), (yyvsp[-1].n));
		}
#line 1528 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 232 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = list_node((yyvsp[0].n)); }
#line 1534 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 233 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1540 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 238 "bison.y" /* yacc.c:1646  */
    { 
			/*printf("column '%s' (%d)\n", $1, $2);*/
			(yyval.n) = attrtype_node((yyvsp[-5].sval), (yyvsp[-4].tval), (yyvsp[-2].ival), (yyvsp[0].bval));
		}
#line 1549 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 245 "bison.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 1555 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 246 "bison.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 1561 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 250 "bison.y" /* yacc.c:1646  */
    { (yyval.tval) = INT_TYPE; }
#line 1567 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 251 "bison.y" /* yacc.c:1646  */
    { (yyval.tval) = FLOAT_TYPE; }
#line 1573 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 252 "bison.y" /* yacc.c:1646  */
    { (yyval.tval) = CHAR_TYPE; }
#line 1579 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 253 "bison.y" /* yacc.c:1646  */
    { (yyval.tval) = VARCHAR_TYPE; }
#line 1585 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 257 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1591 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 1597 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 262 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1603 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 263 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1609 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = relation_node((yyvsp[-1].sval)); }
#line 1615 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 316 "bison.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1621 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 317 "bison.y" /* yacc.c:1646  */
    {(yyval.n) = NULL;}
#line 1627 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 321 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1633 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 340 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = list_node((yyvsp[0].n));
		}
#line 1641 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 344 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = condition_list_node((yyvsp[-2].n), (yyvsp[-1].combo), (yyvsp[0].n)); 
		}
#line 1649 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 351 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = condition_node((yyvsp[-2].n), (yyvsp[-1].cval), (yyvsp[0].n));
		}
#line 1657 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 355 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = in_node((yyvsp[-1].n), (yyvsp[0].n));
		}
#line 1665 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 362 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_or_value_node((yyvsp[0].n), NULL);
		}
#line 1673 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 366 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_or_value_node(NULL, (yyvsp[0].n));
		}
#line 1681 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 373 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node((yyvsp[-2].sval), (yyvsp[0].sval));
		}
#line 1689 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 377 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node((yyvsp[-2].sval), NULL);	/* can this ok? */
		}
#line 1697 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 381 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = relattr_node(NULL, (yyvsp[0].sval));
		}
#line 1705 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 387 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 1711 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "bison.y" /* yacc.c:1646  */
    { (yyval.combo) = AND_COMBO; }
#line 1717 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 396 "bison.y" /* yacc.c:1646  */
    { (yyval.combo) = OR_COMBO; }
#line 1723 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 409 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = EQU_OP; }
#line 1729 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 410 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = NEQ_OP; }
#line 1735 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 411 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = LSS_OP; }
#line 1741 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 412 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = GTR_OP; }
#line 1747 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 413 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = LEQ_OP; }
#line 1753 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 414 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = GEQ_OP; }
#line 1759 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 415 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = IS_OP; }
#line 1765 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 416 "bison.y" /* yacc.c:1646  */
    { (yyval.cval) = LIKE_OP; }
#line 1771 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 1777 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 511 "bison.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 1783 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 524 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = insert_node((yyvsp[-4].sval), (yyvsp[-1].n));
		}
#line 1791 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 530 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = list_node((yyvsp[0].n)); }
#line 1797 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 532 "bison.y" /* yacc.c:1646  */
    { 
			(yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n)); 
		}
#line 1805 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 538 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node(INT_TYPE, (void *)& (yyvsp[0].ival)); }
#line 1811 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 539 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node(FLOAT_TYPE, (void *)& (yyvsp[0].rval)); }
#line 1817 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 540 "bison.y" /* yacc.c:1646  */
    { (yyval.n) = value_node(STRING_TYPE, (void *) (yyvsp[0].sval)); }
#line 1823 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 545 "bison.y" /* yacc.c:1646  */
    {
			(yyval.n) = delete_node((yyvsp[-1].sval), (yyvsp[0].n));
		}
#line 1831 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 1835 "bison.tab.c" /* yacc.c:1646  */
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
#line 552 "bison.y" /* yacc.c:1906  */

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
