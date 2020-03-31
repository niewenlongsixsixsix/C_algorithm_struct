//
// Created by Administrator on 2020/3/31.
//

#ifndef ALGORITHM_STRUCT_COMMON_TREE_H
#define ALGORITHM_STRUCT_COMMON_TREE_H

#endif //ALGORITHM_STRUCT_COMMON_TREE_H

#define SUCCESS 1
#define FAILURE 0

#define BROTHER_INSERT_TYPE 1
#define CHILD_INSERT_TYPE 0

typedef int Status;

typedef  char *element_type;

typedef struct CTreeNode{
    element_type data;
    struct node *first_child; //指向第一个儿子节点
    struct node *next_brother; //指向自己的下一个兄弟节点
}Node, *PtrNode;


// 初始化树
PtrNode init_common_tree();

// 插入一个树节点
Status insert_node(PtrNode n, element_type data, int NodeInsertType)