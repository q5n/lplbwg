#include <string.h>
#include "my_io.h"
#define ANSWER_DEF "OK"
#define LENGTH 50


int main(void){
    char answer[LENGTH];
    puts("Are you OK?");
    s_gets(answer,LENGTH);
    //while(answer!= ANSWER_DEF){ //不能这么比
    while(strcmp(answer,ANSWER_DEF)!=0){
        puts("No, it's wrong!, input again!");
        s_gets(answer,LENGTH);
    }
    puts("Prefect anwser!");

    printf("---------------------strcmp\n:");

    char *str1="aaa";
    char *str2="ccc";
    printf("strcmp(%s,%s)=%d\n",str1,str2,strcmp(str1,str2));

    str1="ccc";
    str2="aaa";
    printf("strcmp(%s,%s)=%d\n",str1,str2,strcmp(str1,str2));

    str1="bbb";
    str2="bbb";
    printf("strcmp(%s,%s)=%d\n",str1,str2,strcmp(str1,str2));

    return 0;
}

