//
// Created by Administrator on 2020/3/31.
//

#include "common_tree.h"
#include <stdlib.h>
#include <stdio.h>

PtrNode init_common_tree(){
    PtrNode t;
    t = (PtrNode)malloc(sizeof(Node));
    if (t != NULL)
        return t;
    return NULL;
}

