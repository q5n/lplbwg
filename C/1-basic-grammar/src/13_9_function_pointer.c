/* 函数和指针 */
#include "my_io.h"
#include <string.h>
#include <ctype.h>

#define LEN 81

char showMenu(void);
void eatLine(void);
void show(void(*fp)(char *),char *str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *); 


int main(void){
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);//声明一个函数指针
    puts("input a string:");
    while(s_gets(line,LEN)!=NULL && line[0] !='\0'){
        while( (choice=showMenu())!='n'){
            switch(choice){
                case 'u':
                    pfun=ToUpper;
                    break;
                case 'l':
                    pfun=ToLower;
                    break;
                case 't':
                    pfun=Transpose;
                    break;
                case 'o':
                    pfun=Dummy;
                    break;
            }
            strcpy(copy,line);
            show(pfun,copy);
        }
        puts("input other string:");
        
    }
    puts("\n==>over!");
    return 0;
}

char showMenu(void){
   
    puts("Enter choice:");
    puts("u) uppercase          l) lowercase");
    puts("t) transposed case    o) original case");
    puts("n) next string");
    int ans=getchar();
    ans=tolower(ans);
     eatLine();
     while(strchr("ulton",ans)==NULL){
         puts("Please enter u,l,t,o, or n:");
        ans =tolower(getchar());
        eatLine();
     }
     return (char)ans;
}

void eatLine(void){
    while(getchar()!='\n'){
        continue;
    }
}

void ToUpper(char *str){
    while(*str){
        *str=(char)toupper(*str);
        str++;
    }
}
void ToLower(char *str){
    while(*str){
        *str=(char)tolower(*str);
        str++;
    }
}
void Transpose(char *str){
    while(*str){
        if(islower(*str)){
            *str=(char)toupper(*str);
        }else {
            *str=(char)tolower(*str);
        }
        str++;
    }
}
void Dummy(char *str){
    //do nothing
} 

void show(void(*fp)(char *),char *str){
    (*fp)(str);
    printf("\n==>%s<==\n\n",str);
}


