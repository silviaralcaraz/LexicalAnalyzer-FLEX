#include "stdio.h"
#include "stdlib.h"

extern FILE *yyin;
extern char* yytext;
extern int yylex (void);
int yylex_destroy();
