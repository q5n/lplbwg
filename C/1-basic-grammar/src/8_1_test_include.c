#include <stdio.h>
#include "8_1_test.h"
#include "8_1_test2.h"

int main(void){
    int a=123,b=456;
    printf("a=%d, b=%d\n",a,b);
    printStar();
    printf("a+ b=%d\n",add(a,b));
    return 0;
}

int add(int a,int b){
    return a+b;
}
void printStar(){
    printf("***********************\n");
}