#include <stdio.h> //引入文件头

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    int x; /* 定义一个名为x的变量 */
    x = 1; /* 为x赋一个值 */ 
    printf("Hello world!\n"); //调用stdio标准库里的printf函数, \n是换行符
    printf("x=%d\n",x); //再次调用stdio标准库里的printf函数，并传参数
    return 0; //返回一个数
}