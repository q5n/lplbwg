#include <stdio.h>
#include <string.h>
#define LIMIT 28
void fit(char *,unsigned int);

int main(void){

    char msg[]="good good study, day day up! fighting, fighting!!!";
    printf("origin msg is :\"%s\"\n",msg);
    fit(msg,LIMIT);
    printf("fit msg is :\"%s\"\n",msg);
    printf("msg+%d is :\"%s\"\n",LIMIT+1,msg+LIMIT+1);
    return 0;
}

void fit(char *str,unsigned int size){
    if( strlen(str)>size){
        str[size]='\0';
    }
}


