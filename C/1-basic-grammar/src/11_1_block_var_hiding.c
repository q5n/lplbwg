#include <stdio.h>

int main(void){
    int var=11;
    printf("var in outer-block1: %d at %p\n",var,&var);
    {
        int var=22;//新的var，隐藏了外层原来的var
        printf("var in inner-block: %d at %p\n",var,&var);
    }
    printf("var in outer-block2: %d at %p\n",var,&var);
    while(var++<33){//原来的var
        int var=44;//新的var，隐藏了外层原来的var
        var++;
        printf("var in while-loop-block: %d at %p\n",var,&var);
    }
    printf("var in outer-block3: %d at %p\n",var,&var);
    return 0;
}
