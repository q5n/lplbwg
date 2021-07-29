#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define MAX 90
uint64_t cache[MAX]={1,1};

uint64_t fibonacci(uint64_t n){
    if(n<0){
        return (uint64_t)-1;
    }
    if(cache[n]==0){
        uint64_t x=fibonacci(n-1)+fibonacci(n-2);
        cache[n]=x;
        return x;
    }else {
        return cache[n];
    }
}

int main(void){
    for(int i=0;i<MAX;i++){
        printf("fibonacci(%2d)=%#llx\n",i,fibonacci(i));
    }
    return 0;
}
