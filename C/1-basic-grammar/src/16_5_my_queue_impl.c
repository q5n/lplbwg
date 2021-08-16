#include "my_queue.h"
#include <stdio.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node * pn);

static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(Queue * pq){
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsEmpty(const Queue * pq){
    return pq->items == 0;
}

bool QueueIsFull(const Queue * pq){ 
    return pq->items == MAXQUEUE;
}

int QueueItemCount(const Queue * pq){
    return pq->items;
}


bool EnQueue(Item item, Queue * pq){
    Node *pnew;
    if (QueueIsFull(pq))
        return false;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL){
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    
    if (QueueIsEmpty(pq)) {
        pq->front = pnew; /* 项位于队列的首端 */
    }else{
        pq->rear->next = pnew; /* 链接到队列的尾端 */
    }
    pq->items++; /* 队列项数加1 */
    pq->rear = pnew; /* 记录队列尾端的位置 */
    return true;
}

bool DeQueue(Item *pitem, Queue * pq){
    Node * pt;
    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items <= 0){
        pq->rear = NULL;
    }
    return true;
}


/* 清空队列 */
void EmptyTheQueue(Queue * pq){
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

/* 局部函数 */
static void CopyToNode(Item item, Node * pn){ 
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi){
    *pi = pn->item;
}
