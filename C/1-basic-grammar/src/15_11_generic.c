/* 定义泛型宏 */
#include <stdio.h>
#include <math.h>

/*math库里三角函数用弧度代表角度，
    1°==π/180 rad
     正切tan(π/4)==tan(45°)==1
    ∴ 反正切atan(1)=π/4
    ∴ π=4*atan(1)
    1 rad =(180/π)° =( 180/(4*atan(1)) )°

    atanl 接收参数long double
*/
#define RAD_TO_DEG ( 180/( 4*atanl(1) ) )

#define SQRT(X) _Generic((X),\
long double: sqrtl,\
default: sqrt,\
float: sqrtf\
)(X)

#define SIN(X) _Generic((X),\
long double: sinl((X)/RAD_TO_DEG),\
default: sin((double)((X)/RAD_TO_DEG)),\
float: sinf((float)((X)/RAD_TO_DEG))\
)


int main(void){
    float x=45.0f;
    double xx=45.0;
    long double xxx=45.0L;
    
    long double y=SQRT(x);
    long double yy=SQRT(xx);
    long double yyy=SQRT(xxx);
    printf("%.17Lf\n",y);
    printf("%.17Lf\n",yy);
    printf("%.17Lf\n",yyy);
    
    int i=45;
    yy=SQRT(i);
    printf("%.17Lf\n",yy);
    
    yyy=SIN(xxx);
    printf("%.17Lf\n",yyy);
    puts("\n==>over!");
    return 0;
}

