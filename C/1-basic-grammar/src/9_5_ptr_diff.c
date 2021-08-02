#include <stdio.h>

int main(void){
    int arr[]={5,5,5,5,5};
    int *p1=arr;
    int *p2=&arr[3];
    printf("main: *p1=%d, p1=%p\n",*p1,p1); 
    printf("main: *p2=%d, p2=%p\n",*p2,p2); 
    printf("main: p2-p1=%d\n",p2-p1); 
    printf("------------------------------\n");
    int a=1;
    int b=2;
    p1=&a;
    p2=&b;
    printf("main: *p1=%d, p1=%p\n",*p1,p1); 
    printf("main: *p2=%d, p2=%p\n",*p2,p2); 
    printf("main: p2-p1=%d\n",p2-p1); 

    return 0;
}