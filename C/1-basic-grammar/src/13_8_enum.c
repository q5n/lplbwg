/* 枚举 */
#include "my_io.h"
#include <string.h>
#include <stdbool.h>

#define LEN 30

enum spectrum { red, orange, yellow, green, blue, violet };
const char * colors [] = { "red", "orange", "yellow","green", "blue", "violet" };


int main(void){
    char choice[LEN];
    enum spectrum color;
    bool color_is_found=false;
    puts("enter a color:");
    
    while(s_gets(choice,LEN)!=NULL && choice[0]!='\0'){
        for(color=red;color<=violet;color++){ //注意c++不支持枚举++操作
            if(strcmp(choice,colors[color])==0){
                color_is_found=true;
                break;
            }
        }
    
        if(color_is_found){
            switch(color){
                case red: puts("Roses are red.");
                    break;
                case orange: puts("Poppies are orange.");
                    break;
                case yellow: puts("Sunflowers are yellow.");
                    break;
                case green: puts("Grass is green.");
                    break;
                case blue: puts("Bluebells are blue.");
                    break;
                case violet: puts("Violets are violet.");
                    break;
            }
        }else{
            printf("sorry, I don't konw %s\n",choice);
        }
        
        color_is_found=false;
        puts("\nNext color,please enter:");
    }
    
    puts("\n==>over!");
    return 0;
}



