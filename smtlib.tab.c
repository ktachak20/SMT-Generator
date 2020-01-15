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

FILE        *ofile_h;
FILE        *vfile_h;
char        *x;
char        *VR_vdec;              /* pointer to string of variable declarations. */
extern int  yyparse();
extern FILE *yyin;
int         varcount = 0;
char        *varlist[MAXVARS];
int         vardef( void );
int         varcheck( char * );
char*       FN_mk_vdecl(char *, char *);

#line 92 "smtlib.tab.c"

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
#line 29 "smtlib.y"

  typedef struct { char *body; int type; } DATA_expr_t;
  DATA_expr_t *FN_mk_node( char *, int );

#line 131 "smtlib.tab.c"

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
    TK_ASS_OP = 285,
    TK_UMI = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "smtlib.y"

  char        *TK_literal_t;
  char        *TK_identifier_t;
  DATA_expr_t *NT_exp_t;

#line 180 "smtlib.tab.c"

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   116,   121,   123,   134,   136,   144,   145,
     150,   155,   160,   165,   170,   174,   179,   182,   183,   184,
     185,   186,   187,   188,   192,   203,   204,   209,   214,   219,
     225,   227,   250,   252,   253,   256,   257,   258,   260,   263,
     264,   265,   267,   269,   272,   273,   274,   276,   280
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
  "TK_ASS_OP", "TK_UMI", "$accept", "primary_expression",
  "postfix_expression", "unary_expression", "expression",
  "assignment_expression", "relational_operator",
  "primary_conditional_expression", "conditional_expression",
  "assignment_statement", "assignments", "mixed_statements", "innerblock",
  "decision", "assertions", "smtlib", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     155,   -35,   -35,   126,   116,     5,   -35,   -19,    -9,     1,
     155,   155,   -35,    39,    29,    41,   108,   -35,    31,   -35,
     135,   -35,   159,   159,   -35,   -35,   -35,   -35,   -35,   116,
     159,   159,    61,   171,   159,   -35,   -35,   -35,   -35,   -35,
     159,   159,   -35,   -35,   159,   116,   116,   116,   155,   116,
     -35,    32,   -35,   112,     3,    74,   182,    38,    71,   -35,
     -35,   -35,    64,     6,    74,    56,    16,    85,   126,   155,
      77,   155,   -35,   145,    79,   -35,   -35,   159,   159,   -35,
     -35,   -35,   -35,   -35,    83,    91,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     3,     0,     0,     0,     4,     6,     0,     0,
      44,    45,    48,     0,     0,     0,     0,     8,     0,    25,
       0,     7,     0,     0,    32,    46,    47,     1,    16,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
       0,     0,    22,    23,     0,     0,     0,     0,     0,     0,
      39,    42,    40,     0,     0,    15,     0,     0,     0,    14,
      30,    13,     9,    10,    24,    26,    28,    27,    33,    35,
       0,    36,    29,     0,     0,     5,    31,     0,     0,    34,
      37,    41,    38,    43,     0,     0,    11,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,    82,   -35,     0,   -15,    94,   -35,   -35,    -2,     2,
      36,   -34,    42,   -16,    73,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,    17,    18,     9,    44,    19,    20,    68,
      69,    70,    51,    11,    12,    13
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    32,    10,     8,    52,    22,    34,    54,    55,    34,
       8,     8,    10,    10,    33,    57,    58,     1,     2,    61,
       8,    23,    50,    45,    24,    62,    63,    56,    75,    64,
      40,    41,    71,    40,    34,    80,    49,    82,    74,    27,
      35,    34,    36,    65,    66,    67,    28,    72,     8,    37,
      38,    39,    77,    71,    73,    71,    29,    52,    40,    41,
      42,    43,    84,    85,    34,    40,    41,    34,     8,     8,
      35,     8,    36,     8,    34,    50,    49,    34,    59,    37,
      38,    39,    34,    25,    26,    78,    34,    21,    40,    41,
      42,    43,    45,    46,    34,    47,    59,    14,    40,    41,
      86,    40,    41,    81,    79,    49,    40,    41,    87,     0,
      40,    41,    30,    31,    15,    83,    30,    31,    40,    41,
       1,     2,    15,    16,     1,     2,     0,    53,     1,     2,
       0,    16,     0,     0,     0,     0,     5,     0,     1,     2,
       5,     3,    45,    46,     5,    47,     0,     1,     2,     0,
       3,    48,     0,     0,     5,    49,     4,     1,     2,     0,
       3,    48,     0,     5,     0,     0,     4,     1,     2,     0,
       3,     1,     2,     5,    53,     0,     4,     0,    45,    46,
       0,    47,     0,     5,     0,     0,     0,     5,    60,    45,
      46,    49,    47,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    49
};

static const yytype_int8 yycheck[] =
{
       0,    16,     0,     3,    20,    24,     3,    22,    23,     3,
      10,    11,    10,    11,    16,    30,    31,    12,    13,    34,
      20,    30,    20,     7,    23,    40,    41,    29,    25,    44,
      27,    28,    48,    27,     3,    69,    20,    71,    53,     0,
       9,     3,    11,    45,    46,    47,    17,    49,    48,    18,
      19,    20,    14,    69,    22,    71,    15,    73,    27,    28,
      29,    30,    77,    78,     3,    27,    28,     3,    68,    69,
       9,    71,    11,    73,     3,    73,    20,     3,    17,    18,
      19,    20,     3,    10,    11,    14,     3,     5,    27,    28,
      29,    30,     7,     8,     3,    10,    17,     3,    27,    28,
      17,    27,    28,    26,    68,    20,    27,    28,    17,    -1,
      27,    28,     4,     5,     6,    73,     4,     5,    27,    28,
      12,    13,     6,    15,    12,    13,    -1,    15,    12,    13,
      -1,    15,    -1,    -1,    -1,    -1,    28,    -1,    12,    13,
      28,    15,     7,     8,    28,    10,    -1,    12,    13,    -1,
      15,    16,    -1,    -1,    28,    20,    21,    12,    13,    -1,
      15,    16,    -1,    28,    -1,    -1,    21,    12,    13,    -1,
      15,    12,    13,    28,    15,    -1,    21,    -1,     7,     8,
      -1,    10,    -1,    28,    -1,    -1,    -1,    28,    17,     7,
       8,    20,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    15,    21,    28,    33,    34,    35,    37,
      41,    45,    46,    47,    37,     6,    15,    35,    36,    39,
      40,    33,    24,    30,    23,    46,    46,     0,    17,    15,
       4,     5,    36,    40,     3,     9,    11,    18,    19,    20,
      27,    28,    29,    30,    38,     7,     8,    10,    16,    20,
      41,    44,    45,    15,    36,    36,    40,    36,    36,    17,
      17,    36,    36,    36,    36,    40,    40,    40,    41,    42,
      43,    45,    40,    22,    36,    25,    17,    14,    14,    42,
      43,    26,    43,    44,    36,    36,    17,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    35,    35,    36,    36,
      36,    36,    36,    36,    36,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    39,    40,    40,    40,    40,    40,
      40,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    46,    46,    46,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     1,     2,     1,     3,
       3,     6,     6,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     4,     2,     1,     2,     1,     1,     2,     2,     1,
       1,     3,     3,     5,     1,     1,     2,     2,     1
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
#line 108 "smtlib.y"
    {
      varcheck((yyvsp[0].TK_identifier_t)); (yyval.NT_exp_t) = FN_mk_node((yyvsp[0].TK_identifier_t), TK_ID);
      /* Required for variable declaration 
      char *tmp = VR_vdecl; VR_vdecl = NULL;
      asprintf(&VR_vdecl, "%s%s", tmp, FN_mk_vdecl($1, "Int");
      free(tmp);
      */
    }
#line 1363 "smtlib.tab.c"
    break;

  case 3:
#line 117 "smtlib.y"
    { (yyval.NT_exp_t) = FN_mk_node((yyvsp[0].TK_literal_t), TK_CT); }
#line 1369 "smtlib.tab.c"
    break;

  case 4:
#line 122 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1375 "smtlib.tab.c"
    break;

  case 5:
#line 124 "smtlib.y"
    { 
      char *tmp;
      asprintf(&tmp, "(select %s %s)", (yyvsp[-3].NT_exp_t)->body, (yyvsp[-1].NT_exp_t)->body);
      (yyval.NT_exp_t) = FN_mk_node(tmp, NT_EXP_ARR);
      free((yyvsp[-3].NT_exp_t)->body); free((yyvsp[-1].NT_exp_t)->body);
      free((yyvsp[-3].NT_exp_t)); free((yyvsp[-1].NT_exp_t));
    }
#line 1387 "smtlib.tab.c"
    break;

  case 6:
#line 135 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1393 "smtlib.tab.c"
    break;

  case 7:
#line 137 "smtlib.y"
    {
        char *tmp;
        asprintf(&tmp, "(- %s)", (yyvsp[0].NT_exp_t));
        (yyval.NT_exp_t) = FN_mk_node(tmp, TK_MI_OP);
    }
#line 1403 "smtlib.tab.c"
    break;

  case 8:
#line 144 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1409 "smtlib.tab.c"
    break;

  case 9:
#line 146 "smtlib.y"
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(+ ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1418 "smtlib.tab.c"
    break;

  case 10:
#line 151 "smtlib.y"
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(- ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1427 "smtlib.tab.c"
    break;

  case 11:
#line 156 "smtlib.y"
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(div ", (yyvsp[-3].NT_exp_t)," ", (yyvsp[-1].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1436 "smtlib.tab.c"
    break;

  case 12:
#line 161 "smtlib.y"
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(mod ", (yyvsp[-3].NT_exp_t)," ", (yyvsp[-1].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1445 "smtlib.tab.c"
    break;

  case 13:
#line 166 "smtlib.y"
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(* ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1454 "smtlib.tab.c"
    break;

  case 14:
#line 170 "smtlib.y"
    {(yyval.NT_exp_t)=(yyvsp[-1].NT_exp_t);}
#line 1460 "smtlib.tab.c"
    break;

  case 15:
#line 174 "smtlib.y"
    {  
      char *x;
      int size = asprintf(&x, "%s%s%s%s%s", "(= ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1470 "smtlib.tab.c"
    break;

  case 16:
#line 179 "smtlib.y"
    {(yyval.NT_exp_t)=(yyvsp[-1].NT_exp_t);}
#line 1476 "smtlib.tab.c"
    break;

  case 17:
#line 182 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1482 "smtlib.tab.c"
    break;

  case 18:
#line 183 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1488 "smtlib.tab.c"
    break;

  case 19:
#line 184 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1494 "smtlib.tab.c"
    break;

  case 20:
#line 185 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1500 "smtlib.tab.c"
    break;

  case 21:
#line 186 "smtlib.y"
    { strcpy((yyval.NT_exp_t),"="); }
#line 1506 "smtlib.tab.c"
    break;

  case 22:
#line 187 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1512 "smtlib.tab.c"
    break;

  case 23:
#line 188 "smtlib.y"
    { strcpy((yyval.NT_exp_t),(yyvsp[0].TK_simple_t)); }
#line 1518 "smtlib.tab.c"
    break;

  case 24:
#line 192 "smtlib.y"
    {
      int size;
      if(strcmp((yyvsp[-1].NT_exp_t),"!=")==0)
      size = asprintf(&x, "%s%s%s%s%s%s", "(not (="," ",(yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),"))");
      else
      size = asprintf(&x, "%s%s%s%s%s%s%s", "(",(yyvsp[-1].NT_exp_t)," ",(yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")");
      (yyval.NT_exp_t)=x;
    }
#line 1531 "smtlib.tab.c"
    break;

  case 25:
#line 203 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1537 "smtlib.tab.c"
    break;

  case 26:
#line 205 "smtlib.y"
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(and ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1546 "smtlib.tab.c"
    break;

  case 27:
#line 210 "smtlib.y"
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(=> ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1555 "smtlib.tab.c"
    break;

  case 28:
#line 215 "smtlib.y"
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(or ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1564 "smtlib.tab.c"
    break;

  case 29:
#line 220 "smtlib.y"
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(= ", (yyvsp[-2].NT_exp_t)," ", (yyvsp[0].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1573 "smtlib.tab.c"
    break;

  case 30:
#line 225 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1579 "smtlib.tab.c"
    break;

  case 31:
#line 228 "smtlib.y"
    {
      int size = asprintf(&x, "%s%s%s", "(not ",(yyvsp[-1].NT_exp_t),")" );
      (yyval.NT_exp_t)=x;
    }
#line 1588 "smtlib.tab.c"
    break;

  case 32:
#line 250 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1594 "smtlib.tab.c"
    break;

  case 33:
#line 252 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1600 "smtlib.tab.c"
    break;

  case 34:
#line 254 "smtlib.y"
    { asprintf( &x, "(and %s %s)", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1606 "smtlib.tab.c"
    break;

  case 35:
#line 256 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1612 "smtlib.tab.c"
    break;

  case 36:
#line 257 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1618 "smtlib.tab.c"
    break;

  case 37:
#line 259 "smtlib.y"
    { asprintf( &x, "(and %s %s)", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1624 "smtlib.tab.c"
    break;

  case 38:
#line 261 "smtlib.y"
    { asprintf( &x, "(and %s %s)", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1630 "smtlib.tab.c"
    break;

  case 39:
#line 263 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1636 "smtlib.tab.c"
    break;

  case 40:
#line 264 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[0].NT_exp_t); }
#line 1642 "smtlib.tab.c"
    break;

  case 41:
#line 265 "smtlib.y"
    { (yyval.NT_exp_t) = (yyvsp[-1].NT_exp_t); }
#line 1648 "smtlib.tab.c"
    break;

  case 42:
#line 268 "smtlib.y"
    { asprintf( &x, "(ite %s %s true)", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1654 "smtlib.tab.c"
    break;

  case 43:
#line 270 "smtlib.y"
    { asprintf( &x, "(ite %s %s %s)", (yyvsp[-3].NT_exp_t), (yyvsp[-2].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1660 "smtlib.tab.c"
    break;

  case 44:
#line 272 "smtlib.y"
    { asprintf( &x, "(assert %s)", (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1666 "smtlib.tab.c"
    break;

  case 45:
#line 273 "smtlib.y"
    { asprintf( &x, "(assert %s)", (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1672 "smtlib.tab.c"
    break;

  case 46:
#line 275 "smtlib.y"
    { asprintf( &x, "(assert %s)\n%s", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1678 "smtlib.tab.c"
    break;

  case 47:
#line 277 "smtlib.y"
    { asprintf( &x, "(assert %s)\n%s", (yyvsp[-1].NT_exp_t), (yyvsp[0].NT_exp_t) ); (yyval.NT_exp_t) = x; }
#line 1684 "smtlib.tab.c"
    break;

  case 48:
#line 280 "smtlib.y"
    { vardef(); asprintf( &x, "%s\n", (yyvsp[0].NT_exp_t) ); fprintf( ofile_h, "%s", x ); }
#line 1690 "smtlib.tab.c"
    break;


#line 1694 "smtlib.tab.c"

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
#line 284 "smtlib.y"


void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   exit(0);
}


int callSMTLIBparser( char *ifile )
{	
  char *vfile, *ofile;
	yyin = fopen( ifile ,"r");
	if(yyin==NULL)
		return 0;
  asprintf( &ofile, "%s.smt", ifile );
	ofile_h = fopen( ofile, "w" );
  asprintf( &vfile, "%s.var", ifile );
  vfile_h = fopen( vfile, "w" );
	if(yyparse())
	{	
		printf("Error\n");
		return 0;	
	}
	fclose(yyin);
	fclose(ofile_h);
  free( ofile );
  free( vfile );
  return 0;
}

int varcheck(char *var)
{
  int i=0;
  if(varcount>0)
  {
    for(i=0;i<varcount;i++)
    {
      if(!strcmp(varlist[i],var)) // Variable Name is already in list
      return 0;
    }
  } 
  varlist[i]=var;
  varcount++;
  return 1;
}

int vardef()
{
  int i=0;
  while(i<varcount-1)
  {
      fprintf(vfile_h,"%s ",varlist[i]);
      i++;
  }
  fprintf(vfile_h, "%s", varlist[i]);
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
