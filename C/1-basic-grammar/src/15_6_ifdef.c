/* ifdef */
#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void){
    int total=0;
    for(int i=1;i<=LIMIT;i++){
        total += 2 * i*i + 1;
        #ifdef JUST_CHECKING
        printf("a) i=%d,running total=%d\n",i,total);
        #else
        printf("a) ....\n");
        #endif
    }
    
    #undef JUST_CHECKING
    
    for(int i=1;i<=LIMIT;i++){
        total += 2 * i*i + 1;
        #ifdef JUST_CHECKING
            printf("b) %i=%d,running total=%d\n",i,total);
        #else
            printf("b) ....\n");
        #endif
    }
    printf("Grand total=%d\n",total);
}
 


