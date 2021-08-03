#include <stdio.h>
#include <string.h>
#include "myio.h"

#define STRING2(x) #x
#define STRING(x) STRING2(x)

#pragma message("C_R_MODE:" STRING(C_R_MODE))


#define STR_LENGTH 10
#define SIZE_T_FMT "zu"


void input_str(char *str){
    puts("enter a string:");
    while(1){
        printf(">");
#if C_R_MODE==1 
#pragma  message("use gets_s() from <stdio.h>")
        gets_s(str,STR_LENGTH);
        printf("first char: %d\n",str[0]);
#else
#pragma  message("use s_gets() from \"myio.h\"")
        s_gets(str,STR_LENGTH);
#endif
        printf("show string by puts ==> ");
        puts(str);
        printf("string length:%"SIZE_T_FMT"\n",strlen(str));
    }
    puts("------------------end\n");
} 
int main(void){
    char str[STR_LENGTH];
    input_str(str);
    //input_str2(str);
    
    return 0;
}

