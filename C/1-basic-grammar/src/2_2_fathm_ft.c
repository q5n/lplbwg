#include <stdio.h> //引入文件头

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    int feet,fathoms;
    
    fathoms=2;
    feet=6*fathoms;
    
    printf("There are %d feet in %d fathoms!\n",feet,fathoms);
    printf("Yes, I said %d feet!\n",6*fathoms);
    return 0;
}