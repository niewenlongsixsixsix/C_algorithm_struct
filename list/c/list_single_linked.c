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




