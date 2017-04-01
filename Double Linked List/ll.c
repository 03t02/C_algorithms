#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void insertTail(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        struct ll *it = *list;
        while (it->next != NULL) {
            it = it->next;
        }
        new_node->prev = malloc(sizeof(*(new_node->prev)));
        new_node->prev = it;
        it->next= new_node;
    }
}

void insertHead(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        (*list)->prev = new_node;
        new_node->next = *list;
        *list = new_node;
    }
}

void deleteHead(struct ll **list) {
    struct ll *head = (*list)->next;

    (*list)->next = NULL;
    head->prev = NULL;
    *list = head;
}

void deleteTail(struct ll **list) {
    struct ll *it = *list;

    while (it->next != NULL) {
        it = it->next;
    }
    it->prev->next = NULL;
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

