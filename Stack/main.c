#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    struct stack *list = NULL;

    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);

    struct stack *node = pop(&list);
    printStack(list);
    if (node != NULL) {
        printf("Pop element: %d\n", node->number);
    }
    return 0;
}
