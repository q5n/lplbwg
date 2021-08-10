/* 位操作显示二进制 */
#include <stdio.h>
#include <limits.h> //CHAR_BIT

char * itobs(int,char *);
void show_bstr(const char *); 
int invert_end(int num, int N);//切换后N位

int main(void){
    char bin_str[CHAR_BIT*sizeof(int)+1];
    int number;
    int ivt_num;
    int last=4;
    puts("input a number:");
    while( scanf("%d",&number)==1){
        itobs(number,bin_str);
        printf("binary is ");
        show_bstr(bin_str);
        printf(",hex is %#x\n",number);
        printf("after invert last %d bit:\n",last);
        ivt_num=invert_end(number,last);
        itobs(ivt_num,bin_str);
        printf("binary is ");
        show_bstr(bin_str);
        printf(",hex is %#x\n",ivt_num);
        putchar('\n');
    }
    puts("==>over!");
    return 0;
}

char * itobs(int n,char * ps){
    const static int size=CHAR_BIT*sizeof(int);
    //反向存入字符数组ps中
    for(int i=size-1; i>=0; i--,n>>=1){//每轮向右位移1位
        ps[i]=(01&n)  //取n最后一位 
        +'0'; //ascii字符'1'比'0'大1
    }
    ps[size]='\0';
    return ps;
}

//按4bit分隔
void show_bstr(const char *str) {
    putchar('"');
    for(int i=0; str[i]!='\0' ;i++){
        if (i && i % 4 == 0) {
            putchar(' ');
        }
        putchar(str[i]);
    }
    putchar('"');
}

int invert_end(int num, int N){
    int mask=0;
    for(int i=0;i<N;i++){
        mask<<=1;
        mask|=1;
    }
    return num^mask;
}



