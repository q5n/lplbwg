#include <string.h>
#include <stdio.h>
#include "my_io.h"
#define ARR_LEN 20
#define STR_LEN 50 

void sort_strs(char *ptr[],int num);//声明排序函数


int main(void){
    char list[ARR_LEN][STR_LEN];
    char *ptr[ARR_LEN]; //一个(元素是char指针的)数组
    printf("input less than %d line words:\n",ARR_LEN);
    int cnt=0;
    for(;cnt<ARR_LEN; cnt++){
        if(s_gets(list[cnt],STR_LEN)==NULL||list[cnt][0]=='\0'){
            break;
        };
        ptr[cnt]=list[cnt];
    }
    puts("\nyour words:");
    for(int i=0;i<cnt;i++){
        printf("%d\t%s\n",i,list[i]);
    }
    sort_strs(ptr,cnt);
    
    puts("\nafter sort: ");
    for(int i=0;i<cnt;i++){
        printf("%d\t%s\n",i,ptr[i]);
    }
    
    return 0;
}

void sort_strs(char *strs[],int num){
    char *tmp;
    for(int i=0,j=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if(strcmp(strs[i],strs[j])>0){
                tmp=strs[i];
                strs[i]=strs[j];
                strs[j]=tmp;
            }
        }
    }
}

