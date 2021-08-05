#include <stdio.h>
#include <stdlib.h>
#include "my_io.h"
#define STR_LIMIT 30

int main(void){
    char numStr[STR_LIMIT];
    char *end;
    long value;
    while(1){
        puts("input 10-based number[0-9]:");
        if(!s_gets(numStr,STR_LIMIT) || numStr[0]=='\0'){
            break;
        }
        value=strtol(numStr,&end,10);//十进制数
        printf("you num:%ld, hex:%#lx, stop parse at '%s'(%d)\n\n",value,value,end,*end);

        puts("input 16-based number[0-9a-f]:");
        if(!s_gets(numStr,STR_LIMIT) || numStr[0]=='\0'){
            break;
        }
        value=strtol(numStr,&end,16);//十进制数
        printf("you num:%ld, hex:%#lx, stop parse at '%s'(%d)\n\n",value,value,end,*end);
    }
    puts("byte!");
    return 0;
}
