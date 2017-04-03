#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    t_stack *list = NULL;

    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);

    t_stack *node = pop(&list);
    printStack(list);
    if (node != NULL) {
        printf("Pop element: %d\n", node->number);
    }

    t_stack *found = search(list, 3);
    printf("Found: %d\n", found->number);
    return 0;
}
