/**
 * @file sort.h
 * @author Тертень Даниил
 * @brief определение функций для запуска сортировок
 */

#ifndef LAB4_SORT_H
#define LAB4_SORT_H

/**
 * @brief Сортировка пузырьком и вывод информации
 * @param A Массив для сортировки
 * @param size Размер массива
 * @param visualize Требуется ли визуализайия
 */
void bubbleSortTest(int* A, int size, bool visualize);

/**
 * @brief Сортировка кучей и вывод информации
 * @param A Массив для сортировки
 * @param size Размер массива
 * @param visualize Требуется ли визуализайия
 */
void heapSortTest(int* B, int size, bool visualize);

/**
 * @brief Запуск сортировок и ввод/вывод массивов
 * @param size
 * @param visualize
 * @param fromFile
 */
void sortArrays(int size, bool visualize, bool fromFile);

#endif //LAB4_SORT_H
