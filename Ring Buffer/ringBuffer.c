#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ringBuffer.h"

void initRingBuffer(RingBuffer **buffer, int dataSize) {
    (*buffer)->data = malloc(sizeof(int) * dataSize);
    (*buffer)->write = 0;
    (*buffer)->read = 0;
    for (int i = 0; i < dataSize; ++i) {
        (*buffer)->data[i] = 1;
    }
}

void writeBuffer(RingBuffer **buffer, int data) {
    int idxToWrite = (*buffer)->write % (*buffer)->dataSize;

    (*buffer)->data[idxToWrite] = data;
    (*buffer)->write++;
}

int readBuffer(RingBuffer **buffer) {
    int idxToRead = (*buffer)->read % (*buffer)->dataSize;

    (*buffer)->read++;
    return (*buffer)->data[idxToRead];
}
