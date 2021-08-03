#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define SYMBO "a string define with symbolic literal"
#define LENGTH 80

void staticStringTest(void){
    char *strPtr="abcd";//字符串字面量地址直接赋值给指针,该地址是static的
    char strArr[]="abcd";//数组是在程序运行时才分配内存，所以这里会复制字符字面量串的内容
    printf("%s\n","abcd");//编译器可以把这个字符串和strPtr指向的字符串存成一个，（C标准未定义）
    printf("before test,  strPtr=%s  strPtr-addr:%p  strArr=%s  strArr-addr:%p\n",
        strPtr,strPtr,strArr,strArr);
    *strPtr='A';//由于字符串常量是static的，这里改变首字符后，以后每次调用strPtr中的首字母都是'A'了，不同编译器效果不一样
    strArr[0]='0';//由于strPtr是每次调用函数时才分配，所以后面调用函数时，两次printf中strArr不一致
    printf("after test,  strPtr=%s  strPtr-addr:%p  strArr=%s  strArr-addr:%p\n",
        strPtr,strPtr,strArr,strArr);
}

int main(void){
    char charArr[LENGTH]="hello lala, test string ";
    const char *ptr="test pointer for string!"
     ", concat ?";
    puts("----------start------------");
    puts(SYMBO ", concat ?"); //字符串字面量之间是空白字符或没字符时，视为连在一起的
    puts(charArr );
    puts(ptr);
    charArr[7]=charArr[9]='i';
    puts(charArr);
    
    uint64_t bigNum=1234567890123456;
    printf("this is a big num:%"PRIu64", hex:%#"PRIx64"!\n",bigNum,bigNum);
    
    puts("----------------------");
    staticStringTest();
    staticStringTest();
    return 0;
}

