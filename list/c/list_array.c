//
// Created by Administrator on 2019/11/12.
// Implement list by array
//
#include "../h/list_array.h"

/**
 * init a List
 * @param p
 */
void InitList(pList p) {
    p->length = 0;
}

/**
 * Insert a value into the List.
 * @param p
 * @param i
 * @param e
 * @return
 */
Status ListInsert(pList p, int i, ElemType e) {
    // 容量已满, i 取值范围错误
    if (p->length == MAX_CAPACITY || i < 1 || i > p->length + 1) {
        return ERROR;
    }
    // 判断插入的下标是否正好是结尾。
    if (i <= p->length) {
        for (int temp = p->length; temp < i; temp--) {
            p->data[temp] = p->data[temp - 1];
        }
    }
    p->data[i - 1] = e;
    p->length++;
    return OK;
}

Status ListGet(List p, int i, ElemType *e) {
    // 判断是否还有数据
    if (p.length == 0)
        return ERROR;
    // 取值范围不能超过length, 也不能小于1.
    if (i < 1 || i > p.length)
        return ERROR;
    *e = p.data[i - 1];
    return OK;
}

Status ListDelete(pList p, int i, ElemType *e) {
    if (p->length == 0)
        return ERROR;
    if (i < 1 || i > p->length)
        return ERROR;
    *e = p->data[i - 1];
    if (i < p->length) {
        for (int temp = i; temp < p->length; temp++)
            p->data[i - 1] = p->data[i];
    }
    p->length--;
    return OK;
}

int ListLocateElem(List p, int e) {
    if (p.length == 0)
        return FALSE;
    for (int i = 0; i < p.length; i++) {
        if (e == p.data[i])
            return i;
    }
    return FALSE;
}

Status ListEmpty(List p) {
    if (p.length)
        return TRUE;
    return FALSE;
}

int ListElemNum(List p) {
    return p.length;
}


