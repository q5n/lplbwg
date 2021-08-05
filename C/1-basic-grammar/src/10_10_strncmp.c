#include <string.h>
#include <stdio.h>
#define LENGTH 5


int main(void){
    const char* list[LENGTH]={
        "aabb","abbc","abbc","acbb","bcdd",
    };
    puts("there some words:");
    for(int i=0;i<LENGTH;i++){
        printf("%d\t%s\n",i,list[i]);
    }
    char* start="ab";
    printf("-------------search start with \"%s\"--------------------\n",start);
    //printf("sizeof(char):%d\n",sizeof(char));
    size_t n=strlen(start)/sizeof(char);
    for(int i=0;i<LENGTH;i++){
        if(strncmp(list[i],"ab",n)==0){
            printf("found[%d]==>%s\n",i,list[i]);
        }
    }
    return 0;
}

