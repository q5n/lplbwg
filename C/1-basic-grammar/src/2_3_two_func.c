#include <stdio.h> //引入文件头

void butler(void); //ANSI/ISO c函数原型

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes Bring me some tea and writeable DVDs.\n");
    return 0;
}

void butler(void){
    printf("You rang, sir?\n");
}