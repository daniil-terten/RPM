/**
 * @file matrix.cpp
 * @author Terten Daniil
 * @brief Реализация функций для работы с матрицами
 */

#include "matrix.h"
#include <iostream>

using namespace std;

int **fillMatrix(int **Matrix, int x, int y)
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> Matrix[i][j];
        }
    }
    return Matrix;
}

int **getMatrixInt(int &x, int &y)
{
    cout << "Input matrix sizes: ROWS, COLUMNS" << endl;
    cin >> x >> y;

    int **Matrix = new int *[x];
    for (int i = 0; i < x; ++i) {
        Matrix[i] = new int [y];
    }

    cout << "Fill matrix:" << endl;
    return fillMatrix(Matrix, x, y);
}

void printMatrix(int **Matrix, int x, int y)
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}