/**
 * @file array.h
 * @author Тертень Даниил
 * @brief Функции для работы с массивами
 */

#ifndef LAB5_ARRAY_H
#define LAB5_ARRAY_H

/**
 * Заполнить рандомно массив
 * @param A Массив
 * @param size Размер массива
 * @return Указатель на заполненный массив
 */
int* fillRandomArray(int* A, int size, int maxValue, int randomOffset = 0);

/**
 * Вывести результат на экран
 * @param value Значение
 * @param index Индекс значения
 * @param showResult Показывать ли результат или нет
 */
void printResult(int value, int index, bool showResult);

/**
 * Поиск массива элементов в массиве с помощью transpositionSearch, вывод информации на экран
 * @param Array Массив, в котором искать
 * @param sizeArray
 * @param DesiredArray Массив, элементы которого надо искать
 * @param sizeDesired
 * @param showResults
 */
void transpositionSearchManyElements(int* Array, int sizeArray, int* DesiredArray, int sizeDesired, bool showResults);

/**
 * Поиск массива элементов в массиве с помощью transpositionSearch, вывод информации на экран
 * @param Array Массив, в котором искать
 * @param sizeArray
 * @param DesiredArray Массив, элементы которого надо искать
 * @param sizeDesired
 * @param showResults
 */
void binarySearchManyElements(int* Array, int sizeArray, int* DesiredArray, int sizeDesired, bool showResults);

#endif //LAB5_ARRAY_H
