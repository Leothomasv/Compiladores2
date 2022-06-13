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
#line 5 "minic.y"

    #include <cstdio>
    #include "asm.h"
    #include <fstream>
    #include <iostream>
    using namespace std;
    int yylex();
    extern int yylineno;

    #define EQUAL 1
    #define PLUSEQUAL 2
    #define MINUSEQUAL 3

    Asm assemblyResultFile;
    void yyerror(const char * s){
        fprintf(stderr, "Line %d, error: %s\n", yylineno, s);
    }

    void writeFile(string name){
        ofstream file;
        file.open(name);
        file << assemblyResultFile.data <<endl
        << assemblyResultFile.global<<endl
        << assemblyResultFile.text<< endl;
        file.close();
    }

#line 99 "minic_parser.cpp"

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

#include "tokens.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ID = 3,                      /* TK_ID  */
  YYSYMBOL_TK_LIT_STRING = 4,              /* TK_LIT_STRING  */
  YYSYMBOL_TK_LIT_INT = 5,                 /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 6,               /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_IF = 7,                      /* TK_IF  */
  YYSYMBOL_TK_WHILE = 8,                   /* TK_WHILE  */
  YYSYMBOL_TK_VOID = 9,                    /* TK_VOID  */
  YYSYMBOL_TK_INT_TYPE = 10,               /* TK_INT_TYPE  */
  YYSYMBOL_TK_FLOAT_TYPE = 11,             /* TK_FLOAT_TYPE  */
  YYSYMBOL_TK_PRINTF = 12,                 /* TK_PRINTF  */
  YYSYMBOL_TK_GTE = 13,                    /* TK_GTE  */
  YYSYMBOL_TK_LTE = 14,                    /* TK_LTE  */
  YYSYMBOL_TK_PLUS_EQUAL = 15,             /* TK_PLUS_EQUAL  */
  YYSYMBOL_TK_LESS_EQUAL = 16,             /* TK_LESS_EQUAL  */
  YYSYMBOL_TK_OR = 17,                     /* TK_OR  */
  YYSYMBOL_TK_AND = 18,                    /* TK_AND  */
  YYSYMBOL_TK_EQUALS = 19,                 /* TK_EQUALS  */
  YYSYMBOL_TK_NOT_EQUAL = 20,              /* TK_NOT_EQUAL  */
  YYSYMBOL_TK_RETURN = 21,                 /* TK_RETURN  */
  YYSYMBOL_22_ = 22,                       /* ')'  */
  YYSYMBOL_TK_ELSE = 23,                   /* TK_ELSE  */
  YYSYMBOL_24_ = 24,                       /* ';'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_start = 40,                     /* start  */
  YYSYMBOL_input = 41,                     /* input  */
  YYSYMBOL_external_declaration = 42,      /* external_declaration  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_init_declarator_list = 44,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 45,           /* init_declarator  */
  YYSYMBOL_initializer = 46,               /* initializer  */
  YYSYMBOL_initializer_list = 47,          /* initializer_list  */
  YYSYMBOL_method_definition = 48,         /* method_definition  */
  YYSYMBOL_type = 49,                      /* type  */
  YYSYMBOL_parameter_type_list = 50,       /* parameter_type_list  */
  YYSYMBOL_parameter_declaration = 51,     /* parameter_declaration  */
  YYSYMBOL_declarator = 52,                /* declarator  */
  YYSYMBOL_block_statement = 53,           /* block_statement  */
  YYSYMBOL_declaration_list = 54,          /* declaration_list  */
  YYSYMBOL_statement_list = 55,            /* statement_list  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_while_statement = 57,           /* while_statement  */
  YYSYMBOL_expression_statement = 58,      /* expression_statement  */
  YYSYMBOL_if_statement = 59,              /* if_statement  */
  YYSYMBOL_jump_statement = 60,            /* jump_statement  */
  YYSYMBOL_assignment_expression = 61,     /* assignment_expression  */
  YYSYMBOL_assignment_operator = 62,       /* assignment_operator  */
  YYSYMBOL_logical_or_expression = 63,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 64,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 65,       /* equality_expression  */
  YYSYMBOL_relational_expression = 66,     /* relational_expression  */
  YYSYMBOL_additive_expression = 67,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 68, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 69,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 70,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 71,  /* argument_expression_list  */
  YYSYMBOL_primary_expression = 72,        /* primary_expression  */
  YYSYMBOL_constant = 73                   /* constant  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,    38,     2,     2,     2,     2,     2,     2,
      29,    22,    36,    34,    25,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      33,    26,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    98,    99,   102,   103,   106,   109,   110,
     113,   114,   117,   118,   121,   122,   125,   126,   129,   130,
     131,   134,   135,   138,   141,   142,   143,   146,   147,   150,
     151,   154,   155,   158,   159,   160,   161,   162,   163,   166,
     169,   172,   173,   176,   177,   180,   190,   194,   195,   196,
     200,   201,   204,   205,   208,   209,   210,   213,   214,   215,
     216,   217,   220,   221,   222,   225,   226,   227,   230,   231,
     234,   235,   236,   237,   240,   241,   244,   245,   246,   247,
     250,   251
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_ID",
  "TK_LIT_STRING", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_IF", "TK_WHILE",
  "TK_VOID", "TK_INT_TYPE", "TK_FLOAT_TYPE", "TK_PRINTF", "TK_GTE",
  "TK_LTE", "TK_PLUS_EQUAL", "TK_LESS_EQUAL", "TK_OR", "TK_AND",
  "TK_EQUALS", "TK_NOT_EQUAL", "TK_RETURN", "')'", "TK_ELSE", "';'", "','",
  "'='", "'{'", "'}'", "'('", "'['", "']'", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'!'", "$accept", "start", "input", "external_declaration",
  "declaration", "init_declarator_list", "init_declarator", "initializer",
  "initializer_list", "method_definition", "type", "parameter_type_list",
  "parameter_declaration", "declarator", "block_statement",
  "declaration_list", "statement_list", "statement", "while_statement",
  "expression_statement", "if_statement", "jump_statement",
  "assignment_expression", "assignment_operator", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "argument_expression_list", "primary_expression",
  "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -77,   -77,   -77,    13,    66,   -77,   -77,   -77,    36,
     -77,   -77,    20,    92,   -77,    15,    56,    14,   -77,    44,
      19,    26,    44,   -15,   -77,   -77,   -77,   -77,   -77,    67,
     -77,    67,    31,    -1,    50,    83,    47,    86,    93,    78,
     103,   -77,   -77,    51,   -77,    67,   -77,   -77,    80,   -77,
     -77,    26,    66,    73,   -77,   -77,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,   -77,   -77,
     -77,    67,   156,    67,   -20,    -1,   -77,    71,    77,   110,
     166,   -77,    44,   -77,    80,   107,   -77,   -77,   -77,   -77,
     -77,   139,   -77,   -77,   -77,    50,    83,    47,    47,    86,
      86,    86,    86,    93,    93,   -77,   -77,   -77,   -77,   -77,
     -11,   133,    67,   -77,    67,    67,    67,   -77,   141,   -77,
     119,   -77,   -77,   -77,   -77,    67,   -77,    -1,   144,   152,
     154,   -77,   -77,   -77,   146,   146,   153,   145,   -77,   -77,
     146,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,     0,     2,     4,     6,     5,     0,
       1,     3,    24,     0,     9,    10,     0,     0,     7,     0,
       0,     0,     0,     0,    22,    77,    79,    80,    81,     0,
      26,     0,     0,    46,    51,    53,    56,    61,    64,    67,
      69,    73,    78,    24,     8,     0,    11,    12,     0,    17,
      23,     0,     0,     0,    68,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      47,     0,     0,     0,     0,    15,    67,     0,     0,     0,
       0,    30,     0,    36,     0,     0,    32,    33,    34,    35,
      38,     0,    16,    21,    76,    50,    52,    54,    55,    59,
      60,    57,    58,    62,    63,    65,    66,    45,    71,    75,
       0,     0,     0,    13,     0,     0,     0,    43,     0,    29,
       0,    28,    31,    40,    72,     0,    70,    14,     0,     0,
       0,    44,    27,    74,     0,     0,     0,    41,    39,    37,
       0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   174,   -44,   -77,   161,   -77,   -77,   -77,
     -10,   -77,   129,   160,     0,   -77,    99,   -76,   -77,   -77,
     -77,   -77,   -17,   -77,   -43,   130,   131,    79,    81,    91,
     -30,   -77,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    13,    14,    46,    74,     8,
       9,    23,    24,    15,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    71,    33,    34,    35,    36,    37,    38,
      39,    40,   110,    41,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    54,    75,    47,    81,   112,    22,    51,   113,   122,
      52,   124,    53,    10,   125,    76,    56,    25,    26,    27,
      28,    49,    25,    26,    27,    28,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,   105,   106,    82,    12,
     119,    20,    22,    29,   122,    30,    45,    43,    29,    16,
      17,    92,    31,    48,   107,   109,   111,    31,   137,   138,
      60,    61,    55,   118,   141,     1,     2,     3,    57,   127,
      25,    26,    27,    28,    82,     1,     2,     3,    21,    62,
      63,    17,    76,    25,    26,    27,    28,    77,    78,     1,
       2,     3,    79,    68,    69,    94,    29,   128,   129,   130,
     114,    80,    58,    59,    70,    31,   115,    48,   133,    29,
      25,    26,    27,    28,    77,    78,    18,    19,    31,    79,
      64,    65,    25,    26,    27,    28,    77,    78,    80,    66,
      67,    79,    72,    73,    48,   121,    29,    97,    98,   116,
      80,    99,   100,   101,   102,    31,    48,   132,    29,    25,
      26,    27,    28,    77,    78,   103,   104,    31,    79,    25,
      26,    27,    28,   123,   126,   131,   134,    80,   140,    25,
      26,    27,    28,    48,   135,    29,   136,   139,   108,    11,
      44,    93,    50,   120,    31,    29,    95,     0,    96,     0,
     117,     0,     0,     0,    31,    29,     0,     0,     0,     0,
       0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      17,    31,    45,    20,    48,    25,    16,    22,    28,    85,
      25,    22,    29,     0,    25,    45,    17,     3,     4,     5,
       6,    21,     3,     4,     5,     6,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    48,     3,
      84,    26,    52,    29,   120,    31,    27,     3,    29,    29,
      30,    51,    38,    27,    71,    72,    73,    38,   134,   135,
      13,    14,    31,    80,   140,     9,    10,    11,    18,   112,
       3,     4,     5,     6,    84,     9,    10,    11,    22,    32,
      33,    30,   112,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    15,    16,    22,    29,   114,   115,   116,
      29,    21,    19,    20,    26,    38,    29,    27,   125,    29,
       3,     4,     5,     6,     7,     8,    24,    25,    38,    12,
      34,    35,     3,     4,     5,     6,     7,     8,    21,    36,
      37,    12,    29,    30,    27,    28,    29,    58,    59,    29,
      21,    60,    61,    62,    63,    38,    27,    28,    29,     3,
       4,     5,     6,     7,     8,    64,    65,    38,    12,     3,
       4,     5,     6,    24,    31,    24,    22,    21,    23,     3,
       4,     5,     6,    27,    22,    29,    22,    24,    22,     5,
      19,    52,    22,    84,    38,    29,    56,    -1,    57,    -1,
      24,    -1,    -1,    -1,    38,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    40,    41,    42,    43,    48,    49,
       0,    42,     3,    44,    45,    52,    29,    30,    24,    25,
      26,    22,    49,    50,    51,     3,     4,     5,     6,    29,
      31,    38,    61,    63,    64,    65,    66,    67,    68,    69,
      70,    72,    73,     3,    45,    27,    46,    61,    27,    53,
      52,    22,    25,    61,    69,    31,    17,    18,    19,    20,
      13,    14,    32,    33,    34,    35,    36,    37,    15,    16,
      26,    62,    29,    30,    47,    63,    69,     7,     8,    12,
      21,    43,    49,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    53,    51,    22,    64,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    61,    22,    61,
      71,    61,    25,    28,    29,    29,    29,    24,    61,    43,
      55,    28,    56,    24,    22,    25,    31,    63,    61,    61,
      61,    24,    28,    61,    22,    22,    22,    56,    56,    24,
      23,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    57,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     3,     3,     1,     6,     5,     1,     1,
       1,     3,     1,     2,     1,     4,     3,     4,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     5,     1,     5,
       2,     5,     7,     2,     3,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     1,
       4,     3,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1
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
  case 2: /* start: input  */
#line 83 "minic.y"
            {
    assemblyResultFile.global = ".global main\n";
    assemblyResultFile.data = ".data \n";
    assemblyResultFile.text = ".text\n";
    list<Statement *>::iterator stmtIt = (yyvsp[0].statement_list_t)->begin();
    string code = "";
    while(stmtIt != (yyvsp[0].statement_list_t)->end()){
        (*stmtIt)->evaluateSemantic();
        code += (*stmtIt)->genCode();
        stmtIt++;
    }
    assemblyResultFile.text += code;
    writeFile("result.asm");
}
#line 1287 "minic_parser.cpp"
    break;

  case 3: /* input: input external_declaration  */
#line 98 "minic.y"
                                  { (yyval.statement_list_t) = (yyvsp[-1].statement_list_t); (yyval.statement_list_t)->push_back((yyvsp[0].statement_t));}
#line 1293 "minic_parser.cpp"
    break;

  case 4: /* input: external_declaration  */
#line 99 "minic.y"
                           {(yyval.statement_list_t) = new StatementList; (yyval.statement_list_t)->push_back((yyvsp[0].statement_t));}
#line 1299 "minic_parser.cpp"
    break;

  case 5: /* external_declaration: method_definition  */
#line 102 "minic.y"
                                        {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1305 "minic_parser.cpp"
    break;

  case 6: /* external_declaration: declaration  */
#line 103 "minic.y"
                          {(yyval.statement_t) = new GlobalDeclaration((yyvsp[0].declaration_t));}
#line 1311 "minic_parser.cpp"
    break;

  case 7: /* declaration: type init_declarator_list ';'  */
#line 106 "minic.y"
                                           {(yyval.declaration_t) = new Declaration((Type)(yyvsp[-2].int_t), *(yyvsp[-1].init_declarator_list_t), yylineno);}
#line 1317 "minic_parser.cpp"
    break;

  case 8: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 109 "minic.y"
                                                               {(yyval.init_declarator_list_t) = (yyvsp[-2].init_declarator_list_t); (yyval.init_declarator_list_t)->push_back((yyvsp[0].init_declarator_t));}
#line 1323 "minic_parser.cpp"
    break;

  case 9: /* init_declarator_list: init_declarator  */
#line 110 "minic.y"
                                      {(yyval.init_declarator_list_t) = new InitDeclaratorList; (yyval.init_declarator_list_t)->push_back((yyvsp[0].init_declarator_t));}
#line 1329 "minic_parser.cpp"
    break;

  case 10: /* init_declarator: declarator  */
#line 113 "minic.y"
                            { (yyval.init_declarator_t) = new InitDeclarator((yyvsp[0].declarator_t), (new InitializerList), yylineno );}
#line 1335 "minic_parser.cpp"
    break;

  case 11: /* init_declarator: declarator '=' initializer  */
#line 114 "minic.y"
                                          { (yyval.init_declarator_t) = new InitDeclarator((yyvsp[-2].declarator_t), (yyvsp[0].initializer_list_t), yylineno );}
#line 1341 "minic_parser.cpp"
    break;

  case 12: /* initializer: assignment_expression  */
#line 117 "minic.y"
                                   { (yyval.initializer_list_t) = new InitializerList; (yyval.initializer_list_t)->push_back((yyvsp[0].expr_t)); }
#line 1347 "minic_parser.cpp"
    break;

  case 13: /* initializer: '{' initializer_list '}'  */
#line 118 "minic.y"
                                      {(yyval.initializer_list_t) = (yyvsp[-1].initializer_list_t);}
#line 1353 "minic_parser.cpp"
    break;

  case 14: /* initializer_list: initializer_list ',' logical_or_expression  */
#line 121 "minic.y"
                                                             { (yyval.initializer_list_t) = (yyvsp[-2].initializer_list_t); (yyval.initializer_list_t)->push_back((yyvsp[0].expr_t));}
#line 1359 "minic_parser.cpp"
    break;

  case 15: /* initializer_list: logical_or_expression  */
#line 122 "minic.y"
                                        { (yyval.initializer_list_t) = new InitializerList; (yyval.initializer_list_t)->push_back((yyvsp[0].expr_t));}
#line 1365 "minic_parser.cpp"
    break;

  case 16: /* method_definition: type TK_ID '(' parameter_type_list ')' block_statement  */
#line 125 "minic.y"
                                                                          { (yyval.statement_t) = new MethodDefinitionStatement((Type)(yyvsp[-5].int_t), (yyvsp[-4].string_t), *(yyvsp[-2].parameter_list_t), (yyvsp[0].statement_t), yylineno);}
#line 1371 "minic_parser.cpp"
    break;

  case 17: /* method_definition: type TK_ID '(' ')' block_statement  */
#line 126 "minic.y"
                                                      { (yyval.statement_t) = new MethodDefinitionStatement((Type)(yyvsp[-4].int_t), (yyvsp[-3].string_t), *(new ParameterList), (yyvsp[0].statement_t), yylineno);}
#line 1377 "minic_parser.cpp"
    break;

  case 18: /* type: TK_VOID  */
#line 129 "minic.y"
              {(yyval.int_t) = VOID;}
#line 1383 "minic_parser.cpp"
    break;

  case 19: /* type: TK_INT_TYPE  */
#line 130 "minic.y"
                  {(yyval.int_t) = INT;}
#line 1389 "minic_parser.cpp"
    break;

  case 20: /* type: TK_FLOAT_TYPE  */
#line 131 "minic.y"
                    {(yyval.int_t) = FLOAT;}
#line 1395 "minic_parser.cpp"
    break;

  case 21: /* parameter_type_list: parameter_type_list ',' parameter_declaration  */
#line 134 "minic.y"
                                                                   {(yyval.parameter_list_t) = (yyvsp[-2].parameter_list_t); (yyval.parameter_list_t)->push_back((yyvsp[0].parameter_t));}
#line 1401 "minic_parser.cpp"
    break;

  case 22: /* parameter_type_list: parameter_declaration  */
#line 135 "minic.y"
                                           { (yyval.parameter_list_t) = new ParameterList; (yyval.parameter_list_t)->push_back((yyvsp[0].parameter_t));}
#line 1407 "minic_parser.cpp"
    break;

  case 23: /* parameter_declaration: type declarator  */
#line 138 "minic.y"
                                       { (yyval.parameter_t) = new Parameter((Type)(yyvsp[-1].int_t), (yyvsp[0].declarator_t), yylineno);}
#line 1413 "minic_parser.cpp"
    break;

  case 24: /* declarator: TK_ID  */
#line 141 "minic.y"
                  { (yyval.declarator_t) = new Declarator((yyvsp[0].string_t), NULL, false, yylineno);}
#line 1419 "minic_parser.cpp"
    break;

  case 25: /* declarator: TK_ID '[' assignment_expression ']'  */
#line 142 "minic.y"
                                                { (yyval.declarator_t) = new Declarator((yyvsp[-3].string_t), (yyvsp[-1].expr_t), true, yylineno);}
#line 1425 "minic_parser.cpp"
    break;

  case 26: /* declarator: TK_ID '[' ']'  */
#line 143 "minic.y"
                          { (yyval.declarator_t) = new Declarator((yyvsp[-2].string_t), NULL, true, yylineno);}
#line 1431 "minic_parser.cpp"
    break;

  case 27: /* block_statement: '{' declaration_list statement_list '}'  */
#line 146 "minic.y"
                                                         { (yyval.statement_t) = new BlockStatement(*(yyvsp[-2].declaration_list_t), *(yyvsp[-1].statement_list_t), yylineno); }
#line 1437 "minic_parser.cpp"
    break;

  case 28: /* block_statement: '{' statement_list '}'  */
#line 147 "minic.y"
                                        { (yyval.statement_t) = new BlockStatement(*(new DeclarationList), *(yyvsp[-1].statement_list_t), yylineno); }
#line 1443 "minic_parser.cpp"
    break;

  case 29: /* declaration_list: declaration_list declaration  */
#line 150 "minic.y"
                                               {(yyval.declaration_list_t) = (yyvsp[-1].declaration_list_t); (yyval.declaration_list_t)->push_back((yyvsp[0].declaration_t));}
#line 1449 "minic_parser.cpp"
    break;

  case 30: /* declaration_list: declaration  */
#line 151 "minic.y"
                              {(yyval.declaration_list_t) = new DeclarationList; (yyval.declaration_list_t)->push_back((yyvsp[0].declaration_t));}
#line 1455 "minic_parser.cpp"
    break;

  case 31: /* statement_list: statement_list statement  */
#line 154 "minic.y"
                                         {(yyval.statement_list_t) = (yyvsp[-1].statement_list_t); (yyval.statement_list_t)->push_back((yyvsp[0].statement_t));}
#line 1461 "minic_parser.cpp"
    break;

  case 32: /* statement_list: statement  */
#line 155 "minic.y"
                          {(yyval.statement_list_t) = new StatementList; (yyval.statement_list_t)->push_back((yyvsp[0].statement_t));}
#line 1467 "minic_parser.cpp"
    break;

  case 33: /* statement: while_statement  */
#line 158 "minic.y"
                           { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1473 "minic_parser.cpp"
    break;

  case 34: /* statement: expression_statement  */
#line 159 "minic.y"
                                { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1479 "minic_parser.cpp"
    break;

  case 35: /* statement: if_statement  */
#line 160 "minic.y"
                        { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1485 "minic_parser.cpp"
    break;

  case 36: /* statement: block_statement  */
#line 161 "minic.y"
                           { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1491 "minic_parser.cpp"
    break;

  case 37: /* statement: TK_PRINTF '(' assignment_expression ')' ';'  */
#line 162 "minic.y"
                                                       {(yyval.statement_t) = new PrintStatement((yyvsp[-2].expr_t), yylineno);}
#line 1497 "minic_parser.cpp"
    break;

  case 38: /* statement: jump_statement  */
#line 163 "minic.y"
                          {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1503 "minic_parser.cpp"
    break;

  case 39: /* while_statement: TK_WHILE '(' assignment_expression ')' statement  */
#line 166 "minic.y"
                                                                  { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), yylineno);}
#line 1509 "minic_parser.cpp"
    break;

  case 40: /* expression_statement: assignment_expression ';'  */
#line 169 "minic.y"
                                                {(yyval.statement_t) = new ExprStatement((yyvsp[-1].expr_t), yylineno);}
#line 1515 "minic_parser.cpp"
    break;

  case 41: /* if_statement: TK_IF '(' assignment_expression ')' statement  */
#line 172 "minic.y"
                                                            { (yyval.statement_t) = new IfStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), yylineno); }
#line 1521 "minic_parser.cpp"
    break;

  case 42: /* if_statement: TK_IF '(' assignment_expression ')' statement TK_ELSE statement  */
#line 173 "minic.y"
                                                                              { (yyval.statement_t) = new IfElseStatement((yyvsp[-4].expr_t), (yyvsp[-2].statement_t), (yyvsp[0].statement_t), yylineno); }
#line 1527 "minic_parser.cpp"
    break;

  case 43: /* jump_statement: TK_RETURN ';'  */
#line 176 "minic.y"
                              { (yyval.statement_t) = new ReturnStatement(NULL, yylineno);}
#line 1533 "minic_parser.cpp"
    break;

  case 44: /* jump_statement: TK_RETURN assignment_expression ';'  */
#line 177 "minic.y"
                                                    {(yyval.statement_t) = new ReturnStatement((yyvsp[-1].expr_t), yylineno);}
#line 1539 "minic_parser.cpp"
    break;

  case 45: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 180 "minic.y"
                                                                                 {
    if((yyvsp[-1].int_t) == EQUAL){
        (yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);
    }else if((yyvsp[-1].int_t) == PLUSEQUAL){
        (yyval.expr_t) = new PlusAssignExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);
    }
    else {
        (yyval.expr_t) = new MinusAssignExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);
    }
}
#line 1554 "minic_parser.cpp"
    break;

  case 46: /* assignment_expression: logical_or_expression  */
#line 190 "minic.y"
                                             {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1560 "minic_parser.cpp"
    break;

  case 47: /* assignment_operator: '='  */
#line 194 "minic.y"
                         { (yyval.int_t) = EQUAL; }
#line 1566 "minic_parser.cpp"
    break;

  case 48: /* assignment_operator: TK_PLUS_EQUAL  */
#line 195 "minic.y"
                                  { (yyval.int_t) = PLUSEQUAL; }
#line 1572 "minic_parser.cpp"
    break;

  case 49: /* assignment_operator: TK_LESS_EQUAL  */
#line 196 "minic.y"
                                  { (yyval.int_t) = MINUSEQUAL;}
#line 1578 "minic_parser.cpp"
    break;

  case 50: /* logical_or_expression: logical_or_expression TK_OR logical_and_expression  */
#line 200 "minic.y"
                                                                           {(yyval.expr_t) = new LogicalOrExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1584 "minic_parser.cpp"
    break;

  case 51: /* logical_or_expression: logical_and_expression  */
#line 201 "minic.y"
                                             { (yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1590 "minic_parser.cpp"
    break;

  case 52: /* logical_and_expression: logical_and_expression TK_AND equality_expression  */
#line 204 "minic.y"
                                                                           {(yyval.expr_t) = new LogicalAndExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1596 "minic_parser.cpp"
    break;

  case 53: /* logical_and_expression: equality_expression  */
#line 205 "minic.y"
                                            {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1602 "minic_parser.cpp"
    break;

  case 54: /* equality_expression: equality_expression TK_EQUALS relational_expression  */
#line 208 "minic.y"
                                                                           {(yyval.expr_t) = new EqExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1608 "minic_parser.cpp"
    break;

  case 55: /* equality_expression: equality_expression TK_NOT_EQUAL relational_expression  */
#line 209 "minic.y"
                                                                             {(yyval.expr_t) = new NeqExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1614 "minic_parser.cpp"
    break;

  case 56: /* equality_expression: relational_expression  */
#line 210 "minic.y"
                                           {(yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1620 "minic_parser.cpp"
    break;

  case 57: /* relational_expression: relational_expression '>' additive_expression  */
#line 213 "minic.y"
                                                                     {(yyval.expr_t) = new GtExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1626 "minic_parser.cpp"
    break;

  case 58: /* relational_expression: relational_expression '<' additive_expression  */
#line 214 "minic.y"
                                                                     {(yyval.expr_t) = new LtExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1632 "minic_parser.cpp"
    break;

  case 59: /* relational_expression: relational_expression TK_GTE additive_expression  */
#line 215 "minic.y"
                                                                        {(yyval.expr_t) = new GteExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1638 "minic_parser.cpp"
    break;

  case 60: /* relational_expression: relational_expression TK_LTE additive_expression  */
#line 216 "minic.y"
                                                                        {(yyval.expr_t) = new LteExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1644 "minic_parser.cpp"
    break;

  case 61: /* relational_expression: additive_expression  */
#line 217 "minic.y"
                                           {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1650 "minic_parser.cpp"
    break;

  case 62: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 220 "minic.y"
                                                                       { (yyval.expr_t) = new AddExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1656 "minic_parser.cpp"
    break;

  case 63: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 221 "minic.y"
                                                                       { (yyval.expr_t) = new SubExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1662 "minic_parser.cpp"
    break;

  case 64: /* additive_expression: multiplicative_expression  */
#line 222 "minic.y"
                                               { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1668 "minic_parser.cpp"
    break;

  case 65: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 225 "minic.y"
                                                                          { (yyval.expr_t) = new MultExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno);}
#line 1674 "minic_parser.cpp"
    break;

  case 66: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 226 "minic.y"
                                                                          { (yyval.expr_t) = new DivExpr((yyvsp[-2].expr_t), (yyvsp[0].expr_t), yylineno); }
#line 1680 "minic_parser.cpp"
    break;

  case 67: /* multiplicative_expression: unary_expression  */
#line 227 "minic.y"
                                            {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1686 "minic_parser.cpp"
    break;

  case 68: /* unary_expression: '!' unary_expression  */
#line 230 "minic.y"
                                       { (yyval.expr_t) = new UnaryExpr(1, (yyvsp[0].expr_t)); }
#line 1692 "minic_parser.cpp"
    break;

  case 69: /* unary_expression: postfix_expression  */
#line 231 "minic.y"
                                     { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1698 "minic_parser.cpp"
    break;

  case 70: /* postfix_expression: postfix_expression '[' assignment_expression ']'  */
#line 234 "minic.y"
                                                                     {(yyval.expr_t) = new ArrayExpr((IdExpr *)(yyvsp[-3].expr_t), (yyvsp[-1].expr_t), yylineno );}
#line 1704 "minic_parser.cpp"
    break;

  case 71: /* postfix_expression: postfix_expression '(' ')'  */
#line 235 "minic.y"
                                               { (yyval.expr_t) = new MethodInvocationExpr((IdExpr*)(yyvsp[-2].expr_t), *(new ArgumentList), yylineno); }
#line 1710 "minic_parser.cpp"
    break;

  case 72: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 236 "minic.y"
                                                                        { (yyval.expr_t) = new MethodInvocationExpr((IdExpr*)(yyvsp[-3].expr_t), *(yyvsp[-1].argument_list_t), yylineno);  }
#line 1716 "minic_parser.cpp"
    break;

  case 73: /* postfix_expression: primary_expression  */
#line 237 "minic.y"
                                       { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1722 "minic_parser.cpp"
    break;

  case 74: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 240 "minic.y"
                                                                             { (yyval.argument_list_t) = (yyvsp[-2].argument_list_t); (yyval.argument_list_t)->push_back((yyvsp[0].expr_t));  }
#line 1728 "minic_parser.cpp"
    break;

  case 75: /* argument_expression_list: assignment_expression  */
#line 241 "minic.y"
                                                { (yyval.argument_list_t) = new ArgumentList;  (yyval.argument_list_t)->push_back((yyvsp[0].expr_t)); }
#line 1734 "minic_parser.cpp"
    break;

  case 76: /* primary_expression: '(' assignment_expression ')'  */
#line 244 "minic.y"
                                                  { (yyval.expr_t) = (yyvsp[-1].expr_t); }
#line 1740 "minic_parser.cpp"
    break;

  case 77: /* primary_expression: TK_ID  */
#line 245 "minic.y"
                          { (yyval.expr_t) = new IdExpr((yyvsp[0].string_t), yylineno); }
#line 1746 "minic_parser.cpp"
    break;

  case 78: /* primary_expression: constant  */
#line 246 "minic.y"
                             { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1752 "minic_parser.cpp"
    break;

  case 79: /* primary_expression: TK_LIT_STRING  */
#line 247 "minic.y"
                                  {(yyval.expr_t) = new StringExpr((yyvsp[0].string_t), yylineno);}
#line 1758 "minic_parser.cpp"
    break;

  case 80: /* constant: TK_LIT_INT  */
#line 250 "minic.y"
                     { (yyval.expr_t) = new IntExpr((yyvsp[0].int_t), yylineno);}
#line 1764 "minic_parser.cpp"
    break;

  case 81: /* constant: TK_LIT_FLOAT  */
#line 251 "minic.y"
                       { (yyval.expr_t)= new FloatExpr((yyvsp[0].float_t), yylineno);}
#line 1770 "minic_parser.cpp"
    break;


#line 1774 "minic_parser.cpp"

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

#line 254 "minic.y"
