#include <stdio.h>
#define CONS 3

void test2(void){
    const int i=1;
    int* pi;
    const int **ppi;
    printf("i=%d, pi=%p, ppi=%p\n",i,pi, ppi);
    ppi=&pi;
    printf("i=%d, pi=%p, ppi=%p\n",i,pi, ppi);
    *ppi=&i;
    printf("i=%d, pi=%p, ppi=%p\n",i,pi, ppi);
    *pi=2;
    printf("i=%d, pi=%p, ppi=%p\n",i,pi, ppi);
}

int main(void){
    const int j=2;
    int  i=0;
    i=j;
    int *pi=&i;
    int *pj=&j;
    int dif=pi-pj;
    printf("i=%d, &i=%p\n",i,&i);
    printf("j=%d, &j=%p\n",j,&j);
    printf("dif=%d \n",dif);
    *pi=3;
    *pj=5;
    *(pi-dif)=5;
    printf("i=%d, &i=%p\n",i,&i);
    printf("j=%d, &j=%p\n",j,&j);
    
    const int arr1[]={1,2,3,4};//常量类型数组，数组里存的是(const int)
    const int arr2=arr1;
    const int *p1=arr1;//指(向常量整形)的 常量指针
    const int *const p2=arr1;
    printf("arr1=%p, arr2=%p, p1=%p, p2=%p\n",arr1,arr2,p1,p2);


    //printf("1=%p, &1=%p\n",1,&1);//wrong!
    //printf("CONS=%d, &CONS=%p\n",CONS,&CONS); //wrong!
    printf("---------------------------\n");

    test2();

    return 0;
}