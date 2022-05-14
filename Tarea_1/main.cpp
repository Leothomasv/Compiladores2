#include <stdio.h>

using namespace std;
extern FILE * yyin;
int yylval;
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
        fprintf(stderr, "Cou");
    }
    

    yyin = f;
    int token;
    while ((token = yylex()))
    {
        printf("Line %d Token type: %d", yylineno, token);
        if(token == 261){
            printf("=%d\n", yylval);
        }else{
            printf("\n");
        }
    }
    
}