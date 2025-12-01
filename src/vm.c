/* src/vm.c
 *
 * Interpretador da LINHA-VM (assembly gerado pelo compilador linha).
 * Lê instruções de stdin e simula um robô seguidor de linha.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS   1024
#define NAME_SIZE  64

typedef struct {
    char name[NAME_SIZE];
    int  value;
    int  initialized;
} Var;

static Var vars[MAX_VARS];
static int var_count = 0;

/* Estado do robô */
static int motor_left  = 0;
static int motor_right = 0;
static long time_ms    = 0;  /* tempo lógico acumulado */

/* ==================== TABELA DE VARIÁVEIS (para SET / LOG) ==================== */

static int find_var(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

static void vm_set_var(const char *name, int value) {
    int idx = find_var(name);
    if (idx < 0) {
        if (var_count >= MAX_VARS) {
            fprintf(stderr, "[VM ERRO] Tabela de variáveis cheia.\n");
            exit(1);
        }
        strncpy(vars[var_count].name, name, NAME_SIZE - 1);
        vars[var_count].name[NAME_SIZE - 1] = '\0';
        vars[var_count].value = value;
        vars[var_count].initialized = 1;
        idx = var_count;
        var_count++;
    } else {
        vars[idx].value = value;
        vars[idx].initialized = 1;
    }

    printf("[t=%ld] SET %s = %d\n", time_ms, vars[idx].name, vars[idx].value);
}

static int vm_get_var(const char *name, int *out) {
    int idx = find_var(name);
    if (idx < 0 || !vars[idx].initialized) {
        return 0;
    }
    *out = vars[idx].value;
    return 1;
}

/* ==================== INSTRUÇÕES DA VM ==================== */

static void vm_forward(int v) {
    motor_left  = v;
    motor_right = v;
    printf("[t=%ld] FORWARD %d -> L=%d R=%d\n",
           time_ms, v, motor_left, motor_right);
}

static void vm_turn_left(int intensity) {
    /* gira para a esquerda: diminui L, aumenta R */
    motor_left  -= intensity;
    motor_right += intensity;
    printf("[t=%ld] TURN_LEFT %d -> L=%d R=%d\n",
           time_ms, intensity, motor_left, motor_right);
}

static void vm_turn_right(int intensity) {
    /* gira para a direita: diminui R, aumenta L */
    motor_left  += intensity;
    motor_right -= intensity;
    printf("[t=%ld] TURN_RIGHT %d -> L=%d R=%d\n",
           time_ms, intensity, motor_left, motor_right);
}

static void vm_stop(void) {
    motor_left  = 0;
    motor_right = 0;
    printf("[t=%ld] STOP -> L=%d R=%d\n", time_ms, motor_left, motor_right);
}

static void vm_set_speed(int vl, int vr) {
    motor_left  = vl;
    motor_right = vr;
    printf("[t=%ld] SET_SPEED %d %d -> L=%d R=%d\n",
           time_ms, vl, vr, motor_left, motor_right);
}

static void vm_sleep(int ms) {
    /* avança tempo lógico */
    printf("[t=%ld] SLEEP %d\n", time_ms, ms);
    time_ms += ms;
}

static void vm_log(int value) {
    printf("[t=%ld] LOG %d\n", time_ms, value);
}

/* ==================== LOOP PRINCIPAL DA VM ==================== */

int main(void) {
    char line[256];

    fprintf(stderr, "[VM] Iniciando interpretador LINHA-VM...\n");

    while (fgets(line, sizeof(line), stdin)) {
        /* Ignora linhas em branco e que começam com comentário (# ou //) */
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0' || *p == '\n') continue;
        if (*p == '#') continue;
        if (p[0] == '/' && p[1] == '/') continue;

        /* IMPORTANTE: primeiro checamos instruções mais específicas,
           depois as genéricas (como SET). */

        /* SET_SPEED a b */
        {
            int vl, vr;
            if (sscanf(p, "SET_SPEED %d %d", &vl, &vr) == 2) {
                vm_set_speed(vl, vr);
                continue;
            }
        }

        /* FORWARD v */
        {
            int v;
            if (sscanf(p, "FORWARD %d", &v) == 1) {
                vm_forward(v);
                continue;
            }
        }

        /* TURN_LEFT v */
        {
            int v;
            if (sscanf(p, "TURN_LEFT %d", &v) == 1) {
                vm_turn_left(v);
                continue;
            }
        }

        /* TURN_RIGHT v */
        {
            int v;
            if (sscanf(p, "TURN_RIGHT %d", &v) == 1) {
                vm_turn_right(v);
                continue;
            }
        }

        /* STOP (sem argumentos) */
        {
            int dummy;
            if (sscanf(p, "STOP %d", &dummy) == 1) {
                /* não é STOP puro, deixa passar pra frente */
            } else if (strncmp(p, "STOP", 4) == 0) {
                vm_stop();
                continue;
            }
        }

        /* SLEEP ms */
        {
            int ms;
            if (sscanf(p, "SLEEP %d", &ms) == 1) {
                vm_sleep(ms);
                continue;
            }
        }

        /* LOG v */
        {
            int v;
            if (sscanf(p, "LOG %d", &v) == 1) {
                vm_log(v);
                continue;
            }
        }

        /* SET nome valor  -> DEPOIS das outras, e com espaço obrigatório */
        {
            char name[NAME_SIZE];
            int value;
            if (sscanf(p, "SET %63s %d", name, &value) == 2) {
                vm_set_var(name, value);
                continue;
            }
        }

        /* Se chegou aqui, não reconheceu a linha */
        fprintf(stderr, "[VM AVISO] Instrução desconhecida ou mal-formada: %s", line);
    }

    fprintf(stderr, "[VM] Fim da execução. Tempo total = %ld ms, L=%d, R=%d\n",
            time_ms, motor_left, motor_right);

    return 0;
}
