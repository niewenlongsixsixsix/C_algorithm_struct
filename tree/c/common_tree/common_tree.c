//
// Created by Administrator on 2020/3/31.
//

#include "common_tree.h"
#include <stdlib.h>

/**
 * 初始化一个树
 * @return
 */
PtrNode init_common_tree(){
    PtrNode t;
    t = (PtrNode)malloc(sizeof(Node));
    if (t != NULL)
        return t;
    return NULL;
}

/**
 * 往树中插入节点
 * @param n
 * @param data
 * @param NodeInsertType 1 为兄弟节点， 2 为孩子节点
 * @return
 */
Status insert_node(PtrNode n, element_type data, int NodeInsertType){
    if (n == NULL){
        return FAILURE;
    }

    PtrNode temp_node = (PtrNode)malloc(sizeof(Node));

    if (temp_node == NULL){
        return FAILURE;
    }

    temp_node->data = data;
    temp_node->first_child = NULL;
    temp_node->next_brother = NULL;

    if (NodeInsertType){
        n->next_brother = temp_node;
    }else{
        n->first_child = temp_node;
    }

    return SUCCESS;
}
