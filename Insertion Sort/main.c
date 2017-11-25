#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertionSort.h"

int main() {
    int array[10000] = { 0 };

    srand(time(NULL));
    for (int i = 0; i < 10000; ++i) {
        array[i] = rand();
    }

    clock_t begin = clock();
    insertionSort(array);
    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Took to sort: %f\n", timeSpent);
    return 0;
}
