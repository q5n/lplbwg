#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STR_LEN 81

//声明函数，字符串转大写
void toUpper(char *);
//声明函数，标点符号计数
int punctCount(const char *);

int main(void){
    char str[STR_LEN];
    char *findLF;
    puts("input something:");
    fgets(str,STR_LEN,stdin);
    findLF=strchr(str,'\n');
    if(findLF!=NULL){
        *findLF='\0';//行尾空字符替换 换行符
    }
    toUpper(str);
    puts(str);
    printf("Has %d punctuation characters.\n",punctCount(str));
    return 0;
}

//定义函数，字符串转大写
void toUpper(char * str){
    while(*str){
        *str=toupper(*str); //ctype.h库函数
        str++;
    }
}
//定义函数，标点符号计数
int punctCount(const char * str){
    int count=0;
    while(*str!='\0'){
        if(ispunct(*str)){//ctype.h库函数
            count++;
        }
        str++;
    }
    return count;
}

