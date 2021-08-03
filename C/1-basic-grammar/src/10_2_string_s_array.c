#include <stdio.h>

#define STR_LENGTH 20
#define ARR_LENGTH 3

int main(void){
    const char *ptrStrArr[ARR_LENGTH]={
        "Hello!",
        "how are you?",
        "fine, thnak you!"
    };
    char arrStrArr[ARR_LENGTH][STR_LENGTH]={
        "Good day!",
        "how do you do!",
        "nice to meet you!"
    };

    printf("%20s %20s\n","ptrStrArr","arrStrArr");
    printf("%20s %20s\n","- - - - - ","- - - - - ");
    for(int i=0;i<ARR_LENGTH;i++){
        printf("%20s %20s\n",ptrStrArr[i],arrStrArr[i]);
    }
    printf("sizeof(ptrStrArr):%d  sizeof(arrStrArr):%d\n",sizeof(ptrStrArr),sizeof(arrStrArr));
    return 0;
}

