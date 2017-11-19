#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linearSearch.h"

int main() {
    int *arr = malloc(sizeof(int) * 100000000);
    for (int i = 0; i < 100000000; ++i) {
        arr[i] = i;
    }

    clock_t begin = clock();
    int result = linearSearch(arr, 348437);
    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Found at index: %d\n", result);
    printf("It tooks: %f\n", timeSpent);
    return 0;
}
