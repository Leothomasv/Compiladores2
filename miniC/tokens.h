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
    TK_ELSE = 263,                 /* TK_ELSE  */
    TK_WHILE = 264,                /* TK_WHILE  */
    TK_VOID = 265,                 /* TK_VOID  */
    TK_INT_TYPE = 266,             /* TK_INT_TYPE  */
    TK_FLOAT_TYPE = 267,           /* TK_FLOAT_TYPE  */
    TK_PRINTF = 268,               /* TK_PRINTF  */
    TK_GTE = 269,                  /* TK_GTE  */
    TK_LTE = 270,                  /* TK_LTE  */
    TK_PLUS_EQUAL = 271,           /* TK_PLUS_EQUAL  */
    TK_LESS_EQUAL = 272,           /* TK_LESS_EQUAL  */
    TK_OR = 273,                   /* TK_OR  */
    TK_AND = 274,                  /* TK_AND  */
    TK_EQUALS = 275,               /* TK_EQUALS  */
    TK_NOT_EQUAL = 276,            /* TK_NOT_EQUAL  */
    TK_RETURN = 277,               /* TK_RETURN  */
    TK_CONTINUE = 278              /* TK_CONTINUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "minic.y"

    const char* string_t;
    int int_t;
    float float_t;

#line 93 "tokens.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKENS_H_INCLUDED  */
