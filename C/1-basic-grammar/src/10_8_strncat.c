#include <string.h>
#include "my_io.h"
#define ENOUGH_LEN 200
#define SHORT_LEN 30


int main(void){
    char str1[ENOUGH_LEN];
    char str2[SHORT_LEN];
    char add[]=", You really can talk!";
    printf("say something1:");
    s_gets(str1,ENOUGH_LEN);
    if(strlen(add)+strlen(str1)<ENOUGH_LEN){
        strcat(str1,add);
    }
    puts(str1);
    printf("\nsay something2:");
    s_gets(str2,SHORT_LEN);
    int remain=SHORT_LEN-strlen(str2)-1;
    strncat(str2,add,remain);
    puts(str2);
    return 0;
}

