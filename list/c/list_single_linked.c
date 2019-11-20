//
// Created by Administrator on 2019/11/13.
//
#include "../h/list_single_linked.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * 初始化一个单链表，带头结点
 * @return
 */
LinkNode* LinkedListInit(){
    LinkNode *n;
    n = (LinkNode*)malloc(sizeof(LinkNode));
    if (n == NULL){
        printf("ListInit 分配内存失败");
    }
    n->next = NULL;
    return n;
}

Status LinkedListAdd(LinkNode *headNode, ElemType e){
    if (headNode == NULL){
        printf("headNode is NULL\n");
        return ERROR;
    }
    while (headNode->next != NULL){
        headNode = headNode->next;
    }
    LinkNode *addNode = (LinkNode*)malloc(sizeof(LinkNode));
    addNode->data = e;
    addNode->next = headNode->next;
    headNode->next = addNode;
    return OK;
}

Status LinkedListInsert(LinkNode *headNode, int position, ElemType e){
    if (headNode == NULL){
        printf("headNode is NULL\n");
        return ERROR;
    }
    int count = 1;
    while (headNode && count < position){
        headNode = headNode->next;
        count++;
    }
    if (headNode != NULL){
        LinkNode *tempNode = (LinkNode*)malloc(sizeof(LinkNode));
        tempNode->data = e;
        tempNode->next = headNode->next;
        headNode->next = tempNode;
        return OK;
    }
    return FALSE;
}

Status LinkedListLength(LinkNode *headNode, int *e){
    if (headNode == NULL){
        printf("headNode is NULL");
        return ERROR;
    }
    int n = 0;
    LinkNode *tempNode = headNode;
    while (tempNode->next != NULL){
        n++;
        tempNode = tempNode->next;
    }
    *e = n;
    return OK;
}

/**
 * 删除n位置上的结点，并返回结点里的数据
 * @param headNode
 * @param n
 * @param e
 * @return
 */
Status LinkedDelete(LinkNode *headNode, int n, ElemType *e){
    if (headNode == NULL){
        printf("the headNode is null");
        return ERROR;
    }
    int i = 1;
    // 由于单链表删除和添加结点都需要获取到他的前驱结点，由于头结点存在的关系，因此头指针初始化的时候位于第一个有效结点的前面
    // 此时就可以认为找到了1的位置，但是由于我们是要进行删除结点，因此应当保证删除的结点是存在的，所以头指针的next不应该为空，于是
    // headNode->next != NULL
    // 这里和插入结点不一样，插入结点只需要找到插入位置的前驱结点，并且保证插入位置没有超出链表的长度+1，至于前驱结点后面是不是为NULL，不重要
    // 因此在insert里面是这样写的：
    // count = 1;
    // while (headNode && count < position) 并不是headNode->next
    while (headNode->next && i < n){
        headNode = headNode->next;
        i++;
    }

    if (headNode->next == NULL || i > n){
        printf("the n is illegal\n");
        return ERROR;
    }
    LinkNode *tempNode = headNode->next;
    headNode->next = tempNode->next;
    *e = tempNode->data;
    free(tempNode);
    return OK;
}

Status LinkedClear(LinkNode *headNode){
    LinkNode *p, *q;
    p = headNode->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    headNode->next = NULL;
    return OK;
}
