%option noyywrap
%option yylineno
%option caseless

%{
    #include "main.cpp"
    #define TK_PLUS 1;
    #define TK_MINUS 2;
    #define TK_MULT 3;
    #define TK_DIV 4;
    #define TK_NUMBER 5;
%}


%%
"+" {return TK_PLUS;}
"-" {return TK_MINUS;}
"/" {return TK_DIV;}
"*" {return TK_MULT;}

%%