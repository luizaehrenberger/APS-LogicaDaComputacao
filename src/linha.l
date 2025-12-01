%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linha.tab.h"

void yyerror(const char *s);
%}

%option noyywrap
%option yylineno

DIGIT   [0-9]
LETTER  [A-Za-z]
IDCHAR  [A-Za-z0-9_]

%%

[ \t\r\n]+             { /* ignora whitespace */ }
"//".*                 { /* ignora comentário de linha */ }

"if"                   { return T_IF; }
"else"                 { return T_ELSE; }
"while"                { return T_WHILE; }

"true"                 { yylval.ival = 1; return T_TRUE; }
"false"                { yylval.ival = 0; return T_FALSE; }

"log"                  { return T_LOG; }

"forward"              { return T_FORWARD; }
"turn_left"            { return T_TURN_LEFT; }
"turn_right"           { return T_TURN_RIGHT; }
"stop"                 { return T_STOP; }
"set_speed"            { return T_SET_SPEED; }
"sleep"                { return T_SLEEP; }

"line_left"            { return T_LINE_LEFT; }
"line_right"           { return T_LINE_RIGHT; }
"dist"                 { return T_DIST; }

"&&"                   { return T_AND; }
"||"                   { return T_OR; }
"!"                    { return '!'; }

"==="                  { return T_EQEQ; }
"!="                   { return T_NEQ; }
">="                   { return T_GTE; }
"<="                   { return T_LTE; }
">"                    { return '>'; }
"<"                    { return '<'; }

"+"                    { return '+'; }
"-"                    { return '-'; }
"*"                    { return '*'; }
"/"                    { return '/'; }
"%"                    { return '%'; }

"="                    { return '='; }
";"                    { return ';'; }
","                    { return ','; }
"("                    { return '('; }
")"                    { return ')'; }
"{"                    { return '{'; }
"}"                    { return '}'; }

{DIGIT}+               {
                          yylval.ival = atoi(yytext);
                          return NUMBER;
                       }

{LETTER}{IDCHAR}*      {
                          yylval.sval = strdup(yytext);
                          return IDENT;
                       }

.                      {
                          fprintf(stderr,
                                  "Caracter desconhecido '%s' na linha %d\n",
                                  yytext, yylineno);
                       }

%%
