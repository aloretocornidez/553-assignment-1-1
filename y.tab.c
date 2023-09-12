/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 13 "parser.y"

#include "global.h"
#include "error.h"
#include "syntax-tree.h"
#include "symbol-table.h"

extern int yylex();
extern void yyerror();

/*
 * The function process_syntax_tree() is defined in the file 
 * process_syntax_tree.c.  For each function in the input program, 
 * process_syntax_tree() is called once that function's syntax tree has 
 * been constructed.  The arguments passed to process_syntrax_tree() 
 * are (1) a pointer to the global symbol table entry for the function
 * name; and (2) a pointer to the root of the syntax tree for the function
 * body.
 *
 * Syntax tree processing can be customized by replacing the code for
 * this function.
 */
extern void process_syntax_tree(symtabnode *fn_name, struct treenode *fn_body);

  /*
   * struct treenode *currfnbodyTree is set to point to
   * the syntax tree for the body of the current function
   * at the end of each function.  
   * NOTE: the syntax tree MUST be used before CleanupFnInfo()
   * is called at the end of the function.  After that the
   * symbol table entries for the local variables of the
   * function will go away, leaving dangling pointers from
   * the syntax tree.
   */
struct treenode *currfnbodyTree = NULL;

extern char *id_name, *yytext;
extern int ival;
extern int linenum;
char *fnName;
symtabnode *stptr, *currFun;
int CurrType, EltType, fnRetType;
int CurrScope = Global;
llistptr lptr;
bool is_extern;
int errstate = 0;

#line 117 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    INTCON = 259,
    CHARCON = 260,
    STRINGCON = 261,
    CHAR = 262,
    INT = 263,
    VOID = 264,
    EXTERN = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    FOR = 269,
    RETURN = 270,
    AND = 271,
    OR = 272,
    EQ = 273,
    NEQ = 274,
    LE = 275,
    GE = 276,
    dangling_else = 277
  };
#endif
/* Tokens.  */
#define ID 258
#define INTCON 259
#define CHARCON 260
#define STRINGCON 261
#define CHAR 262
#define INT 263
#define VOID 264
#define EXTERN 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define RETURN 270
#define AND 271
#define OR 272
#define EQ 273
#define NEQ 274
#define LE 275
#define GE 276
#define dangling_else 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "parser.y"

  tnptr tptr;
  llistptr idlistptr;
  char *chptr;
  int nval;

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      31,    32,    28,    26,    30,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      22,    24,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    96,    98,   101,   100,   114,   117,   119,
     128,   128,   129,   133,   145,   146,   150,   151,   155,   156,
     161,   162,   163,   167,   168,   172,   176,   176,   177,   177,
     178,   182,   193,   207,   211,   212,   216,   222,   228,   234,
     258,   259,   260,   261,   262,   270,   271,   271,   275,   276,
     276,   280,   284,   285,   289,   290,   294,   295,   299,   300,
     304,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   355,   379,   401,   412,   438,   464,   475,
     485,   512,   527,   528,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCON", "CHARCON", "STRINGCON",
  "CHAR", "INT", "VOID", "EXTERN", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "AND", "OR", "EQ", "NEQ", "LE", "GE", "'<'", "'>'", "'='", "'!'", "'+'",
  "'-'", "'*'", "'/'", "','", "'('", "')'", "';'", "'{'", "'}'", "'['",
  "']'", "dangling_else", "$accept", "prog", "$@1", "Extern", "SetFnInfo",
  "fprotRest", "$@2", "fprototype", "parm_types",
  "nonempty_parm_type_list", "parm_type_decl", "type", "var_decls",
  "var_decl", "id_list", "$@3", "$@4", "id_decl", "ArraySize", "stmt_list",
  "stmt", "semicolon", "$@5", "comma", "$@6", "compound_stmt",
  "optional_else", "optional_assgt", "optional_expr", "optional_boolexp",
  "assignment", "boolexp", "expr", "fun_call", "proc_call", "variable",
  "expr_list", "Ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    60,    62,    61,    33,    43,    45,    42,    47,
      44,    40,    41,    59,   123,   125,    91,    93,   277
};
# endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -108,   266,  -108,  -108,  -108,  -108,  -108,   200,   137,    24,
      16,  -108,    57,  -108,     0,    22,  -108,  -108,    70,  -108,
    -108,  -108,    84,  -108,    24,  -108,    24,   208,  -108,    63,
     208,  -108,    96,  -108,   102,   101,    25,  -108,    24,  -108,
     117,    73,   200,   119,    92,  -108,  -108,  -108,  -108,  -108,
      91,  -108,  -108,    24,  -108,   128,  -108,   129,  -108,   133,
     134,   136,    93,  -108,     9,   137,   126,   135,     9,  -108,
     139,   139,   145,     1,    92,   208,   228,   228,    24,  -108,
    -108,  -108,    93,   193,   139,   265,  -108,  -108,    30,   138,
      25,  -108,  -108,  -108,  -108,  -108,   174,  -108,    93,   147,
     199,  -108,   149,   228,   187,    33,   242,    52,   139,  -108,
     150,  -108,   155,   258,  -108,    93,    93,    93,    93,   179,
    -108,  -108,   265,   157,  -108,   251,   163,   164,    82,  -108,
    -108,    69,   217,   228,   228,   143,    93,    93,    93,    93,
      93,    93,   143,   228,  -108,  -108,    11,    11,  -108,  -108,
     181,  -108,   189,  -108,    93,  -108,  -108,  -108,  -108,  -108,
    -108,   207,   265,   265,   265,   265,   265,   265,  -108,   139,
      62,  -108,  -108,  -108,   143,  -108,    24,  -108,   190,   143,
    -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     1,    21,    20,    22,     8,     0,     0,     0,
      49,    94,    49,    30,    31,     0,    48,    28,     0,     2,
      26,     9,     0,     9,     0,    50,     0,     0,    33,     0,
       0,    29,    31,    27,    14,     0,    15,    17,     0,    32,
       0,    49,     0,    18,    49,    12,     5,     3,    10,    16,
       0,     4,    24,     0,    19,     0,     9,     0,    44,     0,
       0,     0,    57,    43,     0,     0,     0,     0,     0,    42,
      46,    46,     0,    89,    49,     0,     0,     0,    55,    80,
      81,    82,     0,     0,    46,    56,    76,    77,    89,     0,
      25,    23,     6,    34,    45,    40,     0,    41,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    46,    54,
      89,    71,     0,     0,    39,     0,     0,     0,     0,     0,
      51,    47,    60,     0,    86,    49,     0,     0,     0,    13,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    79,    78,    72,    73,    74,    75,
       0,    83,     0,    88,     0,    87,    91,    90,    70,    68,
      69,    53,    61,    62,    63,    64,    65,    66,    37,    46,
      58,    85,    84,    92,     0,    36,    55,    52,     0,     0,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,    -4,   -23,  -108,  -108,   -21,  -108,
     183,     7,  -108,  -108,   158,  -108,  -108,   121,  -108,    13,
    -107,   -67,  -108,    -7,  -108,  -108,  -108,    51,  -108,  -108,
     -72,   -70,   -24,  -108,  -108,   -53,  -106,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    52,     7,    27,    47,    53,    56,    35,    36,
      37,    38,    55,    66,    12,    26,    24,    13,    29,    67,
      68,    95,    96,    48,    18,    69,   175,   108,    84,   169,
      70,   105,   106,    86,    71,    87,   126,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    15,    72,    17,    97,    20,   109,   107,     8,    40,
      58,    72,    11,   152,     9,    72,    32,   114,    32,    30,
      59,    51,    60,    61,    62,    72,   -49,    11,   161,    42,
      43,    21,    99,   130,   131,   168,    22,   100,    85,   117,
     118,   143,    63,    64,   -35,    57,    16,    73,   173,   133,
     134,   101,    74,    23,   102,    16,    73,    32,   111,   113,
      73,   119,    65,   159,   160,   135,   100,   177,   133,   134,
     110,    25,   180,   170,   122,   125,   128,    89,   133,   134,
     132,    93,    72,    20,   142,   133,   134,    16,    28,    72,
      19,   146,   147,   148,   149,   125,    11,    79,    80,    81,
      39,   158,   176,    16,   109,   -22,    45,    46,   115,   116,
     117,   118,   162,   163,   164,   165,   166,   167,   154,   157,
      82,    72,    16,    72,    83,    45,    72,    73,    54,    58,
     125,    11,    22,    41,    73,     3,     4,     5,    10,    59,
      11,    60,    61,    62,    58,    31,    11,    33,   123,    44,
      11,    79,    80,    81,    59,    50,    60,    61,    62,    91,
      75,    63,    64,   -35,    76,    77,    73,    78,   110,    98,
      92,    73,    94,   120,    82,   121,    63,    64,    83,   124,
     150,   129,    11,    79,    80,    81,   100,   144,   112,   153,
      11,    79,    80,    81,   112,   155,    11,    79,    80,    81,
     127,   156,    11,    79,    80,    81,    82,     3,     4,     5,
      83,   151,   103,   171,    82,     3,     4,    34,   104,   174,
      82,   172,   179,    90,    83,    49,    82,   178,     0,     0,
      83,    11,    79,    80,    81,   136,   137,   138,   139,   140,
     141,     0,     0,   115,   116,   117,   118,     0,     0,   145,
       0,     0,     0,   103,     0,    82,     0,     0,     0,   104,
     136,   137,   138,   139,   140,   141,     2,     0,   115,   116,
     117,   118,     0,     3,     4,     5,     6,   115,   116,   117,
     118,    16,     0,   -93,   115,   116,   117,   118,     0,     0,
     145,   115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
       8,     9,    55,    10,    71,    12,    78,    77,     1,    30,
       1,    64,     3,   119,     7,    68,    24,    84,    26,    23,
      11,    44,    13,    14,    15,    78,     1,     3,   135,    36,
      38,    31,    31,   103,   104,   142,    36,    36,    62,    28,
      29,   108,    33,    34,    35,    53,    30,    55,   154,    16,
      17,    74,    56,    31,    75,    30,    64,    65,    82,    83,
      68,    31,    55,   133,   134,    32,    36,   174,    16,    17,
      78,     1,   179,   143,    98,    99,   100,    64,    16,    17,
     104,    68,   135,    90,    32,    16,    17,    30,     4,   142,
      33,   115,   116,   117,   118,   119,     3,     4,     5,     6,
      37,    32,   169,    30,   176,     3,    33,    34,    26,    27,
      28,    29,   136,   137,   138,   139,   140,   141,   125,    37,
      27,   174,    30,   176,    31,    33,   179,   135,    37,     1,
     154,     3,    36,    32,   142,     7,     8,     9,     1,    11,
       3,    13,    14,    15,     1,    24,     3,    26,     1,    32,
       3,     4,     5,     6,    11,    36,    13,    14,    15,    33,
      31,    33,    34,    35,    31,    31,   174,    31,   176,    24,
      35,   179,    33,    35,    27,     1,    33,    34,    31,    32,
       1,    32,     3,     4,     5,     6,    36,    32,     1,    32,
       3,     4,     5,     6,     1,    32,     3,     4,     5,     6,
       1,    37,     3,     4,     5,     6,    27,     7,     8,     9,
      31,    32,    25,    32,    27,     7,     8,     9,    31,    12,
      27,    32,    32,    65,    31,    42,    27,   176,    -1,    -1,
      31,     3,     4,     5,     6,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    31,
      18,    19,    20,    21,    22,    23,     0,    -1,    26,    27,
      28,    29,    -1,     7,     8,     9,    10,    26,    27,    28,
      29,    30,    -1,    32,    26,    27,    28,    29,    -1,    -1,
      32,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,     0,     7,     8,     9,    10,    42,    50,    50,
       1,     3,    53,    56,    76,    76,    30,    62,    63,    33,
      62,    31,    36,    31,    55,     1,    54,    43,     4,    57,
      43,    56,    76,    56,     9,    47,    48,    49,    50,    37,
      47,    32,    62,    76,    32,    33,    34,    44,    62,    49,
      36,    44,    41,    45,    37,    51,    46,    76,     1,    11,
      13,    14,    15,    33,    34,    50,    52,    58,    59,    64,
      69,    73,    74,    76,    43,    31,    31,    31,    31,     4,
       5,     6,    27,    31,    67,    71,    72,    74,    76,    58,
      53,    33,    35,    58,    33,    60,    61,    60,    24,    31,
      36,    44,    47,    25,    31,    70,    71,    70,    66,    69,
      76,    71,     1,    71,    60,    26,    27,    28,    29,    31,
      35,     1,    71,     1,    32,    71,    75,     1,    71,    32,
      70,    70,    71,    16,    17,    32,    18,    19,    20,    21,
      22,    23,    32,    60,    32,    32,    71,    71,    71,    71,
       1,    32,    75,    32,    62,    32,    37,    37,    32,    70,
      70,    59,    71,    71,    71,    71,    71,    71,    59,    68,
      70,    32,    32,    75,    12,    65,    60,    59,    66,    32,
      59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    40,    40,    42,    43,
      45,    44,    44,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    52,    54,    53,    55,    53,
      53,    56,    56,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    61,    60,    62,    63,
      62,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     8,     9,     0,    12,     0,     1,     0,
       0,     5,     1,     4,     1,     1,     3,     1,     2,     4,
       1,     1,     1,     3,     0,     2,     0,     4,     0,     4,
       1,     1,     4,     1,     2,     0,     6,     5,     9,     3,
       2,     2,     1,     1,     1,     1,     0,     2,     1,     0,
       2,     3,     2,     0,     1,     0,     1,     0,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     1,     1,     3,     4,     4,     3,     4,     4,     1,
       4,     4,     3,     1,     1
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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
  case 5:
#line 101 "parser.y"
    { currFun = SymTabRecordFunInfo(false);}
#line 1542 "y.tab.c"
    break;

  case 6:
#line 103 "parser.y"
    { 
      currfnbodyTree = AppendReturn((yyvsp[-1].tptr));
      /*
       * At this point, currfnbodyTree points to the syntax tree
       * for the body of the current function.  This can then
       * be traversed for code generation etc.
       */
      process_syntax_tree(currFun, currfnbodyTree);

      CleanupFnInfo(); 
    }
#line 1558 "y.tab.c"
    break;

  case 8:
#line 117 "parser.y"
                { is_extern = true; }
#line 1564 "y.tab.c"
    break;

  case 9:
#line 119 "parser.y"
            { 
	CurrScope = Local; 
	fnRetType = CurrType;
	fnName = id_name;
	lptr = NULL;
  }
#line 1575 "y.tab.c"
    break;

  case 10:
#line 128 "parser.y"
          { SymTabRecordFunInfo(true); }
#line 1581 "y.tab.c"
    break;

  case 12:
#line 129 "parser.y"
        { SymTabRecordFunInfo(true); CleanupFnInfo(); }
#line 1587 "y.tab.c"
    break;

  case 13:
#line 133 "parser.y"
                           { 
    stptr = SymTabLookupAll((yyvsp[-3].chptr));
    if (stptr != NULL) {
      errmsg("%s multiply declared", (yyvsp[-3].chptr));
    }
    else {
      CurrScope = Local;
    }
 }
#line 1601 "y.tab.c"
    break;

  case 14:
#line 145 "parser.y"
         { (yyval.idlistptr) = NULL; }
#line 1607 "y.tab.c"
    break;

  case 15:
#line 146 "parser.y"
                            { (yyval.idlistptr) = (yyvsp[0].idlistptr); }
#line 1613 "y.tab.c"
    break;

  case 16:
#line 150 "parser.y"
                                               { lptr = Attach((yyvsp[-2].idlistptr), (yyvsp[0].idlistptr)); (yyval.idlistptr) = lptr; }
#line 1619 "y.tab.c"
    break;

  case 17:
#line 151 "parser.y"
                   { (yyval.idlistptr) = (yyvsp[0].idlistptr); }
#line 1625 "y.tab.c"
    break;

  case 18:
#line 155 "parser.y"
             { lptr = NewListNode((yyvsp[0].chptr), (yyvsp[-1].nval), false); (yyval.idlistptr) = lptr; }
#line 1631 "y.tab.c"
    break;

  case 19:
#line 156 "parser.y"
                     { lptr = NewListNode((yyvsp[-2].chptr), (yyvsp[-3].nval), true); (yyval.idlistptr) = lptr; }
#line 1637 "y.tab.c"
    break;

  case 20:
#line 161 "parser.y"
         { (yyval.nval) = CurrType = t_Int; }
#line 1643 "y.tab.c"
    break;

  case 21:
#line 162 "parser.y"
          { (yyval.nval) = CurrType = t_Char; }
#line 1649 "y.tab.c"
    break;

  case 22:
#line 163 "parser.y"
          { (yyval.nval) = CurrType = t_None; }
#line 1655 "y.tab.c"
    break;

  case 26:
#line 176 "parser.y"
                  {yyerrok;}
#line 1661 "y.tab.c"
    break;

  case 28:
#line 177 "parser.y"
                {yyerrok;}
#line 1667 "y.tab.c"
    break;

  case 31:
#line 182 "parser.y"
        { 
    if (CurrType == t_None) {
      errmsg("Illegal type [void] for variable %s", id_name);
    }
    else {
      stptr = SymTabInsert(id_name, CurrScope); 
      stptr->type = CurrType;
      stptr->formal = stptr->is_extern = false;
      stptr->elt_type = t_None;
    }
  }
#line 1683 "y.tab.c"
    break;

  case 32:
#line 193 "parser.y"
                          { 
    if (CurrType == t_None) {
      errmsg("Illegal type [void] for variable %s", id_name);
    }
    else {
      stptr = SymTabInsert(id_name, CurrScope);
      stptr->type = t_Array;
      stptr->formal = false;
      stptr->elt_type = CurrType;
      stptr->num_elts = (yyvsp[-1].nval);
    }
  }
#line 1700 "y.tab.c"
    break;

  case 33:
#line 207 "parser.y"
                   { (yyval.nval) = atoi(yytext); }
#line 1706 "y.tab.c"
    break;

  case 34:
#line 211 "parser.y"
                   { (yyval.tptr) = mkListNode((yyvsp[-1].tptr), (yyvsp[0].tptr)); }
#line 1712 "y.tab.c"
    break;

  case 35:
#line 212 "parser.y"
    { (yyval.tptr) = NULL; }
#line 1718 "y.tab.c"
    break;

  case 36:
#line 216 "parser.y"
                                        {
      if ((yyvsp[-3].tptr)->etype != t_Bool && (yyvsp[-3].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(If, t_None, (yyvsp[-3].tptr), (yyvsp[-1].tptr), (yyvsp[0].tptr), NULL);
    }
#line 1729 "y.tab.c"
    break;

  case 37:
#line 222 "parser.y"
                               {
      if ((yyvsp[-2].tptr)->etype != t_Bool && (yyvsp[-2].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(While, t_None, (yyvsp[-2].tptr), (yyvsp[0].tptr), NULL, NULL);
    }
#line 1740 "y.tab.c"
    break;

  case 38:
#line 228 "parser.y"
                                                                                        {
      if ((yyvsp[-4].tptr) != NULL && (yyvsp[-4].tptr)->etype != t_Bool && (yyvsp[-4].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(For, t_None, (yyvsp[-6].tptr), (yyvsp[-4].tptr), (yyvsp[-2].tptr), (yyvsp[0].tptr));
    }
#line 1751 "y.tab.c"
    break;

  case 39:
#line 234 "parser.y"
                                   {
      if (currFun->ret_type != t_None) {
	if ((yyvsp[-1].tptr) == NULL) {
	  errmsg("return with no return value in non-void function");
          (yyval.tptr) = mkErrorNode();
	}
	else if ( !((yyvsp[-1].tptr)->etype == t_Int || (yyvsp[-1].tptr)->etype == t_Char || (yyvsp[-1].tptr)->etype == t_Error) ) {
	  errmsg("illegal return type");
          (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSTNode(Return, (yyvsp[-1].tptr)->etype, (yyvsp[-1].tptr), NULL, NULL, NULL);
	}
      }
      else {
	if ((yyvsp[-1].tptr) != NULL) {    /* there is a return expression  */
	  errmsg("non-void return expression in function with no return value");
          (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSTNode(Return, t_None, NULL, NULL, NULL, NULL);
	}
      }
    }
#line 1780 "y.tab.c"
    break;

  case 40:
#line 258 "parser.y"
                         { (yyval.tptr) = (yyvsp[-1].tptr); }
#line 1786 "y.tab.c"
    break;

  case 41:
#line 259 "parser.y"
                         { (yyval.tptr) = (yyvsp[-1].tptr); }
#line 1792 "y.tab.c"
    break;

  case 42:
#line 260 "parser.y"
                         { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1798 "y.tab.c"
    break;

  case 43:
#line 261 "parser.y"
                         { (yyval.tptr) = NULL; }
#line 1804 "y.tab.c"
    break;

  case 44:
#line 262 "parser.y"
                         { (yyval.tptr) = mkErrorNode(); }
#line 1810 "y.tab.c"
    break;

  case 46:
#line 271 "parser.y"
    {errstate = NOSEMICOLON;}
#line 1816 "y.tab.c"
    break;

  case 49:
#line 276 "parser.y"
    {errstate = NOCOMMA;}
#line 1822 "y.tab.c"
    break;

  case 51:
#line 280 "parser.y"
                      { (yyval.tptr) = (yyvsp[-1].tptr); }
#line 1828 "y.tab.c"
    break;

  case 52:
#line 284 "parser.y"
               { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1834 "y.tab.c"
    break;

  case 53:
#line 285 "parser.y"
    { (yyval.tptr) = NULL; }
#line 1840 "y.tab.c"
    break;

  case 54:
#line 289 "parser.y"
               { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1846 "y.tab.c"
    break;

  case 55:
#line 290 "parser.y"
    { (yyval.tptr) = NULL; }
#line 1852 "y.tab.c"
    break;

  case 56:
#line 294 "parser.y"
          { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1858 "y.tab.c"
    break;

  case 57:
#line 295 "parser.y"
      { (yyval.tptr) = NULL; }
#line 1864 "y.tab.c"
    break;

  case 58:
#line 299 "parser.y"
            { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1870 "y.tab.c"
    break;

  case 59:
#line 300 "parser.y"
    { (yyval.tptr) = NULL; }
#line 1876 "y.tab.c"
    break;

  case 60:
#line 304 "parser.y"
                    {
    if ((yyvsp[-2].tptr)->ntype == Error) {
      (yyval.tptr) = (yyvsp[-2].tptr);
    }
    else if ((yyvsp[0].tptr)->ntype == Error) {
      (yyval.tptr) = (yyvsp[0].tptr);
    }
    else if (!((yyvsp[-2].tptr)->etype == t_Int || (yyvsp[-2].tptr)->etype == t_Char)) {
      errmsg("invalid LHS in assignment");
      (yyval.tptr) = mkErrorNode();
    }
    else if (!((yyvsp[0].tptr)->etype == t_Int || (yyvsp[0].tptr)->etype == t_Char)) {
      errmsg("invalid RHS in assignment");
      (yyval.tptr) = mkErrorNode();
    }
    else {
      (yyval.tptr) = mkExprNode(Assg, t_None, (yyvsp[-2].tptr), (yyvsp[0].tptr));
    }
  }
#line 1900 "y.tab.c"
    break;

  case 61:
#line 326 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Equals, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1906 "y.tab.c"
    break;

  case 62:
#line 327 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Neq, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1912 "y.tab.c"
    break;

  case 63:
#line 328 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Leq, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1918 "y.tab.c"
    break;

  case 64:
#line 329 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Geq, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1924 "y.tab.c"
    break;

  case 65:
#line 330 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Lt, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1930 "y.tab.c"
    break;

  case 66:
#line 331 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Gt, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1936 "y.tab.c"
    break;

  case 67:
#line 332 "parser.y"
                              { (yyval.tptr) = SynTreeUnExp(LogicalNot, (yyvsp[0].tptr)); }
#line 1942 "y.tab.c"
    break;

  case 68:
#line 333 "parser.y"
                         { (yyval.tptr) = SynTreeBinExp(LogicalAnd, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1948 "y.tab.c"
    break;

  case 69:
#line 334 "parser.y"
                         { (yyval.tptr) = SynTreeBinExp(LogicalOr, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1954 "y.tab.c"
    break;

  case 70:
#line 335 "parser.y"
                    { (yyval.tptr) = (yyvsp[-1].tptr); }
#line 1960 "y.tab.c"
    break;

  case 71:
#line 339 "parser.y"
                              { (yyval.tptr) = SynTreeUnExp(UnaryMinus, (yyvsp[0].tptr)); }
#line 1966 "y.tab.c"
    break;

  case 72:
#line 340 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Plus, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1972 "y.tab.c"
    break;

  case 73:
#line 341 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(BinaryMinus, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1978 "y.tab.c"
    break;

  case 74:
#line 342 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Mult, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1984 "y.tab.c"
    break;

  case 75:
#line 343 "parser.y"
                    { (yyval.tptr) = SynTreeBinExp(Div, (yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 1990 "y.tab.c"
    break;

  case 76:
#line 344 "parser.y"
                    { (yyval.tptr) = (yyvsp[0].tptr); }
#line 1996 "y.tab.c"
    break;

  case 77:
#line 345 "parser.y"
                    { (yyval.tptr) = (yyvsp[0].tptr); }
#line 2002 "y.tab.c"
    break;

  case 78:
#line 346 "parser.y"
                    { (yyval.tptr) = (yyvsp[-1].tptr); }
#line 2008 "y.tab.c"
    break;

  case 79:
#line 347 "parser.y"
                    { (yyval.tptr) = mkErrorNode(); }
#line 2014 "y.tab.c"
    break;

  case 80:
#line 348 "parser.y"
         { (yyval.tptr) = mkConstNode(Intcon, t_Int, ival); }
#line 2020 "y.tab.c"
    break;

  case 81:
#line 349 "parser.y"
           { (yyval.tptr) = mkConstNode(Charcon, t_Char, ival); }
#line 2026 "y.tab.c"
    break;

  case 82:
#line 350 "parser.y"
             { yytext[strlen(yytext)-1] = '\0'; /* to remove the trailing " */
               (yyval.tptr) = mkStrNode(strdup(yytext+1)); }
#line 2033 "y.tab.c"
    break;

  case 83:
#line 355 "parser.y"
                  {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[-2].chptr));
      if (stptr == NULL) {
	err_occurred = true;
        errmsg("%s undeclared", (yyvsp[-2].chptr));
      }
      else {
        if (stptr->type != t_Func) {
	  err_occurred = true;
	  errmsg("%s is not a function", (yyvsp[-2].chptr));
        }
        else {
	  err_occurred = !ActualsMatchFormals(stptr, NULL);
        }
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, NULL);
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
#line 2062 "y.tab.c"
    break;

  case 84:
#line 379 "parser.y"
                            {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[-3].chptr));
      if (stptr == NULL) {
	err_occurred = true;
        errmsg("%s undeclared", (yyvsp[-3].chptr));
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[-3].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, (yyvsp[-1].tptr));
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, (yyvsp[-1].tptr));
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
#line 2089 "y.tab.c"
    break;

  case 85:
#line 401 "parser.y"
                         {
      stptr = SymTabLookupAll((yyvsp[-3].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[-3].chptr));
      }

      (yyval.tptr) = mkErrorNode();
    }
#line 2102 "y.tab.c"
    break;

  case 86:
#line 412 "parser.y"
                  {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[-2].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[-2].chptr));
        (yyval.tptr) = mkErrorNode();
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[-2].chptr));
      }
      else if (stptr->ret_type != t_None) {
	err_occurred = true;
	errmsg("non-VOID function %s used in a statement", (yyvsp[-2].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, NULL);
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, NULL);
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
#line 2133 "y.tab.c"
    break;

  case 87:
#line 438 "parser.y"
                             {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[-3].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[-3].chptr));
        (yyval.tptr) = mkErrorNode();
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[-3].chptr));
      }
      else if (stptr->ret_type != t_None) {
	err_occurred = true;
	errmsg("non-VOID function %s used in a statement", (yyvsp[-3].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, (yyvsp[-1].tptr));
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, (yyvsp[-1].tptr));
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
#line 2164 "y.tab.c"
    break;

  case 88:
#line 464 "parser.y"
                        {
    stptr = SymTabLookupAll((yyvsp[-3].chptr));
    if (stptr == NULL) {
      errmsg("undeclared identifier %s", (yyvsp[-3].chptr));
    }

    (yyval.tptr) = mkErrorNode();
  }
#line 2177 "y.tab.c"
    break;

  case 89:
#line 475 "parser.y"
           { 
	stptr = SymTabLookupAll((yyvsp[0].chptr));
	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[0].chptr));
	  (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSymTabRefNode(Var, stptr->type, stptr, NULL);
	}
    }
#line 2192 "y.tab.c"
    break;

  case 90:
#line 485 "parser.y"
                       {
	bool err_occurred = false;

	stptr = SymTabLookupAll((yyvsp[-3].chptr));

	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[-3].chptr));
	  err_occurred = true;
	}
	else if (stptr->type != t_Array) {
	  errmsg("%s not declared as an array", (yyvsp[-3].chptr));
	  err_occurred = true;
	}
	if ( !((yyvsp[-1].tptr)->etype == t_Int || (yyvsp[-1].tptr)->etype == t_Char) ) {
	  if ((yyvsp[-1].tptr)->etype != t_Error) {
	    errmsg("subscript to array %s must be of type int or char", (yyvsp[-3].chptr));
	    err_occurred = 1;
	  }
	}

	if (err_occurred) {
	  (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSymTabRefNode(ArraySubscript, stptr->elt_type, stptr, (yyvsp[-1].tptr));
	}
    }
#line 2224 "y.tab.c"
    break;

  case 91:
#line 512 "parser.y"
                        {
	stptr = SymTabLookupAll((yyvsp[-3].chptr));

	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[-3].chptr));
	}
	else if (stptr->type != t_Array) {
	  errmsg("%s not declared as an array", (yyvsp[-3].chptr));
	}

	(yyval.tptr) = mkErrorNode();
    }
#line 2241 "y.tab.c"
    break;

  case 92:
#line 527 "parser.y"
                         { (yyval.tptr) = mkListNode((yyvsp[-2].tptr), (yyvsp[0].tptr)); }
#line 2247 "y.tab.c"
    break;

  case 93:
#line 528 "parser.y"
             { (yyval.tptr) = mkListNode((yyvsp[0].tptr), NULL); }
#line 2253 "y.tab.c"
    break;

  case 94:
#line 531 "parser.y"
           { (yyval.chptr) = id_name; }
#line 2259 "y.tab.c"
    break;


#line 2263 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 533 "parser.y"


