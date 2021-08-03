#include <stdio.h>

char* s_gets(char*str,int n){
    char *ret;
    int i=0;
    ret=fgets(str,n,stdin);
    if(ret!=NULL){
        while(str[i]!='\n' && str[i]!='\0'){
            i++;
        }
        if(str[i]=='\n'){
            str[i]='\0';
        }else{
            while(getchar()!='\n'){
                continue;
            }
        }
    }
    return ret;
}
