/*
* 循环输出尺寸
*/
#include <stdio.h> //引入文件头
#define FIX 7.31

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    const double RATE=0.333;//倍数
    double shoeSize,footLen;
    printf("shoe size\t foot inches\n");
    shoeSize=3;
    while(shoeSize<18.5){
        footLen=shoeSize*RATE+FIX;
        printf("%10.1f\t %15.2f\n",shoeSize,footLen);
        shoeSize=shoeSize+1;
    }
    return 0;
}
 