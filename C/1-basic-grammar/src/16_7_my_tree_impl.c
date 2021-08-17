#include "my_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

/* 局部函数 */
static void InOrder(const Trnode * root, void(*pfun)(Item item)){
    if(root != NULL){
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root){
    Trnode * pright;
    if (root != NULL){
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static bool ToLeft(const Item * i1, const Item * i2){
    int comp1= strcmp(i1->petname, i2->petname);
    if (comp1 < 0)
        return true;
    else if (comp1 == 0 &&strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2){
    int comp1 = strcmp(i1->petname, i2->petname);
    if (comp1 > 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}

static void AddNode(Trnode * new_node, Trnode * root){
    if(ToLeft(&new_node->item, &root->item)){
        if (root->left == NULL) /* 空子树 */
            root->left = new_node; /* 把节点添加到此处 */
        else
            AddNode(new_node, root->left); /* 否则处理该子树 */
    } else if (ToRight(&new_node->item, &root->item)){
        if(root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    } else {/* 不允许有重复项*/
        fprintf(stderr, "location error in AddNode()\n");
        exit(EXIT_FAILURE);
    }
}

static Trnode * MakeNode(const Item * pi){
    Trnode * new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL){
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    } 
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree){
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
        return look; /* 提前返回 */
    while (look.child != NULL){
        if(ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        } else /* 如果前两种情况都不满足， 则必定是相等的情况 */
            break; /* look.child 目标项的节点 */
    }
    return look; /* 成功返回 */
}

static void DeleteNode(Trnode **ptr){/* ptr 是指向目标节点的父节点指针成员的地址 */
    Trnode * temp;
    if ((*ptr)->left == NULL){
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {/* 被删除的节点有两个子节点 */
        /* 找到重新连接右子树的位置 */
        for (temp = (*ptr)->left; temp->right != NULL;temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

/* 函数原型 */
/* 操作： 把树初始化为空*/
/* 前提条件： ptree指向一个树 */
/* 后置条件： 树被初始化为空 */
void InitializeTree(Tree * ptree){
    ptree->root = NULL;
    ptree->size = 0;
}

/* 操作： 确定树是否为空 */
/* 前提条件： ptree指向一个树 */
/* 后置条件： 如果树为空， 该函数返回true */
/* 否则， 返回false */
bool TreeIsEmpty(const Tree * ptree){
    return ptree->root==NULL;
}

/* 操作： 确定树是否已满 */
/* 前提条件： ptree指向一个树 */
/* 后置条件： 如果树已满， 该函数返回true */
/* 否则， 返回false */
bool TreeIsFull(const Tree * ptree){
    return ptree->size >= MAXITEMS;
}

/* 操作： 确定树的项数 */
/* 前提条件： ptree指向一个树 */
/* 后置条件： 返回树的项数 */
int TreeItemCount(const Tree * ptree){
    return ptree->size;
}

/* 操作： 在树中添加一个项 */
/* 前提条件： pi是待添加项的地址 */
/* ptree指向一个已初始化的树 */
/* 后置条件： 如果可以添加， 该函数将在树中添加一个项 */
/* 并返回true； 否则， 返回false */
bool AddItem(const Item * pi, Tree * ptree){
    Trnode * new_node;
    if (TreeIsFull(ptree)){
        fprintf(stderr, "Tree is full\n");
        return false; /* 提前返回 */
    }
    
    if(SeekItem(pi, ptree).child != NULL){
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false; /* 提前返回 */
    }
    
    new_node = MakeNode(pi); /* 指向新节点 */
    if (new_node == NULL){
        fprintf(stderr, "Couldn't create node\n");
        return false; /* 提前返回 */
    } /* 成功创建了一个新节点 */
    ptree->size++;
    if (ptree->root == NULL) /* 情况1： 树为空 */
        ptree->root = new_node; /* 新节点为树的根节点 */
    else /* 情况2： 树不为空 */
        AddNode(new_node, ptree->root);/* 在树中添加新节点 */
    return true; /* 成功返回 */
}

/* 操作： 在树中查找一个项 */
/* 前提条件： pi指向一个项 */
/* ptree指向一个已初始化的树 */
/* 后置条件： 如果在树中添加一个项， 该函数返回true */
/* 否则， 返回false */
bool InTree(const Item * pi, const Tree * ptree){
    return SeekItem(pi, ptree).child != NULL;
}

/* 操作： 从树中删除一个项 */
/* 前提条件： pi是删除项的地址 */
/* ptree指向一个已初始化的树 */
/* 后置条件： 如果从树中成功删除一个项， 该函数返回true*/
/* 否则， 返回false */
bool DeleteItem(const Item * pi, Tree * ptree){
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL) /* 删除根节点项 */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;
    return true;
}

/* 操作： 把函数应用于树中的每一项 */
/* 前提条件： ptree指向一个树 */
/* pfun指向一个函数， */
/* 该函数接受一个Item类型的参数， 并无返回值*/
/* 后置条件： pfun指向的这个函数为树中的每一项执行一次*/
void Traverse(const Tree * ptree, void(*pfun)(Item item)){
    if(ptree != NULL)
        InOrder(ptree->root, pfun);
}

/* 操作： 删除树中的所有内容 */
/* 前提条件： ptree指向一个已初始化的树 */
/* 后置条件： 树为空 */
void DeleteAll(Tree * ptree){
    if(ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
    
}


