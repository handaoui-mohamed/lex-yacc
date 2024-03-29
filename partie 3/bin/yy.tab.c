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
    #include "quadruplet.h"

    // extern functions
    extern int cursor;
    extern char line[255];
    extern char* yytext;
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineNumber;
    extern int tempNumber;
    extern char result[100];
    
    // global variables
    int fileIsOpen = 0;
    int printToFile = 0;

    // global functions
    void openInputFile(char *input);
    void openOutputFile(char *input);
    void closeFiles();

#line 96 "./bin/yy.tab.c" /* yacc.c:339  */

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
    IF = 259,
    EOI = 260,
    EXIT = 261,
    SUM = 262,
    PRODUCT = 263,
    AVERAGE = 264,
    VARIANCE = 265,
    STANDARD_DEVIATION = 266,
    MIN = 267,
    MAX = 268,
    unary_minus = 269
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define IF 259
#define EOI 260
#define EXIT 261
#define SUM 262
#define PRODUCT 263
#define AVERAGE 264
#define VARIANCE 265
#define STANDARD_DEVIATION 266
#define MIN 267
#define MAX 268
#define unary_minus 269

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "./src/yacc.y" /* yacc.c:355  */
 int number; 

#line 167 "./bin/yy.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_YY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "./bin/yy.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

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
      20,    21,    16,    15,    26,    14,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
      23,    25,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    49,    50,    53,    54,    55,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    65,    66,    67,    67,    67,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    85,    88,    88,    89,    89,    90,    90,    93,    94,
      95,    96,    97,    98,    99,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     113,   113,   114,   118,   121,   121,   122,   126,   129,   129,
     130,   134,   137,   137,   138,   142,   145,   145,   146,   150
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "IF", "EOI", "EXIT", "SUM",
  "PRODUCT", "AVERAGE", "VARIANCE", "STANDARD_DEVIATION", "MIN", "MAX",
  "'-'", "'+'", "'*'", "'/'", "'^'", "unary_minus", "'('", "')'", "';'",
  "'<'", "'>'", "'='", "','", "$accept", "Input", "Line", "Expr", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "Test", "$@10",
  "$@11", "$@12", "Function", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "SUM_List", "$@20", "PRODUCT_List", "$@21",
  "VARIANCE_List", "$@22", "MIN_List", "$@23", "MAX_List", "$@24", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    45,    43,    42,    47,    94,   269,
      40,    41,    59,    60,    62,    61,    44
};
# endif

#define YYPACT_NINF -19

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-19)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -19,   518,   -19,    92,   -19,   -18,   -19,   -19,   -17,
     -16,    -9,    -6,    -4,    -3,     3,   -19,   532,   -19,   630,
     -19,   -19,   -19,   -19,   -19,   -19,   546,   560,    11,   574,
      25,   560,    28,   588,    33,   588,    35,   602,    37,   616,
      39,   546,    -8,    45,   453,   -19,   -19,   -19,   -19,   -19,
     -19,   439,   -19,    92,     4,    26,   -19,    92,    79,    34,
     -19,    36,   -19,    92,   295,    43,   -19,    44,   -19,    92,
     313,    51,   -19,    92,   331,    52,   -19,    27,   -19,    53,
     -19,   -19,   -19,   -19,   -19,   -19,   546,   546,   546,   546,
     546,   546,   121,   -19,   -19,   -19,    59,   -19,    30,   -19,
      56,   -19,   -19,    57,   -19,   -19,    64,   -19,    65,   147,
     173,   199,   225,   251,   277,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   471,   480,   489,   498,   349,   367,
     385,   403,   421,    70,   546,   139,   -19
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     0,     1,     0,    21,     0,     5,     6,    67,
      63,    65,    61,    59,    55,    57,    18,     0,     3,     0,
      22,    35,    34,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    40,     7,     8,    10,    14,    12,
      16,     0,    23,    73,     0,    70,    68,    77,     0,    74,
      64,    70,    66,    81,     0,    78,    62,    78,    60,    85,
       0,    82,    56,    89,     0,    86,    58,     0,    27,    40,
      20,    30,    29,    31,    32,    33,     0,     0,     0,     0,
       0,     0,    40,    42,    44,    46,     0,    48,     0,    50,
       0,    49,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,   -19,    -2,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,    67,   -19,   -19,   -19,    66,
     -19,   -19,   -19,   -19,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    18,    54,    87,    88,    90,    89,    91,    41,
      96,   133,    86,    52,   115,   116,   117,    20,    38,    40,
      36,    34,    30,    32,    28,    55,    98,    59,   100,    65,
     103,    71,   106,    75,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,     1,    26,    27,    29,    44,    21,    22,    23,    24,
      25,    31,    56,    78,    33,    43,    35,    37,    46,    47,
      48,    49,    50,    39,    51,   -72,    60,    58,    44,    62,
     -72,    64,   -19,    64,    66,    70,    68,    74,    72,    77,
      76,   -19,   -19,   -19,   -19,   -19,    79,    97,   -19,   -19,
     -19,   -19,   -19,   -19,   -28,    99,   119,   101,   -28,    46,
      47,    48,    49,    50,   102,   104,    80,    81,    82,    83,
      84,    85,   105,   107,   -28,   -28,   -28,   -28,   -28,   -28,
      44,   118,   120,   121,   109,   110,   111,   112,   113,   114,
     122,   123,   134,    46,    47,    48,    49,    50,    61,     0,
     -76,    67,     0,     0,     0,   -76,    21,    22,    23,    24,
      25,     0,     0,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   -39,     0,     0,     0,   -39,     0,     0,     0,
       0,     0,   135,     0,     0,    81,    82,    83,    84,    85,
      44,     0,   -39,   -39,   -39,   -39,   -39,   -39,    44,     0,
       0,     0,   -41,    46,    47,    48,    49,    50,     0,     0,
     136,    46,    47,    48,    49,    50,     0,     0,   -41,   -41,
     -41,   -41,   -41,   -41,    44,     0,     0,     0,    -9,     0,
       0,     0,     0,     0,     0,     0,     0,    -9,    -9,    48,
      49,    50,     0,     0,    -9,    -9,    -9,    -9,    -9,    -9,
      44,     0,     0,     0,   -11,     0,     0,     0,     0,     0,
       0,     0,     0,   -11,   -11,    48,    49,    50,     0,     0,
     -11,   -11,   -11,   -11,   -11,   -11,    44,     0,     0,     0,
     -15,     0,     0,     0,     0,     0,     0,     0,     0,   -15,
     -15,   -15,   -15,    50,     0,     0,   -15,   -15,   -15,   -15,
     -15,   -15,    44,     0,     0,     0,   -13,     0,     0,     0,
       0,     0,     0,     0,     0,   -13,   -13,   -13,   -13,    50,
       0,     0,   -13,   -13,   -13,   -13,   -13,   -13,    44,     0,
       0,     0,   -17,     0,     0,     0,     0,     0,     0,     0,
       0,   -17,   -17,   -17,   -17,    50,    44,     0,   -17,   -17,
     -17,   -17,   -17,   -17,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    44,     0,   -80,     0,     0,     0,
       0,   -80,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    44,     0,   -84,     0,     0,     0,     0,   -84,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    50,
      44,     0,   -88,     0,     0,     0,     0,   -88,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,    44,     0,
     -71,     0,     0,     0,     0,   -71,     0,     0,     0,     0,
       0,    46,    47,    48,    49,    50,    44,     0,   -75,     0,
       0,     0,     0,   -75,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    44,     0,   -79,     0,     0,     0,
       0,   -79,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    44,     0,   -83,     0,     0,     0,     0,   -83,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    50,
      92,     0,   -87,     0,     0,     0,     0,   -87,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,   -69,     0,
       0,     0,    93,    94,    95,     0,     0,    81,    82,    83,
      84,    85,    44,     0,   -69,   -69,   -69,   -69,   -69,   -69,
       0,    44,     0,     0,     0,    46,    47,    48,    49,    50,
      44,     0,     0,   -43,    46,    47,    48,    49,    50,    44,
       0,     0,   -45,    46,    47,    48,    49,    50,     0,     0,
       0,   -47,    46,    47,    48,    49,    50,     0,     3,     4,
     -24,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    42,     0,     5,     6,     0,    17,     9,
      10,    11,    12,    13,    14,    15,    16,     4,     0,     5,
       6,     0,    17,     9,    10,    11,    12,    13,    14,    15,
      16,    53,     0,     5,     6,     0,    17,     9,    10,    11,
      12,    13,    14,    15,    16,    57,     0,     5,     6,     0,
      17,     9,    10,    11,    12,    13,    14,    15,    16,    63,
       0,     5,     6,     0,    17,     9,    10,    11,    12,    13,
      14,    15,    16,    69,     0,     5,     6,     0,    17,     9,
      10,    11,    12,    13,    14,    15,    16,    73,     0,     5,
       6,     0,    17,     9,    10,    11,    12,    13,    14,    15,
      16,    44,     0,     0,     0,    45,    17,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50
};

static const yytype_int16 yycheck[] =
{
       2,     6,    20,    20,    20,     1,    14,    15,    16,    17,
      18,    20,     1,    21,    20,    17,    20,    20,    14,    15,
      16,    17,    18,    20,    26,    21,     1,    29,     1,     1,
      26,    33,     5,    35,     1,    37,     1,    39,     1,    41,
       1,    14,    15,    16,    17,    18,     1,    21,    21,    22,
      23,    24,    25,    26,     1,    21,    26,    21,     5,    14,
      15,    16,    17,    18,    21,    21,    21,    14,    15,    16,
      17,    18,    21,    21,    21,    22,    23,    24,    25,    26,
       1,    22,    26,    26,    86,    87,    88,    89,    90,    91,
      26,    26,    22,    14,    15,    16,    17,    18,    31,    -1,
      21,    35,    -1,    -1,    -1,    26,    14,    15,    16,    17,
      18,    -1,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    14,    15,    16,    17,    18,
       1,    -1,    21,    22,    23,    24,    25,    26,     1,    -1,
      -1,    -1,     5,    14,    15,    16,    17,    18,    -1,    -1,
      21,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,     1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
       1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,     1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,     1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,     1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,     1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,     1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,     1,    -1,    21,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
       1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,     1,    -1,
      21,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,     1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,     1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,     1,    -1,    21,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
       1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,     5,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    14,    15,    16,
      17,    18,     1,    -1,    21,    22,    23,    24,    25,    26,
      -1,     1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
       1,    -1,    -1,    22,    14,    15,    16,    17,    18,     1,
      -1,    -1,    22,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    22,    14,    15,    16,    17,    18,    -1,     0,     1,
      22,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     1,    -1,     3,     4,    -1,    20,     7,
       8,     9,    10,    11,    12,    13,    14,     1,    -1,     3,
       4,    -1,    20,     7,     8,     9,    10,    11,    12,    13,
      14,     1,    -1,     3,     4,    -1,    20,     7,     8,     9,
      10,    11,    12,    13,    14,     1,    -1,     3,     4,    -1,
      20,     7,     8,     9,    10,    11,    12,    13,    14,     1,
      -1,     3,     4,    -1,    20,     7,     8,     9,    10,    11,
      12,    13,    14,     1,    -1,     3,     4,    -1,    20,     7,
       8,     9,    10,    11,    12,    13,    14,     1,    -1,     3,
       4,    -1,    20,     7,     8,     9,    10,    11,    12,    13,
      14,     1,    -1,    -1,    -1,     5,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    28,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    20,    29,    30,
      44,    14,    15,    16,    17,    18,    20,    20,    51,    20,
      49,    20,    50,    20,    48,    20,    47,    20,    45,    20,
      46,    36,     1,    30,     1,     5,    14,    15,    16,    17,
      18,    30,    40,     1,    30,    52,     1,     1,    30,    54,
       1,    52,     1,     1,    30,    56,     1,    56,     1,     1,
      30,    58,     1,     1,    30,    60,     1,    30,    21,     1,
      21,    14,    15,    16,    17,    18,    39,    31,    32,    34,
      33,    35,     1,    23,    24,    25,    37,    21,    53,    21,
      55,    21,    21,    57,    21,    21,    59,    21,    61,    30,
      30,    30,    30,    30,    30,    41,    42,    43,    22,    26,
      26,    26,    26,    26,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    38,    22,    30,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    28,    28,    29,    29,    29,    31,    30,
      32,    30,    33,    30,    34,    30,    35,    30,    36,    30,
      30,    30,    30,    37,    38,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      39,    30,    41,    40,    42,    40,    43,    40,    44,    44,
      44,    44,    44,    44,    44,    45,    44,    46,    44,    47,
      44,    48,    44,    49,    44,    50,    44,    51,    44,    44,
      53,    52,    52,    52,    55,    54,    54,    54,    57,    56,
      56,    56,    59,    58,    58,    58,    61,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     3,
       3,     1,     1,     0,     0,    10,     2,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     2,
       0,     4,     1,     1,     0,     4,     1,     1,     0,     4,
       1,     1,     0,     4,     1,     1,     0,     4,     1,     1
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
#line 49 "./src/yacc.y" /* yacc.c:1646  */
    {  cursor = 0; strcpy(line,""); }
#line 1453 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "./src/yacc.y" /* yacc.c:1646  */
    { closeFiles(); }
#line 1459 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 54 "./src/yacc.y" /* yacc.c:1646  */
    { closeFiles(); }
#line 1465 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "./src/yacc.y" /* yacc.c:1646  */
    { printQuadruplets(); }
#line 1471 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1477 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 58 "./src/yacc.y" /* yacc.c:1646  */
    { generateArithmeticQuadruplet(); }
#line 1483 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 59 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1489 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 59 "./src/yacc.y" /* yacc.c:1646  */
    { generateArithmeticQuadruplet(); }
#line 1495 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 60 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1501 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "./src/yacc.y" /* yacc.c:1646  */
    { generateArithmeticQuadruplet(); }
#line 1507 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 61 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1513 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 61 "./src/yacc.y" /* yacc.c:1646  */
    { generateArithmeticQuadruplet(); }
#line 1519 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1525 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "./src/yacc.y" /* yacc.c:1646  */
    { generatePowQuadruplet(); }
#line 1531 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1537 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 63 "./src/yacc.y" /* yacc.c:1646  */
    { generateQuadrupletUnaryMinus(); }
#line 1543 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 64 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1549 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 65 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1555 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 66 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1561 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 67 "./src/yacc.y" /* yacc.c:1646  */
    { (yyvsp[0].number) = lineNumber; }
#line 1567 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 67 "./src/yacc.y" /* yacc.c:1646  */
    { generateTempQuadruplet(); (yyvsp[0].number) = lineNumber; }
#line 1573 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 67 "./src/yacc.y" /* yacc.c:1646  */
    { generateIfQuadruplet((yyvsp[-7].number), (yyvsp[-4].number)); }
#line 1579 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 71 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1585 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 72 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1591 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 73 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
#line 1597 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 74 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1603 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 75 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1609 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 76 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1615 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 77 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1621 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 78 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1627 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 79 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1633 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 80 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1639 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 81 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1645 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 82 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1651 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 83 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1657 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 84 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(TEST_EXPECTED); }
#line 1663 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 85 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(OPERATOR_EXPECTED); }
#line 1669 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 88 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1675 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 88 "./src/yacc.y" /* yacc.c:1646  */
    { generateTestQuadruplet(); }
#line 1681 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 89 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1687 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 89 "./src/yacc.y" /* yacc.c:1646  */
    { generateTestQuadruplet(); }
#line 1693 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 90 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1699 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 90 "./src/yacc.y" /* yacc.c:1646  */
    { generateTestQuadruplet(); }
#line 1705 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 94 "./src/yacc.y" /* yacc.c:1646  */
    { generateAverageQuadruplet((yyvsp[-1].number)); }
#line 1711 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 96 "./src/yacc.y" /* yacc.c:1646  */
    { generateVarianceQuadruplet((yyvsp[-1].number)); }
#line 1717 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 97 "./src/yacc.y" /* yacc.c:1646  */
    { generateVarianceQuadruplet((yyvsp[-1].number)); generateDeviationQuadruplet((yyvsp[-1].number)); }
#line 1723 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 98 "./src/yacc.y" /* yacc.c:1646  */
    { generateMinQuadruplet(); }
#line 1729 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 99 "./src/yacc.y" /* yacc.c:1646  */
    { generateMaxQuadruplet(); }
#line 1735 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 103 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1741 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 104 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1747 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 105 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1753 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 106 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1759 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 107 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1765 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 108 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1771 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 109 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1777 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 110 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
#line 1783 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 113 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1789 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 113 "./src/yacc.y" /* yacc.c:1646  */
    { generateSumQuadruplet(); (yyval.number)++; }
#line 1795 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 114 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = 1;}
#line 1801 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 118 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1807 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 121 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1813 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 121 "./src/yacc.y" /* yacc.c:1646  */
    { generateProductQuadruplet(); }
#line 1819 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 122 "./src/yacc.y" /* yacc.c:1646  */
    {}
#line 1825 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 126 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1831 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 129 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1837 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 129 "./src/yacc.y" /* yacc.c:1646  */
    { generatePreVarianceQuadruplet((yyval.number)++); }
#line 1843 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 130 "./src/yacc.y" /* yacc.c:1646  */
    { generateInitVarianceQuadruplet(); (yyval.number) = 1; }
#line 1849 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 134 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1855 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 137 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1861 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 137 "./src/yacc.y" /* yacc.c:1646  */
    { generatePreMinQuadruplet(); }
#line 1867 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 138 "./src/yacc.y" /* yacc.c:1646  */
    { generateInitMinMaxQuadruplet();}
#line 1873 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 142 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1879 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 145 "./src/yacc.y" /* yacc.c:1646  */
    { push(); }
#line 1885 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 145 "./src/yacc.y" /* yacc.c:1646  */
    { generatePreMaxQuadruplet(); }
#line 1891 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 146 "./src/yacc.y" /* yacc.c:1646  */
    { generateInitMinMaxQuadruplet();}
#line 1897 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 150 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1903 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;


#line 1907 "./bin/yy.tab.c" /* yacc.c:1646  */
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
#line 152 "./src/yacc.y" /* yacc.c:1906  */

int main(int nbInputs,char **inputs){
    if(nbInputs == 2 && (!strcmp(inputs[1], "-h") || !strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs > 2){ 
        if (!strcmp(inputs[1], "-f")){
            openInputFile(inputs[2]);
        }
        else if (!strcmp(inputs[1], "-o")){
            openOutputFile(inputs[2]);
        }
        
    }

    if(nbInputs > 3){
        if (!strcmp(inputs[3], "-o")){
             openOutputFile(inputs[4]);
        }
        else if (!strcmp(inputs[3], "-f")){
            openInputFile(inputs[4]);
        }
    }

    yyparse();
    closeFiles();
    return 0;
}

void closeFiles(){
    if(yyin != NULL && fileIsOpen) 
        fclose(yyin);
    if(yyout != NULL && printToFile)
        fclose(yyout);
    exit(0);
}

void openInputFile(char *input){
    yyin = NULL;
    yyin = fopen(input,"r"); 
    if(yyin) fileIsOpen = 1;
    else {
        printf("Error: unable to open file or file does not existe!\n");
        exit(0);
    }
}

void openOutputFile(char *output){
    yyout = NULL;
    yyout = fopen(output,"w");
    if(yyout) printToFile = 1;
    else {
        printf("Error: unable to open or create file!\n");
        exit(0);
    }
}

int yyerror(char *s) {
    if(strcmp(s,"syntax error")<-1){
        if(fileIsOpen){
            printf("*** %s\n%*c^\n",line,cursor+3,' ');
            printf("Erreur: %s dans la ligne %d à la position %d\n\n", s, yylineno, cursor);
        }else {
            if(cursor-1 != 0) printf("%*c^\n",cursor-1,' '); else printf("^\n");
            printf("Erreur: %s à la position %d\n\n", s, cursor);
        }
        exit(0);
    }
}
