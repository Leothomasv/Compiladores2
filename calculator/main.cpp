#include <stdio.h>

using namespace std;


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
    

}