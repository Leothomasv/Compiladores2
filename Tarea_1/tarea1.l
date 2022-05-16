%option yylineno
%option noyywrap

%{
    #include "tokens.h"
%}

DIGIT [0-9]

%%
[\t \r \n] { /* do nothing */}

"def" {return TK_DEF;}
"write" {return TK_WRITE;}
"end" {return TK_END;}
"int" {return TK_INT;}
{DIGIT}+ { yylval.int_t = atoi(yytext); return TK_NUMBER;}
[a-zA-Z]({DIGIT}|[a-zA-Z_0-9]|_)* { yylval.string_t = strdup(yytext); return TK_ID;}

":" {return TK_COLON;}
";" {return TK_SEMICOLON;}
"=" {return TK_EQUAL;}
"+" {return TK_PLUS;}
"-" {return TK_MINUS;}
"/" {return TK_DIV;}
"*" {return TK_MULTI;}
"(" {return TK_LEFTPARENS;}
")" {return TK_RIGHTPARENS;}
\n {return TK_EOL;}
\t {/*ignore*/}
. {printf("Invalid character %c\n", *yytext);}

%%