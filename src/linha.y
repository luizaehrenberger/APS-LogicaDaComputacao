/* src/linha.y */
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  void yyerror(const char *s);
  int yylex(void);
  extern int yylineno;

  /* ================= TABELA DE VARIÁVEIS (SÍMBOLOS) ================= */

  typedef struct {
    char *name;
    int  value;
    int  initialized;
  } Var;

  #define MAX_VARS 1024

  static Var symtab[MAX_VARS];
  static int symcount = 0;

  static int find_var(const char *name) {
    for (int i = 0; i < symcount; i++) {
      if (strcmp(symtab[i].name, name) == 0) {
        return i;
      }
    }
    return -1;
  }

  static void set_var(const char *name, int value) {
    int idx = find_var(name);
    if (idx < 0) {
      if (symcount >= MAX_VARS) {
        fprintf(stderr, "Erro: tabela de variáveis cheia.\n");
        exit(1);
      }
      symtab[symcount].name = strdup(name);
      symtab[symcount].value = value;
      symtab[symcount].initialized = 1;
      symcount++;
    } else {
      symtab[idx].value = value;
      symtab[idx].initialized = 1;
    }
  }

  static int get_var(const char *name, int *out) {
    int idx = find_var(name);
    if (idx < 0 || !symtab[idx].initialized) {
      return 0; /* não encontrada ou não inicializada */
    }
    *out = symtab[idx].value;
    return 1;
  }

%}

/* ----- Tipos da união para tokens / não-terminais ----- */
%union {
  int   ival;   /* números inteiros / booleanos */
  char *sval;   /* identificadores */
}

/* ----- Tokens com tipo ----- */
%token <ival> NUMBER
%token <sval> IDENT

/* ----- Palavras-chave / comandos ----- */
%token T_IF T_ELSE T_WHILE
%token T_LOG
%token T_FORWARD T_TURN_LEFT T_TURN_RIGHT T_STOP T_SET_SPEED T_SLEEP
%token T_LINE_LEFT T_LINE_RIGHT T_DIST

/* Booleanos como inteiros (0/1) */
%token <ival> T_TRUE T_FALSE

/* ----- Operadores multi-char ----- */
%token T_AND T_OR
%token T_EQEQ T_NEQ T_GTE T_LTE

/* ----- Precedência (da menor para a maior) ----- */
%left T_OR
%left T_AND
%left T_EQEQ T_NEQ '>' '<' T_GTE T_LTE
%left '+' '-'
%left '*' '/' '%'
%right '!'    /* unário */

/* Não-terminais que carregam int */
%type <ival> expr or_expr and_expr rel_expr add_expr mul_expr un_expr primary sensor_call

%%

program
  : stmts_opt
    {
      /* Mensagem só em stderr para não misturar com o "assembly" da VM */
      fprintf(stderr, "Programa válido.\n");
    }
  ;

stmts_opt
  : /* vazio */
  | stmts
  ;

stmts
  : stmt
  | stmts stmt
  ;

/* =============== STATEMENTS =============== */
/* Usamos matched_stmt / unmatched_stmt para evitar dangling else */

stmt
  : matched_stmt
  | unmatched_stmt
  ;

/* comandos simples (sempre com ;) */
simple_stmt
  : assignment
  | print_stmt
  | drive_stmt
  ;

/* bloco { ... } */
block
  : '{' stmts_opt '}'
  ;

/* if/while já entram aqui com ou sem else */
matched_stmt
  : simple_stmt ';'
  | block
  | T_IF '(' expr ')' matched_stmt T_ELSE matched_stmt
  | T_WHILE '(' expr ')' matched_stmt
  ;

unmatched_stmt
  : T_IF '(' expr ')' stmt
  | T_IF '(' expr ')' matched_stmt T_ELSE unmatched_stmt
  | T_WHILE '(' expr ')' unmatched_stmt
  ;

/* ---------- Atribuição / log ---------- */

assignment
  : IDENT '=' expr
    {
      /* guarda na tabela de variáveis */
      set_var($1, $3);
      /* gera código para a VM */
      printf("SET %s %d\n", $1, $3);
      free($1);
    }
  ;

print_stmt
  : T_LOG '(' expr ')'
    {
      /* Log para a VM */
      printf("LOG %d\n", $3);
    }
  ;

/* ---------- Comandos de direção ---------- */

drive_stmt
  : forward_stmt
  | turn_left_stmt
  | turn_right_stmt
  | stop_stmt
  | set_speed_stmt
  | sleep_stmt
  ;

forward_stmt
  : T_FORWARD '(' expr ')'
    {
      printf("FORWARD %d\n", $3);
    }
  ;

turn_left_stmt
  : T_TURN_LEFT '(' expr ')'
    {
      printf("TURN_LEFT %d\n", $3);
    }
  ;

turn_right_stmt
  : T_TURN_RIGHT '(' expr ')'
    {
      printf("TURN_RIGHT %d\n", $3);
    }
  ;

stop_stmt
  : T_STOP '(' ')'
    {
      printf("STOP\n");
    }
  ;

set_speed_stmt
  : T_SET_SPEED '(' expr ',' expr ')'
    {
      printf("SET_SPEED %d %d\n", $3, $5);
    }
  ;
sleep_stmt
  : T_SLEEP '(' expr ')'
    {
      printf("SLEEP %d\n", $3);
    }
  ;

/* =============== EXPRESSÕES =============== */

expr
  : or_expr                       { $$ = $1; }
  ;

or_expr
  : and_expr                      { $$ = $1; }
  | or_expr T_OR and_expr         { $$ = $1 || $3; }
  ;

and_expr
  : rel_expr                      { $$ = $1; }
  | and_expr T_AND rel_expr       { $$ = $1 && $3; }
  ;

rel_expr
  : add_expr                      { $$ = $1; }
  | rel_expr T_EQEQ add_expr      { $$ = ($1 == $3); }
  | rel_expr T_NEQ  add_expr      { $$ = ($1 != $3); }
  | rel_expr '>'    add_expr      { $$ = ($1 >  $3); }
  | rel_expr '<'    add_expr      { $$ = ($1 <  $3); }
  | rel_expr T_GTE  add_expr      { $$ = ($1 >= $3); }
  | rel_expr T_LTE  add_expr      { $$ = ($1 <= $3); }
  ;

add_expr
  : mul_expr                      { $$ = $1; }
  | add_expr '+' mul_expr         { $$ = $1 + $3; }
  | add_expr '-' mul_expr         { $$ = $1 - $3; }
  ;

mul_expr
  : un_expr                       { $$ = $1; }
  | mul_expr '*' un_expr          { $$ = $1 * $3; }
  | mul_expr '/' un_expr          { $$ = $1 / $3; }
  | mul_expr '%' un_expr          { $$ = $1 % $3; }
  ;

un_expr
  : primary                       { $$ = $1; }
  | '+' un_expr                   { $$ = +$2; }
  | '-' un_expr                   { $$ = -$2; }
  | '!' un_expr                   { $$ = !$2; }
  ;

primary
  : NUMBER                        { $$ = $1; }
  | IDENT
    {
      int v;
      if (!get_var($1, &v)) {
        fprintf(stderr,
                "Aviso: variável '%s' usada sem inicializar (linha %d). Assumindo 0.\n",
                $1, yylineno);
        v = 0;
      }
      free($1);
      $$ = v;
    }
  | sensor_call                   { $$ = $1; }
  | T_TRUE                        { $$ = 1; }
  | T_FALSE                       { $$ = 0; }
  | '(' expr ')'                  { $$ = $2; }
  ;

/* Sensores retornam int (placeholder 0 por enquanto) */
sensor_call
  : T_LINE_LEFT '(' ')'           { $$ = 0; }
  | T_LINE_RIGHT '(' ')'          { $$ = 0; }
  | T_DIST '(' ')'                { $$ = 0; }
  ;

%%

void yyerror(const char *s) {
  fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}
