/**
 * @author Тертень Даниил
 * @file main.cpp
 * @brief Точка входа в программу
 */

#include <iostream>
#include "array.h"
#include <iomanip>
#include "heapsort.h"

using namespace std;

/**
 * @brief Точка входу в программу, получение вводимых данных
 * @return
 */
int main() {
    int *Array = nullptr, sizeArray = 1000000, *DesiredArray = nullptr, sizeDesired = 40, maxValue = 6000000;
    bool showResult;
    cout << "Show results? 0-no 1-yes" << endl;
    cin >> showResult;
    Array = fillRandomArray(Array, sizeArray, maxValue);
    DesiredArray = fillRandomArray(DesiredArray, sizeDesired, maxValue, 10);
    transpositionSearchManyElements(Array, sizeArray, DesiredArray, sizeDesired, showResult);
    HeapSort sort;
    Array = sort.makeSort(Array, sizeArray);
    binarySearchManyElements(Array, sizeArray, DesiredArray, sizeDesired, showResult);
    return 0;
}
