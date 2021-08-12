/* atexit()示例 */
#include <stdio.h>
#include <stdlib.h>


void sign_off(void);
void too_bad(void);


int main(void){
    int n;
    atexit(sign_off);

    puts("input an interger:");
    if(scanf("%d",&n)!=1){
        puts("not an integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n",n,(n%2==0)?"even":"odd");

    puts("\n==>over!");
    return 0;
}

void sign_off(void){
    printf("==>program over! exit by %s\n",__func__);
}

void too_bad(void){
    printf("==>something wrong! exit by %s\n",__func__);
}

