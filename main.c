//
// Created by Administrator on 2019/11/12.
//
#include <stdio.h>
#include "list/h/list_array.h"

int main() {
    List list;
    InitList(&list);
    ListInsert(&list, 1, 110);
    ListInsert(&list, 2, 120);
    int b = ListLocateElem(list, 120);
    printf("%d\n", b);
    return 0;
}
