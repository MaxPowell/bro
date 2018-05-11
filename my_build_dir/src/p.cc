/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */

// See the file "COPYING" in the main distribution directory for copyright.
#line 71 "parse.y" /* yacc.c:339  */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"
#include "Expr.h"
#include "Stmt.h"
#include "Var.h"
/* #include "analyzer/protocol/dns/DNS.h" */
#include "RE.h"
#include "Scope.h"
#include "Reporter.h"
#include "Brofiler.h"
#include "broxygen/Manager.h"

#include <set>
#include <string>

extern const char* filename;  // Absolute path of file currently being parsed.

YYLTYPE GetCurrentLocation();
extern int yyerror(const char[]);
extern int brolex();

#define YYLLOC_DEFAULT(Current, Rhs, N) \
	(Current) = (Rhs)[(N)];

/*
 * Part of the module facility: while parsing, keep track of which
 * module to put things in.
 */
string current_module = GLOBAL_MODULE_NAME;
bool is_export = false; // true if in an export {} block

/*
 * When parsing an expression for the debugger, where to put the result
 * (obviously not reentrant).
 */
extern Expr* g_curr_debug_expr;
extern bool in_debug;
extern const char* g_curr_debug_error;

#define YYLTYPE yyltype

static int in_hook = 0;
int in_init = 0;
int in_record = 0;
bool resolving_global_ID = false;
bool defining_global_ID = false;
std::vector<int> saved_in_init;

ID* func_id = 0;
EnumType *cur_enum_type = 0;
static ID* cur_decl_type_id = 0;

static void parser_new_enum (void)
	{
	/* Starting a new enum definition. */
	assert(cur_enum_type == NULL);

	if ( cur_decl_type_id )
		cur_enum_type = new EnumType(cur_decl_type_id->Name());
	else
		reporter->FatalError("incorrect syntax for enum type declaration");
	}

static void parser_redef_enum (ID *id)
	{
	/* Redef an enum. id points to the enum to be redefined.
	   Let cur_enum_type point to it. */
	assert(cur_enum_type == NULL);
	if ( ! id->Type() )
		id->Error("unknown identifier");
	else
		{
		cur_enum_type = id->Type()->AsEnumType();
		if ( ! cur_enum_type )
			id->Error("not an enum");
		}
	}

static type_decl_list* copy_type_decl_list(type_decl_list* tdl)
	{
	if ( ! tdl )
		return 0;

	type_decl_list* rval = new type_decl_list();

	loop_over_list(*tdl, i)
		{
		TypeDecl* td = (*tdl)[i];
		rval->append(new TypeDecl(*td));
		}

	return rval;
	}

static attr_list* copy_attr_list(attr_list* al)
	{
	if ( ! al )
		return 0;

	attr_list* rval = new attr_list();

	loop_over_list(*al, i)
		{
		Attr* a = (*al)[i];
		::Ref(a);
		rval->append(a);
		}

	return rval;
	}

static void extend_record(ID* id, type_decl_list* fields, attr_list* attrs)
	{
	set<BroType*> types = BroType::GetAliases(id->Name());

	if ( types.empty() )
		{
		id->Error("failed to redef record: no types found in alias map");
		return;
		}

	for ( set<BroType*>::const_iterator it = types.begin(); it != types.end(); )
		{
		RecordType* add_to = (*it)->AsRecordType();
		const char* error = 0;
		++it;

		if ( it == types.end() )
			error = add_to->AddFields(fields, attrs);
		else
			error = add_to->AddFields(copy_type_decl_list(fields),
			                          copy_attr_list(attrs));

		if ( error )
			{
			id->Error(error);
			break;
			}
		}
	}

static bool expr_is_table_type_name(const Expr* expr)
	{
	if ( expr->Tag() != EXPR_NAME )
		return false;

	BroType* type = expr->Type();

	if ( type->IsTable() )
		return true;

	if ( type->Tag() == TYPE_TYPE )
		return type->AsTypeType()->Type()->IsTable();

	return false;
	}

static bool has_attr(const attr_list* al, attr_tag tag)
	{
	if ( ! al )
		return false;

	for ( int i = 0; i < al->length(); ++i )
		if ( (*al)[i]->Tag() == tag )
			return true;

	return false;
	}

#line 243 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:339  */

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
   by #include "broparse.h".  */
#ifndef YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BROPARSE_H_INCLUDED
# define YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BROPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_ADD = 258,
    TOK_ADD_TO = 259,
    TOK_ADDR = 260,
    TOK_ANY = 261,
    TOK_ATENDIF = 262,
    TOK_ATELSE = 263,
    TOK_ATIF = 264,
    TOK_ATIFDEF = 265,
    TOK_ATIFNDEF = 266,
    TOK_BOOL = 267,
    TOK_BREAK = 268,
    TOK_CASE = 269,
    TOK_OPTION = 270,
    TOK_CONST = 271,
    TOK_CONSTANT = 272,
    TOK_COPY = 273,
    TOK_COUNT = 274,
    TOK_COUNTER = 275,
    TOK_DEFAULT = 276,
    TOK_DELETE = 277,
    TOK_DOUBLE = 278,
    TOK_ELSE = 279,
    TOK_ENUM = 280,
    TOK_EVENT = 281,
    TOK_EXPORT = 282,
    TOK_FALLTHROUGH = 283,
    TOK_FILE = 284,
    TOK_FOR = 285,
    TOK_FUNCTION = 286,
    TOK_GLOBAL = 287,
    TOK_HOOK = 288,
    TOK_ID = 289,
    TOK_IF = 290,
    TOK_INT = 291,
    TOK_INTERVAL = 292,
    TOK_LIST = 293,
    TOK_LOCAL = 294,
    TOK_MODULE = 295,
    TOK_NEXT = 296,
    TOK_OF = 297,
    TOK_OPAQUE = 298,
    TOK_PATTERN = 299,
    TOK_PATTERN_TEXT = 300,
    TOK_PORT = 301,
    TOK_PRINT = 302,
    TOK_RECORD = 303,
    TOK_REDEF = 304,
    TOK_REMOVE_FROM = 305,
    TOK_RETURN = 306,
    TOK_SCHEDULE = 307,
    TOK_SET = 308,
    TOK_STRING = 309,
    TOK_SUBNET = 310,
    TOK_SWITCH = 311,
    TOK_TABLE = 312,
    TOK_TIME = 313,
    TOK_TIMEOUT = 314,
    TOK_TIMER = 315,
    TOK_TYPE = 316,
    TOK_UNION = 317,
    TOK_VECTOR = 318,
    TOK_WHEN = 319,
    TOK_WHILE = 320,
    TOK_ATTR_ADD_FUNC = 321,
    TOK_ATTR_ENCRYPT = 322,
    TOK_ATTR_DEFAULT = 323,
    TOK_ATTR_OPTIONAL = 324,
    TOK_ATTR_REDEF = 325,
    TOK_ATTR_ROTATE_INTERVAL = 326,
    TOK_ATTR_ROTATE_SIZE = 327,
    TOK_ATTR_DEL_FUNC = 328,
    TOK_ATTR_EXPIRE_FUNC = 329,
    TOK_ATTR_EXPIRE_CREATE = 330,
    TOK_ATTR_EXPIRE_READ = 331,
    TOK_ATTR_EXPIRE_WRITE = 332,
    TOK_ATTR_PERSISTENT = 333,
    TOK_ATTR_SYNCHRONIZED = 334,
    TOK_ATTR_RAW_OUTPUT = 335,
    TOK_ATTR_MERGEABLE = 336,
    TOK_ATTR_PRIORITY = 337,
    TOK_ATTR_LOG = 338,
    TOK_ATTR_ERROR_HANDLER = 339,
    TOK_ATTR_TYPE_COLUMN = 340,
    TOK_ATTR_DEPRECATED = 341,
    TOK_DEBUG = 342,
    TOK_NO_TEST = 343,
    TOK_OR = 344,
    TOK_AND = 345,
    TOK_LE = 346,
    TOK_GE = 347,
    TOK_EQ = 348,
    TOK_NE = 349,
    TOK_IN = 350,
    TOK_NOT_IN = 351,
    TOK_INCR = 352,
    TOK_DECR = 353,
    TOK_HAS_FIELD = 354,
    TOK_HAS_ATTR = 355
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 245 "parse.y" /* yacc.c:355  */

	bool b;
	char* str;
	ID* id;
	id_list* id_l;
	init_class ic;
	Val* val;
	RE_Matcher* re;
	Expr* expr;
	EventExpr* event_expr;
	Stmt* stmt;
	ListExpr* list;
	BroType* type;
	RecordType* record;
	FuncType* func_type;
	TypeList* type_l;
	TypeDecl* type_decl;
	type_decl_list* type_decl_l;
	Case* c_case;
	case_list* case_l;
	Attr* attr;
	attr_list* attr_l;
	attr_tag attrtag;

#line 409 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BROPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 440 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1870

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  546

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,     2,     2,   112,   108,     2,     2,
     115,   116,   106,   104,    89,   105,     2,   107,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,   121,
      96,    91,    97,    92,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   113,     2,   114,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   119,    90,   120,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    94,    95,    98,    99,   100,   101,
     102,   103,   109,   110,   117,   118
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   273,   273,   288,   288,   295,   296,   300,   303,   307,
     313,   319,   325,   331,   337,   343,   349,   355,   361,   367,
     373,   379,   385,   391,   397,   403,   409,   415,   421,   427,
     433,   439,   445,   451,   457,   463,   473,   479,   486,   485,
     500,   506,   512,   537,   544,   550,   550,   550,   557,   563,
     570,   576,   569,   618,   618,   627,   633,   635,   641,   690,
     696,   703,   711,   717,   725,   727,   731,   737,   745,   745,
     745,   750,   756,   764,   766,   775,   787,   796,   805,   810,
     815,   820,   825,   830,   835,   840,   845,   850,   855,   860,
     865,   870,   875,   881,   888,   890,   887,   897,   904,   904,
     911,   919,   927,   933,   939,   945,   951,   957,   963,   969,
     989,   991,   999,  1004,  1010,  1021,  1023,  1026,  1030,  1032,
    1034,  1039,  1047,  1053,  1053,  1056,  1062,  1068,  1074,  1081,
    1080,  1088,  1090,  1092,  1087,  1104,  1103,  1112,  1115,  1119,
    1121,  1123,  1125,  1127,  1132,  1139,  1145,  1153,  1163,  1172,
    1162,  1184,  1189,  1198,  1200,  1205,  1208,  1212,  1213,  1214,
    1215,  1219,  1219,  1219,  1222,  1226,  1228,  1230,  1234,  1236,
    1240,  1242,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,
    1266,  1268,  1270,  1272,  1274,  1276,  1278,  1280,  1282,  1284,
    1286,  1288,  1290,  1292,  1297,  1305,  1313,  1321,  1327,  1333,
    1339,  1344,  1349,  1357,  1365,  1373,  1381,  1389,  1397,  1405,
    1413,  1421,  1427,  1436,  1442,  1450,  1458,  1464,  1469,  1476,
    1480,  1501,  1504,  1508,  1511,  1516,  1542,  1547,  1549,  1557,
    1578,  1578,  1583,  1583,  1583,  1588,  1588,  1593,  1629,  1642,
    1645,  1648,  1651,  1654,  1657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ADD", "TOK_ADD_TO", "TOK_ADDR",
  "TOK_ANY", "TOK_ATENDIF", "TOK_ATELSE", "TOK_ATIF", "TOK_ATIFDEF",
  "TOK_ATIFNDEF", "TOK_BOOL", "TOK_BREAK", "TOK_CASE", "TOK_OPTION",
  "TOK_CONST", "TOK_CONSTANT", "TOK_COPY", "TOK_COUNT", "TOK_COUNTER",
  "TOK_DEFAULT", "TOK_DELETE", "TOK_DOUBLE", "TOK_ELSE", "TOK_ENUM",
  "TOK_EVENT", "TOK_EXPORT", "TOK_FALLTHROUGH", "TOK_FILE", "TOK_FOR",
  "TOK_FUNCTION", "TOK_GLOBAL", "TOK_HOOK", "TOK_ID", "TOK_IF", "TOK_INT",
  "TOK_INTERVAL", "TOK_LIST", "TOK_LOCAL", "TOK_MODULE", "TOK_NEXT",
  "TOK_OF", "TOK_OPAQUE", "TOK_PATTERN", "TOK_PATTERN_TEXT", "TOK_PORT",
  "TOK_PRINT", "TOK_RECORD", "TOK_REDEF", "TOK_REMOVE_FROM", "TOK_RETURN",
  "TOK_SCHEDULE", "TOK_SET", "TOK_STRING", "TOK_SUBNET", "TOK_SWITCH",
  "TOK_TABLE", "TOK_TIME", "TOK_TIMEOUT", "TOK_TIMER", "TOK_TYPE",
  "TOK_UNION", "TOK_VECTOR", "TOK_WHEN", "TOK_WHILE", "TOK_ATTR_ADD_FUNC",
  "TOK_ATTR_ENCRYPT", "TOK_ATTR_DEFAULT", "TOK_ATTR_OPTIONAL",
  "TOK_ATTR_REDEF", "TOK_ATTR_ROTATE_INTERVAL", "TOK_ATTR_ROTATE_SIZE",
  "TOK_ATTR_DEL_FUNC", "TOK_ATTR_EXPIRE_FUNC", "TOK_ATTR_EXPIRE_CREATE",
  "TOK_ATTR_EXPIRE_READ", "TOK_ATTR_EXPIRE_WRITE", "TOK_ATTR_PERSISTENT",
  "TOK_ATTR_SYNCHRONIZED", "TOK_ATTR_RAW_OUTPUT", "TOK_ATTR_MERGEABLE",
  "TOK_ATTR_PRIORITY", "TOK_ATTR_LOG", "TOK_ATTR_ERROR_HANDLER",
  "TOK_ATTR_TYPE_COLUMN", "TOK_ATTR_DEPRECATED", "TOK_DEBUG",
  "TOK_NO_TEST", "','", "'|'", "'='", "'?'", "':'", "TOK_OR", "TOK_AND",
  "'<'", "'>'", "TOK_LE", "TOK_GE", "TOK_EQ", "TOK_NE", "TOK_IN",
  "TOK_NOT_IN", "'+'", "'-'", "'*'", "'/'", "'%'", "TOK_INCR", "TOK_DECR",
  "'!'", "'$'", "'['", "']'", "'('", "')'", "TOK_HAS_FIELD",
  "TOK_HAS_ATTR", "'{'", "'}'", "';'", "$accept", "bro", "$@1",
  "decl_list", "opt_expr", "expr", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "expr_list", "opt_expr_list", "pattern", "single_pattern", "$@8",
  "$@9", "enum_body", "enum_body_list", "enum_body_elem", "type", "$@10",
  "$@11", "$@12", "type_list", "type_decl_list", "type_decl",
  "formal_args", "formal_args_decl_list", "formal_args_decl", "decl",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "conditional",
  "func_hdr", "func_body", "$@19", "$@20", "anonymous_function",
  "begin_func", "func_params", "opt_type", "init_class", "opt_init",
  "$@21", "$@22", "init", "opt_attr", "attr_list", "attr", "stmt",
  "stmt_list", "event", "case_list", "case", "for_head", "local_id_list",
  "local_id", "global_id", "$@23", "def_global_id", "$@24", "$@25",
  "event_id", "$@26", "global_or_event_id", "resolve_id", "opt_no_test",
  "opt_no_test_block", "opt_deprecated", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,    44,
     124,    61,    63,    58,   344,   345,    60,    62,   346,   347,
     348,   349,   350,   351,    43,    45,    42,    47,    37,   352,
     353,    33,    36,    91,    93,    40,    41,   354,   355,   123,
     125,    59
};
# endif

#define YYPACT_NINF -468

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-468)))

#define YYTABLE_NINF -165

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-165)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -52,  -468,    57,   237,  1678,  -468,  -468,  -468,   -45,   -29,
     -26,  -468,  -468,  -468,   -24,  -468,  -468,  -468,    73,    25,
    -468,  -468,  -468,  1784,   745,  -468,    -5,    -2,  -468,  -468,
      75,     2,  1678,     4,     6,    10,  1678,  1678,  1678,  -468,
    1678,  1678,  1678,    95,  1593,  1678,  1362,    41,  -468,  -468,
    1678,   100,   123,    67,  -468,    67,    -2,   127,  -468,    -2,
      67,    -2,    42,  -468,  -468,  -468,    67,   127,    71,    76,
      80,    81,  -468,  -468,    85,    87,   103,   107,   113,   115,
     116,  -468,  -468,  -468,  -468,   117,  -468,  -468,   118,  -468,
    -468,   108,  1784,  -468,  1678,    93,    75,  1678,   195,   109,
     120,   124,    75,   110,  1678,  1454,  1678,   134,   139,   150,
    -468,   494,  -468,  -468,   745,  1678,   221,  1784,  -468,  1678,
    -468,   165,  1678,   842,  1678,  -468,  1678,   961,    15,    15,
     212,    15,    15,    15,   -61,  -468,  1362,   -50,   990,  1678,
    1678,  1678,  1678,  1678,  1678,  1678,  1678,  1678,  1678,  1678,
    1678,  1678,  1678,  1678,  1678,  1678,  1678,  1678,   224,  1678,
    -468,   227,   155,  1020,   149,   151,  1717,    12,  -468,    12,
    -468,  -468,  -468,  -468,  -468,    12,  -468,  -468,   262,    -2,
    -468,    12,  -468,  -468,  1678,  1678,  1678,  1678,  1678,  1678,
    1678,  1678,  1678,  1678,  1678,  1678,  -468,  -468,   609,   184,
      67,   724,   158,   153,   184,    -7,  1678,     5,   184,   -66,
     160,   184,   783,   872,  1678,  1678,  -468,  -468,   184,  -468,
    1050,   183,   162,   -63,  -468,  -468,   811,  1678,   -68,   195,
     191,   166,  1678,   167,  -468,  -468,  1678,   190,  1678,  -468,
    -468,  1362,  1362,  1362,  1079,   372,   811,  1719,  1719,  1719,
    1719,  1719,  1719,   203,   203,    62,    62,    15,    15,    15,
    -468,   194,  1109,   -47,  1678,  -468,  -468,  -468,  -468,  -468,
    -468,  -468,  -468,  -468,  -468,  -468,   169,   174,   242,    -2,
     175,  -468,  -468,  -468,   251,   252,  -468,  -468,   176,   186,
    -468,  -468,   187,  -468,  -468,   177,   255,  -468,  -468,  -468,
    -468,  -468,  1728,  -468,  1728,   210,  1728,   185,  -468,   298,
    1728,  1717,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1362,  1362,  -468,   184,  -468,  -468,    12,   184,
    1678,   184,  -468,   215,    75,  1139,    12,  -468,   184,  1678,
    -468,   184,  -468,  1214,  1244,   400,  -468,  -468,  1717,   219,
     221,   221,  1362,  -468,   199,  1784,   189,  -468,   207,  1362,
    -468,  1362,  1678,  1678,  -468,  -468,  -468,   221,  1717,  -468,
     221,  1717,   287,  -468,  1717,  1717,  1717,  1717,  1784,  1565,
    1784,  -468,  1784,  -468,   204,  1784,  1784,   745,  -468,  1728,
    -468,   206,  -468,  1678,   -33,  -468,   745,  1728,  -468,  1273,
    -468,     3,   745,   745,  -468,  1784,  1717,  -468,  -468,  -468,
    -468,  -468,  -468,  1784,  1184,   214,  1362,   213,   297,   216,
    -468,   217,  -468,  -468,  -468,  -468,   -30,   -23,   -60,  -468,
     218,  1678,  1362,  -468,   220,   222,   297,  -468,   223,   225,
     229,  1784,  -468,  1303,    75,   232,   312,  1784,   745,  1678,
     245,  -468,  -468,   281,  -468,  -468,  -468,  1784,  -468,  -468,
    -468,     8,   231,   253,  -468,  -468,  -468,   311,  1717,  -468,
     305,  -468,  -468,   263,   233,  -468,  -468,  -468,   234,  -468,
    -468,  -468,  -468,   235,  -468,  -468,  1678,   745,   236,   296,
      -6,  -468,  1678,  -468,  -468,    -8,  -468,  -468,   297,   267,
     241,  -468,  -468,  1717,  1482,  -468,   244,   311,   184,  1333,
    -468,   184,  1678,  -468,   745,   901,   276,   346,  -468,  1717,
    -468,  -468,  -468,  -468,   246,  -468,  -468,  -468,   931,   745,
     150,  -468,  -468,  1784,  1784,   150,  -468,   247,   248,  -468,
     515,  -468,  -468,   630,  -468,  -468
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     3,     0,   219,     0,     1,   142,   143,     0,     0,
       0,   232,   232,   235,     0,   232,   232,   232,     0,   230,
     230,     5,   138,   169,     2,    59,     0,     0,    53,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     4,    60,    67,    56,
       0,     0,     0,   156,   230,   156,     0,     0,   123,     0,
     156,     0,     0,   230,   235,   230,   156,     0,     0,     0,
     185,     0,   173,   174,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   187,   188,     0,   191,   192,     0,   193,
     137,     0,   168,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
     216,     0,   217,   218,     0,     0,   117,   169,   152,     0,
     229,     0,     0,     0,    65,    45,    65,     0,    15,    14,
       0,    11,    12,    13,     0,    43,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      50,     0,     0,     0,     0,     0,     0,   157,   233,   157,
     145,   237,   236,     6,   144,   157,   146,   122,     0,     0,
     131,   157,   231,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   170,     0,   240,
     156,     0,     0,     0,   240,     0,     0,   156,   240,     0,
       0,   240,     0,     0,     0,     0,   241,   219,   240,   200,
       0,     0,     0,   115,   120,   151,    54,     0,     0,     0,
      64,     0,    65,     0,    61,    69,     0,     0,     0,    42,
       9,    17,    19,    32,     0,    24,    23,    27,    29,    28,
      30,    25,    26,    40,    41,    16,    18,    20,    21,    22,
      36,     0,    63,     0,    65,    55,    66,   139,   140,   141,
      89,    91,    78,    80,    81,    82,     0,     0,   107,     0,
       0,   238,    79,    84,   100,     0,    86,    88,     0,     0,
      85,    90,     0,    83,    87,     0,     0,   155,   109,   159,
     160,   158,   161,   234,   161,     0,   161,     0,   147,     0,
     161,     0,   177,   186,   172,   175,   176,   178,   179,   180,
     181,   182,   189,   190,   219,   240,   239,   203,   157,   240,
      65,   240,   204,     0,     0,     0,   157,   202,   240,     0,
     205,   240,   222,     0,     0,     0,   215,    10,     0,   154,
       0,   116,    33,    44,     0,   169,     0,    49,     0,    37,
      38,    62,     0,     8,    34,    51,    98,   117,     0,   103,
     117,     0,     0,    94,     0,     0,     0,     0,   169,     0,
     169,   124,   169,   129,     0,   169,   169,   149,   207,   161,
     208,     0,   196,     0,     0,   228,     0,   161,   195,     0,
     206,     0,     0,     0,   194,   169,     0,   119,   118,    57,
      48,    46,    70,   169,    31,     0,     7,     0,     0,     0,
     106,     0,   101,   108,   113,   111,     0,     0,     0,   102,
       0,    65,   167,   162,     0,     0,     0,   132,     0,     0,
       0,   169,   220,     0,     0,     0,   197,   169,     0,     0,
       0,   199,   221,   211,   201,   121,   153,   169,    39,    35,
      52,   244,     0,    71,    73,   104,   105,    95,     0,    93,
       0,    97,   126,    64,     0,   163,   127,   125,     0,   113,
     128,   136,   150,     0,   225,   227,     0,     0,     0,   213,
       0,   219,     0,    47,   243,     0,    77,    99,    72,     0,
       0,   112,   110,     0,     0,   165,     0,   133,   240,     0,
     198,   240,     0,   219,   224,     0,   244,     0,    74,     0,
      96,    92,   166,   130,     0,   210,   226,   209,     0,   223,
     242,    75,    76,   169,   169,   242,   219,     0,     0,   219,
       0,   114,   134,     0,   212,   214
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -468,  -468,  -468,   197,     9,    -4,  -468,  -468,  -468,  -468,
    -468,  -468,   -43,  -106,  -468,   205,  -468,  -468,   -65,  -468,
    -125,  -155,  -468,  -468,  -468,  -332,  -105,  -468,  -290,  -468,
    -246,  -468,  -468,  -468,  -468,  -468,  -468,  -468,     1,  -468,
    -110,  -468,  -468,  -468,  -468,   -46,   -41,  -163,  -235,  -468,
    -468,  -468,  -333,  -468,   285,  -111,  -212,   152,  -468,  -468,
    -468,  -468,   -94,    11,  -468,   180,  -468,  -468,   314,  -468,
     313,  -468,  -126,  -467,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     4,     3,   261,   111,   413,   232,   457,   264,
     417,   119,   230,   231,    47,    48,   130,   358,   462,   463,
     464,   425,   424,   500,   418,   426,   467,   501,   222,   223,
     224,    21,   173,   436,   309,   479,   524,   311,   112,    23,
      90,   324,   440,    49,   117,   118,   167,   302,   378,   379,
     475,   433,    91,    92,    93,   113,    24,   203,   401,   452,
     114,   394,   121,    66,    67,    53,    54,   303,    56,    57,
     172,   298,   327,   217,   496
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,   137,   200,   219,    22,   345,   304,   225,   207,   516,
     170,   297,   306,   174,   169,   176,   299,   449,   310,   175,
     233,   238,   410,   238,   450,   181,   350,   333,   123,   468,
     236,    68,   127,   128,   129,     1,   131,   132,   133,   238,
     136,   138,   238,   427,   428,   430,   163,   434,   353,   435,
      63,    64,   438,   439,   116,   338,   444,     5,   351,   468,
     471,   209,   300,   536,   239,   168,   468,   364,   539,   380,
      50,   382,   455,    65,   178,   385,   180,   419,   332,   228,
     421,   445,   337,   238,   469,   340,    51,   513,   237,    52,
     198,   470,   346,   201,   494,    58,   227,   517,   166,   495,
     136,   212,   213,   301,   407,   408,   334,    62,   483,   120,
     115,   220,   387,   116,   488,   226,   263,   122,   136,   124,
     136,   125,   136,   451,   493,   126,   356,   158,   159,   134,
     160,   162,   161,   308,   164,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   441,   262,   386,   165,   365,   328,
     166,   171,   447,   177,   183,   389,   336,   184,   155,   156,
     157,   185,   186,   397,   158,   159,   187,   160,   188,   161,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,    55,   405,   189,    59,    60,    61,   190,   388,
     537,   538,   335,   390,   191,   392,   192,   193,   194,   195,
     343,   344,   398,   420,   199,   400,   422,     6,     7,     8,
       9,    10,   429,   352,   391,    11,    12,   196,   136,   202,
     204,   208,   359,   369,   361,   205,    13,    14,   216,   206,
     395,    15,    16,    17,     6,     7,     8,     9,    10,   214,
      18,   456,    11,    12,   215,   221,   227,   235,   260,    19,
     136,   265,    39,    13,    14,   268,   307,   269,    15,    16,
      17,    20,   326,   330,   331,   339,   348,    18,   349,   514,
     238,   360,   355,   357,   368,   446,    19,   363,   366,   367,
     370,   453,   454,   371,   372,   373,   376,   377,    20,   374,
     375,   529,   384,   458,   383,   411,    22,   153,   154,   155,
     156,   157,   406,   502,   412,   158,   159,   393,   160,   409,
     161,   423,   442,   437,   540,   474,   136,   543,   459,   460,
     381,   461,   465,   466,   486,   399,   487,   489,   491,   472,
     492,   476,   498,   477,   480,   499,   481,   503,   521,   482,
     485,   497,   504,   505,   506,   512,   508,   511,   414,   416,
     519,   520,   494,   532,   533,   523,   534,   266,   541,   542,
     305,   478,   415,   518,   507,   432,   510,   197,   179,   531,
     182,   354,   525,     0,     0,   527,     0,     0,   473,   443,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,   490,     6,     7,     8,
       9,    10,     0,    95,     0,     0,    96,    25,    26,     0,
       0,     0,    97,     0,     0,     0,    98,   136,    99,     0,
     100,    27,     0,    28,    29,   101,     0,     0,     0,   102,
       0,   103,     0,     0,     0,   136,     0,   104,    31,     0,
       0,   105,    32,    33,     0,     0,   106,    34,     0,     0,
       0,     0,     0,    35,   107,   108,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,   509,     0,   158,   159,     0,   160,   515,   161,
      36,     0,     0,     0,     0,     0,     0,     0,   139,     0,
     361,     0,     0,     0,    37,    38,     0,    39,   528,    40,
      41,    42,    43,    44,     0,    45,     0,     0,    94,   109,
     404,   110,     6,     7,     8,     9,    10,     0,    95,     0,
       0,    96,    25,    26,     0,     0,     0,    97,     0,     0,
       0,    98,     0,    99,   140,   100,    27,     0,    28,    29,
     101,     0,     0,     0,   102,     0,   103,     0,     0,     0,
       0,     0,   104,    31,     0,     0,   105,    32,    33,     0,
       0,   106,    34,     0,     0,     0,     0,     0,    35,   107,
     108,     0,     0,     0,     0,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,    36,   158,   159,     0,   160,
       0,   161,     0,   139,     0,   218,     0,     0,     0,    37,
      38,     0,    39,     0,    40,    41,    42,    43,    44,     0,
      45,     0,     0,    94,   109,   544,   110,     6,     7,     8,
       9,    10,     0,    95,     0,     0,    96,    25,    26,     0,
       0,     0,    97,     0,     0,     0,    98,     0,    99,   140,
     100,    27,     0,    28,    29,   101,     0,     0,     0,   102,
       0,   103,     0,     0,     0,     0,     0,   104,    31,     0,
       0,   105,    32,    33,     0,     0,   106,    34,     0,     0,
       0,     0,     0,    35,   107,   108,     0,     0,     0,     0,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
      36,   158,   159,     0,   160,     0,   161,     0,   139,     0,
     325,     0,     0,     0,    37,    38,     0,    39,     0,    40,
      41,    42,    43,    44,     0,    45,     0,     0,    94,   109,
     545,   110,     6,     7,     8,     9,    10,     0,    95,     0,
       0,    96,    25,    26,     0,     0,     0,    97,     0,     0,
       0,    98,     0,    99,   140,   100,    27,     0,    28,    29,
     101,     0,     0,     0,   102,     0,   103,   139,     0,     0,
       0,     0,   104,    31,     0,     0,   105,    32,    33,     0,
       0,   106,    34,     0,     0,     0,     0,     0,    35,   107,
     108,     0,     0,     0,     0,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   140,     0,    36,   158,   159,     0,   160,
       0,   161,     0,     0,     0,   329,   139,     0,     0,    37,
      38,     0,    39,     0,    40,    41,    42,    43,    44,     0,
      45,     0,     0,     0,   109,     0,   110,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   139,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   140,     0,     0,   158,   159,     0,   160,     0,
     161,     0,     0,     0,   341,   139,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,   140,   158,   159,     0,   160,     0,   161,     0,
       0,     0,     0,   141,   142,   139,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   140,     0,     0,   158,   159,     0,   160,     0,   161,
       0,   229,     0,   141,   142,   139,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   140,     0,     0,   158,   159,     0,   160,     0,   161,
       0,   342,   141,   142,   139,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   140,     0,   158,   159,     0,   160,     0,   161,     0,
     530,     0,   141,   142,   139,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     140,     0,     0,   158,   159,     0,   160,     0,   161,     0,
     535,   234,   141,   142,   139,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     140,     0,     0,   158,   159,     0,   160,     0,   161,     0,
       0,   141,   142,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     140,     0,   158,   159,     0,   160,   240,   161,     0,     0,
       0,   141,   142,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   140,
       0,     0,   158,   159,     0,   160,   267,   161,     0,     0,
       0,   141,   142,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   140,
       0,     0,   158,   159,     0,   160,   347,   161,     0,     0,
     141,   142,   362,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   140,
       0,   158,   159,     0,   160,     0,   161,     0,     0,     0,
     141,   142,    -7,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   139,     0,
       0,   158,   159,     0,   160,     0,   161,     0,     0,     0,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   139,     0,
       0,   158,   159,     0,   160,   396,   161,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   139,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   140,     0,   158,   159,     0,   160,
       0,   161,     0,     0,     0,   141,   142,   139,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   140,     0,     0,   158,   159,     0,   160,
     402,   161,     0,     0,     0,   141,   142,   139,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   140,     0,     0,   158,   159,     0,   160,
     403,   161,     0,     0,   141,   142,   139,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   140,     0,   158,   159,     0,   160,   448,
     161,     0,     0,     0,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   140,     0,     0,   158,   159,     0,   160,   484,
     161,     0,     0,     0,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   158,   159,     0,   160,   526,
     161,     0,     0,   141,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    25,    26,     0,   158,   159,     0,   160,     0,   161,
       0,     0,     0,     0,     0,    27,     0,    28,    29,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,    25,
      26,     0,    31,     0,     0,     0,    32,    33,     0,     0,
       0,    34,     0,    27,     0,    28,    29,    35,   210,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,    32,    33,     0,     0,     0,    34,
       0,     0,     0,     0,    36,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
       0,    39,     0,    40,    41,    42,    43,    44,     0,    45,
       0,     0,    36,     0,     0,   211,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,    37,    38,     0,    39,
       0,    40,    41,    42,    43,    44,    27,    45,    28,    29,
       0,     0,   522,     0,    30,     0,     0,     0,     0,     0,
      25,    26,     0,    31,     0,     0,     0,    32,    33,     0,
       0,     0,    34,     0,    27,     0,    28,    29,    35,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    32,    33,     0,     0,     0,
      34,     0,     0,     0,     0,    36,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,     0,    39,     0,    40,    41,    42,    43,    44,     0,
      45,     0,     0,    36,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    37,    38,     0,
      39,     0,    40,    41,    42,    43,    44,   135,    45,    27,
       0,    28,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,   270,   271,     0,     0,    31,     0,     0,   272,
      32,    33,     0,     0,     0,    34,   273,   274,     0,     0,
     275,    35,   276,   277,     0,     0,   278,     0,   279,     0,
     280,   281,     0,   282,   283,   284,     0,     0,     0,     0,
     285,   286,     0,   287,     0,   288,     0,     0,    36,     0,
     289,   290,   291,     0,   292,   293,     0,   294,     0,   295,
     296,     0,    37,    38,     0,    39,     0,    40,    41,    42,
      43,    44,     0,    45,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -165,  -165,  -165,  -165,  -165,
    -165,   151,   152,   153,   154,   155,   156,   157,     0,     0,
       0,   158,   159,     0,   160,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -164,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89
};

static const yytype_int16 yycheck[] =
{
       4,    44,    96,   114,     3,   217,   169,   117,   102,    17,
      56,   166,   175,    59,    55,    61,     4,    14,   181,    60,
     126,    89,   355,    89,    21,    66,    89,    34,    32,    89,
      91,    20,    36,    37,    38,    87,    40,    41,    42,    89,
      44,    45,    89,   375,   376,   378,    50,   380,   116,   382,
      25,    26,   385,   386,   115,   121,    89,     0,   121,    89,
     120,   104,    50,   530,   114,    54,    89,   114,   535,   304,
     115,   306,   405,    48,    63,   310,    65,   367,   204,   122,
     370,   114,   208,    89,   114,   211,   115,    93,   134,   115,
      94,   114,   218,    97,    86,   119,    91,   105,    93,    91,
     104,   105,   106,    91,   350,   351,   113,    34,   441,    34,
     115,   115,   324,   115,   447,   119,   159,   115,   122,   115,
     124,   115,   126,   120,   457,   115,   232,   112,   113,    34,
     115,    90,   117,   179,    34,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   389,   159,   311,    34,   264,   200,
      93,    34,   397,   121,    93,   328,   207,    91,   106,   107,
     108,    91,    91,   336,   112,   113,    91,   115,    91,   117,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    12,   348,    91,    15,    16,    17,    91,   325,
     533,   534,   206,   329,    91,   331,    91,    91,    91,    91,
     214,   215,   338,   368,   121,   341,   371,     7,     8,     9,
      10,    11,   377,   227,   330,    15,    16,   119,   232,    34,
     121,   121,   236,   279,   238,   115,    26,    27,    88,   115,
     334,    31,    32,    33,     7,     8,     9,    10,    11,   115,
      40,   406,    15,    16,   115,    34,    91,    45,    34,    49,
     264,    34,   107,    26,    27,   116,     4,   116,    31,    32,
      33,    61,    88,   115,   121,   115,    93,    40,   116,   491,
      89,    91,   116,   116,    42,   396,    49,    93,   119,   115,
     115,   402,   403,    42,    42,   119,   119,    42,    61,   113,
     113,   513,     4,   413,   119,   116,   305,   104,   105,   106,
     107,   108,    93,   468,   107,   112,   113,   102,   115,   120,
     117,    34,   116,   119,   536,   431,   330,   539,   114,   116,
     120,    34,   116,   116,   102,   339,    24,   448,    93,   121,
      59,   121,    89,   121,   121,    34,   121,    42,   503,   120,
     444,   120,    89,   120,   120,    59,   121,   121,   362,   363,
      93,   120,    86,    17,   519,   121,   120,   162,   121,   121,
     173,   436,   363,   498,   479,   379,   487,    92,    64,   516,
      67,   229,   508,    -1,    -1,   511,    -1,    -1,   431,   393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,   449,     7,     8,     9,
      10,    11,    -1,    13,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,   431,    28,    -1,
      30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    39,
      -1,    41,    -1,    -1,    -1,   449,    -1,    47,    48,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   486,    -1,   112,   113,    -1,   115,   492,   117,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
     504,    -1,    -1,    -1,   104,   105,    -1,   107,   512,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,     3,   119,
     120,   121,     7,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    26,    -1,    28,    50,    30,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,    90,   112,   113,    -1,   115,
      -1,   117,    -1,     4,    -1,   121,    -1,    -1,    -1,   104,
     105,    -1,   107,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,     3,   119,   120,   121,     7,     8,     9,
      10,    11,    -1,    13,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    28,    50,
      30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      90,   112,   113,    -1,   115,    -1,   117,    -1,     4,    -1,
     121,    -1,    -1,    -1,   104,   105,    -1,   107,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,     3,   119,
     120,   121,     7,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    26,    -1,    28,    50,    30,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,     4,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    50,    -1,    90,   112,   113,    -1,   115,
      -1,   117,    -1,    -1,    -1,   121,     4,    -1,    -1,   104,
     105,    -1,   107,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,     4,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    50,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,     4,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    50,   112,   113,    -1,   115,    -1,   117,    -1,
      -1,    -1,    -1,    91,    92,     4,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    50,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
      -1,   119,    -1,    91,    92,     4,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    50,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
      -1,   119,    91,    92,     4,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    50,    -1,   112,   113,    -1,   115,    -1,   117,    -1,
     119,    -1,    91,    92,     4,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      50,    -1,    -1,   112,   113,    -1,   115,    -1,   117,    -1,
     119,    90,    91,    92,     4,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      50,    -1,    -1,   112,   113,    -1,   115,    -1,   117,    -1,
      -1,    91,    92,     4,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      50,    -1,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    91,    92,     4,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    50,
      -1,    -1,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    91,    92,     4,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    50,
      -1,    -1,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    50,
      -1,   112,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     4,    -1,
      -1,   112,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     4,    -1,
      -1,   112,   113,    -1,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     4,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    50,    -1,   112,   113,    -1,   115,
      -1,   117,    -1,    -1,    -1,    91,    92,     4,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    50,    -1,    -1,   112,   113,    -1,   115,
     116,   117,    -1,    -1,    -1,    91,    92,     4,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    50,    -1,    -1,   112,   113,    -1,   115,
     116,   117,    -1,    -1,    91,    92,     4,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    50,    -1,   112,   113,    -1,   115,   116,
     117,    -1,    -1,    -1,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    50,    -1,    -1,   112,   113,    -1,   115,   116,
     117,    -1,    -1,    -1,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,   112,   113,    -1,   115,   116,
     117,    -1,    -1,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    17,    18,    -1,   112,   113,    -1,   115,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    57,    -1,    31,    -1,    33,    34,    63,    64,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    90,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
      -1,   107,    -1,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,    90,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,   104,   105,    -1,   107,
      -1,   109,   110,   111,   112,   113,    31,   115,    33,    34,
      -1,    -1,   120,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    57,    -1,    31,    -1,    33,    34,    63,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    90,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,    -1,   107,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,    90,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,   104,   105,    -1,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,    31,
      -1,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    48,    -1,    -1,    12,
      52,    53,    -1,    -1,    -1,    57,    19,    20,    -1,    -1,
      23,    63,    25,    26,    -1,    -1,    29,    -1,    31,    -1,
      33,    34,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    44,    -1,    46,    -1,    48,    -1,    -1,    90,    -1,
      53,    54,    55,    -1,    57,    58,    -1,    60,    -1,    62,
      63,    -1,   104,   105,    -1,   107,    -1,   109,   110,   111,
     112,   113,    -1,   115,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,   123,   125,   124,     0,     7,     8,     9,    10,
      11,    15,    16,    26,    27,    31,    32,    33,    40,    49,
      61,   153,   160,   161,   178,    17,    18,    31,    33,    34,
      39,    48,    52,    53,    57,    63,    90,   104,   105,   107,
     109,   110,   111,   112,   113,   115,   127,   136,   137,   165,
     115,   115,   115,   187,   188,   187,   190,   191,   119,   187,
     187,   187,    34,    25,    26,    48,   185,   186,   185,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
     162,   174,   175,   176,     3,    13,    16,    22,    26,    28,
      30,    35,    39,    41,    47,    51,    56,    64,    65,   119,
     121,   127,   160,   177,   182,   115,   115,   166,   167,   133,
      34,   184,   115,   127,   115,   115,   115,   127,   127,   127,
     138,   127,   127,   127,    34,   114,   127,   134,   127,     4,
      50,    91,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   112,   113,
     115,   117,    90,   127,    34,    34,    93,   168,   185,   168,
     167,    34,   192,   154,   167,   168,   167,   121,   185,   190,
     185,   168,   192,    93,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,   119,   176,   127,   121,
     184,   127,    34,   179,   121,   115,   115,   184,   121,   134,
      64,   121,   127,   127,   115,   115,    88,   195,   121,   177,
     127,    34,   150,   151,   152,   162,   127,    91,   134,   119,
     134,   135,   129,   135,    90,    45,    91,   167,    89,   114,
     116,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
      34,   126,   127,   134,   131,    34,   137,   116,   116,   116,
       5,     6,    12,    19,    20,    23,    25,    26,    29,    31,
      33,    34,    36,    37,    38,    43,    44,    46,    48,    53,
      54,    55,    57,    58,    60,    62,    63,   143,   193,     4,
      50,    91,   169,   189,   169,   125,   169,     4,   167,   156,
     169,   159,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   163,   121,    88,   194,   168,   121,
     115,   121,   194,    34,   113,   127,   168,   194,   121,   115,
     194,   121,   119,   127,   127,   178,   194,   116,    93,   116,
      89,   121,   127,   116,   179,   116,   135,   116,   139,   127,
      91,   127,    93,    93,   114,   135,   119,   115,    42,   167,
     115,    42,    42,   119,   113,   113,   119,    42,   170,   171,
     170,   120,   170,   119,     4,   170,   143,   178,   194,   169,
     194,   135,   194,   102,   183,   184,   116,   169,   194,   127,
     194,   180,   116,   116,   120,   143,    93,   152,   152,   120,
     174,   116,   107,   128,   127,   126,   127,   132,   146,   150,
     143,   150,   143,    34,   144,   143,   147,   147,   147,   143,
     174,   119,   127,   173,   174,   174,   155,   119,   174,   174,
     164,   170,   116,   127,    89,   114,   177,   170,   116,    14,
      21,   120,   181,   177,   177,   174,   143,   130,   162,   114,
     116,    34,   140,   141,   142,   116,   116,   148,    89,   114,
     114,   120,   121,   134,   135,   172,   121,   121,   140,   157,
     121,   121,   120,   174,   116,   184,   102,    24,   174,   177,
     134,    93,    59,   174,    86,    91,   196,   120,    89,    34,
     145,   149,   143,    42,    89,   120,   120,   148,   121,   127,
     177,   121,    59,    93,   178,   127,    17,   105,   142,    93,
     120,   143,   120,   121,   158,   194,   116,   194,   127,   178,
     119,   196,    17,   143,   120,   119,   195,   174,   174,   195,
     178,   121,   121,   178,   120,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   122,   123,   124,   123,   125,   125,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   127,
     127,   127,   127,   127,   127,   129,   130,   127,   127,   127,
     131,   132,   127,   133,   127,   127,   127,   127,   127,   127,
     127,   127,   134,   134,   135,   135,   136,   136,   138,   139,
     137,   140,   140,   141,   141,   142,   142,   142,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   145,   143,   143,   146,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     147,   147,   148,   148,   149,   150,   150,   150,   151,   151,
     151,   152,   153,   154,   153,   153,   153,   153,   153,   155,
     153,   156,   157,   158,   153,   159,   153,   153,   153,   160,
     160,   160,   160,   160,   161,   161,   161,   161,   163,   164,
     162,   165,   166,   167,   167,   168,   168,   169,   169,   169,
     169,   171,   172,   170,   170,   173,   173,   173,   174,   174,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   178,   178,
     179,   180,   180,   181,   181,   182,   182,   183,   183,   184,
     186,   185,   188,   189,   187,   191,   190,   192,   193,   194,
     194,   195,   195,   196,   196
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     2,     0,     1,     0,     3,
       4,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     3,     4,     4,     6,     3,     4,     0,     6,
       3,     3,     3,     2,     4,     0,     0,     7,     5,     4,
       0,     0,     6,     0,     3,     3,     1,     5,     1,     1,
       1,     3,     3,     1,     1,     0,     3,     1,     0,     0,
       5,     1,     2,     1,     3,     4,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     4,     0,     0,     6,     4,     0,     5,
       1,     3,     3,     2,     4,     4,     3,     1,     3,     1,
       3,     1,     2,     0,     5,     1,     2,     0,     3,     3,
       1,     4,     3,     0,     5,     7,     7,     7,     7,     0,
       9,     0,     0,     0,    12,     0,     7,     2,     1,     4,
       4,     4,     1,     1,     3,     3,     3,     4,     0,     0,
       6,     3,     1,     5,     3,     2,     0,     0,     1,     1,
       1,     0,     0,     3,     0,     3,     4,     1,     1,     0,
       2,     1,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     4,     4,     4,     5,     7,     5,
       2,     5,     3,     3,     3,     3,     4,     4,     4,     8,
       8,     5,    11,     6,    12,     3,     1,     1,     2,     0,
       4,     2,     0,     4,     3,     6,     8,     3,     1,     1,
       0,     2,     0,     0,     3,     0,     2,     1,     1,     1,
       0,     1,     0,     1,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 274 "parse.y" /* yacc.c:1646  */
    {
			if ( stmts )
				stmts->AsStmtList()->Stmts().append((yyvsp[0].stmt));
			else
				stmts = (yyvsp[0].stmt);

			// Any objects creates from hereon out should not
			// have file positions associated with them.
			set_location(no_location);
			}
#line 2289 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 288 "parse.y" /* yacc.c:1646  */
    { in_debug = true; }
#line 2295 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 289 "parse.y" /* yacc.c:1646  */
    {
			g_curr_debug_expr = (yyvsp[0].expr);
			}
#line 2303 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 301 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2309 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 303 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2315 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 308 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = (yyvsp[-1].expr); (yyval.expr)->MarkParen();
			}
#line 2324 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 314 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.expr) = new CloneExpr((yyvsp[-1].expr));
			}
#line 2333 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 320 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyval.expr) = new IncrExpr(EXPR_INCR, (yyvsp[0].expr));
			}
#line 2342 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 326 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyval.expr) = new IncrExpr(EXPR_DECR, (yyvsp[0].expr));
			}
#line 2351 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 332 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyval.expr) = new NotExpr((yyvsp[0].expr));
			}
#line 2360 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 338 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyval.expr) = new NegExpr((yyvsp[0].expr));
			}
#line 2369 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 344 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyval.expr) = new PosExpr((yyvsp[0].expr));
			}
#line 2378 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 350 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new AddExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2387 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 356 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new AddToExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2396 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 362 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new SubExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2405 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 368 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new RemoveFromExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2414 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 374 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new TimesExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2423 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 380 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new DivideExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2432 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 386 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new ModExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2441 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 392 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new BoolExpr(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2450 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 398 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new BoolExpr(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2459 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 404 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new EqExpr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2468 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 410 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new EqExpr(EXPR_NE, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2477 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 416 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new RelExpr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2486 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 422 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new RelExpr(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2495 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 428 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new RelExpr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2504 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 434 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new RelExpr(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2513 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 440 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[0]));
			(yyval.expr) = new CondExpr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2522 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 446 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = get_assign_expr((yyvsp[-2].expr), (yyvsp[0].expr), in_init);
			}
#line 2531 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 452 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = add_and_assign_local((yyvsp[-2].id), (yyvsp[0].expr), new Val(1, TYPE_BOOL));
			}
#line 2540 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 458 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.expr) = new IndexExpr((yyvsp[-3].expr), (yyvsp[-1].list));
			}
#line 2549 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 464 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-5]), (yylsp[0]));
			Expr* low = (yyvsp[-3].expr) ? (yyvsp[-3].expr) : new ConstExpr(new Val(0, TYPE_COUNT));
			Expr* high = (yyvsp[-1].expr) ? (yyvsp[-1].expr) : new SizeExpr((yyvsp[-5].expr));
			ListExpr* le = new ListExpr(low);
			le->Append(high);
			(yyval.expr) = new IndexExpr((yyvsp[-5].expr), le, true);
			}
#line 2562 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 474 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new FieldExpr((yyvsp[-2].expr), (yyvsp[0].str));
			}
#line 2571 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 480 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.expr) = new FieldAssignExpr((yyvsp[-2].str), (yyvsp[0].expr));
			}
#line 2580 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 486 "parse.y" /* yacc.c:1646  */
    {
			func_id = current_scope()->GenerateTemporary("anonymous-function");
			func_id->SetInferReturnType(true);
			begin_func(func_id,
				   current_module.c_str(),
				   FUNC_FLAVOR_FUNCTION,
				   0,
				   (yyvsp[-1].func_type));
			}
#line 2594 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 496 "parse.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new FieldAssignExpr((yyvsp[-4].str), new ConstExpr(func_id->ID_Val()));
			}
#line 2602 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 501 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new InExpr((yyvsp[-2].expr), (yyvsp[0].expr));
			}
#line 2611 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 507 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new NotExpr(new InExpr((yyvsp[-2].expr), (yyvsp[0].expr)));
			}
#line 2620 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 513 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));

			bool is_record_ctor = true;

			// If every expression in the list is a field assignment,
			// then treat it as a record constructor, else as a list
			// used for an initializer.

			for ( int i = 0; i < (yyvsp[-1].list)->Exprs().length(); ++i )
				{
				if ( (yyvsp[-1].list)->Exprs()[i]->Tag() != EXPR_FIELD_ASSIGN )
					{
					is_record_ctor = false;
					break;
					}
				}

			if ( is_record_ctor )
				(yyval.expr) = new RecordConstructorExpr((yyvsp[-1].list));
			else
				(yyval.expr) = (yyvsp[-1].list);
			}
#line 2648 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 538 "parse.y" /* yacc.c:1646  */
    {
			// We interpret this as an empty record constructor.
			(yyval.expr) = new RecordConstructorExpr(new ListExpr);
			}
#line 2657 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 545 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.expr) = new RecordConstructorExpr((yyvsp[-1].list));
			}
#line 2666 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 550 "parse.y" /* yacc.c:1646  */
    { ++in_init; }
#line 2672 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 550 "parse.y" /* yacc.c:1646  */
    { --in_init; }
#line 2678 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 552 "parse.y" /* yacc.c:1646  */
    { // the ++in_init fixes up the parsing of "[x] = y"
			set_location((yylsp[-6]), (yylsp[-2]));
			(yyval.expr) = new TableConstructorExpr((yyvsp[-3].list), (yyvsp[0].attr_l));
			}
#line 2687 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 558 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[-1]));
			(yyval.expr) = new SetConstructorExpr((yyvsp[-2].list), (yyvsp[0].attr_l));
			}
#line 2696 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 564 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.expr) = new VectorConstructorExpr((yyvsp[-1].list));
			}
#line 2705 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 570 "parse.y" /* yacc.c:1646  */
    {
			if ( expr_is_table_type_name((yyvsp[-1].expr)) )
				++in_init;
			}
#line 2714 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 576 "parse.y" /* yacc.c:1646  */
    {
			if ( expr_is_table_type_name((yyvsp[-3].expr)) )
				--in_init;
			}
#line 2723 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 582 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-5]), (yylsp[0]));

			BroType* ctor_type = 0;

			if ( (yyvsp[-5].expr)->Tag() == EXPR_NAME &&
			     (ctor_type = (yyvsp[-5].expr)->AsNameExpr()->Id()->AsType()) )
				{
				switch ( ctor_type->Tag() ) {
				case TYPE_RECORD:
					(yyval.expr) = new RecordCoerceExpr(new RecordConstructorExpr((yyvsp[-2].list)),
					                          ctor_type->AsRecordType());
					break;

				case TYPE_TABLE:
					if ( ctor_type->IsTable() )
						(yyval.expr) = new TableConstructorExpr((yyvsp[-2].list), 0, ctor_type);
					else
						(yyval.expr) = new SetConstructorExpr((yyvsp[-2].list), 0, ctor_type);

					break;

				case TYPE_VECTOR:
					(yyval.expr) = new VectorConstructorExpr((yyvsp[-2].list), ctor_type);
					break;

				default:
					(yyvsp[-5].expr)->Error("constructor type not implemented");
					YYERROR;
				}
				}

			else
				(yyval.expr) = new CallExpr((yyvsp[-5].expr), (yyvsp[-2].list), in_hook > 0);
			}
#line 2763 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 618 "parse.y" /* yacc.c:1646  */
    { ++in_hook; }
#line 2769 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 619 "parse.y" /* yacc.c:1646  */
    {
			--in_hook;
			set_location((yylsp[-2]), (yylsp[0]));
			if ( (yyvsp[0].expr)->Tag() != EXPR_CALL )
				(yyvsp[0].expr)->Error("not a valid hook call expression");
			(yyval.expr) = (yyvsp[0].expr);
			}
#line 2781 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 628 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new HasFieldExpr((yyvsp[-2].expr), (yyvsp[0].str));
			}
#line 2790 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 636 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[0]));
			(yyval.expr) = new ScheduleExpr((yyvsp[-3].expr), (yyvsp[-1].event_expr));
			}
#line 2799 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 642 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));

			ID* id = lookup_ID((yyvsp[0].str), current_module.c_str());
			if ( ! id )
				{
				if ( ! in_debug )
					{
/*	// CHECK THAT THIS IS NOT GLOBAL.
					id = install_ID($1, current_module.c_str(),
							false, is_export);
*/

					yyerror(fmt("unknown identifier %s", (yyvsp[0].str)));
					YYERROR;
					}
				else
					{
					yyerror(fmt("unknown identifier %s", (yyvsp[0].str)));
					YYERROR;
					}
				}
			else
				{
				if ( ! id->Type() )
					{
					id->Error("undeclared variable");
					id->SetType(error_type());
					(yyval.expr) = new NameExpr(id);
					}

				else if ( id->IsEnumConst() )
					{
					EnumType* t = id->Type()->AsEnumType();
					int intval = t->Lookup(id->ModuleName(),
							       id->Name());
					if ( intval < 0 )
						reporter->InternalError("enum value not found for %s", id->Name());
					(yyval.expr) = new ConstExpr(new EnumVal(intval, t));
					}
				else
					(yyval.expr) = new NameExpr(id);

				if ( id->IsDeprecated() )
					reporter->Warning("deprecated (%s)", id->Name());
				}
			}
#line 2851 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 691 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));
			(yyval.expr) = new ConstExpr((yyvsp[0].val));
			}
#line 2860 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 697 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));
			(yyvsp[0].re)->Compile();
			(yyval.expr) = new ConstExpr(new PatternVal((yyvsp[0].re)));
			}
#line 2870 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 704 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.expr) = new SizeExpr((yyvsp[-1].expr));
			}
#line 2879 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 712 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyvsp[-2].list)->Append((yyvsp[0].expr));
			}
#line 2888 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 718 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));
			(yyval.list) = new ListExpr((yyvsp[0].expr));
			}
#line 2897 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 727 "parse.y" /* yacc.c:1646  */
    { (yyval.list) = new ListExpr(); }
#line 2903 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 732 "parse.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].re)->AddPat((yyvsp[0].str));
			delete [] (yyvsp[0].str);
			}
#line 2912 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 738 "parse.y" /* yacc.c:1646  */
    {
			(yyval.re) = new RE_Matcher((yyvsp[0].str));
			delete [] (yyvsp[0].str);
			}
#line 2921 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 745 "parse.y" /* yacc.c:1646  */
    { begin_RE(); }
#line 2927 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 745 "parse.y" /* yacc.c:1646  */
    { end_RE(); }
#line 2933 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 746 "parse.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str); }
#line 2939 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 751 "parse.y" /* yacc.c:1646  */
    {
			(yyval.type) = cur_enum_type;
			cur_enum_type = NULL;
			}
#line 2948 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 757 "parse.y" /* yacc.c:1646  */
    {
			(yyval.type) = cur_enum_type;
			cur_enum_type = NULL;
			}
#line 2957 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 776 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-1]));
			assert(cur_enum_type);

			if ( (yyvsp[-1].val)->Type()->Tag() != TYPE_COUNT )
				reporter->Error("enumerator is not a count constant");
			else
				cur_enum_type->AddName(current_module, (yyvsp[-3].str),
				                       (yyvsp[-1].val)->InternalUnsigned(), is_export, (yyvsp[0].b));
			}
#line 2972 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 788 "parse.y" /* yacc.c:1646  */
    {
			/* We only accept counts as enumerator, but we want to return a nice
			   error message if users triy to use a negative integer (will also
			   catch other cases, but that's fine.)
			*/
			reporter->Error("enumerator is not a count constant");
			}
#line 2984 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 797 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]));
			assert(cur_enum_type);
			cur_enum_type->AddName(current_module, (yyvsp[-1].str), is_export, (yyvsp[0].b));
			}
#line 2994 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 805 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_BOOL);
				}
#line 3003 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 810 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_INT);
				}
#line 3012 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 815 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_COUNT);
				}
#line 3021 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 820 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_COUNTER);
				}
#line 3030 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 825 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_DOUBLE);
				}
#line 3039 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 830 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_TIME);
				}
#line 3048 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 835 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_INTERVAL);
				}
#line 3057 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 840 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_STRING);
				}
#line 3066 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 845 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_PATTERN);
				}
#line 3075 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 850 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_TIMER);
				}
#line 3084 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 855 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_PORT);
				}
#line 3093 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 860 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_ADDR);
				}
#line 3102 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 865 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_SUBNET);
				}
#line 3111 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 870 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = base_type(TYPE_ANY);
				}
#line 3120 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 876 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-5]), (yylsp[0]));
				(yyval.type) = new TableType((yyvsp[-3].type_l), (yyvsp[0].type));
				}
#line 3129 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 882 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-3]), (yylsp[0]));
				(yyval.type) = new SetType((yyvsp[-1].type_l), 0);
				}
#line 3138 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 888 "parse.y" /* yacc.c:1646  */
    { ++in_record; }
#line 3144 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 890 "parse.y" /* yacc.c:1646  */
    { --in_record; }
#line 3150 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 892 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-5]), (yylsp[-1]));
				(yyval.type) = new RecordType((yyvsp[-2].type_decl_l));
				}
#line 3159 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 898 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-3]), (yylsp[0]));
				reporter->Error("union type not implemented");
				(yyval.type) = 0;
				}
#line 3169 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 904 "parse.y" /* yacc.c:1646  */
    { set_location((yylsp[-1])); parser_new_enum(); }
#line 3175 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 905 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-4]), (yylsp[0]));
				(yyvsp[-1].type)->UpdateLocationEndInfo((yylsp[0]));
				(yyval.type) = (yyvsp[-1].type);
				}
#line 3185 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 912 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				// $$ = new TypeList();
				reporter->Error("list type not implemented");
				(yyval.type) = 0;
				}
#line 3196 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 920 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-2]));
				// $$ = new TypeList($3);
				reporter->Error("list type not implemented");
				(yyval.type) = 0;
				}
#line 3207 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 928 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-2]), (yylsp[0]));
				(yyval.type) = new VectorType((yyvsp[0].type));
				}
#line 3216 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 934 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-1]), (yylsp[0]));
				(yyval.type) = (yyvsp[0].func_type);
				}
#line 3225 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 940 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-3]), (yylsp[-1]));
				(yyval.type) = new FuncType((yyvsp[-1].record), 0, FUNC_FLAVOR_EVENT);
				}
#line 3234 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 946 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-3]), (yylsp[-1]));
				(yyval.type) = new FuncType((yyvsp[-1].record), base_type(TYPE_BOOL), FUNC_FLAVOR_HOOK);
				}
#line 3243 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 952 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-2]), (yylsp[0]));
				(yyval.type) = new FileType((yyvsp[0].type));
				}
#line 3252 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 958 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[0]));
				(yyval.type) = new FileType(base_type(TYPE_STRING));
				}
#line 3261 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 964 "parse.y" /* yacc.c:1646  */
    {
				set_location((yylsp[-2]), (yylsp[0]));
				(yyval.type) = new OpaqueType((yyvsp[0].str));
				}
#line 3270 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 970 "parse.y" /* yacc.c:1646  */
    {
			if ( ! (yyvsp[0].id) || ! ((yyval.type) = (yyvsp[0].id)->AsType()) )
				{
				NullStmt here;
				if ( (yyvsp[0].id) )
					(yyvsp[0].id)->Error("not a BRO type", &here);
				(yyval.type) = error_type();
				}
			else
				{
				Ref((yyval.type));

				if ( (yyvsp[0].id)->IsDeprecated() )
					reporter->Warning("deprecated (%s)", (yyvsp[0].id)->Name());
				}
			}
#line 3291 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 990 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_l)->AppendEvenIfNotPure((yyvsp[0].type)); }
#line 3297 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 992 "parse.y" /* yacc.c:1646  */
    {
			(yyval.type_l) = new TypeList((yyvsp[0].type));
			(yyval.type_l)->Append((yyvsp[0].type));
			}
#line 3306 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 1000 "parse.y" /* yacc.c:1646  */
    {
			(yyvsp[-1].type_decl_l)->append((yyvsp[0].type_decl));
			}
#line 3314 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 1004 "parse.y" /* yacc.c:1646  */
    {
			(yyval.type_decl_l) = new type_decl_list();
			}
#line 3322 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 1011 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[-1]));
			(yyval.type_decl) = new TypeDecl((yyvsp[-2].type), (yyvsp[-4].str), (yyvsp[-1].attr_l), (in_record > 0));

			if ( in_record > 0 && cur_decl_type_id )
				broxygen_mgr->RecordField(cur_decl_type_id, (yyval.type_decl), ::filename);
			}
#line 3334 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 1022 "parse.y" /* yacc.c:1646  */
    { (yyval.record) = new RecordType((yyvsp[0].type_decl_l)); }
#line 3340 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 1024 "parse.y" /* yacc.c:1646  */
    { (yyval.record) = new RecordType((yyvsp[-1].type_decl_l)); }
#line 3346 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 1026 "parse.y" /* yacc.c:1646  */
    { (yyval.record) = new RecordType(new type_decl_list()); }
#line 3352 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 1031 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_decl_l)->append((yyvsp[0].type_decl)); }
#line 3358 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 1033 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_decl_l)->append((yyvsp[0].type_decl)); }
#line 3364 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 1035 "parse.y" /* yacc.c:1646  */
    { (yyval.type_decl_l) = new type_decl_list(); (yyval.type_decl_l)->append((yyvsp[0].type_decl)); }
#line 3370 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 1040 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.type_decl) = new TypeDecl((yyvsp[-1].type), (yyvsp[-3].str), (yyvsp[0].attr_l));
			}
#line 3379 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 1048 "parse.y" /* yacc.c:1646  */
    {
			current_module = (yyvsp[-1].str);
			broxygen_mgr->ModuleUsage(::filename, current_module);
			}
#line 3388 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 1053 "parse.y" /* yacc.c:1646  */
    { is_export = true; }
#line 3394 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 1054 "parse.y" /* yacc.c:1646  */
    { is_export = false; }
#line 3400 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 1057 "parse.y" /* yacc.c:1646  */
    {
			add_global((yyvsp[-5].id), (yyvsp[-4].type), (yyvsp[-3].ic), (yyvsp[-2].expr), (yyvsp[-1].attr_l), VAR_REGULAR);
			broxygen_mgr->Identifier((yyvsp[-5].id));
			}
#line 3409 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 1063 "parse.y" /* yacc.c:1646  */
    {
			add_global((yyvsp[-5].id), (yyvsp[-4].type), (yyvsp[-3].ic), (yyvsp[-2].expr), (yyvsp[-1].attr_l), VAR_OPTION);
			broxygen_mgr->Identifier((yyvsp[-5].id));
			}
#line 3418 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 1069 "parse.y" /* yacc.c:1646  */
    {
			add_global((yyvsp[-5].id), (yyvsp[-4].type), (yyvsp[-3].ic), (yyvsp[-2].expr), (yyvsp[-1].attr_l), VAR_CONST);
			broxygen_mgr->Identifier((yyvsp[-5].id));
			}
#line 3427 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 1075 "parse.y" /* yacc.c:1646  */
    {
			add_global((yyvsp[-5].id), (yyvsp[-4].type), (yyvsp[-3].ic), (yyvsp[-2].expr), (yyvsp[-1].attr_l), VAR_REDEF);
			broxygen_mgr->Redef((yyvsp[-5].id), ::filename);
			}
#line 3436 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 1081 "parse.y" /* yacc.c:1646  */
    { parser_redef_enum((yyvsp[-2].id)); broxygen_mgr->Redef((yyvsp[-2].id), ::filename); }
#line 3442 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 1083 "parse.y" /* yacc.c:1646  */
    {
			// Broxygen already grabbed new enum IDs as the type created them.
			}
#line 3450 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 1088 "parse.y" /* yacc.c:1646  */
    { cur_decl_type_id = (yyvsp[0].id); broxygen_mgr->Redef((yyvsp[0].id), ::filename); }
#line 3456 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 1090 "parse.y" /* yacc.c:1646  */
    { ++in_record; }
#line 3462 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 1092 "parse.y" /* yacc.c:1646  */
    { --in_record; }
#line 3468 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 1094 "parse.y" /* yacc.c:1646  */
    {
			cur_decl_type_id = 0;

			if ( ! (yyvsp[-9].id)->Type() )
				(yyvsp[-9].id)->Error("unknown identifier");
			else
				extend_record((yyvsp[-9].id), (yyvsp[-4].type_decl_l), (yyvsp[-1].attr_l));
			}
#line 3481 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 1104 "parse.y" /* yacc.c:1646  */
    { cur_decl_type_id = (yyvsp[-1].id); broxygen_mgr->StartType((yyvsp[-1].id));  }
#line 3487 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 1106 "parse.y" /* yacc.c:1646  */
    {
			cur_decl_type_id = 0;
			add_type((yyvsp[-5].id), (yyvsp[-2].type), (yyvsp[-1].attr_l));
			broxygen_mgr->Identifier((yyvsp[-5].id));
			}
#line 3497 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 1113 "parse.y" /* yacc.c:1646  */
    { }
#line 3503 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 1120 "parse.y" /* yacc.c:1646  */
    { do_atif((yyvsp[-1].expr)); }
#line 3509 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 1122 "parse.y" /* yacc.c:1646  */
    { do_atifdef((yyvsp[-1].str)); }
#line 3515 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 1124 "parse.y" /* yacc.c:1646  */
    { do_atifndef((yyvsp[-1].str)); }
#line 3521 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 1126 "parse.y" /* yacc.c:1646  */
    { do_atendif(); }
#line 3527 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 1128 "parse.y" /* yacc.c:1646  */
    { do_atelse(); }
#line 3533 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 1133 "parse.y" /* yacc.c:1646  */
    {
			begin_func((yyvsp[-1].id), current_module.c_str(),
				FUNC_FLAVOR_FUNCTION, 0, (yyvsp[0].func_type));
			(yyval.func_type) = (yyvsp[0].func_type);
			broxygen_mgr->Identifier((yyvsp[-1].id));
			}
#line 3544 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 1140 "parse.y" /* yacc.c:1646  */
    {
			begin_func((yyvsp[-1].id), current_module.c_str(),
				   FUNC_FLAVOR_EVENT, 0, (yyvsp[0].func_type));
			(yyval.func_type) = (yyvsp[0].func_type);
			}
#line 3554 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 1146 "parse.y" /* yacc.c:1646  */
    {
			(yyvsp[0].func_type)->ClearYieldType(FUNC_FLAVOR_HOOK);
			(yyvsp[0].func_type)->SetYieldType(base_type(TYPE_BOOL));
			begin_func((yyvsp[-1].id), current_module.c_str(),
				   FUNC_FLAVOR_HOOK, 0, (yyvsp[0].func_type));
			(yyval.func_type) = (yyvsp[0].func_type);
			}
#line 3566 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 1154 "parse.y" /* yacc.c:1646  */
    {
			begin_func((yyvsp[-1].id), current_module.c_str(),
				   FUNC_FLAVOR_EVENT, 1, (yyvsp[0].func_type));
			(yyval.func_type) = (yyvsp[0].func_type);
			}
#line 3576 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 1163 "parse.y" /* yacc.c:1646  */
    {
			saved_in_init.push_back(in_init);
			in_init = 0;

			if ( has_attr((yyvsp[-1].attr_l), ATTR_DEPRECATED) )
				current_scope()->ScopeID()->MakeDeprecated();
			}
#line 3588 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 1172 "parse.y" /* yacc.c:1646  */
    {
			in_init = saved_in_init.back();
			saved_in_init.pop_back();
			}
#line 3597 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 1178 "parse.y" /* yacc.c:1646  */
    {
			end_func((yyvsp[-2].stmt), (yyvsp[-5].attr_l));
			}
#line 3605 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 1185 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = new ConstExpr((yyvsp[-1].id)->ID_Val()); }
#line 3611 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 1190 "parse.y" /* yacc.c:1646  */
    {
			(yyval.id) = current_scope()->GenerateTemporary("anonymous-function");
			begin_func((yyval.id), current_module.c_str(),
				   FUNC_FLAVOR_FUNCTION, 0, (yyvsp[0].func_type));
			}
#line 3621 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 1199 "parse.y" /* yacc.c:1646  */
    { (yyval.func_type) = new FuncType((yyvsp[-3].record), (yyvsp[0].type), FUNC_FLAVOR_FUNCTION); }
#line 3627 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 1201 "parse.y" /* yacc.c:1646  */
    { (yyval.func_type) = new FuncType((yyvsp[-1].record), base_type(TYPE_VOID), FUNC_FLAVOR_FUNCTION); }
#line 3633 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 1206 "parse.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3639 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 1208 "parse.y" /* yacc.c:1646  */
    { (yyval.type) = 0; }
#line 3645 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 1212 "parse.y" /* yacc.c:1646  */
    { (yyval.ic) = INIT_NONE; }
#line 3651 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 1213 "parse.y" /* yacc.c:1646  */
    { (yyval.ic) = INIT_FULL; }
#line 3657 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 1214 "parse.y" /* yacc.c:1646  */
    { (yyval.ic) = INIT_EXTRA; }
#line 3663 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 1215 "parse.y" /* yacc.c:1646  */
    { (yyval.ic) = INIT_REMOVE; }
#line 3669 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 1219 "parse.y" /* yacc.c:1646  */
    { ++in_init; }
#line 3675 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 1219 "parse.y" /* yacc.c:1646  */
    { --in_init; }
#line 3681 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 1220 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3687 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 1222 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 3693 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 1227 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].list); }
#line 3699 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 1229 "parse.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-2].list); }
#line 3705 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 1236 "parse.y" /* yacc.c:1646  */
    { (yyval.attr_l) = 0; }
#line 3711 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 1241 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-1].attr_l)->append((yyvsp[0].attr)); }
#line 3717 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 1243 "parse.y" /* yacc.c:1646  */
    {
			(yyval.attr_l) = new attr_list;
			(yyval.attr_l)->append((yyvsp[0].attr));
			}
#line 3726 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 1251 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_DEFAULT, (yyvsp[0].expr)); }
#line 3732 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 1253 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_OPTIONAL); }
#line 3738 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 174:
#line 1255 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_REDEF); }
#line 3744 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 1257 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ROTATE_INTERVAL, (yyvsp[0].expr)); }
#line 3750 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 1259 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ROTATE_SIZE, (yyvsp[0].expr)); }
#line 3756 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 1261 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ADD_FUNC, (yyvsp[0].expr)); }
#line 3762 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 1263 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_DEL_FUNC, (yyvsp[0].expr)); }
#line 3768 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 1265 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_EXPIRE_FUNC, (yyvsp[0].expr)); }
#line 3774 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 1267 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_EXPIRE_CREATE, (yyvsp[0].expr)); }
#line 3780 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 1269 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_EXPIRE_READ, (yyvsp[0].expr)); }
#line 3786 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 1271 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_EXPIRE_WRITE, (yyvsp[0].expr)); }
#line 3792 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 1273 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_PERSISTENT); }
#line 3798 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 1275 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_SYNCHRONIZED); }
#line 3804 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 1277 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ENCRYPT); }
#line 3810 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 1279 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ENCRYPT, (yyvsp[0].expr)); }
#line 3816 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 1281 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_RAW_OUTPUT); }
#line 3822 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 1283 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_MERGEABLE); }
#line 3828 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 1285 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_PRIORITY, (yyvsp[0].expr)); }
#line 3834 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 1287 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_TYPE_COLUMN, (yyvsp[0].expr)); }
#line 3840 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 1289 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_LOG); }
#line 3846 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 1291 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_ERROR_HANDLER); }
#line 3852 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 1293 "parse.y" /* yacc.c:1646  */
    { (yyval.attr) = new Attr(ATTR_DEPRECATED); }
#line 3858 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 1298 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));
			(yyval.stmt) = (yyvsp[-1].stmt);
			if ( (yyvsp[-2].b) )
			    brofiler.DecIgnoreDepth();
			}
#line 3869 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 1306 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-1]));
			(yyval.stmt) = new PrintStmt((yyvsp[-2].list));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3880 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 1314 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-1]));
			(yyval.stmt) = new EventStmt((yyvsp[-2].event_expr));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3891 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 1322 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[-1]));
			(yyval.stmt) = new IfStmt((yyvsp[-2].expr), (yyvsp[0].stmt), new NullStmt());
			}
#line 3900 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 1328 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-6]), (yylsp[-3]));
			(yyval.stmt) = new IfStmt((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
			}
#line 3909 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 1334 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-4]), (yylsp[-3]));
			(yyval.stmt) = new SwitchStmt((yyvsp[-3].expr), (yyvsp[-1].case_l));
			}
#line 3918 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 1340 "parse.y" /* yacc.c:1646  */
    {
			(yyvsp[-1].stmt)->AsForStmt()->AddBody((yyvsp[0].stmt));
			}
#line 3926 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 1345 "parse.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = new WhileStmt((yyvsp[-2].expr), (yyvsp[0].stmt));
			}
#line 3934 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 1350 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[-1]));
			(yyval.stmt) = new NextStmt;
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3945 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 1358 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[-1]));
			(yyval.stmt) = new BreakStmt;
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3956 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 1366 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[-1]));
			(yyval.stmt) = new FallthroughStmt;
			if ( ! (yyvsp[0].b) )
				brofiler.AddStmt((yyval.stmt));
			}
#line 3967 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 1374 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[-1]));
			(yyval.stmt) = new ReturnStmt(0);
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3978 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 1382 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-2]));
			(yyval.stmt) = new ReturnStmt((yyvsp[-2].expr));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 3989 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 1390 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-1]));
			(yyval.stmt) = new AddStmt((yyvsp[-2].expr));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 4000 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 1398 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[-1]));
			(yyval.stmt) = new DelStmt((yyvsp[-2].expr));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 4011 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 1406 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-7]), (yylsp[-1]));
			(yyval.stmt) = add_local((yyvsp[-6].id), (yyvsp[-5].type), (yyvsp[-4].ic), (yyvsp[-3].expr), (yyvsp[-2].attr_l), VAR_REGULAR);
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 4022 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 1414 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-7]), (yylsp[-2]));
			(yyval.stmt) = add_local((yyvsp[-6].id), (yyvsp[-5].type), (yyvsp[-4].ic), (yyvsp[-3].expr), (yyvsp[-2].attr_l), VAR_CONST);
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 4033 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 1422 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.stmt) = new WhenStmt((yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0, false);
			}
#line 4042 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 1428 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-8]), (yylsp[-2]));
			(yyval.stmt) = new WhenStmt((yyvsp[-8].expr), (yyvsp[-6].stmt), (yyvsp[-1].stmt), (yyvsp[-4].expr), false);
			if ( (yyvsp[-2].b) )
			    brofiler.DecIgnoreDepth();
			}
#line 4053 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 1437 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[0]));
			(yyval.stmt) = new WhenStmt((yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0, true);
			}
#line 4062 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 1443 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-8]), (yylsp[-2]));
			(yyval.stmt) = new WhenStmt((yyvsp[-8].expr), (yyvsp[-6].stmt), (yyvsp[-1].stmt), (yyvsp[-4].expr), true);
			if ( (yyvsp[-2].b) )
			    brofiler.DecIgnoreDepth();
			}
#line 4073 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 1451 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-2]), (yylsp[-1]));
			(yyval.stmt) = new ExprStmt((yyvsp[-2].expr));
			if ( ! (yyvsp[0].b) )
			    brofiler.AddStmt((yyval.stmt));
			}
#line 4084 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 1459 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]), (yylsp[0]));
			(yyval.stmt) = new NullStmt;
			}
#line 4093 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 1465 "parse.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NullStmt; }
#line 4099 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 1470 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-1]), (yylsp[0]));
			(yyvsp[-1].stmt)->AsStmtList()->Stmts().append((yyvsp[0].stmt));
			(yyvsp[-1].stmt)->UpdateLocationEndInfo((yylsp[0]));
			}
#line 4109 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 1476 "parse.y" /* yacc.c:1646  */
    { (yyval.stmt) = new StmtList(); }
#line 4115 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 1481 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-3]), (yylsp[0]));

			ID* id = lookup_ID((yyvsp[-3].str), current_module.c_str());
			if ( id )
				{
				if ( ! id->IsGlobal() )
					{
					yyerror(fmt("local identifier \"%s\" cannot be used to reference an event", (yyvsp[-3].str)));
					YYERROR;
					}
				if ( id->IsDeprecated() )
					reporter->Warning("deprecated (%s)", id->Name());
				}

			(yyval.event_expr) = new EventExpr((yyvsp[-3].str), (yyvsp[-1].list));
			}
#line 4137 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 1502 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-1].case_l)->append((yyvsp[0].c_case)); }
#line 4143 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 1504 "parse.y" /* yacc.c:1646  */
    { (yyval.case_l) = new case_list; }
#line 4149 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 1509 "parse.y" /* yacc.c:1646  */
    { (yyval.c_case) = new Case((yyvsp[-2].list), (yyvsp[0].stmt)); }
#line 4155 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 1512 "parse.y" /* yacc.c:1646  */
    { (yyval.c_case) = new Case(0, (yyvsp[0].stmt)); }
#line 4161 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 1517 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[-5]), (yylsp[0]));

			// This rule needs to be separate from the loop
			// body so that we execute these actions - defining
			// the local variable - prior to parsing the body,
			// which might refer to the variable.
			ID* loop_var = lookup_ID((yyvsp[-3].str), current_module.c_str());

			if ( loop_var )
				{
				if ( loop_var->IsGlobal() )
					loop_var->Error("global used in for loop");
				}

			else
				loop_var = install_ID((yyvsp[-3].str), current_module.c_str(),
						      false, false);

			id_list* loop_vars = new id_list;
			loop_vars->append(loop_var);

			(yyval.stmt) = new ForStmt(loop_vars, (yyvsp[-1].expr));
			}
#line 4190 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 1543 "parse.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForStmt((yyvsp[-4].id_l), (yyvsp[-1].expr)); }
#line 4196 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 1548 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-2].id_l)->append((yyvsp[0].id)); }
#line 4202 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 1550 "parse.y" /* yacc.c:1646  */
    {
			(yyval.id_l) = new id_list;
			(yyval.id_l)->append((yyvsp[0].id));
			}
#line 4211 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 1558 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));

			(yyval.id) = lookup_ID((yyvsp[0].str), current_module.c_str());
			if ( (yyval.id) )
				{
				if ( (yyval.id)->IsGlobal() )
					(yyval.id)->Error("already a global identifier");
				delete [] (yyvsp[0].str);
				}

			else
				{
				(yyval.id) = install_ID((yyvsp[0].str), current_module.c_str(),
						false, is_export);
				}
			}
#line 4233 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 1578 "parse.y" /* yacc.c:1646  */
    { resolving_global_ID = 1; }
#line 4239 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 1579 "parse.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 4245 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 1583 "parse.y" /* yacc.c:1646  */
    { defining_global_ID = 1; }
#line 4251 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 1583 "parse.y" /* yacc.c:1646  */
    { defining_global_ID = 0; }
#line 4257 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 1584 "parse.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[-1].id); }
#line 4263 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 1588 "parse.y" /* yacc.c:1646  */
    { resolving_global_ID = 0; }
#line 4269 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 1589 "parse.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 4275 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 1594 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));

			(yyval.id) = lookup_ID((yyvsp[0].str), current_module.c_str(), false, defining_global_ID);
			if ( (yyval.id) )
				{
				if ( ! (yyval.id)->IsGlobal() )
					(yyval.id)->Error("already a local identifier");

				if ( (yyval.id)->IsDeprecated() )
					{
					BroType* t = (yyval.id)->Type();

					if ( t->Tag() != TYPE_FUNC ||
					     t->AsFuncType()->Flavor() != FUNC_FLAVOR_FUNCTION )
						reporter->Warning("deprecated (%s)", (yyval.id)->Name());
					}

				delete [] (yyvsp[0].str);
				}

			else
				{
				const char* module_name =
					resolving_global_ID ?
						current_module.c_str() : 0;

				(yyval.id) = install_ID((yyvsp[0].str), module_name,
						true, is_export);
				}
			}
#line 4311 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 1630 "parse.y" /* yacc.c:1646  */
    {
			set_location((yylsp[0]));
			(yyval.id) = lookup_ID((yyvsp[0].str), current_module.c_str());

			if ( ! (yyval.id) )
				reporter->Error("identifier not defined: %s", (yyvsp[0].str));

			delete [] (yyvsp[0].str);
			}
#line 4325 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 1643 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = true; }
#line 4331 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 1645 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = false; }
#line 4337 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 1649 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = true; brofiler.IncIgnoreDepth(); }
#line 4343 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 1651 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = false; }
#line 4349 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 1655 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = true; }
#line 4355 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 1657 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = false; }
#line 4361 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
    break;


#line 4365 "/home/ubuntu/bro/my_build_dir/src/p.cc" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 1659 "parse.y" /* yacc.c:1906  */


int yyerror(const char msg[])
	{
	char* msgbuf = new char[strlen(msg) + strlen(last_tok) + 128];

	if ( last_tok[0] == '\n' )
		sprintf(msgbuf, "%s, on previous line", msg);
	else if ( last_tok[0] == '\0' )
		sprintf(msgbuf, "%s, at end of file", msg);
	else
		sprintf(msgbuf, "%s, at or near \"%s\"", msg, last_tok);

	if ( in_debug )
		g_curr_debug_error = copy_string(msg);

	reporter->Error("%s", msgbuf);

	return 0;
	}
