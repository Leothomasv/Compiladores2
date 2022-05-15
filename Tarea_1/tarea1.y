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



external_declaration: definition_block statement_list
    | statement_list
    | expr_list
    ;
statement_list: 
    |statement_list statement

statement: 
    | write_statement
    | assignation_statement
    ;
assignation_statement: TK_ID '=' expr_list ';'

write_statement: TK_WRITE '(' expr_list ')' ';'
    ;

definition_block: TK_DEF TK_ID declarations_list TK_END
    ;

declarations_list: 
    |declarations_list declarations
    ;

declarations: declarations
    | TK_ID ':' TK_INT ';'
    ;

expr_list: /*E*/
    |expr_list expression TK_EOL
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