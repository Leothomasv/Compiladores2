%option yylineno
%option noyywrap
%option caseless

%{
    #include "tokens.h"
%}

DIGIT [0-9]

%%
[\t \r] { /* do nothing */}
"SELECT" {return TK_SELECT;}
"FROM" {return TK_FROM; }
"UPDATE" {return TK_UPDATE; }
"DELETE" {return TK_DELETE; }
"INSERT" {return TK_INSERT; }
"WHERE" {return TK_WHERE; }
"GROUP BY" {return TK_GROUPBY; }
"INTO" {return TK_INTO;}
"VALUES" {return TK_VALUES;}
"IN" {return TK_IN; }
"ORDER BY" {return TK_ORDERBY; }
"ASC" {return TK_ASC; }
"DESC" {return TK_DESC; }
"INT" { return TK_INT_TYPE; }
"FLOAT" { return TK_FLOAT_TYPE; }
"OR" {return TK_OR; }
"AND" {return TK_AND; }
{DIGIT}+ { yylval.int_t = atoi(yytext); return TK_NUMERO;}
{DIGIT}+"."{DIGIT}+ { yylval.float_t = atof(yytext); return TK_FLOTANTE; }
[a-zA-Z]({DIGIT}|[a-zA-Z_0-9]|_)* { yylval.string_t = strdup(yytext); 
return TK_ID;}
\'.*\' { yylval.string_t = strdup(yytext); return TK_STRING; }
"*" {return '*'; }
">" {return '>'; }
"<" {return '<'; }
"<=" {return TK_GREATER_EQUAL; }
">=" {return TK_LESS_EQUAL; }
"=" {return '='; }
"!=" {return TK_NOT_EQUAL; }
"(" {return '('; }
")" {return ')'; }
";" {return ';'; }
\n {return TK_EOF;}

. {printf("Invalid character %c, line %d\n", yytext[0], yylineno);}
%%