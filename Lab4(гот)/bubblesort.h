/**
 * @file bubblesort.h
 * @author Тертень Даниил
 * @brief Сортировка пузырьком
 */

#ifndef LAB4_BUBBLESORT_H
#define LAB4_BUBBLESORT_H

/**
 * @brief Сортировка пузырьком
 */
class BubbleSort {

private:

    /** Массив для сортировки */
    int *A;
    /** Размер массива */
    int size;
    /** Требуется ли визуализация работы массива */
    bool visualize;

    /**
     * Функция для смены элементов массива местами
     * @param f Первый элемент
     * @param s Второй элемент
     */
    void swap(int *f, int *s)
    {
        int temp = *f;
        *f = *s;
        *s = temp;
    }

public:

    /**
     * @param visualize Визуализировать ли сортировку
     */
    BubbleSort(bool visualize = false) : visualize(visualize) {}

    /**
     * Произвести сортировку
     * @param Array Массив для сортировки
     * @param arraySize Размер массива
     * @return указатель на отсортированный массив
     */
    int* makeSort(int *a, int arraySize)
    {
        A = a;
        size = arraySize;

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    if (visualize) {
                        visualizeSort(j, j + 1);
                    }
                    swap(&A[j], &A[j + 1]);
                }
            }
        }

        return A;
    }

private:

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


#endif //LAB4_BUBBLESORT_H
