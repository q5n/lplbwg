/* 宽字节 示例 */

/*抑制告警：warning C4996: 'mbsrtowcs': This function or variable may be unsafe.*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <stdlib.h>
#include <string.h>

#define  TO_STR2(x) #x
#define  TO_STR(x) TO_STR2(x)
#define  LINE TO_STR(__LINE__)



//注意函数名不要超过31字符
static wchar_t* moreBytesToWideChars(const char *moreBytes){
    size_t size=strlen(moreBytes)+1;
    //printf("size=%zd\n",size);
    wchar_t* dest=(wchar_t*) malloc(size*sizeof(wchar_t));
    //printf("dest@%p\n",dest);
    mbstate_t state;
    if ( !mbsinit(&state) ){//判断state是否初始化
        memset(&state,0,sizeof(state));//使state数组置为0值（初始化为0)
    }
    size_t len=mbsrtowcs(dest,&moreBytes,size,&state);//多字节字符串 转 宽字符串
    //printf("len=%zd\n",len);
    dest[len]='\0';
    //printf("wcslen(dest)=%zd\n",wcslen(dest));
    printf("dest@%p\n",dest);
    return dest;
}


static char* wideCharsToMoreBytes(const wchar_t *wideChars){
    size_t wc_size=wcslen(wideChars);
    size_t size=wc_size*4+1;//当前多字节字符集为utf8,字节可变范围(1-4),取最大，乘以4
    printf("size=%zd\n",size);
    char* dest=(char*) malloc(size*sizeof(char));
    mbstate_t state;
    char* tmpDest=dest; 
    char16_t c16=u'\0';
    /*若 c16 是空宽字符 u'\0' ，则存储空字节，前附恢复到初始迁移状态所需的任何迁移序列，
    并更新 state 以表示初始迁移状态。*/
    size_t mbsLen=c16rtomb(tmpDest,c16,&state);
    //printf("%04x(%zd) ",c16,mbsLen);
    for(size_t i=0;i<wc_size;i++){
        c16=(char16_t)wideChars[i];
        mbsLen=c16rtomb(tmpDest,c16,&state);
        if(mbsLen>(size_t)0){
            tmpDest+=mbsLen;
        }
        //printf("%04x(%zd) ",c16,mbsLen);
    }
    *tmpDest='\0';
    return dest;
}


int main(void){
    wchar_t *str=L"hello world!";
    wprintf(L""LINE": %ls\n",str);

    /* 多字节字符串，由/execution-charset指定可执行文件中字符常量的编码集 */
    char *mbStr="你好，世界！"; 
    wprintf(L""LINE": strlen(mbStr)=%zd\n",strlen(mbStr));
    wchar_t* wcStr=moreBytesToWideChars(mbStr);//多字节字符串 转 宽字符串
    wprintf(L""LINE": %ls\n",wcStr);
    //printf("wcslen(wcStr)=%zd\n",wcslen(wcStr));
    //printf("wcStr@%p\n",wcStr);
    free(wcStr);
    printf("--------\n");

    wchar_t *widecStr=L"123abc你好，世界！";//这里会把‘多字节字符’的每个字符转成宽字符，所以下面会乱码
    size_t wc_size=wcslen(widecStr);
    wprintf(L""LINE": wcslen(widecStr)=%zd\n",wc_size);
    wprintf(L""LINE": %ls\n",widecStr); //这里乱码，
    
    char *moreBytes=wideCharsToMoreBytes(widecStr);//宽字符串 转 多字节字符串
    printf("\n");
    if(moreBytes!=NULL){
        printf(LINE": strlen(moreBytes)=%zd\n",strlen(moreBytes)); 
        printf(LINE": %s\n",moreBytes); 
        free(moreBytes);
    }
    return 0;
}


