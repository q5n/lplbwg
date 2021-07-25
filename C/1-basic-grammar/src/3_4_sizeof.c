/*
* 类型字节数大小
*/
#include <stdio.h> //引入文件头


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    printf("char : %zd bytes.\n",sizeof(char));
    printf("short : %zd bytes.\n",sizeof(short));
    printf("int : %zd bytes.\n",sizeof(int));
    printf("long : %zd bytes.\n",sizeof(long));
    printf("long long : %zd bytes.\n",sizeof(long long));
    printf("float : %zd bytes.\n",sizeof(float));
    printf("double : %zd bytes.\n",sizeof(double));
    printf("long double : %zd bytes.\n",sizeof(long double));
    //printf("float _Complex : %zd bytes.\n",sizeof(float _Complex));
    //printf("double _Complex : %zd bytes.\n",sizeof(double _Complex));
    //printf("long double _Complex : %zd bytes.\n",sizeof(long double _Complex));
    return 0;
}
 