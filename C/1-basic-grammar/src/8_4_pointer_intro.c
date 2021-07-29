#include <stdio.h>


void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

int main(void){
    int a=123;
    int b=456;
    printf("main==> a=%d, &a=%p\n",a,&a);
    printf("main==> b=%d, &b=%p\n",b,&b);
    swap(&a,&b);
    printf("after swap==> a=%d, &a=%p\n",a,&a);
    printf("after swap==> b=%d, &b=%p\n",b,&b);
    return 0;
}
