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

`2_1_first.c`:

```c
#include　<stdio.h>
int main(void)　　　　　　　　 /* 一个简单的C程序 */
{
　　int num;　　　　　　　　　 /* 定义一个名为num的变量 */
　　num = 1;　　　　　　　　　 /* 为num赋一个值 */
　　printf("I am a simple ");　/* 使用printf()函数 */
　　printf("computer.\n");
　　printf("My　favorite　number　is　％d　because　it　is　first.\n"，num);
　　return　0;
}
```







