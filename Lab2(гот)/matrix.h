/**
 * @file matrix.h
 * @author Terten Daniil
 * @brief Заголовочный файл для функций по работе с матрицами
 */

#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H

/**
 * @brief Функция заполнения матрицы
 * @param Matrix Матрица для заполнения
 * @param x Кол-во строк
 * @param y Кол-во столбцов
 * @return Результат
 */
int **fillMatrix(int **Matrix, int x, int y);

/**
 * @brief Cоздание матрицы заданных размеров
 * @param x Кол-во строк
 * @param y Кол-во столбцов
 * @return Указатель на матрицу
 */
int **getMatrixInt(int &x, int &y);

/**
 * @brief Вывод матрицы на экран
 * @param Matrix Матрица для вывода
 * @param x Кол-во строк
 * @param y Кол-во столбцов
 */
void printMatrix(int **Matrix, int x, int y);

#endif //LAB2_MATRIX_H
