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
    #include "yy.tab.h"
    #include "error.strings.h"

    // extern functions
    extern int cursor;
    extern char* yytext;
    extern int yylineno;
    
    // global variables
    int fileIsOpen = 0;
    
    // global functions
    void help();

#line 85 "./bin/yy.tab.c" /* yacc.c:339  */

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
    NUMBER = 258,
    EOI = 259,
    AVERAGE = 260,
    SUM = 261,
    PRODUCT = 262,
    VARIANCE = 263,
    STANDARD_DEVIATION = 264,
    MIN = 265,
    MAX = 266,
    IF = 267,
    unary_minus = 268
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define EOI 259
#define AVERAGE 260
#define SUM 261
#define PRODUCT 262
#define VARIANCE 263
#define STANDARD_DEVIATION 264
#define MIN 265
#define MAX 266
#define IF 267
#define unary_minus 268

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "./src/yacc.y" /* yacc.c:355  */

    struct list{
        double value;
        double sqr_value;
        int size;
    } list;
    double number;
    int function;

#line 161 "./bin/yy.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_YY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "./bin/yy.tab.c" /* yacc.c:358  */

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
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   268

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
      19,    20,    15,    14,    25,    13,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
      23,    24,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    17,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    47,    50,    51,    54,    55,    56,    57,
      58,    62,    63,    64,    65,    66,    69,    70,    71,    72,
      73,    74,    75,    76,    79,    80,    81,    84,    85,    86,
      87,    88,    89,    90,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   108,   109,   110,
     111,   114,   115,   116,   117,   120,   121,   122,   123,   126,
     127,   128,   129,   132,   137,   138,   139
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "EOI", "AVERAGE", "SUM",
  "PRODUCT", "VARIANCE", "STANDARD_DEVIATION", "MIN", "MAX", "IF", "'-'",
  "'+'", "'*'", "'/'", "'^'", "unary_minus", "'('", "')'", "';'", "'>'",
  "'<'", "'='", "','", "$accept", "Input", "Line", "Expr", "Test",
  "Function", "AVERAGE_List", "PRODUCT_List", "MIN_List", "MAX_List",
  "VARIANCE_List", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    45,    43,    42,    47,    94,   268,    40,
      41,    59,    62,    60,    61,    44
};
# endif

#define YYPACT_NINF -19

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-19)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,   158,   -19,   -19,   -19,   -19,   -18,   -17,   -15,   -14,
      -8,    30,    32,    35,   189,   204,   -19,   394,   -19,   219,
     234,   249,   264,   279,   294,   309,   189,   -19,     1,   171,
     -19,   324,   339,   354,   369,   384,   -19,    25,     2,   -19,
      42,    27,   -19,    84,    28,   -19,   101,    43,   -19,    45,
     -19,   118,    83,   -19,   135,    85,    -7,    -9,   -19,   -19,
     -19,   -19,    20,   -19,    20,   -19,    44,   -19,    44,   -19,
      44,   -19,   -19,   -19,   189,   -19,   -19,   -19,   -19,   -19,
     189,   -19,   -19,   -19,   189,   -19,   -19,   -19,   -19,   189,
     -19,   -19,   -19,   189,   189,   189,   189,   189,   165,   165,
     165,   165,   165,   165,   165,   165,    61,   189,   399,   -19
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    46,     6,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    16,     0,
       5,     0,     0,     0,     0,     0,    34,     0,     0,    35,
       0,     0,    36,     0,     0,    39,     0,     0,    40,     0,
      37,     0,     0,    38,     0,     0,     0,     0,    17,    18,
      13,    20,     7,    19,     8,    21,     9,    22,    10,    23,
      11,    41,    49,    27,     0,    42,    28,    43,    53,    29,
       0,    66,    65,    32,     0,    33,    44,    57,    30,     0,
      45,    61,    31,     0,     0,     0,     0,     0,    47,    51,
      63,    55,    59,    24,    25,    26,     0,     0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,   -19,    -1,   -19,   -19,    40,   -19,   -19,   -19,
      41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    16,    46,    57,    18,    38,    44,    52,    55,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    19,    20,    72,    21,    22,    31,    32,    33,    34,
      35,    23,    97,    27,    29,    94,    95,    96,    37,    40,
      43,    58,    73,    51,    54,    56,    71,    74,    72,    78,
      62,    64,    66,    68,    70,    33,    34,    35,    31,    32,
      33,    34,    35,    75,    82,   -48,    82,    76,    79,    24,
     -48,    25,    74,    80,    26,    31,    32,    33,    34,    35,
      41,    35,   -48,    83,    49,    85,     0,   -48,    84,     0,
      84,     0,     0,    98,    31,    32,    33,    34,    35,    99,
       0,     0,   107,   100,    87,    77,    91,     0,   101,     0,
       0,     0,   102,   103,   104,   105,   106,    31,    32,    33,
      34,    35,    81,    88,   -52,    92,   108,     0,    89,   -52,
      93,     0,     0,     0,    31,    32,    33,    34,    35,    86,
       0,   -64,     0,     0,     0,     0,   -64,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    90,     0,   -56,     0,
       0,     0,     0,   -56,     0,     0,     0,     0,    31,    32,
      33,    34,    35,     0,     0,   -60,     0,     0,     2,     3,
     -60,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    59,     0,     0,     0,     0,    15,    31,    32,
      33,    34,    35,     0,    31,    32,    33,    34,    35,     0,
       3,    60,     4,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    28,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      36,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    39,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      42,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    45,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      48,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    50,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      53,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    61,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      63,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    65,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      67,     0,     4,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    69,     0,     4,    15,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    30,     0,
       0,     0,     0,    15,     0,     0,     0,    31,    32,    33,
      34,    35,    31,    32,    33,    34,    35,     0,     0,   109
};

static const yytype_int8 yycheck[] =
{
       1,    19,    19,     1,    19,    19,    13,    14,    15,    16,
      17,    19,    21,    14,    15,    22,    23,    24,    19,    20,
      21,    20,    20,    24,    25,    26,     1,    25,     1,     1,
      31,    32,    33,    34,    35,    15,    16,    17,    13,    14,
      15,    16,    17,     1,     1,    20,     1,    20,    20,    19,
      25,    19,    25,    25,    19,    13,    14,    15,    16,    17,
      20,    17,    20,    20,    23,    20,    -1,    25,    25,    -1,
      25,    -1,    -1,    74,    13,    14,    15,    16,    17,    80,
      -1,    -1,    21,    84,     1,     1,     1,    -1,    89,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    13,    14,    15,
      16,    17,     1,    20,    20,    20,   107,    -1,    25,    25,
      25,    -1,    -1,    -1,    13,    14,    15,    16,    17,     1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,     1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    20,    -1,    -1,     0,     1,
      25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     1,    -1,    -1,    -1,    -1,    19,    13,    14,
      15,    16,    17,    -1,    13,    14,    15,    16,    17,    -1,
       1,    20,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       1,    -1,     3,    19,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     1,    -1,     3,    19,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     4,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    13,    14,    15,    16,    17,    -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    19,    28,    29,    31,    19,
      19,    19,    19,    19,    19,    19,    19,    29,     1,    29,
       4,    13,    14,    15,    16,    17,     1,    29,    32,     1,
      29,    32,     1,    29,    33,     1,    29,    36,     1,    36,
       1,    29,    34,     1,    29,    35,    29,    30,    20,     1,
      20,     1,    29,     1,    29,     1,    29,     1,    29,     1,
      29,     1,     1,    20,    25,     1,    20,     1,     1,    20,
      25,     1,     1,    20,    25,    20,     1,     1,    20,    25,
       1,     1,    20,    25,    22,    23,    24,    21,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    21,    29,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    28,    28,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    30,    30,    30,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    32,    32,    32,
      32,    33,    33,    33,    33,    34,    34,    34,    34,    35,
      35,    35,    35,    36,    36,    36,    36
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     3,     3,     3,
       3,     3,     2,     3,     1,     8,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     1,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     2,     2,     3,
       1,     2,     2,     3,     1,     2,     2
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
#line 47 "./src/yacc.y" /* yacc.c:1646  */
    { cursor = 0;}
#line 1380 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "./src/yacc.y" /* yacc.c:1646  */
    { printf("%lf \n", (yyvsp[-1].number));}
#line 1386 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 54 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[0].number); }
#line 1392 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) - (yyvsp[0].number); }
#line 1398 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 1404 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 57 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * (yyvsp[0].number); }
#line 1410 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 58 "./src/yacc.y" /* yacc.c:1646  */
    { 
       if((yyvsp[0].number) == 0) yyerror("division by zero");
       (yyval.number) = (yyvsp[-2].number) / (yyvsp[0].number);
    }
#line 1419 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = pow((yyvsp[-2].number), (yyvsp[0].number)); }
#line 1425 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = -(yyvsp[0].number); }
#line 1431 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number); }
#line 1437 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 65 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number)  = (yyvsp[0].number) ; }
#line 1443 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 66 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-5].number) ? (yyvsp[-3].number) : (yyvsp[-1].number); }
#line 1449 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 69 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1455 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 70 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1461 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 71 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(CLOSING_PARENTHESIS_EXPECTED); }
#line 1467 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1473 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1479 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 74 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1485 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 75 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1491 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 76 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(EXPRESSION_EXPECTED); }
#line 1497 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 79 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) > (yyvsp[0].number); }
#line 1503 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 80 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) < (yyvsp[0].number); }
#line 1509 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 81 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) == (yyvsp[0].number); }
#line 1515 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "./src/yacc.y" /* yacc.c:1646  */
    {  (yyval.number) = (yyvsp[-1].list).value / (yyvsp[-1].list).size; }
#line 1521 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 85 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].list).value; }
#line 1527 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 86 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].list).value; }
#line 1533 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 87 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].list).value; }
#line 1539 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 88 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].list).value; }
#line 1545 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 89 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = ((yyvsp[-1].list).sqr_value / (yyvsp[-1].list).size) - pow((yyvsp[-1].list).value / (yyvsp[-1].list).size,2); }
#line 1551 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 90 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.number) = sqrt(((yyvsp[-1].list).sqr_value / (yyvsp[-1].list).size) - pow((yyvsp[-1].list).value / (yyvsp[-1].list).size,2)); }
#line 1557 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 93 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1563 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1569 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1575 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1581 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1587 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 98 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1593 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 99 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_PARAMS_EXPECTED); }
#line 1599 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 100 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1605 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 101 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1611 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 102 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1617 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 103 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1623 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 104 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1629 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 105 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(FUNCTION_OPENING_PARENTHESIS_EXPECTED); }
#line 1635 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 108 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[-2].list).value + (yyvsp[0].number); (yyval.list).size = (yyvsp[-2].list).size + 1; }
#line 1641 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 109 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[0].number); (yyval.list).size = 1; }
#line 1647 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 110 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1653 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 111 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1659 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 114 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[-2].list).value * (yyvsp[0].number); }
#line 1665 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 115 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[0].number); }
#line 1671 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 116 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1677 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 117 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1683 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 120 "./src/yacc.y" /* yacc.c:1646  */
    { if ( (yyvsp[0].number) < (yyvsp[-2].list).value) (yyval.list).value = (yyvsp[0].number); }
#line 1689 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 121 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[0].number); }
#line 1695 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 122 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1701 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 123 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1707 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 126 "./src/yacc.y" /* yacc.c:1646  */
    { if ( (yyvsp[0].number) > (yyvsp[-2].list).value) (yyval.list).value = (yyvsp[0].number); }
#line 1713 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 127 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[0].number); }
#line 1719 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 128 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1725 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 129 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1731 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 132 "./src/yacc.y" /* yacc.c:1646  */
    { 
                (yyval.list).value = (yyvsp[-2].list).value + (yyvsp[0].number); 
                (yyval.list).sqr_value = (yyvsp[-2].list).sqr_value + pow((yyvsp[0].number),2);
                (yyval.list).size = (yyvsp[-2].list).size + 1; 
             }
#line 1741 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 137 "./src/yacc.y" /* yacc.c:1646  */
    { (yyval.list).value = (yyvsp[0].number); (yyval.list).sqr_value = pow((yyvsp[0].number),2); (yyval.list).size = 1; }
#line 1747 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 138 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1753 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 139 "./src/yacc.y" /* yacc.c:1646  */
    { yyerror(COMMA_EXPECTED); }
#line 1759 "./bin/yy.tab.c" /* yacc.c:1646  */
    break;


#line 1763 "./bin/yy.tab.c" /* yacc.c:1646  */
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
#line 142 "./src/yacc.y" /* yacc.c:1906  */

int main(int nbInputs,char **inputs){
    extern FILE *yyin;
    
    if(nbInputs == 2 && (strcmp(inputs[1], "-h") || strcmp(inputs[1], "--help"))){
        help();
        exit(0);
    }

    if(nbInputs == 3 && strcmp(inputs[2], "-f")){
        yyin = NULL;
        yyin = fopen(inputs[2],"r");
        if(yyin) fileIsOpen = 1;
        else {
            printf("Error: unable to open file or file does not existe!\n");
            exit(0);
        }
    }
    yyparse();
    if(fileIsOpen) fclose(yyin);
    return 0;
}

int yyerror(char *s) {
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
