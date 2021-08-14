#include "my_io.h"
#include <string.h>
#include <stdlib.h>

#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
};

inline static void eatLine(void ){
    while(getchar()!='\n'){
        continue;
    }
}

int main(void){
    struct film *movies;
    int i=0,n=0;

    printf("the max movies number is:\n");
    scanf("%d", &n);
    eatLine();
    movies=(struct film *) malloc(n*sizeof(struct film));
    puts("input movie title:");
    while(i<n && s_gets(movies[i].title,TSIZE)!=NULL
            && movies[i].title[0]!='\0' ){
        puts("input rating [0,10]:");
        scanf("%d",&movies[i++].rating);
        eatLine();
        puts("\nnext movie title:");
    }
    
    if (i==0){
        printf("No data input...\n");
    }else{
        printf("movie list:\n");
    }
    for (int j=0;j<i;j++){
        printf("\tMovie:<<%s>> Rating: %d\n",movies[j].title,movies[j].rating);
    }
    
    puts("==>over!");
    return 0;
}



