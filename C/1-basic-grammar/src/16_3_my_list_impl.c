/* 实现my_list.h的链表函数 */
#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

/* 局部函数原型 */
static void CopyToNode(Item item,Node *pnode);


/*接口函数实现：*/

//初始化一个链表
void InitializeList(List *plist){
    *plist=NULL;//List是指向Node的指针，NULL是指向void的指针，地址值为0
}

//确定链表是否为空定义
bool ListIsEmpty(const List *plist){
    return *plist == NULL;
}

//确定链表是否已满
bool ListIsFull(const List *plist){
    Node *pt=(Node *)malloc(sizeof(Node));
    if(pt==NULL){
        return true;
    }
    free(pt);
    return false;
}

//确定链表中的项数
unsigned int ListItemCount(const List *plist){
    long count=0;
    Node *pnode=*plist;
    while(pnode!=NULL){
        count++;
        pnode=pnode->next;
    }
    return count;
}

//在链表的末尾添加项
bool AddItem(Item item, List * plist){
    Node *scan=*plist;
    Node *pnew=(Node*) malloc(sizeof(Node));
    if(pnew==NULL){
        return false;
    }
    CopyToNode(item,pnew);
    pnew->next=NULL;
    if(scan==NULL){
        *plist=pnew;
    }else{
        while(scan->next!=NULL){
            scan=scan->next;
        }
        scan->next=pnew;
    }
    return true;
}

/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List *plist, void(*pfun)(Item item)){
    Node *scan=*plist;
    while(scan!=NULL){
        (*pfun)(scan->item);
        scan=scan->next;
    }
}

/* 释放已分配的内存（如果有的话） */
void EmptyTheList(List *plist){
    Node * psave;
    while (*plist != NULL){
        psave = (*plist)->next; /* 保存下一个节点的地址 */
        free(*plist); /* 释放当前节点 */
        *plist = psave; /* 前进至下一个节点 */
    }
}

//把一个项拷贝到节点中 
static void CopyToNode(Item item, Node * pnode){
    pnode->item = item; /* 拷贝结构 */
}