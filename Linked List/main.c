#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main() {
    struct ll *list = NULL;
    struct ll *found_node = NULL;

    insertTail(&list, 5);
    insertTail(&list, 8);
    insertHead(&list, 4);
    insertHead(&list, 3);
    insertTail(&list, 29);
    insertTail(&list, 54);

    deleteHead(&list);
    deleteTail(&list);

    found_node = searchNode(list, 4);
    if (found_node != 0x0) {
        printf("Found: %d\n", found_node->number);
    }
    printList(list);
    return 0;
}
