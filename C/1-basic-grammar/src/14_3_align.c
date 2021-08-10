/* 使用对齐关键字_Alignas 和 _Alignof*/
#include <stdio.h>
 
int main(void){
    double double0;
    char char0;
    char char1;
    double double1;
    char char2;
    char char3;
    char _Alignas(double) char4;
    char char5;
    char char6;
    
    printf("char alignment: %zd\n",_Alignof(char));
    printf("double alignment: %zd\n",_Alignof(double));
    
    printf("&double0: %p\n",&double0);
    printf("&char0: %p\n",&char0);
    printf("&char1: %p\n",&char1);
    printf("&double1: %p\n",&double1);
    printf("&char2: %p\n",&char2);
    printf("&char3: %p\n",&char3);
    printf("align &char4: %p\n",&char4);
    printf("&char5: %p\n",&char5);
    printf("&char6: %p\n",&char6);
    
    puts("==>over!");
    return 0;
}
 


