#include <stdio.h>

using namespace std;
extern FILE * yyin;
extern int yylineno;

int yylex();
int yyparse();

int main(int argc, char*argv[]){

    if(argc !=2){
        fprintf(stderr, "Missing input file %s \n", argv[0]);
        return 1;
    }

    FILE * f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Couldn't open the file");
    }

    yyin = f;
    
    yyparse()

    return 0;
}