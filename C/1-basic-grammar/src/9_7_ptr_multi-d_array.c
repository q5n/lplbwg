#include <stdio.h>
#define ROW 3
#define COL 4

void printArr(int arr[ROW][COL]){
    printf(" x\\y | ");
    for(int j=0;j<COL;j++){
        printf("%3d ",j);
    }
    printf("\n");
    printf("-----|-");
    for(int j=0;j<COL;j++){
        printf("----");
    }
    printf("\n");

    for(int i=0;i<ROW;i++){
        printf("  %-2d | ",i);
        for(int j=0;j<COL;j++){
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printPtr(void *arr){
    printf(" x\\y | ");
    for(int j=0;j<COL;j++){
        printf("%3d ",j);
    }
    printf("\n");
    printf("-----|-");
    for(int j=0;j<COL;j++){
        printf("----");
    }
    printf("\n");
    int *p=arr;
    for(int i=0;i<ROW;i++){
        printf("  %-2d | ",i);
        for(int j=0;j<COL;j++){
            printf("%3d ",*p++);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int arr2[ROW][COL]={1,1,1,1,1,1};//多维数组，按一维初始化
    printArr(arr2);
    printf("------------------------------------------------\n");

    int arr1[ROW][COL]; 
    for(int i=0;i<ROW;i++){//循环初始化数组
        for(int j=0;j<COL;j++){
            arr1[i][j]=i*COL+j+1;
        }
    }
    //arr1[0]=arr1[1]; //编译不通过
    //arr1=arr2;//编译不通过
    printPtr(arr1); //按一维数组遍历
    printf("------------------------------------------------\n");
    printf("int (*ptr)[%d]=arr1;\n\n",COL);
    int (*ptr)[COL]=arr1;
    printf("arr1=%p, ptr=%p, ptr+1=%p, ptr+2=%p\n",arr1,ptr,ptr+1,ptr+2);
    printf("ptr[0]=%p, ptr[0]+1=%p, ptr[0]+2=%p\n",ptr[0],ptr[0]+1,ptr[0]+2);
    printf("*ptr=%p, *ptr+1=%p, *ptr+2=%p\n",*ptr,*ptr+1,*ptr+2);//*运算符优先级比+高
    
    // []运算符优先级比*高,*从右往左结合
    printf("ptr[0][0]=%d, *ptr[0]=%d, **ptr=%d \n", 
            ptr[0][0],*ptr[0],**ptr);
    printf("ptr[2][0]=%d, **(ptr+2)=%d, *ptr[2]=%d \n",
            ptr[2][0],**(ptr+2),*ptr[2]);
    printf("ptr[2][1]=%d, *(*(ptr+2)+1)=%d, *(ptr[2]+1)=%d \n",
            ptr[2][1],*(*(ptr+2)+1),*(ptr[2]+1));

    return 0;
}