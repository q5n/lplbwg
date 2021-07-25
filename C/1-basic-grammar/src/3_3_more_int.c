/*
* 更多整数类型
*/
#include <stdio.h> //引入文件头


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    unsigned int uint=3000000000;
    short si=200;
    long li=63357;
    long long big=12345678901234;
    printf("uint=%u(%%u), uint=%d(%%d)\n",uint,uint);
    printf("si=%hd(%%hd), si=%d(%%d)), si=%uh(%%uh)\n",si,si,si);
    printf("li=%ld(%%ld), li=%hd(%%hd)\n",big,big);
    printf("big=%ld(%%ld),  big=%lld(%%lld)\n",big,big);
    return 0;
}
 