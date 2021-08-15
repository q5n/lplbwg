#include "my_list.h"
#include "my_io.h"
#include <stdlib.h>

void showmovies(Item item);

int main(void){
    List movies;
    InitializeList(&movies);

    if (ListIsFull(&movies)){
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    
    puts("Enter first movie title:");
    Item temp;
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0'){
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') { continue; }
        if (!AddItem(temp, &movies)){
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies)){
            puts("The list is now full.");
            break;
        }
        puts("\nEnter next movie title (empty line to stop):");
    }
    
    if (ListIsEmpty(&movies)) {
        printf("No data entered. ");
    }else{
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    EmptyTheList(&movies);
    puts("==>over!");
    return 0;
}

void showmovies(Item item){
    printf("    Movie:<<%s>> Rating: %d\n", item.title,item.rating);
}


