/* 结构体中的字符指针和字符数组 */
#include "my_io.h"
#include <string.h>  //strcpy(),strlen()
#include <stdlib.h>  //malloc(),free()

#define STR_LEN 100

struct name_t {
    char * first;
    char * last;
    int letterCnt;
};

void get(struct name_t*);
void update(struct name_t*);
void show(const struct name_t*);
void clean(struct name_t*);

int main(void){
    struct name_t name;
    get(&name);
    update(&name);
    show(&name);
    clean(&name);
    return 0;
}

void setFirst(struct name_t* namePtr,const char *val){
    static int init1=0;
    if(init1){
        free(namePtr->first);
    }else{
        init1++;
    }
    namePtr->first=(char*)malloc(strlen(val)+1);//分配字符串大小的空间
    strcpy(namePtr->first,val);
}
void setLast(struct name_t* namePtr,const char *val){
    static int init2=0;
    if(init2){
        free(namePtr->last);
    }else{
        init2++;
    }
    namePtr->last=(char*)malloc(strlen(val)+1);//分配字符串大小的空间
    strcpy(namePtr->last,val);
}


void get(struct name_t* namePtr){
    char tmp[STR_LEN];
    printf("Input your first name:\n");
    s_gets(tmp,STR_LEN);
    setFirst(namePtr,tmp);

    printf("last name:\n");
    s_gets(tmp,STR_LEN);
    setLast(namePtr,tmp);

}

void update(struct name_t* namePtr){
    namePtr->letterCnt=strlen(namePtr->first)+strlen(namePtr->last);
}

void show(const struct name_t* namePtr){
    printf("%s %s, contains %d letters.\n",namePtr->first, namePtr->last, namePtr->letterCnt);
}

void clean(struct name_t* namePtr){
    free(namePtr->first);
    free(namePtr->last);
}

 



