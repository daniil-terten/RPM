/**
 * @file main.cpp
 * @author Тертень Даниил
 * @brief Инициализация рандомного массива, запуск сортировки, замер времени
 */

#include <iostream>
#include "sort.h"

using namespace std;

/**
 * @brief Инициализация массива, запуск сортировки, замер времени
 * @return 0
 */
int main()
{
    int size;
    bool visualize, fromFile;

    cout << "Input size of array:" << endl;
    cin >> size;
    cout << "Do you need visualization? 1-yes 0-no" << endl;
    cin >> visualize;
    cout << "How to create array? 0-random 1-from 'INPUT.txt'" << endl;
    cin >> fromFile;

    sortArrays(size, visualize, fromFile);

    return 0;
}
