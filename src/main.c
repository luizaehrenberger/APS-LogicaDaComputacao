/* src/main.c */
#include <stdio.h>

int yyparse(void);
extern int yylineno;

int main(void) {
    int ret = yyparse();
    if (ret == 0) {
        /* sucesso: o próprio parser já imprime
           "Programa válido." em stderr
           e o "assembly" da VM em stdout */
        return 0;
    } else {
        fprintf(stderr, "Falha na análise.\n");
        return 1;
    }
}
