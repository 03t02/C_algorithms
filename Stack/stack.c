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
        new_node->next = *list;
        *list = new_node;
    }
}

struct stack *pop(struct stack **list) {
    if (list == NULL) {
        return NULL;
    }
    struct stack *node = *list;
    struct stack *head = (*list)->next;
    (*list)->next = NULL;
    *list = head;
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

