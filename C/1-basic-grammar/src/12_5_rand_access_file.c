//随机访问文件
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000



int main(void){
    double DAT[SIZE];
    const char *fileName="target/numbers.dat";
    FILE *fp;
    
    for(int i=0;i<SIZE;i++){
        DAT[i]=100*i+1/(i+1.0);
    }

    if( (fp=fopen(fileName,"wb")) ==NULL){//二进制只写模式
        fprintf(stderr,"Can not open file: %s.\n",fileName);
        exit(EXIT_FAILURE);
    }

    fwrite(DAT,sizeof(double),SIZE,fp);
    if (fclose(fp) != 0){
        fprintf(stderr,"Error in closing file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    if( (fp=fopen(fileName,"rb")) ==NULL){//二进制只读模式
        fprintf(stderr,"Can not open file: %s.\n",fileName);
        exit(EXIT_FAILURE);
    }
    
    printf("input file index in [0,%d].\n",SIZE-1);
    int i;
    long pos;
    double value;
    while( scanf("%d",&i)==1 && i>=0 && i<SIZE ){
        pos=(long)i*sizeof(double);
        fseek(fp,pos,SEEK_SET);
        fread(&value,sizeof(double),1,fp);
        printf("there's value is:%f.\n",value);
        puts("Next index:");
    }
    puts("==>over!");
    if (fclose(fp) != 0){
        fprintf(stderr,"Error in closing file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return 0;
}
