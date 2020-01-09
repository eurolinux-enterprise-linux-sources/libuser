
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         lu_gdparse
#define yylex           lu_gdlex
#define yyerror         lu_gderror
#define yylval          lu_gdlval
#define yychar          lu_gdchar
#define yydebug         lu_gddebug
#define yynerrs         lu_gdnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "getdate.y"

/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 13 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

/* Since the code of getdate.y is not included in the Emacs executable
   itself, there is no need to #define static in this file.  Even if
   the code were included in the Emacs executable, it probably
   wouldn't do any harm to #undef it here; this will only cause
   problems if we try to write to a static variable, which I don't
   think this code needs to do.  */
#ifdef emacs
# undef static
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)

#include "lib/internal.h"

#define EPOCH		1970
#define HOUR(x)		((x) * 60)

#define MAX_BUFF_LEN    128   /* size of buffer to read the date into */

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    int		value;
} TABLE;


/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;

struct global {
  int	DayOrdinal;
  int	DayNumber;
  int	HaveDate;
  int	HaveDay;
  int	HaveRel;
  int	HaveTime;
  int	HaveZone;
  int	Timezone;
  int	Day;
  int	Hour;
  int	Minutes;
  int	Month;
  int	Seconds;
  int	Year;
  MERIDIAN	Meridian;
  int	RelDay;
  int	RelHour;
  int	RelMinutes;
  int	RelMonth;
  int	RelSeconds;
  int	RelYear;
};

union YYSTYPE;
static int yylex (union YYSTYPE *lvalp, const char **yyInput);
static int yyerror (const char **yyInput, struct global *yy, char *s);
static int yyparse (const char **yyInput, struct global *yy);

#define YYENABLE_NLS 0
#define YYLTYPE_IS_TRIVIAL 0



/* Line 189 of yacc.c  */
#line 174 "lib/getdate.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tAGO = 258,
     tDAY = 259,
     tDAY_UNIT = 260,
     tDAYZONE = 261,
     tDST = 262,
     tHOUR_UNIT = 263,
     tID = 264,
     tMERIDIAN = 265,
     tMINUTE_UNIT = 266,
     tMONTH = 267,
     tMONTH_UNIT = 268,
     tSEC_UNIT = 269,
     tSNUMBER = 270,
     tUNUMBER = 271,
     tYEAR_UNIT = 272,
     tZONE = 273
   };
#endif
/* Tokens.  */
#define tAGO 258
#define tDAY 259
#define tDAY_UNIT 260
#define tDAYZONE 261
#define tDST 262
#define tHOUR_UNIT 263
#define tID 264
#define tMERIDIAN 265
#define tMINUTE_UNIT 266
#define tMONTH 267
#define tMONTH_UNIT 268
#define tSEC_UNIT 269
#define tSNUMBER 270
#define tUNUMBER 271
#define tYEAR_UNIT 272
#define tZONE 273




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 100 "getdate.y"

    int			Number;
    enum _MERIDIAN	Meridian;



/* Line 214 of yacc.c  */
#line 253 "lib/getdate.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 265 "lib/getdate.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   50

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNRULES -- Number of states.  */
#define YYNSTATES  61

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    20,     2,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    22,    27,    32,    39,    46,    48,    50,    53,    55,
      58,    61,    65,    71,    75,    79,    82,    87,    90,    94,
      97,    99,   102,   105,   107,   110,   113,   115,   118,   121,
     123,   126,   129,   131,   134,   137,   139,   142,   145,   147,
     149,   150
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      23,     0,    -1,    -1,    23,    24,    -1,    25,    -1,    26,
      -1,    28,    -1,    27,    -1,    29,    -1,    31,    -1,    16,
      10,    -1,    16,    19,    16,    32,    -1,    16,    19,    16,
      15,    -1,    16,    19,    16,    19,    16,    32,    -1,    16,
      19,    16,    19,    16,    15,    -1,    18,    -1,     6,    -1,
      18,     7,    -1,     4,    -1,     4,    20,    -1,    16,     4,
      -1,    16,    21,    16,    -1,    16,    21,    16,    21,    16,
      -1,    16,    15,    15,    -1,    16,    12,    15,    -1,    12,
      16,    -1,    12,    16,    20,    16,    -1,    16,    12,    -1,
      16,    12,    16,    -1,    30,     3,    -1,    30,    -1,    16,
      17,    -1,    15,    17,    -1,    17,    -1,    16,    13,    -1,
      15,    13,    -1,    13,    -1,    16,     5,    -1,    15,     5,
      -1,     5,    -1,    16,     8,    -1,    15,     8,    -1,     8,
      -1,    16,    11,    -1,    15,    11,    -1,    11,    -1,    16,
      14,    -1,    15,    14,    -1,    14,    -1,    16,    -1,    -1,
      10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   122,   125,   128,   131,   134,   137,
     140,   146,   152,   161,   167,   179,   182,   186,   191,   195,
     199,   205,   209,   227,   233,   239,   243,   248,   252,   259,
     267,   270,   273,   276,   279,   282,   285,   288,   291,   294,
     297,   300,   303,   306,   309,   312,   315,   318,   321,   326,
     360,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAGO", "tDAY", "tDAY_UNIT", "tDAYZONE",
  "tDST", "tHOUR_UNIT", "tID", "tMERIDIAN", "tMINUTE_UNIT", "tMONTH",
  "tMONTH_UNIT", "tSEC_UNIT", "tSNUMBER", "tUNUMBER", "tYEAR_UNIT",
  "tZONE", "':'", "','", "'/'", "$accept", "spec", "item", "time", "zone",
  "day", "date", "rel", "relunit", "number", "o_merid", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    58,
      44,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    22,    23,    23,    24,    24,    24,    24,    24,    24,
      25,    25,    25,    25,    25,    26,    26,    26,    27,    27,
      27,    28,    28,    28,    28,    28,    28,    28,    28,    29,
      29,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    31,
      32,    32
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     6,     6,     1,     1,     2,     1,     2,
       2,     3,     5,     3,     3,     2,     4,     2,     3,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     1,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    18,    39,    16,    42,    45,     0,    36,
      48,     0,    49,    33,    15,     3,     4,     5,     7,     6,
       8,    30,     9,    19,    25,    38,    41,    44,    35,    47,
      32,    20,    37,    40,    10,    43,    27,    34,    46,     0,
      31,     0,     0,    17,    29,     0,    24,    28,    23,    50,
      21,    26,    51,    12,     0,    11,     0,    50,    22,    14,
      13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    15,    16,    17,    18,    19,    20,    21,    22,
      55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -20
static const yytype_int8 yypact[] =
{
     -20,     0,   -20,   -19,   -20,   -20,   -20,   -20,   -13,   -20,
     -20,    30,    15,   -20,    14,   -20,   -20,   -20,   -20,   -20,
     -20,    19,   -20,   -20,     4,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,    -6,   -20,   -20,    16,
     -20,    17,    23,   -20,   -20,    24,   -20,   -20,   -20,    27,
      28,   -20,   -20,   -20,    29,   -20,    32,    -8,   -20,   -20,
     -20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
      -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,    23,    52,    24,     3,     4,     5,    59,     6,    46,
      47,     7,     8,     9,    10,    11,    12,    13,    14,    31,
      32,    43,    44,    33,    45,    34,    35,    36,    37,    38,
      39,    48,    40,    49,    41,    25,    42,    52,    26,    50,
      51,    27,    53,    28,    29,    57,    54,    30,    58,    56,
      60
};

static const yytype_uint8 yycheck[] =
{
       0,    20,    10,    16,     4,     5,     6,    15,     8,    15,
      16,    11,    12,    13,    14,    15,    16,    17,    18,     4,
       5,     7,     3,     8,    20,    10,    11,    12,    13,    14,
      15,    15,    17,    16,    19,     5,    21,    10,     8,    16,
      16,    11,    15,    13,    14,    16,    19,    17,    16,    21,
      57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,     0,     4,     5,     6,     8,    11,    12,    13,
      14,    15,    16,    17,    18,    24,    25,    26,    27,    28,
      29,    30,    31,    20,    16,     5,     8,    11,    13,    14,
      17,     4,     5,     8,    10,    11,    12,    13,    14,    15,
      17,    19,    21,     7,     3,    20,    15,    16,    15,    16,
      16,    16,    10,    15,    19,    32,    21,    16,    16,    15,
      32
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (yyInput, yy, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, yyInput)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, yyInput, yy); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, const char **yyInput, struct global *yy)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyInput, yy)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    const char **yyInput;
    struct global *yy;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yyInput);
  YYUSE (yy);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, const char **yyInput, struct global *yy)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yyInput, yy)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    const char **yyInput;
    struct global *yy;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyInput, yy);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, const char **yyInput, struct global *yy)
#else
static void
yy_reduce_print (yyvsp, yyrule, yyInput, yy)
    YYSTYPE *yyvsp;
    int yyrule;
    const char **yyInput;
    struct global *yy;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , yyInput, yy);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, yyInput, yy); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, const char **yyInput, struct global *yy)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yyInput, yy)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    const char **yyInput;
    struct global *yy;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yyInput);
  YYUSE (yy);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (const char **yyInput, struct global *yy);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (const char **yyInput, struct global *yy)
#else
int
yyparse (yyInput, yy)
    const char **yyInput;
    struct global *yy;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 122 "getdate.y"
    {
	    yy->HaveTime++;
	}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "getdate.y"
    {
	    yy->HaveZone++;
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 128 "getdate.y"
    {
	    yy->HaveDate++;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "getdate.y"
    {
	    yy->HaveDay++;
	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 134 "getdate.y"
    {
	    yy->HaveRel++;
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 140 "getdate.y"
    {
	    yy->Hour = (yyvsp[(1) - (2)].Number);
	    yy->Minutes = 0;
	    yy->Seconds = 0;
	    yy->Meridian = (yyvsp[(2) - (2)].Meridian);
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 146 "getdate.y"
    {
	    yy->Hour = (yyvsp[(1) - (4)].Number);
	    yy->Minutes = (yyvsp[(3) - (4)].Number);
	    yy->Seconds = 0;
	    yy->Meridian = (yyvsp[(4) - (4)].Meridian);
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 152 "getdate.y"
    {
	    yy->Hour = (yyvsp[(1) - (4)].Number);
	    yy->Minutes = (yyvsp[(3) - (4)].Number);
	    yy->Meridian = MER24;
	    yy->HaveZone++;
	    yy->Timezone = ((yyvsp[(4) - (4)].Number) < 0
			  ? -(yyvsp[(4) - (4)].Number) % 100 + (-(yyvsp[(4) - (4)].Number) / 100) * 60
			  : - ((yyvsp[(4) - (4)].Number) % 100 + ((yyvsp[(4) - (4)].Number) / 100) * 60));
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 161 "getdate.y"
    {
	    yy->Hour = (yyvsp[(1) - (6)].Number);
	    yy->Minutes = (yyvsp[(3) - (6)].Number);
	    yy->Seconds = (yyvsp[(5) - (6)].Number);
	    yy->Meridian = (yyvsp[(6) - (6)].Meridian);
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 167 "getdate.y"
    {
	    yy->Hour = (yyvsp[(1) - (6)].Number);
	    yy->Minutes = (yyvsp[(3) - (6)].Number);
	    yy->Seconds = (yyvsp[(5) - (6)].Number);
	    yy->Meridian = MER24;
	    yy->HaveZone++;
	    yy->Timezone = ((yyvsp[(6) - (6)].Number) < 0
			  ? -(yyvsp[(6) - (6)].Number) % 100 + (-(yyvsp[(6) - (6)].Number) / 100) * 60
			  : - ((yyvsp[(6) - (6)].Number) % 100 + ((yyvsp[(6) - (6)].Number) / 100) * 60));
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 179 "getdate.y"
    {
	    yy->Timezone = (yyvsp[(1) - (1)].Number);
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 182 "getdate.y"
    {
	    yy->Timezone = (yyvsp[(1) - (1)].Number) - 60;
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 186 "getdate.y"
    {
	    yy->Timezone = (yyvsp[(1) - (2)].Number) - 60;
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 191 "getdate.y"
    {
	    yy->DayOrdinal = 1;
	    yy->DayNumber = (yyvsp[(1) - (1)].Number);
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 195 "getdate.y"
    {
	    yy->DayOrdinal = 1;
	    yy->DayNumber = (yyvsp[(1) - (2)].Number);
	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 199 "getdate.y"
    {
	    yy->DayOrdinal = (yyvsp[(1) - (2)].Number);
	    yy->DayNumber = (yyvsp[(2) - (2)].Number);
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 205 "getdate.y"
    {
	    yy->Month = (yyvsp[(1) - (3)].Number);
	    yy->Day = (yyvsp[(3) - (3)].Number);
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 209 "getdate.y"
    {
	  /* Interpret as YY->YY/MM/DD if $1 >= 1000, otherwise as MM/DD/YY.
	     The goal in recognizing YY->YY/MM/DD is solely to support legacy
	     machine-generated dates like those in an RCS log listing.  If
	     you want portability, use the ISO 8601 format.  */
	  if ((yyvsp[(1) - (5)].Number) >= 1000)
	    {
	      yy->Year = (yyvsp[(1) - (5)].Number);
	      yy->Month = (yyvsp[(3) - (5)].Number);
	      yy->Day = (yyvsp[(5) - (5)].Number);
	    }
	  else
	    {
	      yy->Month = (yyvsp[(1) - (5)].Number);
	      yy->Day = (yyvsp[(3) - (5)].Number);
	      yy->Year = (yyvsp[(5) - (5)].Number);
	    }
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 227 "getdate.y"
    {
	    /* ISO 8601 format.  yy->yy-mm-dd.  */
	    yy->Year = (yyvsp[(1) - (3)].Number);
	    yy->Month = -(yyvsp[(2) - (3)].Number);
	    yy->Day = -(yyvsp[(3) - (3)].Number);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 233 "getdate.y"
    {
	    /* e.g. 17-JUN-1992.  */
	    yy->Day = (yyvsp[(1) - (3)].Number);
	    yy->Month = (yyvsp[(2) - (3)].Number);
	    yy->Year = -(yyvsp[(3) - (3)].Number);
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 239 "getdate.y"
    {
	    yy->Month = (yyvsp[(1) - (2)].Number);
	    yy->Day = (yyvsp[(2) - (2)].Number);
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 243 "getdate.y"
    {
	    yy->Month = (yyvsp[(1) - (4)].Number);
	    yy->Day = (yyvsp[(2) - (4)].Number);
	    yy->Year = (yyvsp[(4) - (4)].Number);
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 248 "getdate.y"
    {
	    yy->Month = (yyvsp[(2) - (2)].Number);
	    yy->Day = (yyvsp[(1) - (2)].Number);
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 252 "getdate.y"
    {
	    yy->Month = (yyvsp[(2) - (3)].Number);
	    yy->Day = (yyvsp[(1) - (3)].Number);
	    yy->Year = (yyvsp[(3) - (3)].Number);
	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 259 "getdate.y"
    {
	    yy->RelSeconds = -yy->RelSeconds;
	    yy->RelMinutes = -yy->RelMinutes;
	    yy->RelHour = -yy->RelHour;
	    yy->RelDay = -yy->RelDay;
	    yy->RelMonth = -yy->RelMonth;
	    yy->RelYear = -yy->RelYear;
	}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 270 "getdate.y"
    {
	    yy->RelYear += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 273 "getdate.y"
    {
	    yy->RelYear += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 276 "getdate.y"
    {
	    yy->RelYear++;
	}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 279 "getdate.y"
    {
	    yy->RelMonth += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 282 "getdate.y"
    {
	    yy->RelMonth += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 285 "getdate.y"
    {
	    yy->RelMonth++;
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 288 "getdate.y"
    {
	    yy->RelDay += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 291 "getdate.y"
    {
	    yy->RelDay += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 294 "getdate.y"
    {
	    yy->RelDay++;
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 297 "getdate.y"
    {
	    yy->RelHour += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 300 "getdate.y"
    {
	    yy->RelHour += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 303 "getdate.y"
    {
	    yy->RelHour++;
	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 306 "getdate.y"
    {
	    yy->RelMinutes += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 309 "getdate.y"
    {
	    yy->RelMinutes += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 312 "getdate.y"
    {
	    yy->RelMinutes++;
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 315 "getdate.y"
    {
	    yy->RelSeconds += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 318 "getdate.y"
    {
	    yy->RelSeconds += (yyvsp[(1) - (2)].Number) * (yyvsp[(2) - (2)].Number);
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 321 "getdate.y"
    {
	    yy->RelSeconds++;
	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 327 "getdate.y"
    {
	    if (yy->HaveTime && yy->HaveDate && !yy->HaveRel)
	      yy->Year = (yyvsp[(1) - (1)].Number);
	    else
	      {
		if ((yyvsp[(1) - (1)].Number)>10000)
		  {
		    yy->HaveDate++;
		    yy->Day= ((yyvsp[(1) - (1)].Number))%100;
		    yy->Month= ((yyvsp[(1) - (1)].Number)/100)%100;
		    yy->Year = (yyvsp[(1) - (1)].Number)/10000;
		  }
		else
		  {
		    yy->HaveTime++;
		    if ((yyvsp[(1) - (1)].Number) < 100)
		      {
			yy->Hour = (yyvsp[(1) - (1)].Number);
			yy->Minutes = 0;
		      }
		    else
		      {
		    	yy->Hour = (yyvsp[(1) - (1)].Number) / 100;
		    	yy->Minutes = (yyvsp[(1) - (1)].Number) % 100;
		      }
		    yy->Seconds = 0;
		    yy->Meridian = MER24;
		  }
	      }
	  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 360 "getdate.y"
    {
	    (yyval.Meridian) = MER24;
	  }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 364 "getdate.y"
    {
	    (yyval.Meridian) = (yyvsp[(1) - (1)].Meridian);
	  }
    break;



/* Line 1455 of yacc.c  */
#line 2025 "lib/getdate.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (yyInput, yy, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yyInput, yy, yymsg);
	  }
	else
	  {
	    yyerror (yyInput, yy, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval, yyInput, yy);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, yyInput, yy);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyInput, yy, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, yyInput, yy);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yyInput, yy);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 369 "getdate.y"


/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL, 0, 0 }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tYEAR_UNIT,	1 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tDAY_UNIT,	14 },
    { "week",		tDAY_UNIT,	7 },
    { "day",		tDAY_UNIT,	1 },
    { "hour",		tHOUR_UNIT,	1 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL, 0, 0 }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tMINUTE_UNIT,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL, 0, 0 }
};

/* The timezone table. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR ( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR ( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR ( 0) },
    { "wet",	tZONE,     HOUR ( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR ( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR ( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR ( 2) },	/* Azores */
    { "ast",	tZONE,     HOUR ( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR ( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR ( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR ( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR ( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR ( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR ( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR ( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR ( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR ( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR ( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR ( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR (10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR (10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR (10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR (10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR (11) },	/* Nome */
    { "idlw",	tZONE,     HOUR (12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR (1) },	/* Central European */
    { "met",	tZONE,     -HOUR (1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR (1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "mesz",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR (1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR (1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR (1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR (1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR (2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR (3) },	/* Baghdad, USSR Zone 2 */
    { "zp4",	tZONE,     -HOUR (4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR (5) },	/* USSR Zone 4 */
    { "zp6",	tZONE,     -HOUR (6) },	/* USSR Zone 5 */
    { "wast",	tZONE,     -HOUR (7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR (7) },	/* West Australian Daylight */
    { "cct",	tZONE,     -HOUR (8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR (9) },	/* Japan Standard, USSR Zone 8 */
    { "east",	tZONE,     -HOUR (10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR (10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR (10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR (12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR (12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR (12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR (12) },	/* International Date Line East */
    {  NULL, 0, 0  }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tZONE,	HOUR (  1) },
    { "b",	tZONE,	HOUR (  2) },
    { "c",	tZONE,	HOUR (  3) },
    { "d",	tZONE,	HOUR (  4) },
    { "e",	tZONE,	HOUR (  5) },
    { "f",	tZONE,	HOUR (  6) },
    { "g",	tZONE,	HOUR (  7) },
    { "h",	tZONE,	HOUR (  8) },
    { "i",	tZONE,	HOUR (  9) },
    { "k",	tZONE,	HOUR ( 10) },
    { "l",	tZONE,	HOUR ( 11) },
    { "m",	tZONE,	HOUR ( 12) },
    { "n",	tZONE,	HOUR (- 1) },
    { "o",	tZONE,	HOUR (- 2) },
    { "p",	tZONE,	HOUR (- 3) },
    { "q",	tZONE,	HOUR (- 4) },
    { "r",	tZONE,	HOUR (- 5) },
    { "s",	tZONE,	HOUR (- 6) },
    { "t",	tZONE,	HOUR (- 7) },
    { "u",	tZONE,	HOUR (- 8) },
    { "v",	tZONE,	HOUR (- 9) },
    { "w",	tZONE,	HOUR (-10) },
    { "x",	tZONE,	HOUR (-11) },
    { "y",	tZONE,	HOUR (-12) },
    { "z",	tZONE,	HOUR (  0) },
    { NULL, 0, 0 }
};




/* ARGSUSED */
static int
yyerror (const char **yyInput, struct global *yy, char *s)
{
  (void)yyInput;
  (void)yy;
  (void)s;
  return 0;
}

static int
ToHour (int Hours, MERIDIAN Meridian)
{
  switch (Meridian)
    {
    case MER24:
      if (Hours < 0 || Hours > 23)
	return -1;
      return Hours;
    case MERam:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours;
    case MERpm:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours + 12;
    default:
      abort ();
    }
  /* NOTREACHED */
}

static int
ToYear (int Year)
{
  if (Year < 0)
    Year = -Year;

  /* XPG4 suggests that years 00-68 map to 2000-2068, and
     years 69-99 map to 1969-1999.  */
  if (Year < 69)
    Year += 2000;
  else if (Year < 100)
    Year += 1900;

  return Year;
}

static int
LookupWord (YYSTYPE *lvalp, char *buff)
{
  register char *p;
  register char *q;
  register const TABLE *tp;
  int i;
  int abbrev;

  /* Make it lowercase. */
  for (p = buff; *p; p++)
    if (isupper ((unsigned char)*p))
      *p = tolower (*p);

  if (strcmp (buff, "am") == 0 || strcmp (buff, "a.m.") == 0)
    {
      lvalp->Meridian = MERam;
      return tMERIDIAN;
    }
  if (strcmp (buff, "pm") == 0 || strcmp (buff, "p.m.") == 0)
    {
      lvalp->Meridian = MERpm;
      return tMERIDIAN;
    }

  /* See if we have an abbreviation for a month. */
  if (strlen (buff) == 3)
    abbrev = 1;
  else if (strlen (buff) == 4 && buff[3] == '.')
    {
      abbrev = 1;
      buff[3] = '\0';
    }
  else
    abbrev = 0;

  for (tp = MonthDayTable; tp->name; tp++)
    {
      if (abbrev)
	{
	  if (strncmp (buff, tp->name, 3) == 0)
	    {
	      lvalp->Number = tp->value;
	      return tp->type;
	    }
	}
      else if (strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}
    }

  for (tp = TimezoneTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  if (strcmp (buff, "dst") == 0)
    return tDST;

  for (tp = UnitsTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Strip off any plural and try the units table again. */
  i = strlen (buff) - 1;
  if (buff[i] == 's')
    {
      buff[i] = '\0';
      for (tp = UnitsTable; tp->name; tp++)
	if (strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
      buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

  for (tp = OtherTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Military timezones. */
  if (buff[1] == '\0' && isalpha ((unsigned char)*buff))
    {
      for (tp = MilitaryTable; tp->name; tp++)
	if (strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
    }

  /* Drop out any periods and try the timezone table again. */
  for (i = 0, p = q = buff; *q; q++)
    if (*q != '.')
      *p++ = *q;
    else
      i++;
  *p = '\0';
  if (i)
    for (tp = TimezoneTable; tp->name; tp++)
      if (strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}

  return tID;
}

static int
yylex (YYSTYPE *lvalp, const char **yyInput)
{
  register char c;
  register char *p;
  char buff[20];
  int Count;
  int sign;

  for (;;)
    {
      while (isspace ((unsigned char)**yyInput))
	(*yyInput)++;

      if (ISDIGIT (c = **yyInput) || c == '-' || c == '+')
	{
	  if (c == '-' || c == '+')
	    {
	      sign = c == '-' ? -1 : 1;
	      if (!ISDIGIT (*++*yyInput))
		/* skip the '-' sign */
		continue;
	    }
	  else
	    sign = 0;
	  for (lvalp->Number = 0; ISDIGIT (c = *(*yyInput)++);)
	    lvalp->Number = 10 * lvalp->Number + c - '0';
	  (*yyInput)--;
	  if (sign < 0)
	    lvalp->Number = -lvalp->Number;
	  return sign ? tSNUMBER : tUNUMBER;
	}
      if (isalpha ((unsigned char)c))
	{
	  for (p = buff; (c = *(*yyInput)++, isalpha ((unsigned char)c))
		 || c == '.';)
	    if (p < &buff[sizeof buff - 1])
	      *p++ = c;
	  *p = '\0';
	  (*yyInput)--;
	  return LookupWord (lvalp, buff);
	}
      if (c != '(')
	return *(*yyInput)++;
      Count = 0;
      do
	{
	  c = *(*yyInput)++;
	  if (c == '\0')
	    return c;
	  if (c == '(')
	    Count++;
	  else if (c == ')')
	    Count--;
	}
      while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

/* Yield A - B, measured in seconds.  */
static long
difftm (struct tm *a, struct tm *b)
{
  int ay = a->tm_year + (TM_YEAR_ORIGIN - 1);
  int by = b->tm_year + (TM_YEAR_ORIGIN - 1);
  long days = (
  /* difference in day of year */
		a->tm_yday - b->tm_yday
  /* + intervening leap days */
		+ ((ay >> 2) - (by >> 2))
		- (ay / 100 - by / 100)
		+ ((ay / 100 >> 2) - (by / 100 >> 2))
  /* + difference in years * 365 */
		+ (long) (ay - by) * 365
  );
  return (60 * (60 * (24 * days + (a->tm_hour - b->tm_hour))
		+ (a->tm_min - b->tm_min))
	  + (a->tm_sec - b->tm_sec));
}

time_t
lu_get_date (const char *p, const time_t *now)
{
  struct tm tm, tm0, *tmp;
  struct global yy;
  time_t Start;

  Start = now ? *now : time ((time_t *) NULL);
  tmp = localtime (&Start);
  memset (&yy, 0, sizeof(yy));
  yy.Year = tmp->tm_year + TM_YEAR_ORIGIN;
  yy.Month = tmp->tm_mon + 1;
  yy.Day = tmp->tm_mday;
  yy.Hour = tmp->tm_hour;
  yy.Minutes = tmp->tm_min;
  yy.Seconds = tmp->tm_sec;
  yy.Meridian = MER24;
  yy.RelSeconds = 0;
  yy.RelMinutes = 0;
  yy.RelHour = 0;
  yy.RelDay = 0;
  yy.RelMonth = 0;
  yy.RelYear = 0;
  yy.HaveDate = 0;
  yy.HaveDay = 0;
  yy.HaveRel = 0;
  yy.HaveTime = 0;
  yy.HaveZone = 0;

  if (yyparse (&p, &yy)
      || yy.HaveTime > 1 || yy.HaveZone > 1 || yy.HaveDate > 1 || yy.HaveDay > 1)
    return -1;

  tm.tm_year = ToYear (yy.Year) - TM_YEAR_ORIGIN + yy.RelYear;
  tm.tm_mon = yy.Month - 1 + yy.RelMonth;
  tm.tm_mday = yy.Day + yy.RelDay;
  if (yy.HaveTime || (yy.HaveRel && !yy.HaveDate && !yy.HaveDay))
    {
      tm.tm_hour = ToHour (yy.Hour, yy.Meridian);
      if (tm.tm_hour < 0)
	return -1;
      tm.tm_min = yy.Minutes;
      tm.tm_sec = yy.Seconds;
    }
  else
    {
      tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    }
  tm.tm_hour += yy.RelHour;
  tm.tm_min += yy.RelMinutes;
  tm.tm_sec += yy.RelSeconds;
  tm.tm_isdst = -1;
  tm0 = tm;

  Start = mktime (&tm);

  if (Start == (time_t) -1)
    {

      /* Guard against falsely reporting errors near the time_t boundaries
         when parsing times in other time zones.  For example, if the min
         time_t value is 1970-01-01 00:00:00 UTC and we are 8 hours ahead
         of UTC, then the min localtime value is 1970-01-01 08:00:00; if
         we apply mktime to 1970-01-01 00:00:00 we will get an error, so
         we apply mktime to 1970-01-02 08:00:00 instead and adjust the time
         zone by 24 hours to compensate.  This algorithm assumes that
         there is no DST transition within a day of the time_t boundaries.  */
      if (yy.HaveZone)
	{
	  tm = tm0;
	  if (tm.tm_year <= EPOCH - TM_YEAR_ORIGIN)
	    {
	      tm.tm_mday++;
	      yy.Timezone -= 24 * 60;
	    }
	  else
	    {
	      tm.tm_mday--;
	      yy.Timezone += 24 * 60;
	    }
	  Start = mktime (&tm);
	}

      if (Start == (time_t) -1)
	return Start;
    }

  if (yy.HaveDay && !yy.HaveDate)
    {
      tm.tm_mday += ((yy.DayNumber - tm.tm_wday + 7) % 7
		     + 7 * (yy.DayOrdinal - (0 < yy.DayOrdinal)));
      Start = mktime (&tm);
      if (Start == (time_t) -1)
	return Start;
    }

  if (yy.HaveZone)
    {
      long delta = yy.Timezone * 60L + difftm (&tm, gmtime (&Start));
      if ((Start + delta < Start) != (delta < 0))
	return -1;		/* time_t overflow */
      Start += delta;
    }

  return Start;
}

#if	defined (TEST)

/* ARGSUSED */
int
main (ac, av)
     int ac;
     char *av[];
{
  char buff[MAX_BUFF_LEN + 1];
  time_t d;

  (void) printf ("Enter date, or blank line to exit.\n\t> ");
  (void) fflush (stdout);

  buff[MAX_BUFF_LEN] = 0;
  while (fgets (buff, MAX_BUFF_LEN, stdin) && buff[0])
    {
      d = lu_get_date (buff, (time_t *) NULL);
      if (d == -1)
	(void) printf ("Bad format - couldn't convert.\n");
      else
	(void) printf ("%s", ctime (&d));
      (void) printf ("\t> ");
      (void) fflush (stdout);
    }
  exit (0);
  /* NOTREACHED */
}
#endif /* defined (TEST) */

