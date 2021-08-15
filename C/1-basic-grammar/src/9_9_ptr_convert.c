#include <stdio.h>
#include <stdint.h>
 
int main(void){
    int16_t nums[]={1,2};
    int16_t* pInt16=nums;
    printf("pInt16=%p \n",pInt16);
    printf("*pInt16=%d \n",*pInt16);
    printf("pInt16+1=%p \n",pInt16+1);
    printf("*(pInt16+1)=%d \n",*(pInt16+1));
    printf("\n");

    /*1.将pInt16强转为pVoid, 指向地址不变，
     *  指向类型变为void, 意味着指针不能解引用(或解引用为void)，不能做指针加法(或运算单位变为0) 
     */
    void* pVoid=(void*)pInt16;
    printf("pVoid=%p \n",pVoid);
    //printf("*pVoid=%d \n",*pVoid); //编译失败
    //printf("pVoid=%p \n",pVoid); //编译失败
    //printf("*(pVoid+1)=%d \n",*(pVoid+1)); //编译失败
    printf("\n");

    /*2.将pVoid强转为pInt8, 指向地址不变，
     *  指向类型变为int8_t, 意味着指针解引用后的数据类型为int8_t，指针加法运算单位变为1字节 
     */
    int8_t* pInt8=(int8_t*)pVoid;
    printf("pInt8=%p \n",pInt8);
    printf("*pInt8=%d \n",*pInt8);
    printf("pInt8+1=%p \n",pInt8+1);
    printf("*(pInt8+1)=%d \n",*(pInt8+1));
    printf("\n");


    /*3.将pInt16强转为pInt8, 指向地址不变，
     *  指向类型变为int8_t, 意味着指针解引用后的数据类型为int8_t，指针加法运算单位变为1字节 
     */
    int8_t* pInt8_2=(int8_t*)pInt16;
    printf("pInt8_2=%p \n",pInt8_2);
    printf("*pInt8_2=%d \n",*pInt8_2);
    printf("pInt8_2+1=%p \n",pInt8_2+1);
    printf("*(pInt8_2+1)=%d \n",*(pInt8_2+1));
    printf("\n");

    return 0;
}