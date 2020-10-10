/**
 * @file summatrices.cpp
 * @author Terten Daniil
 * @brief Реализация функций суммы матриц
 */

#include "summatrices.h"
#include <iostream>

using namespace std;

int **getSumOfMatrices(int **Matrix1, int x1, int y1, int **Matrix2, int x2, int y2)
{
    if (x1 != x2 || y1 != y2) {
        throw runtime_error("Matrices have different sizes");
    }
    int **Sum = new int *[x1];
    for (int i = 0; i < x1; ++i) {
        Sum[i] = new int [y1];
        for (int j = 0; j < y1; ++j) {
            Sum[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    return Sum;
}

int **getSumOfMatrixAndNumber(int **Matrix, int x, int y, int number)
{
    int **Sum = new int *[x];
    for (int i = 0; i < x; ++i) {
        Sum[i] = new int [y];
        for (int j = 0; j < y; ++j) {
            Sum[i][j] = Matrix[i][j] + number;
        }
    }

    return Sum;
}