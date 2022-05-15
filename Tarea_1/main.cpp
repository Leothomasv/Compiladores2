#include <stdio.h>

using namespace std;
extern FILE * yyin;
extern  char* yylval;
extern int yylineno;

int yylex();

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
    int token;
    while ((token = yylex()))
    {
        printf("Line %d Token type: %d\n", yylineno, token);
    }
    
}