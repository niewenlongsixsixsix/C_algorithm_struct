//
// Created by Administrator on 2019/11/13.
//

#define MAX_CAPACITY 50
#define ERROR 1
#define OK 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct List {
    ElemType data[MAX_CAPACITY];
    int length;
} List, *pList;

void InitList(pList p);

int ListInsert(pList, int, ElemType);

Status ListGet(List p, int i, ElemType *e);

Status ListDelete(pList p, int i, ElemType *e);

Status ListEmpty(List p);

int ListLocateElem(List p, int e);