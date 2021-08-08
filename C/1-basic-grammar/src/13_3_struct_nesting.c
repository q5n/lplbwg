/* 结构体嵌套 */
#include <stdio.h>

#define STR_LEN 41
const char * msgs[]={
    "  hello, hello,",
    "thank you very much for choose: ",
    "do you like "
};


struct name_t {
    char first[STR_LEN];
    char last[STR_LEN];
};

struct guy{
    struct name_t name;
    char favfood[STR_LEN];
    char job[STR_LEN];
    float income;
};


int main(void){
    struct guy fellow={  //初始化结构体变量
        {"Carle","Mask"},
        "apple",
        "ITer",
        88888.8
    };
    printf("Dear %s,\n\n",fellow.name.first);
    printf("%s%s,\n",msgs[0],fellow.name.first);
    printf("%s%s,\n",msgs[1],fellow.job);
    printf("%s%s,\n",msgs[2],fellow.favfood);
    
    
    if(fellow.income>75000){
        puts("you have a good job!!");
    }else {
        puts("you have a job!");
    }
    puts("==>over!");
    return 0;
}
