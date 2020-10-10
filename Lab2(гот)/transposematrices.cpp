/**
 * @file transposematrices.cpp
 * @author Terten Daniil
 * @brief Реализация функции транспонирования матрицы
 */

#include "transposematrices.h"

int **getTransposedMatrix(int **Matrix, int x, int y)
{
    int **Transposed = new int *[y];
    for (int i = 0; i < y; ++i) {
        Transposed[i] = new int [x];
        for (int j = 0; j < x; ++j) {
            Transposed[i][j] = Matrix[j][i];
        }
    }

    return Transposed;
}
