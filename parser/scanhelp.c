/*
 * scanhelp.c: help functions for lexer
 *
 * Authors: Jan Jannink
 *          Jason McHugh
 *          
 * originally by: Mark McAuliffe, University of Wisconsin - Madison, 1991
 * 
 * 1997 Changes: "print", "buffer", "reset" and "io" added.
 * 1998 Changes: "resize", "queryplans", "on" and "off" added.
 *
 *
 * This file is not compiled separately; it is #included into lex.yy.c .
 */

/*
 * size of buffer of strings
 */
#define MAXCHAR		5000

/*
 * buffer for string allocation
 */
static char charpool[MAXCHAR];
static int charptr = 0;

static char *mk_string(char *s, int len);

/*
 * string_alloc: returns a pointer to a string of length len if possible
 */
static char *string_alloc(int len)
{
   char *s;

   if(charptr + len > MAXCHAR){
      fprintf(stderr, "out of memory\n");
      exit(1);
   }

   s = charpool + charptr;
   charptr += len;

   return s;
}

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

/*
 * reset_scanner: resets the scanner after a syntax error
 *
 * No return value.
 */
void reset_scanner(void)
{
    charptr = 0;
    yyrestart(yyin);
}

/*
 * get_qstring: removes the quotes from a quoted string, allocates
 * space for the resulting string.
 *
 * Returns:
 * 	a pointer to the new string
 */
static char *get_qstring(char *qstring, int len)
{
   /* replace ending quote with \0 */
   qstring[len - 1] = '\0';

   /* copy everything following beginning quote */
   return mk_string(qstring + 1, len - 2);
}

/*
 * mk_string: allocates space for a string of length len and copies s into
 * it.
 *
 * Returns:
 * 	a pointer to the new string
 */
static char *mk_string(char *s, int len)
{
   char *copy;

   /* allocate space for new string */
   if((copy = string_alloc(len + 1)) == NULL){
      printf("out of string space\n");
      exit(1);
   }

   /* copy the string */
   strncpy(copy, s, len + 1);
   return copy;
}
