#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(t_stack **list, int number) {
    t_stack *new_node = NULL;

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

t_stack *pop(t_stack **list) {
    if (list == NULL) {
        return NULL;
    }
    t_stack *node = *list;
    t_stack *head = (*list)->next;
    (*list)->next = NULL;
    *list = head;
    return node;
}

void printStack(t_stack *list) {
    if (list == NULL) {
        printf("The stack is empty\n");
        exit(0);
    }
    while (list != NULL) {
        printf("%d\n", list->number);
        list = list->next;
    }
}

t_stack *search(t_stack *list, int number) {
    if (list == NULL) {
        return NULL;
    }

    if (list->number == number) {
        return list;
    }
    return search(list->next, number);
}
