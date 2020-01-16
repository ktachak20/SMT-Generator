/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "smtlib.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXVARS 100
#define YYDEBUG 1

#define NT_EXP_ARR  257
#define NT_PST_EXP  258
#define NT_UN_EXP   259
#define NT_ASSN_EXP 260
#define NT_ASSRT    261
#define NT_EXP      262
#define NT_CONJ     263
#define NT_IMPL     264

#define NODE_free(n) \
    free((n)->body); free(n);

typedef struct _DATA_expr_t { char *body; int type; } DATA_expr_t;

char        *ofile;
char        *vfile;
char        *x;
char        *VR_vdec;              /* pointer to string of variable declarations. */
extern int  yyparse();
extern FILE *yyin;
int         varcount = 0;
DATA_expr_t varlist[MAXVARS]; /* variable names and associated type */
int         vardef( void );
int         varcheck( DATA_expr_t * );
char*       FN_mk_vdecl(char *, char *);
DATA_expr_t *FN_mk_node( char *, int );
void        FN_write_node_to_file( DATA_expr_t *, char *);
DATA_expr_t *FN_gen_assert( DATA_expr_t *stmt );
DATA_expr_t *FN_gen_impl( DATA_expr_t *ncond, DATA_expr_t *nbranch1, DATA_expr_t *nbranch2 );
DATA_expr_t *FN_gen_conjunc( DATA_expr_t *nstart, DATA_expr_t *nend );
DATA_expr_t *FN_gen_exp( DATA_expr_t *nleft, DATA_expr_t *nright, int op_t );
DATA_expr_t *FN_gen_exp_unary( DATA_expr_t *, int );

#line 112 "smtlib.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SMTLIB_TAB_H_INCLUDED
# define YY_YY_SMTLIB_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 49 "smtlib.y"

    typedef struct _DATA_expr_t DATA_expr_t;

#line 150 "smtlib.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MU_OP = 258,
    TK_DI_OP = 259,
    TK_MO_OP = 260,
    TK_NOT_OP = 261,
    TK_AND_OP = 262,
    TK_OR_OP = 263,
    TK_LT_OP = 264,
    TK_IMP_OP = 265,
    TK_GT_OP = 266,
    TK_ID = 267,
    TK_CT = 268,
    TK_CMM = 269,
    TK_LB = 270,
    TK_LP = 271,
    TK_RB = 272,
    TK_LE_OP = 273,
    TK_GE_OP = 274,
    TK_EQ_OP = 275,
    TK_IF = 276,
    TK_ELSE = 277,
    TK_ST_END = 278,
    TK_LSQB = 279,
    TK_RSQB = 280,
    TK_RP = 281,
    TK_PL_OP = 282,
    TK_MI_OP = 283,
    TK_NE_OP = 284,
    TK_ASS_OP = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "smtlib.y"

  int         TK_simple_t;
  char        *TK_literal_t;
  char        *TK_identifier_t;
  DATA_expr_t *NT_exp_t;

#line 199 "smtlib.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SMTLIB_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  72

#define YYUNDEFTOK  2
#define YYMAXUTOK   285

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   132,   137,   139,   157,   162,   164,   169,
     170,   171,   172,   173,   177,   179,   184,   194,   199,   200,
     201,   202,   203,   204,   205,   209,   213,   214,   215,   216,
     219,   221,   223,   225,   229,   232,   233,   236,   237,   238,
     239,   242,   243,   244,   247,   249,   253,   254,   261,   262,
     271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MU_OP", "TK_DI_OP", "TK_MO_OP",
  "TK_NOT_OP", "TK_AND_OP", "TK_OR_OP", "TK_LT_OP", "TK_IMP_OP",
  "TK_GT_OP", "TK_ID", "TK_CT", "TK_CMM", "TK_LB", "TK_LP", "TK_RB",
  "TK_LE_OP", "TK_GE_OP", "TK_EQ_OP", "TK_IF", "TK_ELSE", "TK_ST_END",
  "TK_LSQB", "TK_RSQB", "TK_RP", "TK_PL_OP", "TK_MI_OP", "TK_NE_OP",
  "TK_ASS_OP", "$accept", "primary_expression", "postfix_expression",
  "unary_operator", "unary_expression", "operator", "expression",
  "assignment_expression", "relational_operator",
  "primary_conditional_expression", "logical_operator",
  "conditional_expression", "assignment_statement", "assignments",
  "mixed_statements", "innerblock", "decision", "assertions", "smtlib", YY_NULLPTR
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
     285
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      94,   -57,   -57,    98,    60,   -57,   -57,   -16,    -3,   -14,
     -10,    94,    94,   -57,    19,    14,    60,    60,   -57,    50,
     -57,    74,    -3,   -57,    -3,   -57,   -57,   -57,   -57,   -57,
     -57,   110,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    -3,    -3,   -57,   -57,   -57,    94,
     -57,    60,   -57,    11,   -57,    35,    23,   -57,    23,    23,
      98,    94,    10,    94,    27,    84,   -57,   -57,   -57,   -57,
     -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     3,     0,     0,     6,     4,     7,     0,     0,
       0,    46,    48,    50,     0,     0,     0,     0,    14,     0,
      30,     0,     0,     8,     0,    34,    47,    49,     1,    17,
      31,     0,    11,    12,    13,    18,    19,    20,    21,    22,
       9,    10,    23,    24,     0,     0,    26,    27,    28,     0,
      29,     0,    41,    44,    42,     0,    16,    33,    15,    25,
      35,    37,     0,    38,    32,     0,     5,    36,    39,    43,
      40,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,    -2,   -57,   -21,    38,   -57,   -57,
     -57,     1,     0,   -15,   -56,    -9,   -17,    18,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    44,    19,    10,    45,    20,
      51,    21,    60,    61,    62,    53,    12,    13,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    55,    18,    56,    54,    68,    23,    70,    22,     1,
       2,    11,    11,    25,    18,    18,    24,    30,    31,    28,
      18,    52,    18,    58,    59,     5,    32,    33,    34,    26,
      27,    29,    63,    65,    46,    47,    69,    48,    32,    33,
      34,    15,    18,    18,    63,    67,    63,    50,    54,    18,
      40,    41,    64,    32,    33,    34,    71,     0,     0,    35,
      66,    36,    40,    41,     0,    52,    16,     0,    37,    38,
      39,     0,     1,     2,     0,    17,     0,    40,    41,    42,
      43,    46,    47,     0,    48,     0,     1,     2,     5,     3,
      49,     0,     0,     0,    50,     4,     1,     2,     0,     3,
      49,     0,     5,     0,     0,     4,     1,     2,     0,     3,
       1,     2,     5,     3,     0,     4,     0,    46,    47,     0,
      48,     0,     5,     0,     0,     0,     5,    57,     0,     0,
      50
};

static const yytype_int8 yycheck[] =
{
       0,    22,     4,    24,    21,    61,     8,    63,    24,    12,
      13,    11,    12,    23,    16,    17,    30,    16,    17,     0,
      22,    21,    24,    44,    45,    28,     3,     4,     5,    11,
      12,    17,    49,    22,     7,     8,    26,    10,     3,     4,
       5,     3,    44,    45,    61,    60,    63,    20,    65,    51,
      27,    28,    51,     3,     4,     5,    65,    -1,    -1,     9,
      25,    11,    27,    28,    -1,    65,     6,    -1,    18,    19,
      20,    -1,    12,    13,    -1,    15,    -1,    27,    28,    29,
      30,     7,     8,    -1,    10,    -1,    12,    13,    28,    15,
      16,    -1,    -1,    -1,    20,    21,    12,    13,    -1,    15,
      16,    -1,    28,    -1,    -1,    21,    12,    13,    -1,    15,
      12,    13,    28,    15,    -1,    21,    -1,     7,     8,    -1,
      10,    -1,    28,    -1,    -1,    -1,    28,    17,    -1,    -1,
      20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    15,    21,    28,    32,    33,    34,    35,
      38,    43,    47,    48,    49,    38,     6,    15,    35,    37,
      40,    42,    24,    35,    30,    23,    48,    48,     0,    17,
      42,    42,     3,     4,     5,     9,    11,    18,    19,    20,
      27,    28,    29,    30,    36,    39,     7,     8,    10,    16,
      20,    41,    43,    46,    47,    37,    37,    17,    37,    37,
      43,    44,    45,    47,    42,    22,    25,    44,    45,    26,
      45,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    35,    35,    36,
      36,    36,    36,    36,    37,    37,    38,    38,    39,    39,
      39,    39,    39,    39,    39,    40,    41,    41,    41,    41,
      42,    42,    42,    42,    43,    44,    44,    45,    45,    45,
      45,    46,    46,    46,    47,    47,    48,    48,    48,    48,
      49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     1,     2,     1,     1,     2,
       2,     1,     1,     3,     3,     5,     1,     2,     1,     2,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  case 2:
#line 131 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node((yyvsp[0].TK_identifier_t), TK_ID); }
#line 1361 "smtlib.tab.c"
    break;

  case 3:
#line 133 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node((yyvsp[0].TK_literal_t), TK_CT); }
#line 1367 "smtlib.tab.c"
    break;

  case 4:
#line 138 "smtlib.y"
    { varcheck((yyvsp[0].NT_exp_t)); (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1373 "smtlib.tab.c"
    break;

  case 5:
#line 140 "smtlib.y"
    { 
      char *tmp;

      if( (yyvsp[-3].NT_exp_t)->type == TK_ID )
      {
        /* Check variable is already defined and set. */
        varcheck((yyvsp[-3].NT_exp_t));
      }

      asprintf(&tmp, "(select %s %s)", (yyvsp[-3].NT_exp_t)->body, (yyvsp[-1].NT_exp_t)->body);
      (yyval.NT_exp_t) = FN_mk_node(tmp, NT_PST_EXP);
      free((yyvsp[-3].NT_exp_t)->body); free((yyvsp[-1].NT_exp_t)->body);
      free((yyvsp[-3].NT_exp_t)); free((yyvsp[-1].NT_exp_t));
    }
#line 1392 "smtlib.tab.c"
    break;

  case 6:
#line 158 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("-", TK_MI_OP); }
#line 1398 "smtlib.tab.c"
    break;

  case 7:
#line 163 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1404 "smtlib.tab.c"
    break;

  case 8:
#line 165 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_exp_unary((yyvsp[0].NT_exp_t), (yyvsp[-1].NT_exp_t)->type); NODE_free((yyvsp[-1].NT_exp_t)); }
#line 1410 "smtlib.tab.c"
    break;

  case 9:
#line 169 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("+", TK_PL_OP); }
#line 1416 "smtlib.tab.c"
    break;

  case 10:
#line 170 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("-", TK_MI_OP); }
#line 1422 "smtlib.tab.c"
    break;

  case 11:
#line 171 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("*", TK_MU_OP); }
#line 1428 "smtlib.tab.c"
    break;

  case 12:
#line 172 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("div", TK_DI_OP); }
#line 1434 "smtlib.tab.c"
    break;

  case 13:
#line 173 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("mod", TK_MO_OP); }
#line 1440 "smtlib.tab.c"
    break;

  case 14:
#line 178 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1446 "smtlib.tab.c"
    break;

  case 15:
#line 180 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_exp((yyvsp[-2].NT_exp_t), (yyvsp[0].NT_exp_t), (yyvsp[-1].NT_exp_t)->type); }
#line 1452 "smtlib.tab.c"
    break;

  case 16:
#line 185 "smtlib.y"
    {
        char *exp;

        asprintf(&exp, "(= %s %s)", (yyvsp[-2].NT_exp_t)->body, (yyvsp[0].NT_exp_t)->body);
        (yyval.NT_exp_t) = FN_mk_node(exp, NT_ASSN_EXP);

        free((yyvsp[-2].NT_exp_t)->body); free((yyvsp[-2].NT_exp_t));
        free((yyvsp[0].NT_exp_t)->body); free((yyvsp[0].NT_exp_t)); /* replace with a macro */
    }
#line 1466 "smtlib.tab.c"
    break;

  case 17:
#line 195 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1472 "smtlib.tab.c"
    break;

  case 18:
#line 199 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("<", TK_LT_OP); }
#line 1478 "smtlib.tab.c"
    break;

  case 19:
#line 200 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node(">", TK_GT_OP); }
#line 1484 "smtlib.tab.c"
    break;

  case 20:
#line 201 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("<=", TK_LE_OP); }
#line 1490 "smtlib.tab.c"
    break;

  case 21:
#line 202 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node(">=", TK_GE_OP); }
#line 1496 "smtlib.tab.c"
    break;

  case 22:
#line 203 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("=", TK_GE_OP); }
#line 1502 "smtlib.tab.c"
    break;

  case 23:
#line 204 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("neq", TK_NE_OP); }
#line 1508 "smtlib.tab.c"
    break;

  case 24:
#line 205 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("=", TK_NE_OP); }
#line 1514 "smtlib.tab.c"
    break;

  case 25:
#line 210 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_exp((yyvsp[-2].NT_exp_t), (yyvsp[0].NT_exp_t), (yyvsp[-1].NT_exp_t)->type); NODE_free((yyvsp[-1].NT_exp_t)); }
#line 1520 "smtlib.tab.c"
    break;

  case 26:
#line 213 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("and", TK_AND_OP); }
#line 1526 "smtlib.tab.c"
    break;

  case 27:
#line 214 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("or", TK_OR_OP); }
#line 1532 "smtlib.tab.c"
    break;

  case 28:
#line 215 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("=>", TK_IMP_OP); }
#line 1538 "smtlib.tab.c"
    break;

  case 29:
#line 216 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node("=", TK_EQ_OP); }
#line 1544 "smtlib.tab.c"
    break;

  case 30:
#line 220 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1550 "smtlib.tab.c"
    break;

  case 31:
#line 222 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_exp_unary((yyvsp[0].NT_exp_t), TK_NOT_OP); }
#line 1556 "smtlib.tab.c"
    break;

  case 32:
#line 224 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_exp((yyvsp[-2].NT_exp_t), (yyvsp[0].NT_exp_t), (yyvsp[-1].NT_exp_t)->type); NODE_free((yyvsp[-1].NT_exp_t)); }
#line 1562 "smtlib.tab.c"
    break;

  case 33:
#line 226 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1568 "smtlib.tab.c"
    break;

  case 34:
#line 229 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1574 "smtlib.tab.c"
    break;

  case 35:
#line 232 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1580 "smtlib.tab.c"
    break;

  case 36:
#line 233 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_conjunc((yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t)); }
#line 1586 "smtlib.tab.c"
    break;

  case 37:
#line 236 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1592 "smtlib.tab.c"
    break;

  case 38:
#line 237 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1598 "smtlib.tab.c"
    break;

  case 39:
#line 238 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_conjunc((yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t)); }
#line 1604 "smtlib.tab.c"
    break;

  case 40:
#line 239 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_conjunc((yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t)); }
#line 1610 "smtlib.tab.c"
    break;

  case 41:
#line 242 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1616 "smtlib.tab.c"
    break;

  case 42:
#line 243 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1622 "smtlib.tab.c"
    break;

  case 43:
#line 244 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1628 "smtlib.tab.c"
    break;

  case 44:
#line 248 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_impl((yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t), NULL); }
#line 1634 "smtlib.tab.c"
    break;

  case 45:
#line 250 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_impl((yyvsp[-3].NT_exp_t), (yyvsp[-2].NT_exp_t), (yyvsp[0].NT_exp_t)); }
#line 1640 "smtlib.tab.c"
    break;

  case 46:
#line 253 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_assert((yyvsp[0].NT_exp_t)); }
#line 1646 "smtlib.tab.c"
    break;

  case 47:
#line 255 "smtlib.y"
    {
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s)", (yyvsp[-1].NT_exp_t)->body, (yyvsp[0].NT_exp_t)->body);
                NODE_free((yyvsp[-1].NT_exp_t)); NODE_free((yyvsp[0].NT_exp_t));
                (yyval.NT_exp_t) = FN_mk_node(assrt, NT_ASSRT);
            }
#line 1657 "smtlib.tab.c"
    break;

  case 48:
#line 261 "smtlib.y"
    { (yyval.NT_exp_t) = FN_gen_assert((yyvsp[0].NT_exp_t)); }
#line 1663 "smtlib.tab.c"
    break;

  case 49:
#line 263 "smtlib.y"
    {
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s)", (yyvsp[-1].NT_exp_t)->body, (yyvsp[0].NT_exp_t)->body);
                NODE_free((yyvsp[-1].NT_exp_t)); NODE_free((yyvsp[0].NT_exp_t));
                (yyval.NT_exp_t) = FN_mk_node(assrt, NT_ASSRT);
            }
#line 1674 "smtlib.tab.c"
    break;

  case 50:
#line 272 "smtlib.y"
    { vardef(); FN_write_node_to_file((yyvsp[0].NT_exp_t), ofile); NODE_free((yyvsp[0].NT_exp_t)); }
#line 1680 "smtlib.tab.c"
    break;


#line 1684 "smtlib.tab.c"

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 275 "smtlib.y"


/** TODO: change later
void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   exit(0);
}
*/


int callSMTLIBparser( char *ifile )
{       
    yyin = fopen( ifile ,"r");

    if(yyin==NULL) exit(-1);
    
    asprintf( &ofile, "%s.smt", ifile );
    asprintf( &vfile, "%s.var", ifile );
    if(yyparse())
    {       
        printf("Error\n");
        exit(-1);       
    }
    fclose(yyin);
    free( ofile );
    free( vfile );
    return 0;
}

int varcheck(DATA_expr_t *node)
{
  int i = 0;
  if(varcount>0)
  {
    for( ; i<varcount; i++)
    {
      if( !strcmp(varlist[i].body, node->body) ) // Variable Name is already in list
        return 0;
    }
  } 
  /* varlist[i] = var; */
  asprintf(&(varlist[i].body), "%s", node->body);
  varlist[i].type = node->type;
  varcount++;
  return 1;
}

int vardef()
{
  /** TODO: change later
  int i=0;
  while(i<varcount-1)
  {
      fprintf(vfile_h,"%s ",varlist[i]);
      i++;
  }
  fprintf(vfile_h, "%s", varlist[i]);
  return 1;
  */
  return 1;
}

DATA_expr_t* FN_mk_node(char *s, int type)
{
  DATA_expr_t *node = malloc(sizeof(DATA_expr_t));
  node->body = s;
  node->type = type;

  return node;
}

char* FN_mk_vdecl(char *v, char *v_t)
{
  char *decl;
  asprintf(&decl, "(declare-const %s %s)\n", v, v_t);
  return decl;
}

DATA_expr_t* FN_gen_exp(DATA_expr_t *nleft, DATA_expr_t *nright, int op_t)
{
    char *exp;

    switch(op_t)
    {
    case TK_PL_OP:
        asprintf(&exp, "(+ %s %s)", nleft->body, nright->body);
        break;
    case TK_MI_OP:
        asprintf(&exp, "(- %s %s)", nleft->body, nright->body);
        break;
    case TK_MU_OP:
        asprintf(&exp, "(* %s %s)", nleft->body, nright->body);
        break;
    case TK_DI_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, nright->body);
        break;
    case TK_MO_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, nright->body);
        break;
    case TK_LT_OP:
        asprintf(&exp, "(< %s %s)", nleft->body, nright->body);
        break;
    case TK_GT_OP:
        asprintf(&exp, "(> %s %s)", nleft->body, nright->body);
        break;
    case TK_LE_OP:
        asprintf(&exp, "(<= %s %s)", nleft->body, nright->body);
        break;
    case TK_GE_OP:
        asprintf(&exp, "(>= %s %s)", nleft->body, nright->body);
        break;
    case TK_NE_OP:
        asprintf(&exp, "(not (= %s %s))", nleft->body, nright->body);
        break;
    default:
        printf("\nInvalid syntax: Operator no recognized!\n");
        exit(-1); break;
    }

    free(nleft->body); free(nleft);
    free(nright->body); free(nright);

    return FN_mk_node(exp, NT_EXP);
}

DATA_expr_t* FN_gen_conjunc(DATA_expr_t *nstart, DATA_expr_t *nend)
{
    char *assn;
    asprintf(&assn, "(and %s %s)", nstart->body, nend->body);
    NODE_free(nstart); NODE_free(nend);

    return FN_mk_node(assn, NT_CONJ);
}

DATA_expr_t* FN_gen_impl(DATA_expr_t *ncond, DATA_expr_t *nbranch1, DATA_expr_t *nbranch2)
{
    char *impl;

    if( nbranch2 == NULL )
    {
        asprintf(&impl, "(ite %s %s (= 1 1))", ncond->body, nbranch1->body);
        NODE_free(ncond); NODE_free(nbranch1);
    }
    else
    {
        asprintf(&impl, "(ite %s %s %s)", ncond->body, nbranch1->body, nbranch2->body);
        NODE_free(ncond); NODE_free(nbranch1); NODE_free(nbranch2);
    }

    return FN_mk_node(impl, NT_IMPL);
}

DATA_expr_t* FN_gen_assert(DATA_expr_t *stmt)
{
    char *assert;
    asprintf(&assert, "(assert %s)", stmt->body);
    NODE_free(stmt);
    return FN_mk_node(assert, NT_ASSRT);
}

void FN_write_node_to_file(DATA_expr_t *node, char *fname)
{
    FILE *fname_h = fopen(fname, "w");
    fprintf(fname_h, "%s", node->body);
}

DATA_expr_t* FN_gen_exp_unary( DATA_expr_t *arg, int op_t)
{
    char *exp;

    switch(op_t)
    {
    case TK_MI_OP:
        asprintf(&exp, "(* -1 %s)", arg->body);
        break;
    default:
        printf("\nInvalid Syntax: operator no recognized!\n");
        break;
    }
    NODE_free(arg);
    return FN_mk_node(exp, NT_EXP);
}
