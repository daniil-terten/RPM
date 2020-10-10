/**
 * Двусторонняя очередь
 * @file Deque.h
 * @author Тертень Даниил
 */

#ifndef LAB7_DEQUE_H
#define LAB7_DEQUE_H

#include "List.h"

/**
 * Двусторонняя очередь
 * @tparam T
 */
template<typename T>
class Deque {
private:
    /** Двусвязный список */
    List<T> *list;
public:
    Deque():list(new List<T>){};
    ~Deque() {
        delete list;
    }
    /** Вставка в конец */
    void push_front(T value) {
        list->addAfter(list->tail, value);
    }
    /** Вставка в начало */
    void push_back(T value) {
        list->addBefore(list->head, value);
    }
    /** Вырезание из конца */
    T pop_front() {
        if (!list->tail) {
            throw runtime_error("Deque is empty!");
        }
        T value = front();
        list->deleteElement(list->tail);
        return value;
    }
    /** Вырезание из начала */
    T pop_back() {
        if (!list->head) {
            throw runtime_error("Deque is empty!");
        }
        T value = back();
        list->deleteElement(list->head);
        return value;
    }
    /** Получение конца */
    T front() {
        if (!list->tail) {
            throw runtime_error("Deque is empty!");
        }
        return list->tail->field;
    }
    /** Получение начала */
    T back() {
        if (!list->head) {
            throw runtime_error("Deque is empty!");
        }
        return list->head->field;
    }
    void clear() {
        delete list;
        list = new List<T>;
    }
};

#endif //LAB7_DEQUE_H
