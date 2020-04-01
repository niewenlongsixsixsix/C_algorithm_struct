//
// 二叉树的实现及其遍历
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

struct BTreeNode {
    int value;
    PtrNode left;
    PtrNode right;
};

// 这里需要返回值，因为传入的tree中存放这我们期望修改的地址，即使我们用->符号对那个地址改变了，使用malloc生成了一个Node地址，
// 然后赋值给tree，但是这个形参仅仅是传入值的拷贝，因此实参保存的地址并没有给改变。如果不用返回值的话，需要指针的指针。

/**
 * 这里其实是创建了一颗二叉搜索树，如果插入的值已经存在，则什么都不做
 * @param tree
 * @param value
 * @return
 */
PtrNode insert_node(PtrNode tree, int value) {
    if (NULL == tree) {
        tree = (PtrNode) malloc(sizeof(Node));
        if (NULL == tree) {
            return NULL;
        } else {
            printf("insert a value:%d\n", value);
            tree->value = value;
            tree->left = NULL;
            tree->right = NULL;
        }
    } else if (value < tree->value) {
        tree->left = insert_node(tree->left, value);
    } else if (value > tree->value) {
        tree->right = insert_node(tree->right, value);
    }

    return tree;
}

//递归遍历

/**
 * 前序遍历
 * @param tree
 */
void pre_order(PtrNode tree) {
    if (NULL == tree)
        return;
    printf("%d ", tree->value);
    pre_order(tree->left);
    pre_order(tree->right);
}

/**
 * 中序遍历
 * @param tree
 */
void mid_order(PtrNode tree) {
    if (NULL == tree)
        return;
    mid_order(tree->left);
    printf("%d ", tree->value);
    mid_order(tree->right);
}

/**
 * 后序遍历
 * @param tree
 */
void last_order(PtrNode tree) {
    if (NULL == tree)
        return;
    last_order(tree->left);
    last_order(tree->right);
    printf("%d ", tree->value);
}

/**
 * 二叉搜索树搜索某个值，如果存在的话，返回这个节点，不存在的话返回NULL
 * @param tree
 * @param specify_value
 * @return
 */
PtrNode find_value(PtrNode tree, int specify_value) {
    if (NULL == tree) {
        return NULL;
    }

    if (specify_value == tree->value) {
        return tree;
    }

    PtrNode left_result = find_value(tree->left, specify_value);
    if (NULL != left_result){
        return left_result;
    }

    PtrNode right_result = find_value(tree->right, specify_value);
    if (NULL != right_result){
        return right_result;
    }

    return NULL;
}

/**
 * 使用递归方式查找最大值的节点
 * @param tree
 * @return
 */
PtrNode find_max_value(PtrNode tree){
    if (NULL == tree){
        return NULL;
    }
    if (NULL == tree->right){
        return tree;
    }else{
        return find_max_value(tree->right);
    }
}

/**
 * 使用非递归方式实现查找最小值
 * @param tree
 * @return
 */
PtrNode find_min_value(PtrNode tree){
    if (NULL == tree){
        return NULL;
    }
    // 对于寻找值，而且判断条件为他的下个节点是否为空，这中情况只能使用tree->left作为条件，否则可能返回出NULL。因为tree作为
    // 条件时，如果跳出while，此时tree已经是NULL，如果返回的话就是NULL。
    while (NULL != tree->left){
        tree = tree->left;
    }
    return tree;
}

int main() {
    int a[] = {10, 5, 19, 4, 8, 13, 24};
    // 指针变量就是存放了某一个数据的地址，因此将这个变量传入函数中，会进行值拷贝，
    // 并不会对当前值造成影响，因此需要返回值，用来改变当前值。
    PtrNode tree = NULL;

    for (int i = 0; i < 7; i++) {
        tree = insert_node(tree, a[i]);
    }

//    printf("\n");
//    printf("前序遍历: ");
//    pre_order(tree);
//    printf("\n");
//    printf("中序遍历: ");
//    mid_order(tree);
//    printf("\n");
//    printf("后序遍历: ");
//    last_order(tree);
//    printf("\n");


    PtrNode find_result = NULL;

//    find_result = find_value(tree, 24);
// test find_value

// test find_max_value
//    find_result = find_max_value(tree);
    find_result = find_min_value(tree);
    if (!find_result){
        printf("the return value is null\n");
    }else{
        printf("%d\n", find_result->value);
    }
    return 0;
}
