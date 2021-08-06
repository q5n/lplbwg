#include <stdio.h>

void report_cnt(void);

void accumulate(int k);

int cnt=0;//外部链接的静态变量

int main(void){
    int autoVar;//自动变量
    register int ri;//寄存器变量
    printf("please enter a positive number:");
    while(scanf("%d",&autoVar)==1 && autoVar>0){
        cnt++;
        for(ri=autoVar;ri>=0;ri--){
            accumulate(ri);
        }
        printf("\nplease enter a positive number:");
    }
    report_cnt();
    return 0;
}

void report_cnt(void){
    printf("executed %d times\n",cnt);
}

