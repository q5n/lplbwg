#include <stdio.h>

extern int cnt;//引用式声明，外部链接
static int total=0; //静态定义，内部链接


void accumulate(int k); //函数原型,k具有函数原型作用域

void accumulate(int k){//参数具有块作用域，无链接
    static int subtotal=0;//块作用域的静态变量
    if(k<=0){
        printf("k=%d, loop cycle:%d\n",k,cnt);
        printf("subtotal :%d ,total : %d\n",subtotal,total);
        subtotal=0;
    }else{
        subtotal+=k;
        total+=k;
    }
}

