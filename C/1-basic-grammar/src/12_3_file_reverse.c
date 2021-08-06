//颠倒输出文本内容
#include <stdio.h>
#include <stdlib.h> //exit() 所在头

#define CNTL_Z '\032' //DOS文本文件结尾标记
#define STR_LEN 100


int main(void){ 
    FILE *filePtr; //文件指针
    char name[STR_LEN];
    


    puts("input file name:");
    scanf("%99s",name);
    
    if((filePtr=fopen(name,"rb"))==NULL){//二进制只读模式
        fprintf(stderr,"Can not open file: %s.\n",name);
        exit(EXIT_FAILURE);
    }
    
    fseek(filePtr,0L,SEEK_END); //定位到文件尾
    long last=ftell(filePtr);//获取文件结尾位置
    
    char c;
    for(long i=1L;i<=last;i++){
        fseek(filePtr,-i,SEEK_END); //一个个字符回退
        c=getc(filePtr);
        if(c!=CNTL_Z && c!='\r'){
            putchar(c);
        }
    }

    puts("\n==>over!");
    if (fclose(filePtr) != 0){
        fprintf(stderr,"Error in closing file %s\n", name);
        exit(EXIT_FAILURE);
    }
    return 0;
}
