/* 处理结构体数组的函数 */
#include <stdio.h>

#define FLEN 50
#define N 2

struct funds{
    char bank[FLEN];
    double bankfund;
    char save[FLEN];
    double savefund;
};

double sum(const struct funds money[],int n);

int main(void){
    struct funds jones[N]={
        {
            "G-M Bank",4032.27,
            "Lucky's Saving and Loan",8543.94
        },
        {
            "H-J's Bank",3620.88,
            "Party Time Savings",3802.91
        }
    };
    printf("jones total :$%.2f\n",sum(jones,N));
    return 0;
}

double sum(const struct funds money[],int n){
    double total=0;
    for(int i=0;i<n;i++){
        total+=(money[i].bankfund+money[i].savefund);
    }
    
    return total;
}



