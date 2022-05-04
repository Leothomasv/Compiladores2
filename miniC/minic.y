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
    float float_t;
}

%token<string_t> TK_ID TK_LIT_STRING
%token<int_t> TK_LIT_INT
%token<float_t> TK_LIT_FLOAT
%token TK_IF TK_ELSE
%token TK_WHILE
%token TK_VOID TK_INT_TYPE TK_FLOAT_TYPE
%token TK_PRINTF
%token TK_GTE TK_LTE TK_PLUS_EQUAL TK_LESS_EQUAL
%token TK_OR TK_AND TK_EQUALS TK_NOT_EQUAL TK_RETURN TK_CONTINUE

%%

input: input external_declaration
    | external_declaration
    ;

external_declaration: method_definition
                    | declaration
                    ;

declaration: type init_declarator_list ';'
           ;

init_declarator_list: init_declarator_list ',' init_declarator
                    | init_declarator
                    ;

init_declarator: declarator
             | declarator '=' initializer
            ; 

initializer: assignment_expression
           | '{' initializer_list '}'
           ;

initializer_list: initializer_list ',' logical_or_expression
                | logical_or_expression
                ;

method_definition: type TK_ID '(' parameter_type_list ')' block_statement
                 | type TK_ID '(' ')' block_statement
                 | type TK_ID '(' parameter_type_list ')' ';'
                 | type TK_ID '(' ')' ';'
                 ;

type: TK_VOID
    | TK_INT_TYPE
    | TK_FLOAT_TYPE
    ;

parameter_type_list: parameter_type_list ',' parameter_declaration
                   | parameter_declaration
                   ;

parameter_declaration: type declarator
                    ;

declarator: TK_ID
          | TK_ID '[' assignment_expression ']'
          | TK_ID '['  ']'
          ;

block_statement: '{' declaration_list statement_list '}'
               | '{' '}'
               ;

declaration_list: declaration_list declaration
                | declaration
                ;

statement_list: statement_list statement
              | statement
              ;

statement: while_statement
         | expression_statement
         | if_statement
         | block_statement
         | TK_PRINTF assignment_expression ';'
         | jump_statement
         ;

while_statement: TK_WHILE '(' assignment_expression ')' statement
               ;

expression_statement: ';'
                    | assignment_expression ';'
                    ;

if_statement: TK_IF '(' assignment_expression ')' statement
            | TK_IF '(' assignment_expression ')' statement TK_ELSE statement
            ;

jump_statement: TK_RETURN ';'
              | TK_RETURN assignment_expression ';'
              | TK_CONTINUE
              ;

assignment_expression: unary_expression assignment_operator assignment_expression
                     | logical_or_expression
                     ;


assignment_operator: '='
                  | TK_PLUS_EQUAL
                  | TK_LESS_EQUAL
                  ;


logical_or_expression: logical_or_expression TK_OR logical_and_expression
                    | logical_and_expression
                    ;

logical_and_expression: logical_and_expression TK_AND equality_expression
                      | equality_expression
                      ;

equality_expression: equality_expression TK_EQUALS  relational_expression
                   | equality_expression TK_NOT_EQUAL relational_expression
                   | relational_expression
                   ;

relational_expression: relational_expression '>' additive_expression
                     | relational_expression '<' additive_expression
                     | relational_expression TK_GTE additive_expression
                     | relational_expression TK_LTE additive_expression
                     | additive_expression
                     ;
                
additive_expression: additive_expression '+' multiplicative_expression
                   | additive_expression '-' multiplicative_expression
                   | multiplicative_expression
                   ;

multiplicative_expression: multiplicative_expression '*' unary_expression
                         | multiplicative_expression '/' unary_expression
                         | unary_expression
                         ;

unary_expression: '!' unary_expression
                | postfix_expression
                ;

postfix_expression: postfix_expression '[' assignment_expression ']'
                  | postfix_expression '(' ')'
                  | postfix_expression '(' argument_expression_list ')'
                  | primary_expression
                  ;
    
argument_expression_list: argument_expression_list ',' assignment_expression
                        | assignment_expression
                        ;

primary_expression: '(' assignment_expression ')'
                  | TK_ID
                  | constant
                  | TK_LIT_STRING
                  ;

constant: TK_LIT_INT
        | TK_LIT_FLOAT
        ;
        
%%