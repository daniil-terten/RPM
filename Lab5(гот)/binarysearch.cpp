//
// Created by miste on 01.10.2020.
//

#include "binarysearch.h"

int binarySearch(const int *array, int size, int desired) {
    int middle, left = 0, right = size - 1;
    while (true)
    {
        middle = (left + right) / 2;
        if (desired == array[middle]) return middle;

        right = (desired < array[middle]) ? (middle - 1) : (right);
        left = (desired > array[middle]) ? (middle + 1) : (left);
        if (left > right) return -1;
    }
}
