#include <stdio.h>

#include "insertionSort.h"

void insertionSort(int array[]) {
    for (int i = 0; i < 10000; ++i) {
        int j = i;

        while (j > 0 && array[j - 1] > array[j]) {
            int tmp = array[j];

            array[j] = array[j - 1];
            array[j - 1] = tmp;
            j--;
        }
    }
}
