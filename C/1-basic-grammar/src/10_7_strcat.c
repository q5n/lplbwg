#include <string.h>
#include "my_io.h"  //多引入外部库表头
#include "my_pri_star.h" //尝试多引入几个外部库表头
#define STR_LENGTH 100


int main(void){
    char str[STR_LENGTH];
    char add[]=", You really can talk!";
    printStar();
    printf("say something:");
    if(s_gets(str,STR_LENGTH)){
        strcat(str,add);
        puts(str);
        puts(add);
    }else {
        puts("End of file, bye!");
    }
    printStar();

    return 0;
}

