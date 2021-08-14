#include "my_io.h"
#include <string.h>
#include <stdlib.h>

#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film* next;
};

inline static void eatLine(void ){
    while(getchar()!='\n'){
        continue;
    }
}

int main(void){
    struct film * head = NULL;
    struct film *prev= NULL, *current;
    char input[TSIZE];

    //printf("the max movies number is:\n");
    //scanf("%d", &n);
    //eatLine();
    //movies=(struct film *) malloc(n*sizeof(struct film));
    puts("input movie title:");
    while(s_gets(input,TSIZE)!=NULL && input[0] !='\0' ){
        current=(struct film *) malloc(sizeof(struct film));
        current->next=NULL;
        if(head==NULL){
            head=current;
        }else {
            prev->next=current;
        }
        strcpy(current->title, input);
        puts("input rating [0,10]:");
        scanf("%d",&current->rating);
        eatLine();
        puts("\nnext movie title:");
        prev = current;
    }
    

    if (head==NULL){
        printf("No data input...\n");
        return 0;
    }
    
    
    printf("movie list:\n");
    current = head;
    while(current!=NULL){
        printf("\tMovie:<<%s>> Rating: %d\n",current->title,current->rating);
        current=current->next;
    }
    
    do{
        current = head;
        head=current->next;
        free(current);
    }while(head!=NULL);
    
    puts("==>over!");
    return 0;
}



