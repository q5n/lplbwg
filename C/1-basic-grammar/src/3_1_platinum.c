#include <stdio.h> //引入文件头


int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    float weight; 
    float value; 
    printf("你的价值与你体重相同的白金相比，怎样？\n\n");
    printf("请输入你的体重(单位：英磅)：");
    scanf("%f",&weight);
    /* 1700-每盎司白金价格*/
    value=1700.0*weight*14.5833;//1英镑金衡盎司（14.5833）
    
    printf("\n你同体重的白金价值：[%.1f]美元!\n",value);
    return 0;
}
 