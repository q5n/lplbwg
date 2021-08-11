/* 预处理器粘合剂：## */
#include <stdio.h>

#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n"=%d\n",x##n);



int main(void){
    int XNAME(1)=14;
    int XNAME(2)=20;
    int x3=30;
    printf("x1=%d\n",x1);
    PRINT_XN(2);
    PRINT_XN(3);
    puts("==>over!");
    return 0;
}
 


