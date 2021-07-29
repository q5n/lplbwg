#include <stdio.h>

add(int a,int b){
    return a+b;
}
printStar(void){
    printf("**********");
}

int main(void){
    int a=123,b=456;
    printf("a=%d, b=%d\n",a,b);
    printStar();
    printf("a+ b=%d\n",add(a,b));
    return 0;
}
