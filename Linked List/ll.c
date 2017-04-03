#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void insertTail(t_ll **list, int number) {
    t_ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        t_ll *it = *list;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next= new_node;
    }
}

void insertHead(t_ll **list, int number) {
    t_ll *new_node = NULL;

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

void deleteHead(t_ll **list) {
    t_ll *head = (*list)->next;

    (*list)->next = NULL;
    *list = head;
}

void deleteTail(t_ll **list) {
    t_ll *it = *list;

    while (it->next != NULL && it->next->next != NULL) {
        it = it->next;
    }
    it->next = NULL;
}

t_ll *searchNode(t_ll *list, int number) {
    if (list == NULL) {
        return NULL;
    }
    if (list->number == number) {
        return list;
    }
    return searchNode(list->next, number);
}

void printList(t_ll *list) {
    if (list == NULL) {
        printf("The list is empty\n");
        exit(1);
    }
    while (list != NULL) {
        printf("%d\n", list->number);
        list = list->next;
    }
}

