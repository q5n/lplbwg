#include <stdio.h>
#include <stdlib.h> //exit() 所在头
#include <string.h>
#define LIMIT 40


int main(int argc,char*argv[]){ 
    FILE *filePtr; //文件指针
    char text[LIMIT];

    if(argc!=2){
        fprintf(stderr,"Usage: %s filename.\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout,"========> start ~~~\n");
    if((filePtr=fopen(argv[1],"a+"))==NULL){
        fprintf(stderr,"Can not open file: %s.\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    
    puts("==>Enter something add to the file (intput # to quit!):");
    while( fscanf(stdin,"%40s",text)==1 && text[0]!='#'){
        fprintf(filePtr,"%s\n",text);
    }
    
    puts("\n==>File contents:");
    rewind(filePtr); /*指针回放到文件开始处*/
    while(fscanf(filePtr,"%s",text)==1){
        puts(text);
    }
    
    puts("==>over!");
    if (fclose(filePtr) != 0){
        fprintf(stderr,"Error in closing file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
