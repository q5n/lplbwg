/* 宏参数 字符串转换 */
#include <stdio.h>

#define PSQR(X) printf("The square of " #X "(=%d) is %d.\n",(X), ( (X)*(X) ) )



int main(void){
    int y=5;
    PSQR(y);
    PSQR(2+4);
    puts("==>over!");
    return 0;
}
 


