//
// Created by Administrator on 2019/11/13.
//

#ifndef ALGORITHM_STRUCT_LIST_SINGLE_LINKED_H
#define ALGORITHM_STRUCT_LIST_SINGLE_LINKED_H

#endif //ALGORITHM_STRUCT_LIST_SINGLE_LINKED_H

#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1


typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node *next;
} LinkNode;


LinkNode* LinkedListInit();

Status LinkedListLength(LinkNode *headNode, int *e);
Status LinkedListAdd(LinkNode *headNode, ElemType e);
Status LinkedListInsert(LinkNode *headNode, int position, ElemType e);
Status LinkedDelete(LinkNode *headNode, int n, ElemType *e);
Status LinkedClear(LinkNode *headNode);