#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int printTimes;
    if (argc<2 || (printTimes=atoi(argv[1]))<1 ){
        printf("Usage: %s [must a number]\n",argv[0]);
        return 0;
    }
    for(int i=1;i<=printTimes;i++){
        printf("%d\tHello~!\n",i);
    }
    return 0;
} 

