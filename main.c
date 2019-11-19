#include <stdio.h>
#include "list/h/list_single_linked.h"

int main(void){
    LinkNode *p = LinkedListInit();
//    for (int i = 1; i <= 10; ++i) {
//        LinkedListAdd(p, i);
//    }
    int a;
    LinkedListLength(p, &a);
    printf("the linked list length is %d\n", a);
    int b = LinkedListInsert(p, 1, 100);
    LinkedListLength(p, &a);
    printf("insert after length is %d %d\n", a, b);
    while (p->next){
        printf("%d ", p->next->data);
        p = p->next;
    }
    return 0;
}