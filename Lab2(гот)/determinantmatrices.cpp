/**
 * @file determinantmatrices.cpp
 * @author Terten Daniil
 * @brief Реализация функции детерминанта матрицы
 */

#include "determinantmatrices.h"
#include <iostream>

using namespace std;

int getDeterminantOfMatrix(int **Matrix, int x, int y)
{
    if (x != y) {
        throw runtime_error("Matrix has different X and Y");
    }
    if (x == 1 && y == 1) {
        return Matrix[0][0];
    }

    int sum = 0;
    for (int i = 0; i < y; ++i) {
        int **MinorMatrix = new int *[x - 1];
        for (int j = 0; j < x - 1; ++j) {
            MinorMatrix[j] = new int [y - 1];
            for (int k = 0; k < y - 1; ++k) {
                int curX, curY;
                curX = j + 1;
                curY = (k < i) ? (k) : (k + 1);
                MinorMatrix[j][k] = Matrix[curX][curY];
            }
        }
        int minus = (i % 2) ? -1 : 1;
        sum += minus * Matrix[0][i] * getDeterminantOfMatrix(MinorMatrix, x - 1, y - 1);
    }

    return sum;
}