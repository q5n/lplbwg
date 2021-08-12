/* assert()示例 */
#include <stdio.h>
#include <math.h>

//#define NDEBUG
#include <assert.h>


int main(void){
    double x,y,z;
    puts("enter x y :");
    while( scanf("%lf %lf",&x,&y)==2 
        && (x!=0||y!=0)
        ){
        printf("x=%.3lf, y=%.3lf\n",x,y);
        z=x*x - y*y;
        assert(z>=0);
        printf("sqrt(x^2+y^2) answer is %f\n", sqrt(z));
        puts("\nnext x,y :");
    }
    puts("\n==>over!");
    return 0;
}
 
