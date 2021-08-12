/* 泛型表达式 */
#include <stdio.h>

#define MY_TYPE(X) _Generic( (X),\
    int:"int",\
    int*:"int*",\
    float:"float",\
    double:"double",\
    long:"long",\
    default:"other"\
)

#define PRINT_STR(x) printf(#x" ==> %s\n",x)
#define PRINT_NUM(x) printf(#x" ==> %d.\n",x)

int main(void){
    int d=5;
    PRINT_NUM(d);
    PRINT_STR(MY_TYPE(d));
    PRINT_STR(MY_TYPE(2.0*d));
    PRINT_STR(MY_TYPE(3L));
    PRINT_STR(MY_TYPE((float)4.0));
    PRINT_STR(MY_TYPE('d'));
    PRINT_STR(MY_TYPE("d"));
    PRINT_STR(MY_TYPE(&d));
    return 0;
}

