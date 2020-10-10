/**
 * @file normalizedmatrices.cpp
 * @author Terten Daniil
 * @brief Реализация функции для нормализации
 */


#include "normalizedmatrices.h"
#include <iostream>

int **getNormalizedMatrix(int **Matrix, int x, int y)
{
    if (x != y) {
        throw std::runtime_error("Matrix has different X and Y");
    }
    int **Normalized = new int *[x];
    for (int i = 0; i < x; ++i) {
        Normalized[i] = new int [y];
        for (int j = 0; j < y; ++j) {
            Normalized[i][j] = Matrix[i][j] / Matrix[i][i];
        }
    }
    return Normalized;
}