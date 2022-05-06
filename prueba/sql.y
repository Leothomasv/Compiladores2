%{
    #include <cstdio>
    using namespace std;
    int yylex();
    extern int yylineno;

    void yyerror(const char * err){
        fprintf(stderr, "Line %d, error: %s\n", yylineno, err);
    }
%}

%union{
    const char* string_t;
    int int_t;
    float float_t;
}

%token<string_t> TK_ID TK_STRING
%token<int_t> TK_NUMERO
%token<float_t> TK_FLOTANTE

%token TK_SELECT TK_FROM TK_UPDATE TK_DELETE TK_INSERT TK_WHERE TK_GROUPBY TK_INTO TK_IN TK_VALUES  TK_ORDERBY TK_ASC TK_DESC TK_EOF
%token TK_ASTERIC TK_MAYOR TK_MENOR TK_IGUAL TK_NOT_EQUAL TK_LEFT_PARENS TK_RIGHT_PARENS TK_INT_TYPE TK_FLOAT_TYPE TK_AND TK_OR TK_GREATER_EQUAL TK_LESS_EQUAL


%%

input: queries;

queries: queries query_statement
        |query_statement

query_statement: select_statement
        | update_statement
        | delete_statement
        | insert_statement
        ;


select_statement: TK_SELECT PARAM TK_FROM WHERE_OP GROUPBY_OP ORDERBY_OP;

update_statement: TK_UPDATE TK_ID TK_SET PARAM WHERE_OP ORDERBY_OP;

delete_statement: TK_DELETE TK_FROM TK_ID WHERE_OP;

insert_statement: TK_INSERT TK_INTO TK_ID '(' PARAM ')' TK_VALUES '(' PARAM ')';

PARAM_LIST: '*'
    |PARAM_LIST ',' PARAM
    |PARAM
    ;

PARAM: TK_ID
        | TK_NUMERO
        | TK_FLOTANTE
        | TK_STRING
        | PARAM TK_GREATER_EQUAL PARAM
        | PARAM TK_LESS_EQUAL PARAM
        ;


WHERE_OP: TK_WHERE WHERE_EXPR
        ;

WHERE_EXPR: WHERE_EXPR TK_IN '(' TK_VALUES ')'
        | WHERE_EXPR TK_IN '(' select_statement ')'
        | logical_or_expr
        ;

TK_SET:

ORDERBY_OP: TK_ORDERBY PARAM_LIST order_type
        ;

order_type: TK_ASC
        | TK_DESC
        | ''
        ;

GROUPBY_OP: TK_GROUPBY TK_ID
        ;


logical_or_expr: logical_or_expr TK_OR logical_and_expr
                    | logical_and_expr
                    ;

logical_and_expr: logical_and_expr TK_AND equal_expr
                      | equal_expr
                      ;
equal_expr: equal_expr '=' relational_expr
        | equal_expr TK_NOT_EQUAL relational_expr
        |relational_expr
        ;

relational_expr: relational_expr '>' add_expr
            | relational_expr '<' add_expr
            | relational_expr TK_GREATER_EQUAL add_expr
            | relational_expr TK_LESS_EQUAL add_expr
            | add_expr
            ;

add_expr: add_expr '+' multiply_expr
        | add_expr '-' multiply_expr
        |multiply_expr
        ;

multiply_expr: multiply_expr '*' div_expr
            | div_expr
            ;

div_expr: div_expr '/' factor
        | factor 
        ;

factor: TK_ID
    | TK_NUMERO
    | TK_FLOTANTE
    ;
%%