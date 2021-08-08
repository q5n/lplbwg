//结构数组
#include "my_io.h"
#include <stdlib.h>

#define MAX_TITLE 41
#define MAX_AUTH 41
#define MAX_BOOKS 1000 

struct book{ /*结构布局声明，标记book */
    char title[MAX_TITLE];
    char author[MAX_AUTH];
    float value;
};


int main(void){
    struct book library[MAX_BOOKS]; //声明一个book类型的数组;
    
    int inputCount=0;

    while(inputCount<MAX_BOOKS){
        printf("input book[%d]'s title:\n",inputCount);
        if(s_gets(library[inputCount].title,MAX_TITLE)==NULL ||
            library[inputCount].title[0]=='\0'){
                break;
        }; //访问title部分
        
        
        printf("author:\n");
        s_gets(library[inputCount].author,MAX_TITLE); //访问author部分

        printf("price value:\n");
        scanf("%f",&library[inputCount].value);
        inputCount++;
        while (getchar() != '\n')
            continue; /* 清理输入行*/
    }
    
    
    if(inputCount>0){
        puts("\n==>your book list:");
        for(int i=0;i<inputCount;i++){
            printf("%d. <<%s>> by %s: $%.2f\n",i,
                library[i].title,library[i].author,library[i].value);
        }
    }else {
        puts("No Books!");
    }
    puts("==>over!");
    return 0;
}
