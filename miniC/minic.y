%code requires{
    #include "ast.h"
}

%{
    #include <cstdio>
    #include "asm.h"
    #include <fstream>
    #include <iostream>
    using namespace std;
    int yylex();
    extern int yylineno;

    #define EQUAL 1
    #define PLUSEQUAL 2
    #define MINUSEQUAL 3

    Asm assemblyResultFile;
    void yyerror(const char * s){
        fprintf(stderr, "Line %d, error: %s\n", yylineno, s);
    }

    void writeFile(string name){
        ofstream file;
        file.open(name);
        file << assemblyResultFile.data <<endl
        << assemblyResultFile.global<<endl
        << assemblyResultFile.text<< endl;
        file.close();
    }
%}

%union{
    const char* string_t;
    int int_t;
    float float_t;
    Expr * expr_t;
    ArgumentList * argument_list_t;
    Statement * statement_t;
    StatementList * statement_list_t;
    DeclarationList * declaration_list_t;
    Declaration * declaration_t;
    Declarator * declarator_t;
    Parameter * parameter_t;
    ParameterList * parameter_list_t;
    InitializerList * initializer_list_t;
    InitDeclarator * init_declarator_t;
    InitDeclaratorList * init_declarator_list_t;
}


%token<string_t> TK_ID TK_LIT_STRING
%token<int_t> TK_LIT_INT
%token<float_t> TK_LIT_FLOAT
%token TK_IF
%token TK_WHILE
%token TK_VOID TK_INT_TYPE TK_FLOAT_TYPE
%token TK_PRINTF
%token TK_GTE TK_LTE TK_PLUS_EQUAL TK_LESS_EQUAL
%token TK_OR TK_AND TK_EQUALS TK_NOT_EQUAL TK_RETURN

%precedence ')'
%precedence TK_ELSE

%type<expr_t> assignment_expression logical_or_expression logical_and_expression
%type<expr_t>  equality_expression relational_expression additive_expression multiplicative_expression
%type<expr_t> unary_expression postfix_expression primary_expression constant
%type<argument_list_t> argument_expression_list
%type<statement_t> jump_statement if_statement while_statement statement block_statement method_definition external_declaration expression_statement
%type<int_t> assignment_operator type
%type<statement_list_t> statement_list input
%type<declaration_list_t> declaration_list
%type<declaration_t> declaration
%type<declarator_t> declarator
%type<parameter_t> parameter_declaration
%type<parameter_list_t> parameter_type_list
%type<initializer_list_t> initializer_list initializer
%type<init_declarator_t> init_declarator
%type<init_declarator_list_t> init_declarator_list

%%

start: input{
    assemblyResultFile.global = ".global main\n";
    assemblyResultFile.data = ".data \n";
    assemblyResultFile.text = ".text\n";
    list<Statement *>::iterator stmtIt = $1->begin();
    string code = "";
    while(stmtIt != $1->end()){
        (*stmtIt)->evaluateSemantic();
        code += (*stmtIt)->genCode();
        stmtIt++;
    }
    assemblyResultFile.text += code;
    writeFile("result.asm");
}

input: input external_declaration { $$ = $1; $$->push_back($2);}
    | external_declaration {$$ = new StatementList; $$->push_back($1);}
    ;

external_declaration: method_definition {$$ = $1;}
            | declaration {$$ = new GlobalDeclaration($1);}
            ;

declaration: type init_declarator_list ';' {$$ = new Declaration((Type)$1, *$2, yylineno);}
           ;

init_declarator_list: init_declarator_list ',' init_declarator {$$ = $1; $$->push_back($3);}
                    | init_declarator {$$ = new InitDeclaratorList; $$->push_back($1);}
                    ;

init_declarator: declarator { $$ = new InitDeclarator($1, (new InitializerList), yylineno );}
             | declarator '=' initializer { $$ = new InitDeclarator($1, $3, yylineno );}
            ; 

initializer: assignment_expression { $$ = new InitializerList; $$->push_back($1); }
           | '{' initializer_list '}' {$$ = $2;}
           ;

initializer_list: initializer_list ',' logical_or_expression { $$ = $1; $$->push_back($3);}
                | logical_or_expression { $$ = new InitializerList; $$->push_back($1);}
                ;

method_definition: type TK_ID '(' parameter_type_list ')' block_statement { $$ = new MethodDefinitionStatement((Type)$1, $2, *$4, $6, yylineno);}
                 | type TK_ID '(' ')' block_statement { $$ = new MethodDefinitionStatement((Type)$1, $2, *(new ParameterList), $5, yylineno);}
                 ;

type: TK_VOID {$$ = VOID;}
    | TK_INT_TYPE {$$ = INT;}
    | TK_FLOAT_TYPE {$$ = FLOAT;}
    ;

parameter_type_list: parameter_type_list ',' parameter_declaration {$$ = $1; $$->push_back($3);}
                   | parameter_declaration { $$ = new ParameterList; $$->push_back($1);}
                   ;

parameter_declaration: type declarator { $$ = new Parameter((Type)$1, $2, yylineno);}
                    ;

declarator: TK_ID { $$ = new Declarator($1, NULL, false, yylineno);}
          | TK_ID '[' assignment_expression ']' { $$ = new Declarator($1, $3, true, yylineno);}
          | TK_ID '['  ']'{ $$ = new Declarator($1, NULL, true, yylineno);}
          ;

block_statement: '{' declaration_list statement_list '}' { $$ = new BlockStatement(*$2, *$3, yylineno); }
               | '{' statement_list '}' { $$ = new BlockStatement(*(new DeclarationList), *$2, yylineno); }
               ;

declaration_list: declaration_list declaration {$$ = $1; $$->push_back($2);}
                | declaration {$$ = new DeclarationList; $$->push_back($1);}
                ;

statement_list: statement_list statement {$$ = $1; $$->push_back($2);}
              | statement {$$ = new StatementList; $$->push_back($1);}
              ;

statement: while_statement { $$ = $1; }
         | expression_statement { $$ = $1; }
         | if_statement { $$ = $1; }
         | block_statement { $$ = $1; }
         | TK_PRINTF '(' assignment_expression ')' ';' {$$ = new PrintStatement($3, yylineno);}
         | jump_statement {$$ = $1;}
         ;

while_statement: TK_WHILE '(' assignment_expression ')' statement { $$ = new WhileStatement($3, $5, yylineno);}
               ;

expression_statement: assignment_expression ';' {$$ = new ExprStatement($1, yylineno);}
                    ;

if_statement: TK_IF '(' assignment_expression ')' statement { $$ = new IfStatement($3, $5, yylineno); }
            | TK_IF '(' assignment_expression ')' statement TK_ELSE statement { $$ = new IfElseStatement($3, $5, $7, yylineno); }
            ;

jump_statement: TK_RETURN ';' { $$ = new ReturnStatement(NULL, yylineno);}
              | TK_RETURN assignment_expression ';' {$$ = new ReturnStatement($2, yylineno);}
              ;

assignment_expression: unary_expression assignment_operator assignment_expression{
    if($2 == EQUAL){
        $$ = new AssignExpr($1, $3, yylineno);
    }else if($2 == PLUSEQUAL){
        $$ = new PlusAssignExpr($1, $3, yylineno);
    }
    else {
        $$ = new MinusAssignExpr($1, $3, yylineno);
    }
}
                     | logical_or_expression {$$ = $1;}
                     ;


assignment_operator: '=' { $$ = EQUAL; }
                  | TK_PLUS_EQUAL { $$ = PLUSEQUAL; }
                  | TK_LESS_EQUAL { $$ = MINUSEQUAL;}
                  ;


logical_or_expression: logical_or_expression TK_OR logical_and_expression  {$$ = new LogicalOrExpr($1, $3, yylineno);}
                    | logical_and_expression { $$ = $1;}
                    ;

logical_and_expression: logical_and_expression TK_AND equality_expression  {$$ = new LogicalAndExpr($1, $3, yylineno);}
                      | equality_expression {$$ = $1;}
                      ;

equality_expression: equality_expression TK_EQUALS  relational_expression  {$$ = new EqExpr($1, $3, yylineno);}
                   | equality_expression TK_NOT_EQUAL relational_expression  {$$ = new NeqExpr($1, $3, yylineno);}
                   | relational_expression {$$ = $1; }
                   ;

relational_expression: relational_expression '>' additive_expression {$$ = new GtExpr($1, $3, yylineno);}
                     | relational_expression '<' additive_expression {$$ = new LtExpr($1, $3, yylineno);}
                     | relational_expression TK_GTE additive_expression {$$ = new GteExpr($1, $3, yylineno);}
                     | relational_expression TK_LTE additive_expression {$$ = new LteExpr($1, $3, yylineno);}
                     | additive_expression {$$ = $1;}
                     ;
                
additive_expression: additive_expression '+' multiplicative_expression { $$ = new AddExpr($1, $3, yylineno);}
                   | additive_expression '-' multiplicative_expression { $$ = new SubExpr($1, $3, yylineno);}
                   | multiplicative_expression { $$ = $1; }
                   ;

multiplicative_expression: multiplicative_expression '*' unary_expression { $$ = new MultExpr($1, $3, yylineno);}
                         | multiplicative_expression '/' unary_expression { $$ = new DivExpr($1, $3, yylineno); }
                         | unary_expression {$$ = $1;}
                         ;

unary_expression: '!' unary_expression { $$ = new UnaryExpr(1, $2); }
                | postfix_expression { $$ = $1; }
                ;

postfix_expression: postfix_expression '[' assignment_expression ']' {$$ = new ArrayExpr((IdExpr *)$1, $3, yylineno );}
                  | postfix_expression '(' ')' { $$ = new MethodInvocationExpr((IdExpr*)$1, *(new ArgumentList), yylineno); }
                  | postfix_expression '(' argument_expression_list ')' { $$ = new MethodInvocationExpr((IdExpr*)$1, *$3, yylineno);  }
                  | primary_expression { $$ = $1; }
                  ;
    
argument_expression_list: argument_expression_list ',' assignment_expression { $$ = $1; $$->push_back($3);  }
                        | assignment_expression { $$ = new ArgumentList;  $$->push_back($1); }
                        ;

primary_expression: '(' assignment_expression ')' { $$ = $2; }
                  | TK_ID { $$ = new IdExpr($1, yylineno); }
                  | constant { $$ = $1; }
                  | TK_LIT_STRING {$$ = new StringExpr($1, yylineno);}
                  ;

constant: TK_LIT_INT { $$ = new IntExpr($1, yylineno);}
        | TK_LIT_FLOAT { $$= new FloatExpr($1, yylineno);}
        ;
        
%%