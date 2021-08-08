//结构体
#include "my_io.h"
#include <stdlib.h>

#define MAX_TITLE 41
#define MAX_AUTH 41

struct book{ /*结构布局声明，标记book */
    char title[MAX_TITLE];
    char author[MAX_AUTH];
    float value;
};


int main(void){
    struct book library; //声明一个book类型的变量 library;
    puts("book title:");

    s_gets(library.title,MAX_TITLE); //访问title部分
    
    printf("author:\n");
    s_gets(library.author,MAX_TITLE); //访问author部分

    printf("price value:\n");
    scanf("%f",&library.value);
    
    printf("<<%s>> by %s: $%.2f\n",library.title,library.author,library.value);

    puts("==>over!");
    return 0;
}
