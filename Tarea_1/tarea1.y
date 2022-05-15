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

%token<string_t> TK_ID
%token<int_t> TK_NUMBER
%token TK_DEF TK_WRITE TK_END TK_EOL TK_INT

%%



external_declaration: statement
    | exprlist
    ;

statement: definition_statement
    | write_statement
    ;

write_statement: TK_WRITE '(' exprlist ')' ';'
    ;

definition_statement: TK_DEF TK_ID declarations TK_END
    ;

declarations: declarations
    | TK_ID ':' TK_INT ';'
    ;




exprlist: /*E*/
    |exprlist expression TK_EOL
    ;

expression: expression '+' factor
    | expression '-' factor
    | factor
    ;

factor:factor '*' term
    | factor '/' term
    | term
    ;

term: TK_NUMBER
    | TK_ID
    ;


%%