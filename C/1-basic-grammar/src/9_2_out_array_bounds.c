
#include <stdio.h>
#define LEN 5

int main(void){
    int d1=123;
    int arr[LEN];
    int d2=456;
    int i;
    printf("d1=%d d2=%d\n\n",d1,d2);
    for(i=-4;i<=LEN;i++){
        arr[i]=i;
    }
    printf("i=%d, address:%p\n",i,&i);
    int x=LEN+4;
    for(i=-4;i<x;i++){
        printf("arr[%d]=%d, address:%p\n",i,arr[i],&arr[i]);
    }
    printf("\nd1=%d, address:%p\n",d1,&d1);
    printf("d2=%d, address:%p\n",d2,&d2);
    return 0;
}