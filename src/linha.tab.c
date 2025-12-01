/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "linha.y"

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


#line 130 "linha.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "linha.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_T_IF = 5,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 6,                     /* T_ELSE  */
  YYSYMBOL_T_WHILE = 7,                    /* T_WHILE  */
  YYSYMBOL_T_LOG = 8,                      /* T_LOG  */
  YYSYMBOL_T_FORWARD = 9,                  /* T_FORWARD  */
  YYSYMBOL_T_TURN_LEFT = 10,               /* T_TURN_LEFT  */
  YYSYMBOL_T_TURN_RIGHT = 11,              /* T_TURN_RIGHT  */
  YYSYMBOL_T_STOP = 12,                    /* T_STOP  */
  YYSYMBOL_T_SET_SPEED = 13,               /* T_SET_SPEED  */
  YYSYMBOL_T_SLEEP = 14,                   /* T_SLEEP  */
  YYSYMBOL_T_LINE_LEFT = 15,               /* T_LINE_LEFT  */
  YYSYMBOL_T_LINE_RIGHT = 16,              /* T_LINE_RIGHT  */
  YYSYMBOL_T_DIST = 17,                    /* T_DIST  */
  YYSYMBOL_T_TRUE = 18,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 19,                   /* T_FALSE  */
  YYSYMBOL_T_AND = 20,                     /* T_AND  */
  YYSYMBOL_T_OR = 21,                      /* T_OR  */
  YYSYMBOL_T_EQEQ = 22,                    /* T_EQEQ  */
  YYSYMBOL_T_NEQ = 23,                     /* T_NEQ  */
  YYSYMBOL_T_GTE = 24,                     /* T_GTE  */
  YYSYMBOL_T_LTE = 25,                     /* T_LTE  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '!'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_stmts_opt = 43,                 /* stmts_opt  */
  YYSYMBOL_stmts = 44,                     /* stmts  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_simple_stmt = 46,               /* simple_stmt  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_matched_stmt = 48,              /* matched_stmt  */
  YYSYMBOL_unmatched_stmt = 49,            /* unmatched_stmt  */
  YYSYMBOL_assignment = 50,                /* assignment  */
  YYSYMBOL_print_stmt = 51,                /* print_stmt  */
  YYSYMBOL_drive_stmt = 52,                /* drive_stmt  */
  YYSYMBOL_forward_stmt = 53,              /* forward_stmt  */
  YYSYMBOL_turn_left_stmt = 54,            /* turn_left_stmt  */
  YYSYMBOL_turn_right_stmt = 55,           /* turn_right_stmt  */
  YYSYMBOL_stop_stmt = 56,                 /* stop_stmt  */
  YYSYMBOL_set_speed_stmt = 57,            /* set_speed_stmt  */
  YYSYMBOL_sleep_stmt = 58,                /* sleep_stmt  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_or_expr = 60,                   /* or_expr  */
  YYSYMBOL_and_expr = 61,                  /* and_expr  */
  YYSYMBOL_rel_expr = 62,                  /* rel_expr  */
  YYSYMBOL_add_expr = 63,                  /* add_expr  */
  YYSYMBOL_mul_expr = 64,                  /* mul_expr  */
  YYSYMBOL_un_expr = 65,                   /* un_expr  */
  YYSYMBOL_primary = 66,                   /* primary  */
  YYSYMBOL_sensor_call = 67                /* sensor_call  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    32,     2,     2,
      37,    38,    30,    28,    40,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      27,    39,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   106,   107,   111,   112,   119,   120,   125,
     126,   127,   132,   137,   138,   139,   140,   144,   145,   146,
     152,   163,   173,   174,   175,   176,   177,   178,   182,   189,
     196,   203,   210,   216,   225,   229,   230,   234,   235,   239,
     240,   241,   242,   243,   244,   245,   249,   250,   251,   255,
     256,   257,   258,   262,   263,   264,   265,   269,   270,   282,
     283,   284,   285,   290,   291,   292
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENT",
  "T_IF", "T_ELSE", "T_WHILE", "T_LOG", "T_FORWARD", "T_TURN_LEFT",
  "T_TURN_RIGHT", "T_STOP", "T_SET_SPEED", "T_SLEEP", "T_LINE_LEFT",
  "T_LINE_RIGHT", "T_DIST", "T_TRUE", "T_FALSE", "T_AND", "T_OR", "T_EQEQ",
  "T_NEQ", "T_GTE", "T_LTE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'{'", "'}'", "';'", "'('", "')'", "'='", "','", "$accept",
  "program", "stmts_opt", "stmts", "stmt", "simple_stmt", "block",
  "matched_stmt", "unmatched_stmt", "assignment", "print_stmt",
  "drive_stmt", "forward_stmt", "turn_left_stmt", "turn_right_stmt",
  "stop_stmt", "set_speed_stmt", "sleep_stmt", "expr", "or_expr",
  "and_expr", "rel_expr", "add_expr", "mul_expr", "un_expr", "primary",
  "sensor_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,   -16,     0,     5,     7,     9,    11,    18,    32,    35,
      36,    49,    71,   -88,    49,   -88,    13,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    10,
      10,    10,    10,    10,    10,    10,    37,    10,    10,    39,
     -88,   -88,   -88,   -88,   -88,    40,    41,    43,   -88,   -88,
      10,    10,    10,    10,   -88,    55,    61,    -5,    12,    34,
     -88,   -88,   -88,    44,    46,    47,    48,    50,    51,   -88,
      52,    53,   -88,    56,    57,    58,   -88,   -88,   -88,    59,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    49,    49,   -88,   -88,   -88,   -88,    10,
     -88,   -88,   -88,   -88,   -88,    61,    -5,    12,    12,    12,
      12,    12,    12,    34,    34,   -88,   -88,   -88,   -88,    81,
     -88,   -88,    60,    49,   -88,   -88,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     2,     4,     5,     0,    14,     7,     8,
       9,    10,    11,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     6,    13,    57,    58,     0,     0,     0,    60,    61,
       0,     0,     0,     0,    20,    34,    35,    37,    39,    46,
      49,    53,    59,     0,     0,     0,     0,     0,     0,    31,
       0,     0,    12,     0,     0,     0,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    28,    29,    30,     0,
      33,    63,    64,    65,    62,    36,    38,    40,    41,    44,
      45,    42,    43,    47,    48,    50,    51,    52,    17,     7,
      16,    19,     0,     0,    32,    15,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    79,   -88,   -14,   -88,   -88,   -78,   -87,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -29,   -88,
      19,    20,   -52,   -21,   -40,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    54,    55,
      56,    57,    58,    59,    60,    61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      41,    63,    64,    65,    66,    67,    68,   121,    70,    71,
      76,    77,    78,    43,    44,   119,   120,    82,    83,    84,
      85,    86,    87,    29,    79,    45,    46,    47,    48,    49,
     107,   108,   109,   110,   111,   112,   126,    30,    50,    51,
      88,    89,    31,    52,    32,   125,    33,    53,    34,    42,
     115,   116,   117,     1,     2,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    90,    91,    92,   113,   114,    36,
     122,    40,    37,    38,    72,    69,    80,    73,    74,   118,
      75,    81,    93,    11,    94,    95,    96,   123,    97,    98,
      39,   100,    99,     0,   101,   102,   103,   104,   124,   105,
       0,   106
};

static const yytype_int8 yycheck[] =
{
      14,    30,    31,    32,    33,    34,    35,    94,    37,    38,
      50,    51,    52,     3,     4,    93,    94,    22,    23,    24,
      25,    26,    27,    39,    53,    15,    16,    17,    18,    19,
      82,    83,    84,    85,    86,    87,   123,    37,    28,    29,
      28,    29,    37,    33,    37,   123,    37,    37,    37,    36,
      90,    91,    92,     4,     5,    37,     7,     8,     9,    10,
      11,    12,    13,    14,    30,    31,    32,    88,    89,    37,
      99,     0,    37,    37,    35,    38,    21,    37,    37,    93,
      37,    20,    38,    34,    38,    38,    38,     6,    38,    38,
      11,    38,    40,    -1,    38,    38,    38,    38,    38,    80,
      -1,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,     8,     9,    10,    11,    12,    13,
      14,    34,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    39,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    43,
       0,    45,    36,     3,     4,    15,    16,    17,    18,    19,
      28,    29,    33,    37,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    59,    59,    59,    59,    59,    59,    38,
      59,    59,    35,    37,    37,    37,    65,    65,    65,    59,
      21,    20,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    38,    38,    38,    38,    38,    38,    40,
      38,    38,    38,    38,    38,    61,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    65,    45,    48,
      48,    49,    59,     6,    38,    48,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    46,    47,    48,    48,    48,    48,    49,    49,    49,
      50,    51,    52,    52,    52,    52,    52,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     2,     1,     7,     5,     5,     7,     5,
       3,     4,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     3,     6,     4,     1,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: stmts_opt  */
#line 99 "linha.y"
    {
      /* Mensagem só em stderr para não misturar com o "assembly" da VM */
      fprintf(stderr, "Programa válido.\n");
    }
#line 1264 "linha.tab.c"
    break;

  case 20: /* assignment: IDENT '=' expr  */
#line 153 "linha.y"
    {
      /* guarda na tabela de variáveis */
      set_var((yyvsp[-2].sval), (yyvsp[0].ival));
      /* gera código para a VM */
      printf("SET %s %d\n", (yyvsp[-2].sval), (yyvsp[0].ival));
      free((yyvsp[-2].sval));
    }
#line 1276 "linha.tab.c"
    break;

  case 21: /* print_stmt: T_LOG '(' expr ')'  */
#line 164 "linha.y"
    {
      /* Log para a VM */
      printf("LOG %d\n", (yyvsp[-1].ival));
    }
#line 1285 "linha.tab.c"
    break;

  case 28: /* forward_stmt: T_FORWARD '(' expr ')'  */
#line 183 "linha.y"
    {
      printf("FORWARD %d\n", (yyvsp[-1].ival));
    }
#line 1293 "linha.tab.c"
    break;

  case 29: /* turn_left_stmt: T_TURN_LEFT '(' expr ')'  */
#line 190 "linha.y"
    {
      printf("TURN_LEFT %d\n", (yyvsp[-1].ival));
    }
#line 1301 "linha.tab.c"
    break;

  case 30: /* turn_right_stmt: T_TURN_RIGHT '(' expr ')'  */
#line 197 "linha.y"
    {
      printf("TURN_RIGHT %d\n", (yyvsp[-1].ival));
    }
#line 1309 "linha.tab.c"
    break;

  case 31: /* stop_stmt: T_STOP '(' ')'  */
#line 204 "linha.y"
    {
      printf("STOP\n");
    }
#line 1317 "linha.tab.c"
    break;

  case 32: /* set_speed_stmt: T_SET_SPEED '(' expr ',' expr ')'  */
#line 211 "linha.y"
    {
      printf("SET_SPEED %d %d\n", (yyvsp[-3].ival), (yyvsp[-1].ival));
    }
#line 1325 "linha.tab.c"
    break;

  case 33: /* sleep_stmt: T_SLEEP '(' expr ')'  */
#line 217 "linha.y"
    {
      printf("SLEEP %d\n", (yyvsp[-1].ival));
    }
#line 1333 "linha.tab.c"
    break;

  case 34: /* expr: or_expr  */
#line 225 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1339 "linha.tab.c"
    break;

  case 35: /* or_expr: and_expr  */
#line 229 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1345 "linha.tab.c"
    break;

  case 36: /* or_expr: or_expr T_OR and_expr  */
#line 230 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) || (yyvsp[0].ival); }
#line 1351 "linha.tab.c"
    break;

  case 37: /* and_expr: rel_expr  */
#line 234 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1357 "linha.tab.c"
    break;

  case 38: /* and_expr: and_expr T_AND rel_expr  */
#line 235 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) && (yyvsp[0].ival); }
#line 1363 "linha.tab.c"
    break;

  case 39: /* rel_expr: add_expr  */
#line 239 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1369 "linha.tab.c"
    break;

  case 40: /* rel_expr: rel_expr T_EQEQ add_expr  */
#line 240 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) == (yyvsp[0].ival)); }
#line 1375 "linha.tab.c"
    break;

  case 41: /* rel_expr: rel_expr T_NEQ add_expr  */
#line 241 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) != (yyvsp[0].ival)); }
#line 1381 "linha.tab.c"
    break;

  case 42: /* rel_expr: rel_expr '>' add_expr  */
#line 242 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) >  (yyvsp[0].ival)); }
#line 1387 "linha.tab.c"
    break;

  case 43: /* rel_expr: rel_expr '<' add_expr  */
#line 243 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) <  (yyvsp[0].ival)); }
#line 1393 "linha.tab.c"
    break;

  case 44: /* rel_expr: rel_expr T_GTE add_expr  */
#line 244 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) >= (yyvsp[0].ival)); }
#line 1399 "linha.tab.c"
    break;

  case 45: /* rel_expr: rel_expr T_LTE add_expr  */
#line 245 "linha.y"
                                  { (yyval.ival) = ((yyvsp[-2].ival) <= (yyvsp[0].ival)); }
#line 1405 "linha.tab.c"
    break;

  case 46: /* add_expr: mul_expr  */
#line 249 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1411 "linha.tab.c"
    break;

  case 47: /* add_expr: add_expr '+' mul_expr  */
#line 250 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1417 "linha.tab.c"
    break;

  case 48: /* add_expr: add_expr '-' mul_expr  */
#line 251 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1423 "linha.tab.c"
    break;

  case 49: /* mul_expr: un_expr  */
#line 255 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1429 "linha.tab.c"
    break;

  case 50: /* mul_expr: mul_expr '*' un_expr  */
#line 256 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1435 "linha.tab.c"
    break;

  case 51: /* mul_expr: mul_expr '/' un_expr  */
#line 257 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
#line 1441 "linha.tab.c"
    break;

  case 52: /* mul_expr: mul_expr '%' un_expr  */
#line 258 "linha.y"
                                  { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); }
#line 1447 "linha.tab.c"
    break;

  case 53: /* un_expr: primary  */
#line 262 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1453 "linha.tab.c"
    break;

  case 54: /* un_expr: '+' un_expr  */
#line 263 "linha.y"
                                  { (yyval.ival) = +(yyvsp[0].ival); }
#line 1459 "linha.tab.c"
    break;

  case 55: /* un_expr: '-' un_expr  */
#line 264 "linha.y"
                                  { (yyval.ival) = -(yyvsp[0].ival); }
#line 1465 "linha.tab.c"
    break;

  case 56: /* un_expr: '!' un_expr  */
#line 265 "linha.y"
                                  { (yyval.ival) = !(yyvsp[0].ival); }
#line 1471 "linha.tab.c"
    break;

  case 57: /* primary: NUMBER  */
#line 269 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1477 "linha.tab.c"
    break;

  case 58: /* primary: IDENT  */
#line 271 "linha.y"
    {
      int v;
      if (!get_var((yyvsp[0].sval), &v)) {
        fprintf(stderr,
                "Aviso: variável '%s' usada sem inicializar (linha %d). Assumindo 0.\n",
                (yyvsp[0].sval), yylineno);
        v = 0;
      }
      free((yyvsp[0].sval));
      (yyval.ival) = v;
    }
#line 1493 "linha.tab.c"
    break;

  case 59: /* primary: sensor_call  */
#line 282 "linha.y"
                                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1499 "linha.tab.c"
    break;

  case 60: /* primary: T_TRUE  */
#line 283 "linha.y"
                                  { (yyval.ival) = 1; }
#line 1505 "linha.tab.c"
    break;

  case 61: /* primary: T_FALSE  */
#line 284 "linha.y"
                                  { (yyval.ival) = 0; }
#line 1511 "linha.tab.c"
    break;

  case 62: /* primary: '(' expr ')'  */
#line 285 "linha.y"
                                  { (yyval.ival) = (yyvsp[-1].ival); }
#line 1517 "linha.tab.c"
    break;

  case 63: /* sensor_call: T_LINE_LEFT '(' ')'  */
#line 290 "linha.y"
                                  { (yyval.ival) = 0; }
#line 1523 "linha.tab.c"
    break;

  case 64: /* sensor_call: T_LINE_RIGHT '(' ')'  */
#line 291 "linha.y"
                                  { (yyval.ival) = 0; }
#line 1529 "linha.tab.c"
    break;

  case 65: /* sensor_call: T_DIST '(' ')'  */
#line 292 "linha.y"
                                  { (yyval.ival) = 0; }
#line 1535 "linha.tab.c"
    break;


#line 1539 "linha.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 295 "linha.y"


void yyerror(const char *s) {
  fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}
