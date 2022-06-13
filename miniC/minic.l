%option yylineno
%option noyywrap
%x comment

%{
    #include "tokens.h"
%}

DIGIT [0-9]

%%

[\t \r \n] { /* do nothing */}
"/*" { BEGIN(comment);}
"if" { return TK_IF; }
"else" { return TK_ELSE; }
"while" { return TK_WHILE; }
"void" { return TK_VOID; }
"int" { return TK_INT_TYPE; }
"float" { return TK_FLOAT_TYPE; }
"printf" { return TK_PRINTF; }
"return" { return TK_RETURN; }
{DIGIT}+ { yylval.int_t = atoi(yytext); return TK_LIT_INT;}
{DIGIT}+"."{DIGIT}+ { yylval.float_t = atof(yytext); return TK_LIT_FLOAT; }
[a-zA-Z]({DIGIT}|[a-zA-Z_0-9]|_)* { yylval.string_t = strdup(yytext); return TK_ID;}
\".*\" { yylval.string_t = strdup(yytext); return TK_LIT_STRING; }
"+" { return '+'; }
"!" { return '!'; }
";" { return ';'; }
"," { return ','; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }
"[" { return '['; }
"]" { return ']'; }
"=" { return '='; }
"{" { return '{'; }
"}" { return '}'; }
"%" { return '%'; }
"(" { return '('; }
")" { return ')'; }
">" { return '>'; }
"<" { return '<'; }
">=" { return TK_GTE; }
"<=" { return TK_LTE; }
"+=" { return TK_PLUS_EQUAL; }
"-=" { return TK_LESS_EQUAL; }
"||" { return TK_OR; }
"&&" { return TK_AND; }
"==" { return TK_EQUALS; }
"!=" { return TK_NOT_EQUAL; }
"//"[^\n]* {/* nothing */}
. {printf("Invalid character %c, line %d\n", yytext[0], yylineno); yyterminate();}

<comment>"*/" {BEGIN(INITIAL);}
<comment>.|\n {/* do nothing */}
<comment><<EOF>> {printf("incomplete comment, line: %d\n", yylineno); yyterminate();}

%%