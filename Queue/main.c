#include <stdio.h>
#include "Queue.h"

int main() {
    t_queue *queue = NULL;

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("%d\n", search(queue, 2)->number);
    return 0;
}
