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
#line 1 "builtin-func.y" /* yacc.c:339  */

#include <vector>
#include <set>
#include <string>
#include <cstring>

using namespace std;

#include <stdio.h>
#include <stdlib.h>

#include "module_util.h"

using namespace std;

extern int line_number;
extern char* input_filename;
extern char* plugin;

#define print_line_directive(fp) fprintf(fp, "\n#line %d \"%s\"\n", line_number, input_filename)

extern FILE* fp_bro_init;
extern FILE* fp_func_def;
extern FILE* fp_func_h;
extern FILE* fp_func_init;
extern FILE* fp_netvar_h;
extern FILE* fp_netvar_def;
extern FILE* fp_netvar_init;

int in_c_code = 0;
string current_module = GLOBAL_MODULE_NAME;
int definition_type;
string type_name;


enum {
	C_SEGMENT_DEF,
	FUNC_DEF,
	EVENT_DEF,
	TYPE_DEF,
	CONST_DEF,
};

// Holds the name of a declared object (function, enum, record type, event,
// etc. and information about namespaces, etc.
struct decl_struct {
	string module_name;
	string bare_name; // name without module or namespace
	string c_namespace_start; // "opening" namespace for use in netvar_*
	string c_namespace_end;   // closing "}" for all the above namespaces
	string c_fullname; // fully qualified name (namespace::....) for use in netvar_init
	string bro_fullname; // fully qualified bro name, for netvar (and lookup_ID())
	string bro_name;  // the name as we read it from input. What we write into the .bro file

	// special cases for events. Events have an EventHandlerPtr
	// and a generate_* function. This name is for the generate_* function
	string generate_bare_name;
	string generate_c_fullname;
	string generate_c_namespace_start;
	string generate_c_namespace_end;
} decl;

void set_definition_type(int type, const char *arg_type_name)
	{
	definition_type = type;
	if ( type == TYPE_DEF && arg_type_name )
		type_name = string(arg_type_name);
	else
		type_name = "";
	}

void set_decl_name(const char *name)
	{
	decl.bare_name = extract_var_name(name);

	// make_full_var_name prepends the correct module, if any
	// then we can extract the module name again.
	string varname = make_full_var_name(current_module.c_str(), name);
	decl.module_name = extract_module_name(varname.c_str());

	decl.c_namespace_start = "";
	decl.c_namespace_end = "";
	decl.c_fullname = "";
	decl.bro_fullname = "";
	decl.bro_name = "";

	decl.generate_c_fullname = "";
	decl.generate_bare_name = string("generate_") + decl.bare_name;
	decl.generate_c_namespace_start = "";
	decl.generate_c_namespace_end = "";

	switch ( definition_type ) {
	case TYPE_DEF:
		decl.c_namespace_start = "namespace BifType { namespace " + type_name + "{ ";
		decl.c_namespace_end = " } }";
		decl.c_fullname = "BifType::" + type_name + "::";
		break;

	case CONST_DEF:
		decl.c_namespace_start = "namespace BifConst { ";
		decl.c_namespace_end = " } ";
		decl.c_fullname = "BifConst::";
		break;

	case FUNC_DEF:
		decl.c_namespace_start = "namespace BifFunc { ";
		decl.c_namespace_end = " } ";
		decl.c_fullname = "BifFunc::";
		break;

	case EVENT_DEF:
		decl.c_namespace_start = "";
		decl.c_namespace_end = "";
		decl.c_fullname = "::";  // need this for namespace qualified events due do event_c_body
		decl.generate_c_namespace_start = "namespace BifEvent { ";
		decl.generate_c_namespace_end = " } ";
		decl.generate_c_fullname = "BifEvent::";
		break;

	default:
		break;
	}

	if ( decl.module_name != GLOBAL_MODULE_NAME )
		{
		decl.c_namespace_start += "namespace " + decl.module_name + " { ";
		decl.c_namespace_end += string(" }");
		decl.c_fullname += decl.module_name + "::";
		decl.bro_fullname += decl.module_name + "::";

		decl.generate_c_namespace_start  += "namespace " + decl.module_name + " { ";
		decl.generate_c_namespace_end += " } ";
		decl.generate_c_fullname += decl.module_name + "::";
		}

	decl.bro_fullname += decl.bare_name;
	if ( definition_type == FUNC_DEF )
		decl.bare_name = string("bro_") + decl.bare_name;

	decl.c_fullname += decl.bare_name;
	decl.bro_name += name;
	decl.generate_c_fullname += decl.generate_bare_name;

	}

const char* arg_list_name = "BiF_ARGS";

#include "bif_arg.h"

/* Map bif/bro type names to C types for use in const declaration */
static struct {
	const char* bif_type;
	const char* bro_type;
	const char* c_type;
	const char* accessor;
	const char* constructor;
} builtin_types[] = {
#define DEFINE_BIF_TYPE(id, bif_type, bro_type, c_type, accessor, constructor) \
	{bif_type, bro_type, c_type, accessor, constructor},
#include "bif_type.def"
#undef DEFINE_BIF_TYPE
};

int get_type_index(const char *type_name)
	{
	for ( int i = 0; builtin_types[i].bif_type[0] != '\0'; ++i )
		{
		if ( strcmp(builtin_types[i].bif_type, type_name) == 0 )
			return i;
		}
		return TYPE_OTHER;
	}


int var_arg; // whether the number of arguments is variable
std::vector<BuiltinFuncArg*> args;

extern int yyerror(const char[]);
extern int yywarn(const char msg[]);
extern int yylex();

char* concat(const char* str1, const char* str2)
	{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	char* s = new char[len1 + len2 +1];

	memcpy(s, str1, len1);
	memcpy(s + len1, str2, len2);

	s[len1+len2] = '\0';

	return s;
	}

// Print the bro_event_* function prototype in C++, without the ending ';'
void print_event_c_prototype(FILE *fp, bool is_header)
	{
	if ( is_header )
		fprintf(fp, "%s void %s(analyzer::Analyzer* analyzer%s",
			decl.generate_c_namespace_start.c_str(), decl.generate_bare_name.c_str(),
			args.size() ? ", " : "" );
	else
		fprintf(fp, "void %s(analyzer::Analyzer* analyzer%s",
			decl.generate_c_fullname.c_str(),
			args.size() ? ", " : "" );
	for ( int i = 0; i < (int) args.size(); ++i )
		{
		if ( i > 0 )
			fprintf(fp, ", ");
		args[i]->PrintCArg(fp, i);
		}
	fprintf(fp, ")");
	if ( is_header )
		fprintf(fp, "; %s\n", decl.generate_c_namespace_end.c_str());
	else
		fprintf(fp, "\n");
	}

// Print the bro_event_* function body in C++.
void print_event_c_body(FILE *fp)
	{
	fprintf(fp, "\t{\n");
	fprintf(fp, "\t// Note that it is intentional that here we do not\n");
	fprintf(fp, "\t// check if %s is NULL, which should happen *before*\n",
		decl.c_fullname.c_str());
	fprintf(fp, "\t// %s is called to avoid unnecessary Val\n",
		decl.generate_c_fullname.c_str());
	fprintf(fp, "\t// allocation.\n");
	fprintf(fp, "\n");

	fprintf(fp, "\tval_list* vl = new val_list;\n\n");
	BuiltinFuncArg *connection_arg = 0;

	for ( int i = 0; i < (int) args.size(); ++i )
		{
		fprintf(fp, "\t");
		fprintf(fp, "vl->append(");
		args[i]->PrintBroValConstructor(fp);
		fprintf(fp, ");\n");

		if ( args[i]->Type() == TYPE_CONNECTION )
			{
			if ( connection_arg == 0 )
				connection_arg = args[i];
			else
				{
				// We are seeing two connection type arguments.
				yywarn("Warning: with more than connection-type "
				       "event arguments, bifcl only passes "
				       "the first one to EventMgr as cookie.");
				}
			}
		}

	fprintf(fp, "\n");
	fprintf(fp, "\tmgr.QueueEvent(%s, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr",
		decl.c_fullname.c_str());

	if ( connection_arg )
		// Pass the connection to the EventMgr as the "cookie"
		fprintf(fp, ", %s", connection_arg->Name());

	fprintf(fp, ");\n");
	fprintf(fp, "\t} // event generation\n");
	//fprintf(fp, "%s // end namespace\n", decl.generate_c_namespace_end.c_str());
	}

void record_bif_item(const char* id, const char* type)
	{
	if ( ! plugin )
		return;

	fprintf(fp_func_init, "\tplugin->AddBifItem(\"%s\", plugin::BifItem::%s);\n", id, type);
	}


#line 345 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:339  */

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
   by #include "bif_parse.h".  */
#ifndef YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BIF_PARSE_H_INCLUDED
# define YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BIF_PARSE_H_INCLUDED
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
    TOK_LPP = 258,
    TOK_RPP = 259,
    TOK_LPB = 260,
    TOK_RPB = 261,
    TOK_LPPB = 262,
    TOK_RPPB = 263,
    TOK_VAR_ARG = 264,
    TOK_BOOL = 265,
    TOK_FUNCTION = 266,
    TOK_EVENT = 267,
    TOK_CONST = 268,
    TOK_ENUM = 269,
    TOK_OF = 270,
    TOK_TYPE = 271,
    TOK_RECORD = 272,
    TOK_SET = 273,
    TOK_VECTOR = 274,
    TOK_OPAQUE = 275,
    TOK_TABLE = 276,
    TOK_MODULE = 277,
    TOK_ARGS = 278,
    TOK_ARG = 279,
    TOK_ARGC = 280,
    TOK_ID = 281,
    TOK_ATTR = 282,
    TOK_CSTR = 283,
    TOK_LF = 284,
    TOK_WS = 285,
    TOK_COMMENT = 286,
    TOK_ATOM = 287,
    TOK_INT = 288,
    TOK_C_TOKEN = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 293 "builtin-func.y" /* yacc.c:355  */

	const char* str;
	int val;

#line 425 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_UBUNTU_BRO_MY_BUILD_DIR_SRC_BIF_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 442 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    37,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   300,   300,   308,   315,   322,   323,   324,   325,   326,
     327,   328,   332,   346,   365,   367,   369,   371,   375,   378,
     382,   381,   390,   389,   393,   417,   433,   438,   443,   447,
     473,   476,   480,   482,   485,   489,   494,   499,   504,   525,
     582,   586,   589,   590,   594,   596,   604,   606,   610,   612,
     620,   629,   637,   644,   647,   684,   690,   693,   695,   699,
     701,   703,   705,   707,   709,   711,   713,   718,   720,   722,
     735
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_LPP", "TOK_RPP", "TOK_LPB",
  "TOK_RPB", "TOK_LPPB", "TOK_RPPB", "TOK_VAR_ARG", "TOK_BOOL",
  "TOK_FUNCTION", "TOK_EVENT", "TOK_CONST", "TOK_ENUM", "TOK_OF",
  "TOK_TYPE", "TOK_RECORD", "TOK_SET", "TOK_VECTOR", "TOK_OPAQUE",
  "TOK_TABLE", "TOK_MODULE", "TOK_ARGS", "TOK_ARG", "TOK_ARGC", "TOK_ID",
  "TOK_ATTR", "TOK_CSTR", "TOK_LF", "TOK_WS", "TOK_COMMENT", "TOK_ATOM",
  "TOK_INT", "TOK_C_TOKEN", "','", "':'", "';'", "'='", "$accept",
  "builtin_lang", "definitions", "definition", "module_def", "type_def",
  "type_def_types", "opt_func_attrs", "event_def", "$@1", "func_def",
  "$@2", "enum_def", "enum_def_1", "enum_list", "const_def", "attr_list",
  "opt_attr_list", "func_prefix", "event_prefix", "end_of_head",
  "typed_head", "plain_head", "head_1", "arg_begin", "arg_end", "args",
  "args_1", "type", "arg", "return_type", "body", "c_code_begin",
  "c_code_end", "body_start", "body_end", "c_code_segment", "c_body",
  "c_atom", "opt_ws", YY_NULLPTR
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
     285,   286,   287,   288,   289,    44,    58,    59,    61
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,     1,    73,    67,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,   139,   145,   151,
     157,    67,     9,   163,   163,   101,    67,  -105,  -105,  -105,
    -105,   -20,  -105,  -105,   -20,   -23,  -105,   -20,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,     6,  -105,   120,    29,
     123,    18,  -105,    -8,  -105,   108,    23,  -105,    -8,  -105,
    -105,    25,    -5,    35,  -105,  -105,    67,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,    67,    88,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   169,    67,    82,    67,
      76,    31,  -105,  -105,  -105,    67,    35,   131,   180,     4,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     -13,    67,  -105,  -105,  -105,  -105,    44,   111,    41,  -105,
      -1,  -105,   180,    88,  -105,  -105,  -105,  -105,  -105,   175,
    -105,  -105,    67,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      70,     0,     2,     4,     1,    52,    34,    35,    70,    70,
      70,    70,    70,    11,    10,     5,     6,     8,    28,     9,
      70,    70,     7,    68,    67,    69,    70,     0,     0,     0,
       0,     3,     0,     0,     0,    53,    57,    70,    70,    70,
      70,    33,    70,    70,    19,     0,    70,    19,    62,    61,
      63,    59,    64,    65,    66,    60,     0,    70,     0,     0,
       0,     0,    31,    32,    24,     0,     0,    22,    70,    70,
      37,     0,    42,    43,    20,    56,    58,    70,    70,    70,
      12,    30,    70,    70,    40,    39,    36,    18,     0,    41,
      70,    70,    49,    70,    70,    36,     0,    25,     0,    26,
       0,     0,    70,    47,    70,    38,     0,     0,    33,     0,
      70,    14,    15,    16,    17,    70,    70,    52,    23,    70,
       0,    50,    70,    70,    45,    21,     0,     0,     0,    54,
       0,    70,    33,     0,    29,    13,    70,    53,    51,     0,
      44,    48,    27,    55,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,  -105,  -105,  -105,  -105,  -105,    -2,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   -41,  -104,  -105,  -105,
     -45,  -105,    17,  -105,  -105,  -105,  -105,  -105,   -77,   -44,
    -105,  -105,   -54,   -70,  -105,  -105,  -105,   -31,  -105,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    13,    14,   115,    67,    15,    95,
      16,    86,    17,    18,    32,    19,    63,    64,    20,    21,
     101,    44,    45,    46,    85,    90,    71,    72,   104,    94,
      70,   118,    26,    56,   119,   138,    22,    35,    57,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       3,     4,   131,    68,   124,   137,    68,    62,    27,    28,
      29,    30,    31,    69,    75,    41,    23,    24,    25,    81,
      33,    34,    48,    49,    50,    51,    84,    52,   140,    89,
      91,    53,    54,    55,    78,    42,   117,    58,    59,    60,
      61,   125,    65,    66,    92,    74,    73,    23,    24,    25,
     109,    47,    23,    24,    25,    80,   141,    76,    23,    24,
      25,    93,   122,   129,    23,    24,    25,   143,    87,    88,
      23,    24,    25,    23,    24,    25,   136,    96,    97,    98,
       5,   134,    99,   100,     6,     7,     8,     9,   130,    10,
     105,   106,     0,   107,   108,    11,    23,    24,    25,   111,
     112,   113,   120,   114,   121,    23,    24,    25,   102,   116,
     126,    23,    24,    25,   103,   127,   128,    23,    24,    25,
       0,     0,   132,   133,    48,    49,    50,    51,     0,    52,
       0,   139,     0,    53,    54,    55,   142,    23,    24,    25,
      23,    24,    25,    82,     0,     0,    83,     0,   135,    23,
      24,    25,    23,    24,    25,     0,    77,     0,     0,    79,
      23,    24,    25,     0,     0,    37,     0,   123,    23,    24,
      25,    38,     0,     0,    23,    24,    25,    39,     0,     0,
      23,    24,    25,    40,     0,     0,    23,    24,    25,    43,
       0,     0,    23,    24,    25,   110,     0,     0,    23,    24,
      25,   144,     0,     0,    23,    24,    25,    62,     0,    23,
      24,    25
};

static const yytype_int16 yycheck[] =
{
       0,     0,    15,    44,   108,     6,    47,    27,     8,     9,
      10,    11,    12,    36,     8,     6,    29,    30,    31,    27,
      20,    21,    23,    24,    25,    26,     3,    28,   132,     4,
      35,    32,    33,    34,     5,    26,     5,    37,    38,    39,
      40,    37,    42,    43,     9,    47,    46,    29,    30,    31,
      95,    34,    29,    30,    31,    37,   133,    57,    29,    30,
      31,    26,   106,   117,    29,    30,    31,   137,    68,    69,
      29,    30,    31,    29,    30,    31,    35,    77,    78,    79,
       7,    37,    82,    83,    11,    12,    13,    14,   119,    16,
      90,    91,    -1,    93,    94,    22,    29,    30,    31,    17,
      18,    19,   102,    21,   104,    29,    30,    31,    20,    33,
     110,    29,    30,    31,    26,   115,   116,    29,    30,    31,
      -1,    -1,   122,   123,    23,    24,    25,    26,    -1,    28,
      -1,   131,    -1,    32,    33,    34,   136,    29,    30,    31,
      29,    30,    31,    35,    -1,    -1,    38,    -1,    37,    29,
      30,    31,    29,    30,    31,    -1,    36,    -1,    -1,    36,
      29,    30,    31,    -1,    -1,    26,    -1,    36,    29,    30,
      31,    26,    -1,    -1,    29,    30,    31,    26,    -1,    -1,
      29,    30,    31,    26,    -1,    -1,    29,    30,    31,    26,
      -1,    -1,    29,    30,    31,    26,    -1,    -1,    29,    30,
      31,    26,    -1,    -1,    29,    30,    31,    27,    -1,    29,
      30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,    78,     0,     7,    11,    12,    13,    14,
      16,    22,    42,    43,    44,    47,    49,    51,    52,    54,
      57,    58,    75,    29,    30,    31,    71,    78,    78,    78,
      78,    78,    53,    78,    78,    76,    78,    26,    26,    26,
      26,     6,    26,    26,    60,    61,    62,    61,    23,    24,
      25,    26,    28,    32,    33,    34,    72,    77,    78,    78,
      78,    78,    27,    55,    56,    78,    78,    46,    55,    36,
      69,    65,    66,    78,    46,     8,    78,    36,     5,    36,
      37,    27,    35,    38,     3,    63,    50,    78,    78,     4,
      64,    35,     9,    26,    68,    48,    78,    78,    78,    78,
      78,    59,    20,    26,    67,    78,    78,    78,    78,    59,
      26,    17,    18,    19,    21,    45,    33,     5,    70,    73,
      78,    78,    68,    36,    56,    37,    78,    78,    78,    71,
      76,    15,    78,    78,    37,    37,    35,     6,    74,    78,
      56,    67,    78,    72,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    43,    44,    45,    45,    45,    45,    46,    46,
      48,    47,    50,    49,    51,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     9,     1,     1,     1,     1,     2,     0,
       0,     7,     0,     7,     4,     6,     5,     9,     0,     9,
       2,     1,     1,     0,     1,     1,     0,     2,     4,     3,
       1,     1,     1,     1,     6,     4,     5,     1,     5,     1,
       4,     3,     0,     0,     2,     2,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       0
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
        case 2:
#line 301 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_bro_init, "} # end of export section\n");
			fprintf(fp_bro_init, "module %s;\n", GLOBAL_MODULE_NAME);
			}
#line 1640 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 309 "builtin-func.y" /* yacc.c:1646  */
    {
			if ( in_c_code )
				fprintf(fp_func_def, "%s", (yyvsp[0].str));
			else
				fprintf(fp_bro_init, "%s", (yyvsp[0].str));
			}
#line 1651 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 316 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_bro_init, "%s", (yyvsp[0].str));
			fprintf(fp_bro_init, "export {\n");
			}
#line 1660 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 333 "builtin-func.y" /* yacc.c:1646  */
    {
			current_module = string((yyvsp[-2].str));
			fprintf(fp_bro_init, "module %s;\n", (yyvsp[-2].str));
			}
#line 1669 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 347 "builtin-func.y" /* yacc.c:1646  */
    {
			set_decl_name((yyvsp[-6].str));

			fprintf(fp_netvar_h, "%s extern %sType * %s; %s\n",
				decl.c_namespace_start.c_str(), type_name.c_str(),
				decl.bare_name.c_str(), decl.c_namespace_end.c_str());
			fprintf(fp_netvar_def, "%s %sType * %s; %s\n",
				decl.c_namespace_start.c_str(), type_name.c_str(),
				decl.bare_name.c_str(), decl.c_namespace_end.c_str());
			fprintf(fp_netvar_init,
				"\t%s = internal_type(\"%s\")->As%sType();\n",
				decl.c_fullname.c_str(), decl.bro_fullname.c_str(),
				type_name.c_str());

			record_bif_item(decl.bro_fullname.c_str(), "TYPE");
			}
#line 1690 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 366 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(TYPE_DEF, "Record"); }
#line 1696 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 368 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(TYPE_DEF, "Set"); }
#line 1702 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 370 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(TYPE_DEF, "Vector"); }
#line 1708 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 372 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(TYPE_DEF, "Table"); }
#line 1714 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 376 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 1720 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 378 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = ""; }
#line 1726 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 382 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_bro_init, "%s", (yyvsp[0].str)); }
#line 1732 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 383 "builtin-func.y" /* yacc.c:1646  */
    {
			print_event_c_prototype(fp_func_h, true);
			print_event_c_prototype(fp_func_def, false);
			print_event_c_body(fp_func_def);
			}
#line 1742 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 390 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_bro_init, "%s", (yyvsp[0].str)); }
#line 1748 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 394 "builtin-func.y" /* yacc.c:1646  */
    {
			// First, put an end to the enum type decl.
			fprintf(fp_bro_init, "} ");
			fprintf(fp_bro_init, "%s", (yyvsp[0].str));
			fprintf(fp_bro_init, ";\n");
			if ( decl.module_name != GLOBAL_MODULE_NAME )
				fprintf(fp_netvar_h, "}; } }\n");
			else
				fprintf(fp_netvar_h, "}; }\n");

			// Now generate the netvar's.
			fprintf(fp_netvar_h, "%s extern EnumType * %s; %s\n",
				decl.c_namespace_start.c_str(), decl.bare_name.c_str(), decl.c_namespace_end.c_str());
			fprintf(fp_netvar_def, "%s EnumType * %s; %s\n",
				decl.c_namespace_start.c_str(), decl.bare_name.c_str(), decl.c_namespace_end.c_str());
			fprintf(fp_netvar_init,
				"\t%s = internal_type(\"%s\")->AsEnumType();\n",
				decl.c_fullname.c_str(), decl.bro_fullname.c_str());

			record_bif_item(decl.bro_fullname.c_str(), "TYPE");
			}
#line 1774 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 418 "builtin-func.y" /* yacc.c:1646  */
    {
			set_definition_type(TYPE_DEF, "Enum");
			set_decl_name((yyvsp[-3].str));
			fprintf(fp_bro_init, "type %s: enum %s{%s", decl.bro_name.c_str(), (yyvsp[-2].str), (yyvsp[0].str));

			// this is the namespace were the enumerators are defined, not where
			// the type is defined.
			// We don't support fully qualified names as enumerators. Use a module name
			fprintf(fp_netvar_h, "namespace BifEnum { ");
			if ( decl.module_name != GLOBAL_MODULE_NAME )
				fprintf(fp_netvar_h, "namespace %s { ", decl.module_name.c_str());
			fprintf(fp_netvar_h, "enum %s {\n", (yyvsp[-3].str));
			}
#line 1792 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 434 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_bro_init, "%s%s,%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].str));
			fprintf(fp_netvar_h, "\t%s,\n", (yyvsp[-3].str));
			}
#line 1801 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 439 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_bro_init, "%s = %s%s,%s", (yyvsp[-7].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].str));
			fprintf(fp_netvar_h, "\t%s = %s,\n", (yyvsp[-7].str), (yyvsp[-3].str));
			}
#line 1810 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 448 "builtin-func.y" /* yacc.c:1646  */
    {
			set_definition_type(CONST_DEF, 0);
			set_decl_name((yyvsp[-6].str));
			int typeidx = get_type_index((yyvsp[-2].str));
			char accessor[1024];

			snprintf(accessor, sizeof(accessor), builtin_types[typeidx].accessor, "");


			fprintf(fp_netvar_h, "%s extern %s %s; %s\n",
					decl.c_namespace_start.c_str(),
					builtin_types[typeidx].c_type, decl.bare_name.c_str(),
					decl.c_namespace_end.c_str());
			fprintf(fp_netvar_def, "%s %s %s; %s\n",
					decl.c_namespace_start.c_str(),
					builtin_types[typeidx].c_type, decl.bare_name.c_str(),
					decl.c_namespace_end.c_str());
			fprintf(fp_netvar_init, "\t%s = internal_const_val(\"%s\")%s;\n",
				decl.c_fullname.c_str(), decl.bro_fullname.c_str(),
				accessor);

			record_bif_item(decl.bro_fullname.c_str(), "CONSTANT");
			}
#line 1838 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 474 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1844 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 482 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = ""; }
#line 1850 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 486 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(FUNC_DEF, 0); }
#line 1856 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 490 "builtin-func.y" /* yacc.c:1646  */
    { set_definition_type(EVENT_DEF, 0); }
#line 1862 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 494 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_bro_init, ";\n");
			}
#line 1870 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 500 "builtin-func.y" /* yacc.c:1646  */
    {
			}
#line 1877 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 505 "builtin-func.y" /* yacc.c:1646  */
    {
			if ( var_arg )
				fprintf(fp_bro_init, "va_args: any");
			else
				{
				for ( int i = 0; i < (int) args.size(); ++i )
					{
					if ( i > 0 )
						fprintf(fp_bro_init, ", ");
					args[i]->PrintBro(fp_bro_init);
					}
				}

			fprintf(fp_bro_init, ")");

			fprintf(fp_bro_init, "%s", (yyvsp[0].str));
			fprintf(fp_func_def, "%s", (yyvsp[0].str));
			}
#line 1900 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 526 "builtin-func.y" /* yacc.c:1646  */
    {
			const char* method_type = 0;
			set_decl_name((yyvsp[-2].str));

			if ( definition_type == FUNC_DEF )
				{
				method_type = "function";
				print_line_directive(fp_func_def);
				}
			else if ( definition_type == EVENT_DEF )
				method_type = "event";

			if ( method_type )
				fprintf(fp_bro_init,
					"global %s: %s%s(",
					decl.bro_name.c_str(), method_type, (yyvsp[-1].str));

			if ( definition_type == FUNC_DEF )
				{
				fprintf(fp_func_init,
					"\t(void) new BuiltinFunc(%s, \"%s\", 0);\n",
					decl.c_fullname.c_str(), decl.bro_fullname.c_str());

				fprintf(fp_func_h,
					"%sextern Val* %s(Frame* frame, val_list*);%s\n",
					decl.c_namespace_start.c_str(), decl.bare_name.c_str(), decl.c_namespace_end.c_str());

				fprintf(fp_func_def,
					"Val* %s(Frame* frame, val_list* %s)",
					decl.c_fullname.c_str(), arg_list_name);

				record_bif_item(decl.bro_fullname.c_str(), "FUNCTION");
				}
			else if ( definition_type == EVENT_DEF )
				{
				// TODO: add namespace for events here
				fprintf(fp_netvar_h,
					"%sextern EventHandlerPtr %s; %s\n",
					decl.c_namespace_start.c_str(), decl.bare_name.c_str(), decl.c_namespace_end.c_str());

				fprintf(fp_netvar_def,
					"%sEventHandlerPtr %s; %s\n",
					decl.c_namespace_start.c_str(), decl.bare_name.c_str(), decl.c_namespace_end.c_str());

				fprintf(fp_netvar_init,
					"\t%s = internal_handler(\"%s\");\n",
					decl.c_fullname.c_str(), decl.bro_fullname.c_str());

				record_bif_item(decl.bro_fullname.c_str(), "EVENT");

				// C++ prototypes of bro_event_* functions will
				// be generated later.
				}
			}
#line 1959 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 583 "builtin-func.y" /* yacc.c:1646  */
    { args.clear(); var_arg = 0; }
#line 1965 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 591 "builtin-func.y" /* yacc.c:1646  */
    { /* empty, to avoid yacc complaint about type clash */ }
#line 1971 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 595 "builtin-func.y" /* yacc.c:1646  */
    { if ( ! args.empty() ) args[args.size()-1]->SetAttrStr((yyvsp[0].str)); }
#line 1977 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 597 "builtin-func.y" /* yacc.c:1646  */
    { if ( ! args.empty() ) args[args.size()-1]->SetAttrStr((yyvsp[0].str)); }
#line 1983 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 605 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = concat("opaque of ", (yyvsp[0].str)); }
#line 1989 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 607 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1995 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 611 "builtin-func.y" /* yacc.c:1646  */
    { args.push_back(new BuiltinFuncArg((yyvsp[-4].str), (yyvsp[0].str))); }
#line 2001 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 613 "builtin-func.y" /* yacc.c:1646  */
    {
			if ( definition_type == EVENT_DEF )
				yyerror("events cannot have variable arguments");
			var_arg = 1;
			}
#line 2011 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 621 "builtin-func.y" /* yacc.c:1646  */
    {
			BuiltinFuncArg* ret = new BuiltinFuncArg("", (yyvsp[-1].str));
			ret->PrintBro(fp_bro_init);
			delete ret;
			fprintf(fp_func_def, "%s", (yyvsp[0].str));
			}
#line 2022 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 630 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_func_def, " // end of %s\n", decl.c_fullname.c_str());
			print_line_directive(fp_func_def);
			}
#line 2031 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 637 "builtin-func.y" /* yacc.c:1646  */
    {
			in_c_code = 1;
			print_line_directive(fp_func_def);
			}
#line 2040 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 644 "builtin-func.y" /* yacc.c:1646  */
    { in_c_code = 0; }
#line 2046 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 648 "builtin-func.y" /* yacc.c:1646  */
    {
			int implicit_arg = 0;
			int argc = args.size();

			fprintf(fp_func_def, "{");

			if ( argc > 0 || ! var_arg )
				fprintf(fp_func_def, "\n");

			if ( ! var_arg )
				{
				fprintf(fp_func_def, "\tif ( %s->length() != %d )\n", arg_list_name, argc);
				fprintf(fp_func_def, "\t\t{\n");
				fprintf(fp_func_def,
					"\t\treporter->Error(\"%s() takes exactly %d argument(s)\");\n",
					decl.bro_fullname.c_str(), argc);
				fprintf(fp_func_def, "\t\treturn 0;\n");
				fprintf(fp_func_def, "\t\t}\n");
				}
			else if ( argc > 0 )
				{
				fprintf(fp_func_def, "\tif ( %s->length() < %d )\n", arg_list_name, argc);
				fprintf(fp_func_def, "\t\t{\n");
				fprintf(fp_func_def,
					"\t\treporter->Error(\"%s() takes at least %d argument(s)\");\n",
					decl.bro_fullname.c_str(), argc);
				fprintf(fp_func_def, "\t\treturn 0;\n");
				fprintf(fp_func_def, "\t\t}\n");
				}

			for ( int i = 0; i < (int) args.size(); ++i )
				args[i]->PrintCDef(fp_func_def, i + implicit_arg);
			print_line_directive(fp_func_def);
			}
#line 2085 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 685 "builtin-func.y" /* yacc.c:1646  */
    {
			fprintf(fp_func_def, "}");
			}
#line 2093 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 694 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2099 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 696 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2105 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 700 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2111 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 702 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2117 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 704 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "(*%s)", arg_list_name); }
#line 2123 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 706 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", arg_list_name); }
#line 2129 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 708 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s->length()", arg_list_name); }
#line 2135 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 710 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2141 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 712 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%c", (yyvsp[0].val)); }
#line 2147 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 714 "builtin-func.y" /* yacc.c:1646  */
    { fprintf(fp_func_def, "%s", (yyvsp[0].str)); }
#line 2153 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 719 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str)); }
#line 2159 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 721 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = concat((yyvsp[-1].str), "\n"); }
#line 2165 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 723 "builtin-func.y" /* yacc.c:1646  */
    {
			if ( in_c_code )
				(yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str));
			else
				if ( (yyvsp[0].str)[1] == '#' )
					// This is a special type of comment that is used to
					// generate bro script documentation, so pass it through.
					(yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str));
				else
					(yyval.str) = (yyvsp[-1].str);
			}
#line 2181 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 735 "builtin-func.y" /* yacc.c:1646  */
    { (yyval.str) = ""; }
#line 2187 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
    break;


#line 2191 "/home/ubuntu/bro/my_build_dir/src/bif_parse.cc" /* yacc.c:1646  */
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
#line 738 "builtin-func.y" /* yacc.c:1906  */


extern char* yytext;
extern char* input_filename;
extern int line_number;
void err_exit(void);

void print_msg(const char msg[])
	{
	int msg_len = strlen(msg) + strlen(yytext) + 64;
	char* msgbuf = new char[msg_len];

	if ( yytext[0] == '\n' )
		snprintf(msgbuf, msg_len, "%s, on previous line", msg);

	else if ( yytext[0] == '\0' )
		snprintf(msgbuf, msg_len, "%s, at end of file", msg);

	else
		snprintf(msgbuf, msg_len, "%s, at or near \"%s\"", msg, yytext);

	/*
	extern int column;
	sprintf(msgbuf, "%*s\n%*s\n", column, "^", column, msg);
	*/

	if ( input_filename )
		fprintf(stderr, "%s:%d: ", input_filename, line_number);
	else
		fprintf(stderr, "line %d: ", line_number);
	fprintf(stderr, "%s\n", msgbuf);

	delete [] msgbuf;
	}

int yywarn(const char msg[])
	{
	print_msg(msg);
	return 0;
	}

int yyerror(const char msg[])
	{
	print_msg(msg);

	err_exit();
	return 0;
	}
