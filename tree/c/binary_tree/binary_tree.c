//
// Created by Administrator on 2020/3/30.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef struct BTreeNode Node;
typedef struct BTreeNode *PtrNode;

struct BTreeNode{
    int value;
    PtrNode left;
    PtrNode right;
};



PtrNode insert_node(PtrNode tree, int value){
    if (NULL == tree){
        tree = (PtrNode)malloc(sizeof(Node));
        if (NULL == tree){
            return NULL;
        }else{
            printf("insert a value:%d\n", value);
            tree->value = value;
            tree->left = NULL;
            tree->right = NULL;
        }
    }else if(value <= tree->value){
        tree->left = insert_node(tree->left, value);
    }else if(value > tree->value){
        tree->right = insert_node(tree->right, value);
    }

    return tree;
}

// 前序遍历
void pre_order(PtrNode tree){
    if (NULL == tree)
        return;
    printf("%d ", tree->value);
    pre_order(tree->left);
    pre_order(tree->right);
}

// 中序遍历
void mid_order(PtrNode tree){
    if (NULL == tree)
        return;
    pre_order(tree->left);
    printf("%d ", tree->value);
    pre_order(tree->right);
}

// 后序遍历
void last_order(PtrNode tree){
    if (NULL == tree)
        return;
    pre_order(tree->left);
    pre_order(tree->right);
    printf("%d ", tree->value);
}

//目前存在问题
int main(){
    int a[] = {10,5,19,4,8,13,24};
    PtrNode tree = NULL;
    for (int i = 0; i < 7; i++){
        tree = insert_node(tree, a[i]);
    }

    pre_order(tree);
    printf("\n");
    mid_order(tree);
    printf("\n");
    last_order(tree);

    return 0;
}
