%option noyywrap
%option yylineno
%option caseless

%{
    enum yytokentype{
        TK_PLUS = 258, 
        TK_MINUS = 259,
        TK_MULT = 260, 
        TK_NUMBER = 261,
        TK_DIV = 262,
        TK_EOL = 263,
        TK_FOR = 264
    };
    extern int yylval;
%}


%%
"+" {return TK_PLUS;}
"-" {return TK_MINUS;}
"/" {return TK_DIV;}
"*" {return TK_MULT;}
"for" {return TK_FOR;}
[0-9]+ {yylval = atoi(yytext); return TK_NUMBER;}
\n {return TK_EOL;}
\t {/*ignore*/}
. {printf("Invalid character %c\n", *yytext);}

%%