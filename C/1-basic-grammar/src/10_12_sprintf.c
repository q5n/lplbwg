#include <stdio.h> //sprintf 位于stdio.h
#include "my_io.h"
#define MAX 20

int main(void){
    char first[MAX];
    char last[MAX];
    char result[2*MAX+10];
    double prize;
    puts("your first name:");
    s_gets(first,MAX);
    puts("last name:");
    s_gets(last,MAX);
    puts("prize:");
    scanf("%lf",&prize);
    sprintf(result, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts("------your info:");
    puts(result);
    return 0;
}

