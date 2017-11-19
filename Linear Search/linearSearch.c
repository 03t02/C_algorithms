#include "linearSearch.h"

int linearSearch(int *array, int toSearch) {
    for (int i = 0; i < 100000000; ++i) {
        if (array[i] == toSearch) {
            return i;
        }
    }
    return -1;
}
