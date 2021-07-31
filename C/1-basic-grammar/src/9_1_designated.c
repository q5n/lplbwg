
#include <stdio.h>
#define MONTHS 12

int main(void){
    int days[MONTHS]={31,28,[4]=31,30,31,[1]=29};
    days[2]=31;
    days[3]=30;
    for(int i=0;i<MONTHS;i++){
        printf("Month %2d has %d day?\n",(i+1),days[i]);
    }
    return 0;
}