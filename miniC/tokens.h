/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "minic.y"

    #include "ast.h"

#line 53 "tokens.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_ID = 258,                   /* TK_ID  */
    TK_LIT_STRING = 259,           /* TK_LIT_STRING  */
    TK_LIT_INT = 260,              /* TK_LIT_INT  */
    TK_LIT_FLOAT = 261,            /* TK_LIT_FLOAT  */
    TK_IF = 262,                   /* TK_IF  */
    TK_WHILE = 263,                /* TK_WHILE  */
    TK_VOID = 264,                 /* TK_VOID  */
    TK_INT_TYPE = 265,             /* TK_INT_TYPE  */
    TK_FLOAT_TYPE = 266,           /* TK_FLOAT_TYPE  */
    TK_PRINTF = 267,               /* TK_PRINTF  */
    TK_GTE = 268,                  /* TK_GTE  */
    TK_LTE = 269,                  /* TK_LTE  */
    TK_PLUS_EQUAL = 270,           /* TK_PLUS_EQUAL  */
    TK_LESS_EQUAL = 271,           /* TK_LESS_EQUAL  */
    TK_OR = 272,                   /* TK_OR  */
    TK_AND = 273,                  /* TK_AND  */
    TK_EQUALS = 274,               /* TK_EQUALS  */
    TK_NOT_EQUAL = 275,            /* TK_NOT_EQUAL  */
    TK_RETURN = 276,               /* TK_RETURN  */
    TK_ELSE = 277                  /* TK_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "minic.y"

    const char* string_t;
    int int_t;
    float float_t;
    Expr * expr_t;
    ArgumentList * argument_list_t;
    Statement * statement_t;
    StatementList * statement_list_t;
    DeclarationList * declaration_list_t;
    Declaration * declaration_t;
    Declarator * declarator_t;
    Parameter * parameter_t;
    ParameterList * parameter_list_t;
    InitializerList * initializer_list_t;
    InitDeclarator * init_declarator_t;
    InitDeclaratorList * init_declarator_list_t;

#line 110 "tokens.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKENS_H_INCLUDED  */
