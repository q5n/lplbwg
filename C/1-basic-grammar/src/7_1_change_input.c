/*
* 使用getchar + putchar
* 输出字母变更，
*/
#include <stdio.h> //引入文件头
#include <ctype.h>


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    int ch;
    while((ch=getchar())!='\n'){ //不出现换行就一直循环
         if(ch=='z'){
            putchar('A');
        } else if(ch=='Z'){
            putchar('a');
        }else if (isalpha(ch)){
            putchar(ch+1);
        } else {
            putchar(ch);
        }
    }
    putchar(ch);
    return 0;
}
 
