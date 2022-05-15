%{
    #include <cstdio>
    using namespace std;
    int yylex();
    extern int yylineno;

    void yyerror(const char * s){
        fprintf(stderr, "Line %d, error: %s\n", yylineno, s);
    }
%}

%union{
    const char* string_t;
    int int_t;
}

%token<string_t> TK_ID TK_LIT_STRING
%token<int_t> TK_LIT_INT
%token TK_DEF TK_WRITE TK_END TK_EOL

%%

scope: ;

%%