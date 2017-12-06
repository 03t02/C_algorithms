#include <stdio.h>
#include "binarySearch.h"

int binarySearch(int *arr, int lIdx, int rIdx, int toFind) {
    int midIdx = ((rIdx - lIdx) / 2) + lIdx;

    if ((rIdx - 1) > lIdx) {
        if (arr[midIdx] == toFind) {
            return midIdx;
        } else if (arr[midIdx] > toFind) {
            return binarySearch(arr, lIdx, midIdx - 1, toFind);
        }
        return binarySearch(arr, midIdx + 1, rIdx, toFind);
    } else {
        if (arr[lIdx] == toFind) {
            return lIdx;
        } else if (arr[rIdx] == toFind) {
            return rIdx;
        }
        return -1;
    }

    return -1;
}
