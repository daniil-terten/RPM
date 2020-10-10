/**
 * @file array.h
 * @author Тертень Даниил
 * @brief Функции для работы с массивами
 */

#ifndef LAB4_ARRAY_H
#define LAB4_ARRAY_H

/**
 * Заполнить рандомно массив
 * @param A Массив
 * @param size Размер массива
 * @return Указатель на заполненный массив
 */
int* fillRandomArray(int* A, int size);

/**
 * Скопировать массив
 * @param A Массив
 * @param size Размер массива
 * @return Указатель на копию
 */
int* copyArray(const int* A, int size);

/**
 * Вывести массив в файл
 * @param A Массив
 * @param size Размер массива
 * @param file Файл для сохранения
 */
void arrayToFile(int* A, int size, ofstream &file);

/**
 * Ввести массив из файла
 * @param A Массив
 * @param size Размер массива
 * @param file Файл
 */
int* arrayFromFile(int* A, int size, ifstream &file);

#endif //LAB4_ARRAY_H
