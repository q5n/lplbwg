/* 预定义宏 */
#include <stdio.h>


#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)

#pragma message("__FILE__:"__FILE__)
#pragma message("__DATE__:"__DATE__)
#pragma message("__TIME__:"__TIME__)

#pragma message("__LINE__:" TO_STR(__LINE__) )
#pragma message("__STDC__:" TO_STR(__STDC__) )
#pragma message("__STDC_HOSTED__:" TO_STR(__STDC_HOSTED__) )
#pragma message("__STDC_VERSION__:" TO_STR(__STDC_VERSION__) )

void show_sth(void);

int main(void){
    printf("__FILE__ is %s.\n",__FILE__);
    printf("__DATE__ is %s.\n",__DATE__);
    printf("__TIME__ is %s.\n",__TIME__);
    printf("__STDC_VERSION__ is %ld.\n",__STDC_VERSION__);
    printf("__STDC_HOSTED__ is %d.\n",__STDC_HOSTED__);
#ifdef __STDC__
    printf("__STDC__ is %ld.\n",__STDC__);
#else
    printf("__STDC__ undefined!\n");
#endif
    printf("this line is %d.\n",__LINE__);
    printf("current function is %s.\n",__func__);
    puts("");
    show_sth();
    return 0;
}


void show_sth(void){
    printf("current function is %s.\n",__func__);
    printf("this line is %d.\n",__LINE__);
}


