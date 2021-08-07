//把文件附加到另一个文件末尾
#include "my_io.h"
#include <stdlib.h> //exit() 所在头
#include <string.h>

#define STR_LEN 100
#define BUFF_LEN 4096

void append(FILE *source,FILE *dest);


int main(void){ 
    FILE *destFp; //目标文件指针
    FILE *srcFp; //源文件指针
    int fCount=0;//附加文件数量

    char dest_name[STR_LEN];
    char src_name[STR_LEN];


    puts("input destination file name:");
    s_gets(dest_name,STR_LEN); 

    if((destFp=fopen(dest_name,"a+"))==NULL){
        fprintf(stderr,"Can not open file: %s.\n",dest_name);
        exit(EXIT_FAILURE);
    }
    
    if(setvbuf(destFp,NULL,_IOFBF,BUFF_LEN)!=0){
        fputs("create out buffer ERROR!",stderr);
        exit(EXIT_FAILURE);
    }
    
    puts("input source file name:");
    while( s_gets(src_name,STR_LEN) && src_name[0]!='\0') {
        if (strcmp(src_name,dest_name)==0){
            fputs("not itself!",stderr);
            continue;
        } 
        if((srcFp=fopen(src_name,"r"))==NULL){
            fprintf(stderr,"Can not open file: %s.\n",src_name);
            continue;
        }
        if(setvbuf(destFp,NULL,_IOFBF,BUFF_LEN)!=0){
            fputs("create out buffer ERROR!",stderr);
            continue;
        }
        append(srcFp,destFp);
        if(ferror(srcFp)!=0){
            fprintf(stderr,"ERROR in reading file: %s.\n",src_name);
        }
        if(ferror(destFp)!=0){
            fprintf(stderr,"ERROR in writing file: %s.\n",dest_name);
        }
        fclose(srcFp);
        fCount++;
        printf("%s appended!\n",src_name);
        puts("Next file:");
    }

    printf("append over! %d files appended.\n",fCount);
    rewind(destFp);
    
    printf("%s contents:\n",dest_name);
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    int c;
    while( (c=getc(destFp) )!=EOF){
        putchar(c);
    }
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts("\n==>over!");
    if (fclose(destFp) != 0){
        fprintf(stderr,"Error in closing file %s\n", dest_name);
        exit(EXIT_FAILURE);
    }
    return 0;
}


void append(FILE *source,FILE *dest){
    size_t bytes;
    static char tmp[BUFF_LEN];
    while( (bytes=fread(tmp,sizeof(char),BUFF_LEN,source))>0){
        fwrite(tmp,sizeof(char),bytes,dest);
    }
}