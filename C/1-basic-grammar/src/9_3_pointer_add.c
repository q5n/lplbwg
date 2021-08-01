//指针加法
#include <stdio.h>
#define LENGTH 5

int main(void){
    short sArr[LENGTH];
    short *sPtr; 
    double dArr[LENGTH];
    double *dPtr;
    
    sPtr=sArr;
    dPtr=dArr;
    
    for(int i=0;i<LENGTH;i++){
        printf("shortPointer+%d=%p  doublePointer+%d=%p\n",i,sPtr+i,i,dPtr+i);
    }
    
    return 0;
}