%{
    #include <cstdio>
    #include <map>
    #include <string>
    using namespace std;
    int yylex();
    extern int yylineno;

    map<string, int> variables;
    int temp = 0; 
    void yyerror(const char * s){
        fprintf(stderr, "Line %d, error: %s\n", yylineno, s);
    }

%}

%union{
    const char* string_t;
    int int_t;
}

%token <string_t> TK_ID
%token <int_t> TK_NUMBER
%token TK_DEF TK_WRITE TK_END TK_EOL TK_INT TK_COLON TK_SEMICOLON TK_EQUAL TK_PLUS
%token TK_MINUS TK_DIV TK_MULTI TK_LEFTPARENS TK_RIGHTPARENS
%type<int_t> term factor expression write_statement assignation_statement declarations
%%



external_declaration: definition_block statement_list
    | statement_list
    | expression
    ;

statement_list: 
    |statement_list statement
    ;

statement: write_statement
    | assignation_statement
    ;

assignation_statement: TK_ID TK_EQUAL expression TK_SEMICOLON {if(variables.count($1)){variables.find($1)->second = $3;} else {printf("Variable %s no esta declarada\n", $1); return 0;}}

write_statement: TK_WRITE TK_LEFTPARENS expression TK_RIGHTPARENS TK_SEMICOLON {printf("%d\n",$3);}
    ;

definition_block: TK_DEF TK_ID declarations_list TK_END
    ;

declarations_list: 
    |declarations_list declarations
    ;

declarations: TK_ID TK_COLON TK_INT TK_SEMICOLON {variables.insert(make_pair($1, 0));}
    ;

expression: expression TK_PLUS factor {$$ = $1 + $3; }
    | expression TK_MINUS factor {$$ = $1 - $3; }
    | factor {$$ = $1; }
    ;

factor:factor TK_MULTI term {$$ = $1 * $3;}
    | factor TK_DIV term {$$ = $1 / $3;}
    | term {$$ = $1;}
    ;

term: TK_NUMBER {$$ = $1;}
    | TK_ID {if(variables.count($1)){$$ = variables.find($1)->second;} else {printf("Variable %s no esta declarada\n",$1); return 0;}}
    ;


%%