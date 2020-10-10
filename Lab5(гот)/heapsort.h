/**
 * @file heapsort.h
 * @author Тертень Даниил
 * @brief Сортировка кучей
 */

#ifndef LAB5_HEAPSORT_H
#define LAB5_HEAPSORT_H

#include <iostream>

using namespace std;

/**
 * @brief Сортировка кучей
 */
class HeapSort
{

private:

    /**
     * Массив для сортировки
     */
    int *A;
    /**
     * Размер массива
     */
    int size;
    /**
     * Кол-во неотсортированных элементов
     */
    int notSortingSize;
    /**
     * Визуализировать ли сортировку
     */
    bool visualize;

public:

    /**
     * @param visualize Визуализировать ли сортировку
     */
    HeapSort(bool visualize = false) : visualize(visualize) {}

    /**
     * Произвести сортировку
     * @param Array Массив для сортировки
     * @param sizeArray Размер массива
     * @return указатель на отсортированный массив
     */
    int* makeSort(int *Array, int sizeArray)
    {
        A = Array;
        size = sizeArray;
        notSortingSize = sizeArray;

        sortArray();

        return getSortedArray();
    }

private:

    /**
     * Индекс левого элемента
     * @param parent Индекс родительского элемента в дереве
     * @return индекс
     */
    int leftEl(int parent)
    {
        return parent * 2 + 1;
    }

    /**
     * Индекс правого элемента
     * @param parent Индекс родительского элемента в дереве
     * @return индекс
     */
    int rightEl(int parent)
    {
        return parent * 2 + 2;
    }

    /**
     * Определение индекса верхушки
     * @return
     */
    int parentEl()
    {
        return ((notSortingSize - 1) / 2) + (notSortingSize - 1) % 2 - 1;
    }

    /**
     * Сортировка массива
     */
    void sortArray()
    {
        int parent = parentEl();

        while(parent >= 0){
            sortElements(parent);
            parent--;
        }
    }

    /**
     * Сортировка одного разветвления дерева
     * @param parent Индекс родительского элемента разветвления
     */
    void sortElements(int parent)
    {
        int startParent = parent;
        int left = leftEl(parent);
        int right = rightEl(parent);

        if(left < notSortingSize && A[parent] < A[left]){
            parent = left;
        }
        if(right < notSortingSize && A[parent] < A[right]){
            parent = right;
        }

        if(parent != startParent){
            if (visualize) {
                visualizeSort(startParent, parent);
            }
            swap(A[startParent], A[parent]);
            sortElements(parent);
        }
    }

    /**
     * Получение отсортированного массива
     * @return указатель на массив
     */
    int* getSortedArray()
    {
        int parent;

        for(int i = size - 1; i >= 0; i--){
            if (visualize) {
                visualizeSort(0, i);
            }
            swap(A[0], A[i]);
            notSortingSize--;
            sortArray();
        }

        return A;
    }

    /**
     * Визуализация сортировки
     * @param first Первый элемент для свапа
     * @param second Второй элемент для свапа
     */
    void visualizeSort(int first, int second)
    {
        for (int i = 0; i < size; ++i) {
            if (i == first || i == second) {
                cout << "\\" << left << setw(2) << A[i] << "/ ";
            } else {
                cout << " " << left << setw(2) << A[i] << "  ";
            }

        }
        cout << endl;
    }

};


#endif //LAB5_HEAPSORT_H
