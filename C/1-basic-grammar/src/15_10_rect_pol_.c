/* 坐标系转换 */
#include <stdio.h>
#include <math.h>

/*math库里三角函数用弧度代表角度，
    1°==π/180 rad
     正切tan(π/4)==tan(45°)==1
    ∴ 反正切atan(1)=π/4
    ∴ π=4*atan(1)
    1 rad =(180/π)° =( 180/(4*atan(1)) )°
*/
#define RAD_TO_DEG ( 180/( 4*atan(1) ) )

typedef struct polar_v{
    double radial;
    double angle;
} Polar_V;

typedef struct rect_v{
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main(void){
    Rect_V input;
    Polar_V result;
    printf("π=%f\n",4*atan(1));
    puts("input x and y coordinates:");
    while(scanf("%lf %lf",&input.x,&input.y)==2){
        result=rect_to_polar(input);
        printf("radial=%0.2f, angle=%0.2f\n",
            result.radial,result.angle);
    }
    
    puts("\n==>over!");
    return 0;
}

Polar_V rect_to_polar(Rect_V rv){
    Polar_V pv;
    pv.radial = sqrt(rv.x * rv.x + rv.y * rv.y);
    if (pv.radial == 0){
        pv.angle = 0.0;
    } else {
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x); //（atan2是已将象限纳入考量的反正切函数）
    }
    return pv;
}

