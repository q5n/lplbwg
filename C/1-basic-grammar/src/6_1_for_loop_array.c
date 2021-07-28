/*
* 循环遍历数组
*/
#include <stdio.h> //引入文件头
 
#define count 5
int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    int idx, sum, scoresX[count];
    float avg;
    printf("请依次输入5个分数(0~100):\n");
    for(idx=0,sum=0;idx<count;idx++){
        printf( "第 %d 个分数:",(idx+1) );
        scanf("%d",&scoresX[idx]);
        sum+=scoresX[idx];
    }
    avg=((float)sum)/count;
    printf("总分:%d, 平均分:%.1f\n",sum,avg);
    return 0;
}
 
