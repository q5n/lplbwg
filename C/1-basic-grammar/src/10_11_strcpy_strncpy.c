#include <string.h>
#include <stdio.h>
#include "my_io.h"
#define ARR_LEN 3
#define STR_LEN 50
#define LIMIT_LEN 8


int main(void){
    char * str1="Hello!";
    char  str2[]="good day, nice to meet your!";
    puts(str1);
    puts(str2);
    char * ps=strcpy(str2+9,str1);
    puts(str2);
    puts(ps);
    puts("-----------------use strcpy-----------------------");
    char list[ARR_LEN][STR_LEN];
    char tmpStr[STR_LEN];
    printf("input %d words start with a:\n",ARR_LEN);
    for(int i=0;i<ARR_LEN;){
        if(!s_gets(tmpStr,STR_LEN)){
            break;
        };
        if(tmpStr[0]!='a'){
            printf("[warning] input must start with a!\n");
        }else{
            strcpy(list[i],tmpStr);
            i++;
        }
    }
    
    puts("\nyour words:");
    for(int i=0;i<ARR_LEN;i++){
        printf("%d\t%s\n",i,list[i]);
    }
    puts("-------------------use strncpy---------------------");
    char list2[ARR_LEN][LIMIT_LEN];
    printf("input %d words start with a:\n",ARR_LEN);
    for(int i=0;i<ARR_LEN;){
        if(!s_gets(tmpStr,STR_LEN)){
            break;
        };
        if(tmpStr[0]!='a'){
            printf("[warning] input must start with a!\n");
        }else{
            strncpy(list2[i],tmpStr,LIMIT_LEN-1);
            list2[i][LIMIT_LEN-1]='\0';
            i++;
        }
    }
    
    puts("\nyour words:");
    for(int i=0;i<ARR_LEN;i++){
        printf("%d\t%s\n",i,list2[i]);
    }
    
    return 0;
}

