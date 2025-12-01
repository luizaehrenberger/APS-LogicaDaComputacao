%{
#include <stdio.h>
#include "linha.tab.h"
void yyerror(const char *s);
%}

%option noyywrap
%option yylineno

%%

.   { return yytext[0]; }

%%
