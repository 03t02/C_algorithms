#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void enqueue(t_queue **list, int number) {
    t_queue *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        (*list)->prev = new_node;
        new_node->next= *list;
        *list = new_node;
    }
}

void printQueue(t_queue *list) {
    while (list != NULL) {
        printf("%d\n", list->number);
        list = list->next;
    }
}

void dequeue(t_queue **list) {
    t_queue *tmp = *list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (tmp->prev != NULL) {
        tmp->prev->next = NULL;
    }
}

t_queue *search(t_queue *list, int number) {
    while (list != NULL) {
        if (list->number == number) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
