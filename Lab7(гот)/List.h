/**
 * Двунаправленный список
 * @file List.h
 * @author Тертень Даниил
 */

#ifndef LAB7_LIST_H
#define LAB7_LIST_H

#include <stdexcept>
#include <string>

using namespace std;


/**
 * Элемент списка
 * @tparam T
 */
template<typename T>
struct ListNode
{
    T field;
    ListNode *next;
    ListNode *prev;
};

/**
 * Двунаправленный список
 */
template<typename T>
class List {
public:
    /** Начало списка */
    ListNode<T> *head;
    /** Конец списка */
    ListNode<T> *tail;
    List():head(nullptr),tail(nullptr){};
    /** Удаление списка */
    ~List() {
        while (head)
        {
            tail = head->next;
            delete head;
            head = tail;
        }
    }
    /** Добавления элемента в список после указанного элемента */
    ListNode<T> *addAfter(ListNode<T> *node, T value) {
        ListNode<T> *newElement = new ListNode<T>;
        newElement->field = value;
        if (node) {
            newElement->next = node->next;
            if (!newElement->next) {
                tail = newElement;
            } else {
                newElement->next->prev = newElement;
            }
            newElement->prev = node;
            node->next = newElement;
        } else {
            newElement->next = nullptr;
            newElement->prev = nullptr;
            tail = newElement;
            head = newElement;
        }
        return newElement;
    }
    /** Добавления элемента в список до указанного элемента */
    ListNode<T> *addBefore(ListNode<T> *node, T value) {
        ListNode<T> *newElement = new ListNode<T>;
        newElement->field = value;
        if (node) {
            newElement->next = node;
            if (!node->prev) {
                head = newElement;
                newElement->prev = nullptr;
            } else {
                newElement->prev = node->prev;
                node->prev->next = newElement;
            }
            node->prev = newElement;
        } else {
            newElement->next = nullptr;
            newElement->prev = nullptr;
            tail = newElement;
            head = newElement;
        }
        return newElement;
    }
    /** Удаление элемента */
    void deleteElement(ListNode<T> *node) {
        if (!node->prev) {
            head = node->next;
        } else {
            node->prev->next = node->next;
        }
        if (!node->next) {
            tail = node->prev;
        } else {
            node->next->prev = node->prev;
        }
        delete node;
    }
};

#endif //LAB7_LIST_H
