//
// Created by Administrator on 2020/3/31.
//

#include "common_tree.h"
#include <stdio.h>


int main(){

    PtrNode p = init_common_tree();

    if (p == NULL){
        return FAILURE;
    }

    char *a_str = "hello";
    char *b_str = "guo";
    char *c_str = "jia";
    insert_node(p, a_str, CHILD_INSERT_TYPE);

    return SUCCESS;
}