#include <string.h>
#include "my_io.h"
#include "my_pri_star.h"
#pragma  message("use s_gets() from \"myio.h\"")
#define STR_LENGTH 20


int main(void){
    char str[STR_LENGTH];
    printStar();
    printf("input something:");
    s_gets(str,STR_LENGTH);
    //input_str2(str);
    
    return 0;
}

