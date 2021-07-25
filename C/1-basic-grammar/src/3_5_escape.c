/*
* 转义
*/
#include <stdio.h> //引入文件头


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
 float salary;
    printf("\aEnter your desired monthly salary：");/* 1 */
    printf(" $_______\b\b\b\b\b\b\b");             /* 2 */
    scanf("%f",&salary);
    printf("\n\t$%.2f  a  month  is  $%.2f  a  year.",
        salary,salary * 12.0);
    printf("\rGee!\n");
    return 0;
}
 