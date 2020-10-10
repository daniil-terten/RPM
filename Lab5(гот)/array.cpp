/**
 * @file array.cpp
 * @author Тертень Даниил
 * @brief Реализация функций для работы с массивами
 */

#include <iostream>
#include <ctime>
#include "array.h"
#include "transpositionsearch.h"
#include "binarysearch.h"
#include <random>
#include <chrono>
#include <zconf.h>


using namespace std;

int* fillRandomArray(int* A, int size, int maxValue, int randomOffset)
{
    std::mt19937 rng(time(0) + randomOffset);
    std::uniform_int_distribution<int> uni(0, maxValue);

    A = new int[size];
    for(int i = 0; i < size; i++){
        A[i] = uni(rng);
    }
    return A;
}

void printResult(int value, int index, bool showResult)
{
    if (showResult) {
        if (index != -1) {
            cout << "Value " << value << ": index " << index << endl;
        } else {
            cout << "Value " << value << ": not found" << endl;
        }
    }
}

void transpositionSearchManyElements(int *Array, int sizeArray, int *DesiredArray, int sizeDesired, bool showResults) {
    int index;
    cout << endl << endl << "Transposition search: " << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < sizeDesired; ++i) {
        index = transpositionSearch(Array, sizeArray, DesiredArray[i]);
        printResult(DesiredArray[i], index, showResults);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << endl << "Execution time: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns";
}

void binarySearchManyElements(int *Array, int sizeArray, int *DesiredArray, int sizeDesired, bool showResults) {
    int index;
    cout << endl << endl << "Binary search: " << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < sizeDesired; ++i) {
        index = binarySearch(Array, sizeArray, DesiredArray[i]);
        printResult(DesiredArray[i], index, showResults);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << endl << "Execution time: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns";
}
