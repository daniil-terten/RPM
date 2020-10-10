/**
 * @file main.cpp
 * @brief Лабораторная работа 2
 * @author Terten Daniil
 */

#include <iostream>
#include "matrix.h"
#include "summatrices.h"
#include "productmatrices.h"
#include "transposematrices.h"
#include "determinantmatrices.h"
#include "normalizedmatrices.h"

using namespace std;

/**
 * @brief Точка входа в программу, получение и вывод всех данных о матрицах
 * @return 0
 */
int main() {
    int x1, y1, x2, y2;

    int **Matrix1 = getMatrixInt(x1, y1);
    int **Matrix2 = getMatrixInt(x2, y2);

    try {
        cout << endl << "Sum:" << endl;
        int **Sum = getSumOfMatrices(Matrix1, x1, y1, Matrix2, x2, y2);
        printMatrix(Sum, x1, y1);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    try {
        cout << endl << "Product:" << endl;
        int **Product = getProductOfMatrices(Matrix1, x1, y1, Matrix2, x2, y2);
        printMatrix(Product, x1, y2);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << endl << "Transposed 1:" << endl;
    printMatrix(getTransposedMatrix(Matrix1, x1, y1), y1, x1);
    cout << endl << "Transposed 2:" << endl;
    printMatrix(getTransposedMatrix(Matrix2, x2, y2), y2, x2);

    int number;
    cout << endl << "Input number:" << endl;
    cin >> number;
    cout << endl << "Sum of matrix1 and number:" << endl;
    printMatrix(getSumOfMatrixAndNumber(Matrix1, x1, y1, number), x1, y1);
    cout << endl << "Product of matrix2 and number:" << endl;
    printMatrix(getProductOfMatrixAndNumber(Matrix2, x2, y2, number), x2, y2);

    try {
        cout << endl << "Determinant of 1st matrix:" << endl;
        int determinant = getDeterminantOfMatrix(Matrix1, x1, y1);
        cout << determinant << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << endl << "Normalized matrix2:" << endl;
        int **Normalized = getNormalizedMatrix(Matrix2, x2, y2);
        printMatrix(Normalized, x2, y2);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
