/*
* 函数参数，声明、原型
*/
#include <stdio.h> //引入文件头

void func(int x); //函数原型声明

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    char a='a';
    int b=10;
    float c=6.5f;
    func(a);
    func(b);
    func(c);
    return 0;
}

void func(int x){
    printf("output x:%d\n",x);
}
