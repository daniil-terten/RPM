/**
 * @file transpositionsearch.cpp
 * @author Тертень Даниил
 * @brief Реализация функции поиска перебором с транспозицией
 */

#include "transpositionsearch.h"

/**
 * Смена двух элементов массива
 * @param first
 * @param second
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int transpositionSearch(int *array, int size, int desired)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] == desired) {
            if (i != 0) {
                swap(&array[i], &array[i - 1]);
            }
            return i;
        }
    }
    return -1;
}
