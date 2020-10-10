/**
 * @file productmatrices.h
 * @author Terten Daniil
 * @brief Заголовочный файл для функций сумм для матриц
 */

#ifndef LAB2_PRODUCTMATRICES_H
#define LAB2_PRODUCTMATRICES_H

/**
 * @brief Произведение матриц
 * @param Matrix1 Первая матрица
 * @param x1 Кол-во строк первой матрицы
 * @param y1 Кол-во столбцов первой матрицы
 * @param Matrix2 Вторая матрица
 * @param x2 Кол-во строк второй матрицы
 * @param y2 Кол-во столбцов второй матрицы
 * @return Указатель на произведение матриц
 */
int **getProductOfMatrices(int **Matrix1, int x1, int y1, int **Matrix2, int x2, int y2);

/**
 * @brief Произведение матрицы и числа
 * @param Matrix Матриц
 * @param x Кол-во строк
 * @param y Кол-во столбцов
 * @param number Число
 * @return Указатель на произведение
 */
int **getProductOfMatrixAndNumber(int **Matrix, int x, int y, int number);

#endif //LAB2_PRODUCTMATRICES_H
