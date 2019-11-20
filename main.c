#include <stdio.h>
#include "list/h/list_single_linked.h"

int main(void) {
    LinkNode *p = LinkedListInit();
    LinkNode *temp = p;
//    for (int i = 1; i <= 10; ++i) {
//        LinkedListAdd(p, i);
//    }
    int a;
    LinkedListLength(p, &a);
    printf("the linked list length is %d\n", a);
    int b = LinkedListInsert(p, 1, 100);
    LinkedListInsert(p, 2, 102);
    LinkedListInsert(p, 3, 103);
    LinkedListLength(p, &a);
    printf("insert after length is %d\n", a);
    while (temp->next) {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
    LinkedClear(p);
    LinkedListLength(p, &a);
    printf("insert after length is %d\n", a);
//    LinkedDelete(p, 1, &a);
//    printf("delete node data is : %d", a);
    return 0;
}