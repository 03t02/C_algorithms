#include <stdio.h>
#include <stdlib.h>

#include "ringBuffer.h"

int main() {
    RingBuffer *buffer = NULL;

    buffer = malloc(sizeof(*buffer));
    initRingBuffer(&buffer, 5);

    writeBuffer(&buffer, 10);
    writeBuffer(&buffer, 11);
    writeBuffer(&buffer, 12);
    writeBuffer(&buffer, 13);
    writeBuffer(&buffer, 14);

    printf("%d\n", readBuffer(&buffer));
    printf("%d\n", readBuffer(&buffer));
    printf("%d\n", readBuffer(&buffer));
    printf("%d\n", readBuffer(&buffer));
    printf("%d\n", readBuffer(&buffer));

    writeBuffer(&buffer, 42);
    printf("%d\n", readBuffer(&buffer));
    return 0;
}
