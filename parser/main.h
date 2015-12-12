/*
 * main.h: global declarations
 * 
 * Huang Huan
 * CST, Tsinghua University
 */
#ifndef MAIN_H
#define MAIN_H

// Please DO NOT include any other files in this file.
#include <iostream>
#include <math.h>
#include <assert.h>

//
// Globally-useful defines
//
#define MAXNAME       24                // maximum length of a relation
                                        // or attribute name
#define MAXSTRINGLEN  255               // maximum length of a
                                        // string-type attribute
#define MAXATTRS      40                // maximum number of attributes
                                        // in a relation

#define YY_SKIP_YYWRAP 1
#define yywrap() 1
void yyerror(const char *);

//
// Return codes
//
typedef int RC;
/*
#define OK_RC         0    // OK_RC return code is guaranteed to always be 0

#define START_PF_ERR  (-1)
#define END_PF_ERR    (-100)
#define START_RM_ERR  (-101)
#define END_RM_ERR    (-200)
#define START_IX_ERR  (-201)
#define END_IX_ERR    (-300)
#define START_SM_ERR  (-301)
#define END_SM_ERR    (-400)
#define START_QL_ERR  (-401)
#define END_QL_ERR    (-500)

#define START_PF_WARN  1
#define END_PF_WARN    100
#define START_RM_WARN  101
#define END_RM_WARN    200
#define START_IX_WARN  201
#define END_IX_WARN    300
#define START_SM_WARN  301
#define END_SM_WARN    400
#define START_QL_WARN  401
#define END_QL_WARN    500

// ALL_PAGES is defined and used by the ForcePages method defined in RM
// and PF layers
const int ALL_PAGES = -1;
*/
//
// Attribute types
//
enum AttrType {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    VARCHAR_TYPE,
    STRING_TYPE
};

//
// Comparison operators
//
enum CompOp {
    NO_OP,                                      // no comparison
    EQU_OP, NEQ_OP, LSS_OP, GTR_OP, LEQ_OP, GEQ_OP,    // binary atomic operators
    IS_OP, LIKE_OP
};

enum Operator {
    PLUS_OP, MINUS_OP, MULTIPLY_OP, DIVIDE_OP, CONCAT_OP
};

//
// Aggregation functions for group by
//
enum AggFun {
  NO_F,
  MIN_F, MAX_F, COUNT_F, 
  SUM_F, AVG_F           // numeric args only
};

//
// SelectCombo
//
enum SelectCombo {
  UNION_COMBO, INTERSECT_COMBO, EXCEPT_COMBO, AND_COMBO, OR_COMBO
};

/*
//
// Pin Strategy Hint
//
enum ClientHint {
    NO_HINT                                     // default value
};

//
// TRUE, FALSE and BOOLEAN
//
#ifndef BOOLEAN
typedef char Boolean;
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif
*/
#endif
