/* 包含头文件两次 */
#include <stdio.h>
#include "15_7_names.h"
#include "15_7_names.h" // 不小心第2次包含头文件

int main(void){
    names winner = { "Bluce", "Lee" };
    printf("The winner is %s %s.\n", winner.first,winner.last);
    return 0;
}
 


