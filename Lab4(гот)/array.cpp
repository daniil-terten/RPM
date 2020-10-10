/**
 * @file array.cpp
 * @author Тертень Даниил
 * @brief Реализация функций для работы с массивами
 */

#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int* fillRandomArray(int* A, int size)
{
    srand(time(0));

    A = new int[size];
    for(int i = 0; i < size; i++){
        A[i] = rand() % (size * 2);
    }
    return A;
}

int* copyArray(const int* A, int size)
{
    int *B = new int [size];
    for (int i = 0; i < size; ++i) {
        B[i] = A[i];
    }
    return B;
}

void arrayToFile(int *A, int size, ofstream &file) {
    for(int i = 0; i < size; i++){
        file << A[i] << " ";
    }
    file << endl << endl;
}

int* arrayFromFile(int *A, int size, ifstream &file) {
    A = new int[size];
    for(int i = 0; i < size; i++){
        file >> A[i];
    }
    return A;
}
