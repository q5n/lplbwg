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

### 1. 代码

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

### 2. 编译&运行

自己写了个脚本([compileAndRun.bat](compileAndRun.bat))来编译执行这个程序：

![2-1-compileAndRun.png](img\2-1-compileAndRun.png)

### 3.注意

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

### 1. 整数

   > 1. 声明变量   int a,b,c;
   >
   > 2. 初始化变量  int i=1,j=2;
   >
   > 3. printf int占位符%d  
   >
   >    如：printf("%d",i) 
   >
   >    示例：[3_1_platinum.c](src/3_1_platinum.c)
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
   >    
   >    示例：[3_2_int_Literal.c](src/3_2_int_Literal.c)

### 2. 整数其他形式

   > 附属关键字 short long unsigned
   >
   > short int 或 short
   >
   > long int 或 long
   >
   > long long int或long long 至少64bit
   >
   > unsigned int 或 unsigned 无符号整数(非负)
   >
   > unsigned short ,  unsigned long , unsigned long long
   >
   > 任何有符号类型前添加关键字signed可以强调有符号(有负数)， 如 signed int 等同于 int
   >
   > 
   >
   > c语言规定 
   >
   > short占用空间不能比int多 ，long占用空间不能比int少
   >
   > 现在个人计算机常见设置：long long - 64bit, long 32bit, short 16bit, int 16bit或32bit(依计算机自然字长而定)
   >
   > 
   >
   > long和long long字面常量
   >
   > 数字字面量后加L或l,
   >
   > 在支持long long类型的系统中，也可以使用ll或LL后缀表示long long类型，u或U后缀表示无符号，如5ull,5Ull,5llU,5LLu
   >
   > 
   >
   > printf中unsigned 用%u前缀，short用%h前缀，long用%l前缀，long long用%ll前缀
   >
   > 示例[3_3_more_int.c](src/3_3_more_int.c)
   >
   > 
   >
   > 整数运算溢出时，从整数类型能表示最小值开始计算
   >
   > 
   >
   > char类型-1字节
   >
   > 字符'j'  '\x6A' '\0152'
   >
   > printf 占位符%c
   >
   > 有些C编译器把char实现为有符号类型，这意味着char可表示的范围是-128～127。而有些C编译器把char实现为无符号类型
   >
   > C90: 
   >
   > unsigned char表示无符号字节字符
   >
   > signed char表示有符号字节字符
   >
   > 
   >
   > `_Bool`类型
   > C99标准添加了`_Bool`类型，用于表示布尔值，即逻辑值true和false。因为C语言用值1表示true，值0表示false，所以`_Bool`类型实际上也是一种整数类型。但原则上它仅占用1位存储空间，因为对0和1而言，1位的存储空间足够了
   >
   > 
   >
   > C99可移植类型
   >
   > ​	stdint.h和inttypes.h
   >
   > int8_t~int64_t， uint8_t ~ uint64_t
   >
   > int_least8_t uint_least8_t
   >
   > int_fast8_t uint_fast8_t
   >
   > 
   >
   > intmax_t uintmax_t
   >
   > 

### 3. 浮点型

   >float、double和long double
   >
   >浮点字面量：
   >
   >有符号的数字（包括小数点），后面紧跟e或E，最后是一个有符号数表示10的指数
   >
   >​	正号可以省略。可以没有小数点（如，2E5）或指数部分（如，19.28），但是不能同时省略两者。
   >
   >可以省略小数部分（如，3.E16）或整数部分（如，.45E-6），但是不能同时省略两者。
   >
   >
   >
   >C99 标准添加了一种新的浮点型常量格式——用十六进制表示浮点型常量，即在十六进制数前加上十六进制前缀（0x或0X），用p和P分别代替e和E，用2的幂代替10的幂（即，p计数法）。如下所示：
   >0xa.1fp10
   >
   >
   >
   >printf()函数使用％f转换说明打印十进制记数法的float和double类型浮点数，用％e打印指数记数法的浮点数。如果系统支持十六进制格式的浮点数，可用a和A分别代替e和E。打印long double类型要使用％Lf、％Le或％La转换说明
   >
   >
   >
   >IEEE浮点标准,在C11作为可选项
   >
   >

### 4. 复数

   > 一般而言，虚数类型都是可选项。C11标准把整个复数软件包都作为可选项
   >
   > 
   >
   > C语言有3种复数类型：`float_Complex`、`double_Complex`和`long double _Complex`。例如，`float _Complex`类型的变量应包含两个float类型的值，分别表示复数的实部和虚部。
   >
   > 
   >
   > 类似地，C语言的3种虚数类型是float _Imaginary、`double _Imaginary`和`long double _Imaginary`。
   >
   > 
   >
   > 如果包含complex.h头文件，便可用complex代替`_Complex`，用imaginary代替`_Imaginary`，还可以用I代替-1的平方根。

### 5. 其他类型

   > C语言还有一些从基本类型衍生的其他类型，包括数组、指针、结构和联合

### 6. 类型大小

   > sizeof是C语言的内置运算符，以字节为单位给出指定类型的大小
   >
   > 
   >
   > C99和C11提供％zd转换说明匹配sizeof的返回类型(size_t)
   >
   > 示例：[3_4_sizeof.c](src/3_4_sizeof.c)

### 7. 转义字符

   > 警报声（\a） 退格（\b）、水平制表符（\t）和回车（\t）
   >
   > 示例[3_5_escape.c](src/3_5_escape.c)



## 四、字符串

todo
