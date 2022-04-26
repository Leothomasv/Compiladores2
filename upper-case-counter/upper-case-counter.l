%{
   int counter =0;
%}


%%

[A-Z] {printf("letra mayuscula: %s \n", yytext); counter++;}

. {printf("%s no es una letra mayuscula\n", yytext);}

\n {return 0;}

%%

int main(){
    yylex();
    printf("%d letras mayusculas\n", counter);
    return 0;
}

int yywrap(){
    return 1;
}