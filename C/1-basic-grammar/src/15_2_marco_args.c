/* 待参数的宏 */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n",X)



int main(void){
    int x=5;
    printf("x=%d\n",x);
    
    int z=SQUARE(x);
    printf("Eval SQUARE(x):");
    PR(z);
    
    z=SQUARE(2);
    printf("Eval SQUARE(2):");
    PR(z);
    

    z=SQUARE(x+2);
    printf("1Eval SQUARE(x+2):");
    PR(z);
    
    printf("2Eval SQUARE(x+2):");
    PR(SQUARE(x+2));
    
    
    printf("Eval 100/SQUARE(x+2):");
    PR(100/SQUARE(2));
    
    
    printf("x=%d\n",x);
    printf("Eval SQUARE(++x):");
    PR(SQUARE(++x));

    printf("x=%d\n",x);
    puts("==>over!");
    return 0;
}
 


