#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void insertTail(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        while ((*list)->next != NULL) {
            *list = (*list)->next;
        }
        (*list)->next = new_node;
    }
}

void insertHead(struct ll **list, int number) {
    struct ll *new_node = NULL;

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

void deleteHead(struct ll **list) {
    struct ll *head = (*list)->next;

    (*list)->next = NULL;
    *list = head;
}

void deleteTail(struct ll **list) {
    struct ll *it = *list;

    while (it->next != NULL && it->next->next != NULL) {
        it = it->next;
    }
    it->next = NULL;
}

struct ll *searchNode(struct ll *list, int number) {
    if (list == NULL) {
        return NULL;
    }
    if (list->number == number) {
        return list;
    }
    return searchNode(list->next, number);
}

void printList(struct ll *list) {
    if (list == NULL) {
        printf("The list is empty\n");
        exit(1);
    }
    while (list != NULL) {
        printf("%d\n", list->number);
        list = list->next;
    }
}

