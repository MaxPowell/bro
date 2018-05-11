/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 245 "parse.y" /* yacc.c:1909  */

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

#line 180 "/home/ubuntu/bro/my_build_dir/src/broparse.h" /* yacc.c:1909  */
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
