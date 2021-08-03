#include <stdio.h>
#define STR_LENGTH 10
#define REPLACE_CHAR '#'
#define ZERO_CHAR '\0'

void input_str(char *str){
    puts("enter a string:");
    fgets(str,STR_LENGTH,stdin);
    printf("show string by puts ==> ");
    puts(str);
    printf("show string by fputs ==> ");
    fputs(str,stdout);
    puts("------------------end\n");
}
void input_str2(char *str){
    puts("enter strings(empty line to quit):");
    int i=0;
    printf(">");
    int lastIdx=STR_LENGTH-1;
    char preLastChar=REPLACE_CHAR;
    while(fgets(str,STR_LENGTH,stdin)!=NULL){//NULL是stdio.h中的空指针宏
        if(*str=='\n' && preLastChar!=ZERO_CHAR){//空行首字符为换行符
            break;
        }
        printf("fputs-start[%d]=={",++i);
        fputs(str,stdout);
        printf("}==end[%d]\n",i);
        preLastChar=str[lastIdx];
        if(preLastChar!=ZERO_CHAR){
            printf(">");
        }else{
            str[lastIdx]=REPLACE_CHAR;
        }
    }
    puts("------------------input over!!!\n");
}

int main(void){
    char str[STR_LENGTH];
    //input_str(str);
    input_str2(str);
    
    return 0;
}
