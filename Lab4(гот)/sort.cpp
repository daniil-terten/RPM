/**
 * @file sort.cpp
 * @brief Реализация функций запуска сортировок
 * @author Тертень Даниил
 */

#include <iomanip>
#include "heapsort.h"
#include "bubblesort.h"
#include "array.h"
#include <ctime>
#include <fstream>

void bubbleSortTest(int* A, int size, bool visualize)
{
    time_t start, end;
    ofstream sortedFile;

    BubbleSort bubbleSort(visualize);
    time(&start);
    cout << endl << "BubbleSort:" << endl << endl;
    int *sortedArrayA = bubbleSort.makeSort(A, size);
    time(&end);
    cout << endl << "Execution time BubbleSort: " << difftime(end, start) << " seconds";
    sortedFile.open("../BUBBLE_SORTED.txt");
    arrayToFile(sortedArrayA, size, sortedFile);
}

void heapSortTest(int* B, int size, bool visualize)
{
    time_t start, end;
    ofstream sortedFile;

    HeapSort heapSort(visualize);
    time(&start);
    cout << endl << "HeapSort:" << endl << endl;
    int *sortedArrayB = heapSort.makeSort(B, size);
    time(&end);
    cout << endl << "Execution time HeapSort: " << difftime(end, start) << " seconds";
    sortedFile.open("../HEAP_SORTED.txt");
    arrayToFile(sortedArrayB, size, sortedFile);
}


void sortArrays(int size, bool visualize, bool fromFile)
{
    int *A = nullptr, *B = nullptr;
    ifstream input;
    ofstream unsorted;

    if (! fromFile) {
        A = fillRandomArray(A, size);
        B = copyArray(A, size);
    } else {
        input.open("../INPUT.txt");
        A = arrayFromFile(A, size, input);
        B = copyArray(A, size);
    }
    unsorted.open("../UNSORTED.txt");
    arrayToFile(A, size, unsorted);

    bubbleSortTest(A, size, visualize);
    heapSortTest(B, size, visualize);
}
