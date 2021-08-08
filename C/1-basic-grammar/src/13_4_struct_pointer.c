/* 指向结构的指针 */
#include <stdio.h>

#define STR_LEN 21

struct name_t {
    char first[STR_LEN];
    char last[STR_LEN];
};


struct guy{
    struct name_t name; //42字节
    char favfood[STR_LEN];//21字节
    char job[STR_LEN];//21字节
    float income;//4字节
};//共88字节


int main(void){
    //初始化结构体数组
    struct guy fellow[2]={
        {{"Carle","Mask"},
            "apple",
            "worker",
            88888.8
        },
        {{"Quentin","Lee"},
            "fish hot pot",
            "ITer",
            100000.0
        }
    };
    
    struct guy *him; //指向结构体的指针
    printf("addr #1:%p #2:%p\n",&fellow[0],&fellow[1]);
    unsigned long long ptrNum[2];
    ptrNum[0]=&fellow[0];
    ptrNum[1]=&fellow[1];
    printf("difference between #1 and #2 is %d\n",ptrNum[1]-ptrNum[0]);
    him=&fellow[0];
    printf("pointer #1:%p #2:%p\n",him,him+1);
    
    printf("him->income : $%.2f,  (*him).income: $%.2f\n",him->income,(*him).income);
    him++;
    printf("him->favfood : %s,  him->name.last : %s\n",him->favfood,him->name.last);
    
    puts("\n==>over!");
    return 0;
}
