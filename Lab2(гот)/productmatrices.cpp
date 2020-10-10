/**
 * @file productmatrices.cpp
 * @author Terten Daniil
 * @brief Реализация функций для произведений матриц
 */

#include "productmatrices.h"
#include <iostream>

using namespace std;

int **getProductOfMatrices(int **Matrix1, int x1, int y1, int **Matrix2, int x2, int y2)
{
    if (y1 != x2) {
        throw runtime_error("Matrices have different Y1 and X2");
    }
    int **Product = new int *[x1];
    for (int i = 0; i < x1; i++) {
        Product[i] = new int [y2];
        for (int j = 0; j < y2; j++) {
            Product[i][j] = 0;
            for (int k = 0; k < y1; k++) {
                Product[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }
    return Product;
}

int **getProductOfMatrixAndNumber(int **Matrix, int x, int y, int number)
{
    int **Product = new int *[x];
    for (int i = 0; i < x; ++i) {
        Product[i] = new int [y];
        for (int j = 0; j < y; ++j) {
            Product[i][j] = Matrix[i][j] * number;
        }
    }

    return Product;
}