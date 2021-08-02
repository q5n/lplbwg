#include <stdio.h>


void showArr(const int arr[],int n){
    
    printf("array is :{");
    for(int i=0;i<n;i++){
        printf("[%d]=%d, ",i,arr[i]);
    }
    printf("\b\b}\n");
}


int sum(const int arr[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total +=arr[i];
    }
    return total;
}

int main(void){
    //(int[]){1,2,3,4,5}为复合字面量，又叫匿名数组
    showArr( (int[]){1,2,3,4,5} ,5);
    printf("array sum =%d\n",sum( (int[]){1,2,3,4,5} ,5) );
    return 0;
}

