#include <stdio.h>
#include <stdlib.h> //exit() 所在头


int main(int argc,char*argv[]){ 
    FILE *filePtr; //文件指针
    unsigned long count=0;
    if(argc!=2){
        printf("Usage: %s filename.\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("========> start ~~~\n");
    if((filePtr=fopen(argv[1],"r"))==NULL){
        printf("Can not open file: %s.\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    int ch;
    while((ch=getc(filePtr))!=EOF){
        putc(ch,stdout); //与putchar(ch);相同
        count++;
    }
    if (fclose(filePtr) != 0){
        printf("Error in closing file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("\n========> File [%s] has %lu characters\n",argv[1],count);
    return 0;
}
