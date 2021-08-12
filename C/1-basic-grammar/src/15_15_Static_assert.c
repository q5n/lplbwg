/* _Static_assert示例 */
#include <stdio.h>
#include <limits.h>
#define EXPECT 16
_Static_assert(CHAR_BIT == EXPECT, "16-bit char falsely assumed"); //编译报错



int main(void){
    printf("char is %d bits.",EXPECT);
    puts("\n==>over!");
    return 0;
}
 
