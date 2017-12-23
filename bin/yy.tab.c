/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/yacc.y" /* yacc.c:339  */
 
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include "yy.tab.h"
    #include "error.strings.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
    void help();
    
    // quadruplet
    char st [100][10];
    int top = 0;
    int tempNumber = 0;
    int lineNumber = 1;
    char temp[10]="temp";
    void push();
    void generateQuadruplet();
    void generateQuadrupletUnaryMinus();
    void generatePowQuadruplet();
    void generateSumQuadruplet();
    void generateProductQuadruplet();
    void generateAverageQuadruplet();
    void generateVarianceQuadruplet();
    void generateInitVarianceQuadruplet();
    void generatePreVarianceQuadruplet();

#line 105 "./bin/yy.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yy.tab.h".  */
#ifndef YY_YY_BIN_YY_TAB_H_INCLUDED
# define YY_YY_BIN_YY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    EOI = 259,
    SUM = 260,
    PRODUCT = 261,
    AVERAGE = 262,
    VARIANCE = 263,
    unary_minus = 264
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define EOI 259
#define SUM 260
#define PRODUCT 261
#define AVERAGE 262
#define VARIANCE 263
#define unary_minus 264

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 39 "./src/yacc.y" /* yacc.c:355  */
 int number; 

#line 166 "./bin/yy.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_YY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "./bin/yy.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  18
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   264

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      15,    16,    11,    10,    17,     9,     2,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    13,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,    14
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    61,    62,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      73,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      85,    88,    89,    90,    91,    94,    94,    95,    98,    98,
      99,   102,   102,   103
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "EOI", "SUM", "PRODUCT",
  "AVERAGE", "VARIANCE", "'-'", "'+'", "'*'", "'/'", "'^'", "unary_minus",
  "'('", "')'", "','", "$accept", "Input", "Line", "Expr", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "Function", "AVERAGE_List", "$@8",
  "PRODUCT_List", "$@9", "VARIANCE_List", "$@10", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    45,
      43,    42,    47,    94,   264,    40,    41,    44
};
# endif

#define YYPACT_NINF -11

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-11)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,   219,   -11,   -11,   -11,    -9,    -7,    -4,    -3,   -11,
     230,   -11,   239,   -11,   250,   250,   250,   250,   250,     7,
      40,    -8,   -11,   -11,   -11,   -11,   -11,   -11,   139,    12,
     152,    13,    14,   165,    15,     9,   -11,    23,   -11,   -11,
     -11,   -11,   -11,   -11,   250,   250,   250,   250,   250,   250,
     -11,   -10,   -11,    -2,   -11,   -11,    20,    56,    70,    84,
      98,   112,   126,   250,   250,   250,   178,   191,   204
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    19,     4,     0,     0,     0,     0,    16,
       0,     3,     0,    20,     0,     0,     0,     0,     0,    21,
       0,    29,     5,     6,     8,    12,    10,    14,     0,    35,
       0,    38,    35,     0,    41,     0,    22,    29,    18,    25,
      24,    26,    27,    28,     0,     0,     0,     0,     0,     0,
      31,     0,    33,     0,    32,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -11,   -11,   -11,    -1,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,    22,   -11,   -11,   -11,   -11,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    11,    28,    45,    46,    48,    47,    49,    18,
      44,    13,    29,    51,    31,    53,    34,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      12,    39,    40,    41,    42,    43,    14,    63,    15,    20,
      21,    16,    17,   -17,    30,    64,    33,    35,   -17,   -17,
     -17,   -17,   -17,    36,   -23,   -17,   -17,   -23,    50,    52,
      54,    55,    39,    40,    41,    42,    43,    65,    32,   -23,
     -23,    37,     0,    57,    58,    59,    60,    61,    62,    23,
      24,    25,    26,    27,     0,     0,    38,    21,     0,     0,
     -30,     0,    66,    67,    68,    23,    24,    25,    26,    27,
       0,    21,   -30,   -30,    -7,     0,     0,     0,     0,    -7,
      -7,    25,    26,    27,     0,    21,    -7,    -7,    -9,     0,
       0,     0,     0,    -9,    -9,    25,    26,    27,     0,    21,
      -9,    -9,   -13,     0,     0,     0,     0,   -13,   -13,   -13,
     -13,    27,     0,    21,   -13,   -13,   -11,     0,     0,     0,
       0,   -11,   -11,   -11,   -11,    27,     0,    21,   -11,   -11,
     -15,     0,     0,     0,     0,   -15,   -15,   -15,   -15,    27,
      21,     0,   -15,   -15,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    21,     0,   -37,   -37,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    21,     0,   -40,   -40,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    21,
       0,   -43,   -43,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    21,     0,   -36,   -36,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    21,     0,   -39,   -39,     0,
       0,     0,     0,    23,    24,    25,    26,    27,     0,     2,
     -42,   -42,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    19,     0,     3,    10,     5,     6,     7,     8,     9,
      21,     0,     0,    22,     0,    10,     0,     0,    23,    24,
      25,    26,    27,     3,     0,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10
};

static const yytype_int8 yycheck[] =
{
       1,     9,    10,    11,    12,    13,    15,    17,    15,    10,
       1,    15,    15,     4,    15,    17,    17,    18,     9,    10,
      11,    12,    13,    16,     1,    16,    17,     4,    16,    16,
      16,    16,     9,    10,    11,    12,    13,    17,    16,    16,
      17,     1,    -1,    44,    45,    46,    47,    48,    49,     9,
      10,    11,    12,    13,    -1,    -1,    16,     1,    -1,    -1,
       4,    -1,    63,    64,    65,     9,    10,    11,    12,    13,
      -1,     1,    16,    17,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    -1,     1,    16,    17,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,     1,
      16,    17,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    -1,     1,    16,    17,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    -1,     1,    16,    17,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
       1,    -1,    16,    17,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,     1,    -1,    16,    17,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,     1,    -1,    16,    17,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,     1,
      -1,    16,    17,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,     1,    -1,    16,    17,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,     1,    -1,    16,    17,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,     0,
      16,    17,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,     1,    -1,     3,    15,     5,     6,     7,     8,     9,
       1,    -1,    -1,     4,    -1,    15,    -1,    -1,     9,    10,
      11,    12,    13,     3,    -1,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,     0,     3,     4,     5,     6,     7,     8,     9,
      15,    20,    21,    29,    15,    15,    15,    15,    27,     1,
      21,     1,     4,     9,    10,    11,    12,    13,    21,    30,
      21,    32,    30,    21,    34,    21,    16,     1,    16,     9,
      10,    11,    12,    13,    28,    22,    23,    25,    24,    26,
      16,    31,    16,    33,    16,    16,    35,    21,    21,    21,
      21,    21,    21,    17,    17,    17,    21,    21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    18,    19,    19,    20,    20,    22,    21,    23,    21,
      24,    21,    25,    21,    26,    21,    27,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    28,
      21,    29,    29,    29,    29,    31,    30,    30,    33,    32,
      32,    35,    34,    34
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     3,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     0,
       4,     4,     4,     4,     4,     0,     4,     1,     0,     4,
       1,     0,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 58 "./src/yacc.y" /* yacc.c:1646  */
    { cursor = 0; tempNumber = 0; printf("\n"); lineNumber = 1;}
#line 1335 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "./src/yacc.y" /* yacc.c:1646  */
    { }
#line 1341 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1347 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadruplet(); }
#line 1353 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1359 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadruplet(); }
#line 1365 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1371 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadruplet(); }
#line 1377 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1383 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadruplet(); }
#line 1389 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1395 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "./src/yacc.y" /* yacc.c:1646  */
    { generatePowQuadruplet(); }
#line 1401 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1407 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 70 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadrupletUnaryMinus(); }
#line 1413 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 71 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1419 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1425 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1431 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 77 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1437 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1443 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 79 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
#line 1449 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1455 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 81 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1461 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1467 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1473 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1479 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(OPERATOR_EXPECTED); }
#line 1485 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 88 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1491 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 89 "./src/yacc.y" /* yacc.c:1646  */
    { generateAverageQuadruplet((yyvsp[-1].number)); }
#line 1497 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 90 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1503 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 91 "./src/yacc.y" /* yacc.c:1646  */
    { generateVarianceQuadruplet((yyvsp[-1].number)); }
#line 1509 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1515 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 94 "./src/yacc.y" /* yacc.c:1646  */
    { generateSumQuadruplet(); (yyval.number)++; }
#line 1521 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 95 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = 1;}
#line 1527 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 98 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1533 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 98 "./src/yacc.y" /* yacc.c:1646  */
    { generateProductQuadruplet(); }
#line 1539 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 99 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1545 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 102 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1551 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 102 "./src/yacc.y" /* yacc.c:1646  */
    { generatePreVarianceQuadruplet((yyval.number)++); }
#line 1557 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 103 "./src/yacc.y" /* yacc.c:1646  */
    { generateInitVarianceQuadruplet(); (yyval.number) = 1; }
#line 1563 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;


#line 1567 "./bin/yy.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 105 "./src/yacc.y" /* yacc.c:1906  */

int main(int nbInputs,char **inputs){       
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs == 3 && strcmp(inputs[2], "-f")){
        yyin = NULL;
        yyout = NULL;
        yyin = fopen(inputs[2],"r"); 
        yyout = fopen("output","w");
        if(yyin) fileIsOpen = 1;
        else {
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
        if(yyout == NULL){
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
    }
    yyparse();
    if(fileIsOpen) {
        fclose(yyin);
        fclose(yyout);
    }
    return 0;
}

int yyerror(char *s) {
    printf("errror\n");
    if(strcmp(s,"syntax error")<-1){
        if(fileIsOpen){
            printf("\nError: %s on line %d at position %d\n\n", s, yylineno, cursor);
        }else {
            if(cursor-1 != 0) printf("%*c^\n",cursor-1,' '); else printf("^\n");
            printf("Error: %s at position %d\n\n", s, cursor);
        }
        exit(0);
    }
}

void help()
{
    printf(" _    _          _   _ _____          ____  _    _ _____                       \n");
    printf("| |  | |   /\\   | \\ | |  __ \\   /\\   / __ \\| |  | |_   _|                      \n");
    printf("| |__| |  /  \\  |  \\| | |  | | /  \\ | |  | | |  | | | |                        \n");
    printf("|  __  | / /\\ \\ | . ` | |  | |/ /\\ \\| |  | | |  | | | |                        \n");
    printf("| |  | |/ ____ \\| |\\  | |__| / ____ \\ |__| | |__| |_| |_                       \n");
    printf("|_|  |_/_/    \\_\\_| \\_|_____/_/    \\_\\____/ \\____/|_____|                      \n");
    printf(" __  __       _                              _                                 \n");
    printf("|  \\/  |     | |                            | |                                \n");
    printf("| \\  / | ___ | |__   __ _ _ __ ___   ___  __| |                                \n");
    printf("| |\\/| |/ _ \\| '_ \\ / _` | '_ ` _ \\ / _ \\/ _` |                                \n");
    printf("| |  | | (_) | | | | (_| | | | | | |  __/ (_| |                                \n");
    printf("|_|  |_|\\___/|_| |_|\\__,_|_| |_| |_|\\___|\\__,_|                                \n");
    printf(" _______ _____     _____ ____  __  __ _____ _____ _         _____ _____ _      \n");
    printf("|__   __|  __ \\   / ____/ __ \\|  \\/  |  __ \\_   _| |       / ____|_   _| |     \n");
    printf("   | |  | |__) | | |   | |  | | \\  / | |__) || | | |      | (___   | | | |     \n");
    printf("   | |  |  ___/  | |   | |  | | |\\/| |  ___/ | | | |       \\___ \\  | | | |     \n");
    printf("   | |  | |      | |___| |__| | |  | | |    _| |_| |____   ____) |_| |_| |____ \n");
    printf("   |_|  |_|       \\_____\\____/|_|  |_|_|   |_____|______| |_____/|_____|______|\n\n\n");

    printf("Pour analyser un fichier ajouter -f <filename>\n");
    printf("Pour analyser les entrées cmd, exécutez sans paramètre\n");
    printf("Fonctions disponibles : \n");
    printf("\t1- somme.\n");
    printf("\t2- produit.\n");
    printf("\t3- moyenne.\n");
    printf("\t4- variance.\n");
    printf("\t5- ecart-type.\n");
    printf("\t5- min.\n");
    printf("\t5- max.\n");
}


void push(){
    strcpy(st[++top],yytext);
}

void generateSumQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s + %s\n",lineNumber++,temp,st[top-2],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateProductQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s * %s\n",lineNumber++,temp,st[top-2],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generateAverageQuadruplet(int size){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s / %d\n",lineNumber++,temp,st[top],size);
    strcpy(st[top], temp);
}

void generateInitVarianceQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s * %s\n",lineNumber++,temp,st[top],st[top]);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s\n",lineNumber++,temp,st[top]);
    top --;
    strcpy(st[top], temp);
}

void generatePreVarianceQuadruplet(int size){
    tempNumber++;
    sprintf(temp, "temp%d",tempNumber-size);
    printf("%d   %s := %s * %s\n",lineNumber++,temp,st[top],st[top]);
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d",tempNumber-(size + 1));
    printf("%d   %s := %s + %s\n",lineNumber++,prevTemp,prevTemp,st[top]);
    sprintf(prevTemp, "temp%d",tempNumber-(size + 2));
    printf("%d   %s := %s + %s\n",lineNumber++,prevTemp,prevTemp,temp);
    top --;
    strcpy(st[top], temp);
}

void generateVarianceQuadruplet(int size){
    char prevTemp[10] = "";
    sprintf(prevTemp, "temp%d",tempNumber-size-1);
    printf("%d   %s := %s / %d\n",lineNumber++,prevTemp,prevTemp,size);
    char prevTemp2[10] = "";
    sprintf(prevTemp2, "temp%d",tempNumber-size);
    printf("%d   %s := %s / %d\n",lineNumber++,prevTemp2,prevTemp2,size);
    printf("%d   %s := %s * %s\n",lineNumber++,prevTemp2,prevTemp2,prevTemp2);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s - %s\n",lineNumber++,prevTemp,prevTemp2,prevTemp);
    top -= 2;
    strcpy(st[top], temp);
}

void generateQuadruplet(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s %s %s\n",lineNumber++,temp,st[top-2],st[top-1],st[top]);
    top -= 2;
    strcpy(st[top], temp);
}

void generatePowQuadruplet(){
    int saveTempNumber = tempNumber;
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s\n",lineNumber++,temp,st[top]);
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := %s * %s\n",lineNumber++,temp,temp,st[top-2]);
    sprintf(temp, "temp%d",saveTempNumber);
    printf("%d   %s := %s - 1\n",lineNumber++,temp,temp);
    printf("%d   JNZ %s GOTO %d\n",lineNumber++,temp,lineNumber-2);
    top -= 2;
    sprintf(temp, "temp%d",tempNumber-1);
    strcpy(st[top], temp);
}

void generateQuadrupletUnaryMinus(){
    sprintf(temp, "temp%d",tempNumber++);
    printf("%d   %s := -%s\n",lineNumber++,temp,st[top]);
    top--;
    strcpy(st[top], temp);
}
