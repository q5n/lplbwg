#include <stdio.h>
#include <stdlib.h> // malloc() free()所在库

int main(void){
    double * doublePtr;
    int arr_size;
    int count;
    int i=0;
    puts("enter array max-size:");
    if(scanf("%d",&arr_size)<1){
        puts("[ERROR] number format wrong!");
        exit(EXIT_FAILURE);
    }
    doublePtr=(double*) malloc(arr_size*sizeof(double));
    if(doublePtr==NULL){
        puts("[ERROR] Memory alloc failed!");
        exit(EXIT_FAILURE);
    }
    puts("enter the values:");
    while(i<arr_size && scanf("%lf",&doublePtr[i])==1){
        i++;
    }
    printf("your has %d elements:\n",count=i);
    for(i=0;i<count;i++){
        printf("%7.2f ",doublePtr[i]);
        if(i%7==6){
            putchar('\n');
        }
    }
    if(i%7!=0){
        putchar('\n');
    }
    puts("over!");
    free(doublePtr);
    return 0;
}
