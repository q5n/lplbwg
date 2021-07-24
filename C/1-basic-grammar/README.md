# 基本语法



##  一、初识C

### 1. C语言标准

1978年 K&R C 传统C

1989年 ANSI C ==> C89 

1990年 ISO C ==> C90 与C89相同

  C精神:

1. 信任程序员
2. 不要妨碍程序员做需要做的事
3. 保持语言精练简单
4. 只提供一种方法执行一项操作
5. 让程序运行更快，即使不能保证其可移植性

1994年 ANSI/ISO ==> C99

新目标：国际化、弥补缺陷和提高计算的实用性

2011年 ISO  ==> C11

2018年  ISO  ==> C17

主要学习 C89/90  用C99或C11介绍新特性



### 2.编译过程

**Linux**:

c语言编译过程：

1. 预处理(Preprocessing)
       展开头文件/宏替换/去掉注释/条件编译 (.i)

2. 编译(Compilation)
       检查语法，生成汇编代码 (.s)

3. 汇编(Assembly)
       汇编代码转换机器码    (.o)

4. 链接(Linking)
       链接到一起生成可执行程序    (.out .a .so)

**Windows**:

源代码(.c) --> 编译器  --> 目标代码(.obj) --> 连接器+库代码+启动代码 --> 可执行代码(.exe,.dll)

 

## 二、Hello World

## 1. 代码

[2_1_first.c](src/2_1_first.c) :

```c
#include <stdio.h> //引入文件头

int main(void) /* 函数头: 返回类型 函数名(参数[这里是void]) */
{
    printf("Hello world!\n"); //调用stdio标准库里的printf函数, \n是换行符

    int x; /* 定义一个名为x的变量 */
    x = 1; /* 为x赋一个值 */ 
    printf("x=%d\n",x); //再次调用stdio标准库里的printf函数，并传参数
    return 0; //返回一个数
}
```

## 2. 编译&运行

自己写了个脚本([compileAndRun.bat](compileAndRun.bat))来编译执行这个程序：

![2-1-compileAndRun.png](img\2-1-compileAndRun.png)

## 3.注意

1. 每次用到库函数，都会用#include指令包含ANSI/ISO标准指定的头文件
2. main函数必须加(void),返回值必须是int



## 三、数据类型

关键字：int、short、long、unsigned、char、float、double、_Bool、_Complex、_Imaginary
运算符：sizeof()
函数：scanf()



C语言数据类型关键字：

| K&R C    | C90    | C99               |
| -------- | ------ | ----------------- |
| int      | signed | _Bool(true/false) |
| long     | void   | _Complex(复数)    |
| unsigned |        | _Imaginary(虚数)  |
| char     |        |                   |
| float    |        |                   |
| double   |        |                   |

1. 整数

   > 1. 声明变量   int a,b,c;
   >
   > 2. 初始化变量  int i=1,j=2;
   >
   > 3. printf int占位符%d  
   >
   >    如：printf("%d",i) 
   >
   > 4. 字面量：
   >
   >    十进制  7,    8,  9,   10,  15,  16
   >
   >    八进制  07,  10, 11, 12,  17, 20 
   >
   >    十六进制  0x7, 0X8 , 0x9, 0XA, 0XF, 0x10
   >
   >    printf 显示八进制占位符： %o ,带0前缀 %#o
   >
   >     printf 显示十六进制占位符： %x ,  %X,  带0x前缀 %#x,%#X



