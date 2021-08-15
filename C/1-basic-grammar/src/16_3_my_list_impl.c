/* 实现my_list.h的链表函数 */
#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

/* 局部函数原型 */
static void CopyToNode(Item item,Node *pnode);


/*接口函数实现：*/

//初始化一个链表
void InitializeList(List *plist){
    *plist=NULL;
}

