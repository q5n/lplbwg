#include <stdio.h>

int addStatic(int param){
    int blockAutoVar=0;
    blockAutoVar++;
    static int blockStaticVar=0;
    blockStaticVar++;
    printf("addStatic{param:%d blockAutoVar:%d, blockStaticVar:%d}",param,blockAutoVar,blockStaticVar);
    return blockAutoVar+param+blockStaticVar;
}

int main(void){
    for(int i=0;i<5;i++){
        printf("%d. ",i);
        printf(" result==> %d\n",addStatic(i));
    }
    return 0;
}

