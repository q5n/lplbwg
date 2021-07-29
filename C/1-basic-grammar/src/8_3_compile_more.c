#include "8_3_include.h" //src源码目录里

int main(void){
    int a=123,b=456;

    printf("a=%d, b=%d\n",a,b);
    printStar(); //8_3_star_impl.c文件实现
    int x=add(a,b);// 8_3_add_impl.c文件实现
    printf("a+ b=%d\n",x); 
    return 0;
}