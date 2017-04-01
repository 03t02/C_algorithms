#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct stack **list, int number) {
    struct stack *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        struct stack *it = *list;

        while (it->next != NULL) {
            it = it->next;
        }
        it->next = new_node;
    }
}

struct stack *pop(struct stack **list) {
    struct stack *it = *list;
    struct stack *node = NULL;

    while (it->next != NULL && it->next->next != NULL) {
        it = it->next;
    }
    node = it->next;
    it->next = NULL;
    return node;
}

void printStack(struct stack *list) {
    if (list == NULL) {
        printf("The stack is empty\n");
        exit(0);
    }
    while (list != NULL) {
        printf("%d\n", list->number);
        list = list->next;
    }
}

