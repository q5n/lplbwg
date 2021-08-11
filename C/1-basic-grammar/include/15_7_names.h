#ifndef H_15_7_NAMES_
#define H_15_7_NAMES_
#pragma message("start define H_15_7_NAMES_ ...")
// 明示常量
#define SLEN 32
// 结构声明
struct names_st{
char first[SLEN];
char last[SLEN];
};
// 类型定义
typedef struct names_st names;
// 函数原型
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);
#else
#pragma message("H_15_7_NAMES_ already defined!")
#endif //15_7_NAMES_H_