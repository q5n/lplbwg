#include <stdio.h>

void funcp(int *p,int size){
    for(int i=0;i<size;i++){
        p++;
        printf("funcp:v=%d, p=%p\n",*p,p);
    }
}

int main(void){
    int arr[]={1,1,1,1,1};
    //arr++;
    size_t size=sizeof(arr)/sizeof(int);
    printf("arr size: %zu\n",size);
    int *p=arr;
    printf("main:v=%d, p=%p\n",*p,p);
    funcp(p,size);
    printf("main:v=%d, p=%p\n",*p,p);
    printf("----------------------------------------\n");
    printf("main *p++:%d\n",*p++);
    printf("main:v=%d, p=%p\n",*p,p);
    printf("main *++p:%d\n",*++p);
    printf("main:v=%d, p=%p\n",*p,p);
    printf("main (*p)++:%d\n", (*p)++);
    printf("main:v=%d, p=%p\n",*p,p);
    printf("main ++*p:%d\n",++*p);
    printf("main:v=%d, p=%p\n",*p,p);
    printf("----------------------------------------\n");
    
    p=&arr[3];
    printf("main:v=%d, p=%p\n",*p,p);
    p=&arr[4];
    printf("main:v=%d, p=%p\n",*p,p);

    return 0;
}