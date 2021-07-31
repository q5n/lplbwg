#include <stdlib.h>
#include <stdio.h>


int main(void){
    int min=rand();
    int max=min;
    for (int i=0;i<100000;i++){
        int a=rand();
        if(a>max){
            max=a;
        }
        if(a<min){
            min=a;
        }
    }
    printf("rand min:%d, max:%d\n",min,max);
    printf("RAND_MAX:%d\n",RAND_MAX);
    
}