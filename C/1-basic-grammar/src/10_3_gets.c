#include <stdio.h>
#define STR_LENGTH 51

int main(void){
    char str[STR_LENGTH];
    puts("enter a string:");
    gets(str);
    printf("show string by printf ==> %s\n",str);
    printf("show string by puts ==> ");
    puts(str);
    return 0;
}

