/*
* 字符串
*/
#include <stdio.h> //引入文件头
#include <string.h> //提供strlen()函数原型
#define HAHA "哈哈！"

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    char name[40];
    printf("what's your name?");
    scanf("%s",name); //只能输入ANSI字符，why?因为需要支持'\0'字符结尾
    printf("Hello, %s. %s, your name length is %zd, array size:%d \n",
       name,HAHA, strlen(name) ,sizeof(name)); 
    return 0;
}
 