/*
* 整数字面量
*/
#include <stdio.h> //引入文件头


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    int x=100;//十进制
    printf("整数100  十进制:%d,  八进制:%o,  十六进制:%x \n",x,x,x);
    printf("整数100  十进制:%d,  八进制:%#o,  十六进制:%#x \n",x,x,x);

    printf("\n");
    
    int a=0123,b=456,c=0x78;
    printf("整数a=0123, 十进制:%d,  八进制:%#o,  十六进制:%#x \n",a,a,a);
    printf("整数b=456, 十进制:%d,  八进制:%#o,  十六进制:%#X \n",b,b,b);
    printf("整数c=0x78, 十进制:%d,  八进制:%#o,  十六进制:%#X \n",c,c,c);
    return 0;
}
 