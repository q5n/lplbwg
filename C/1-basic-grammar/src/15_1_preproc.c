/* 简单预处理示例 */
#include <stdio.h>
#define TWO 2 //可以使用注释
#define OW "how are\
      you" /*反斜杠把该定义延续到下一行*/
#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

 
int main(void){
    int x=TWO;
    PX;
    x=FOUR;
    printf(FMT,x);
    printf("%s\n",OW);
    printf("TWO: OW\n");
    puts("==>over!");
    return 0;
}
 


