/**
 * Меню для работы с очередью
 * @file Menu.h
 * @author Даниил Тертень
 */

#ifndef LAB7_MENU_H
#define LAB7_MENU_H

#include <iostream>
#include <string>
#include "Deque.h"

using namespace std;

/**
 * Меню для работы с деревом
 * @tparam T
 */
template<typename T>
class Menu {
public:
    /**
     * Создание очереди
     */
    Menu() {
        deque = new Deque<T>();
    }
    /**
     * Удаление очерели
     */
    ~Menu() {
        delete deque;
    }
    /**
     * Показать меню
     */
    void show() {
        mainMenu();
    }

private:
    /** Очередь */
    Deque<T> *deque;

    /**
     * Главное меню
     */
    void mainMenu() {
        try {
            cout << "1. Push front" << endl;
            cout << "2. Push back" << endl;
            cout << "3. Pop front" << endl;
            cout << "4. Pop back" << endl;
            cout << "5. Get front" << endl;
            cout << "6. Get back" << endl;
            cout << "7. Clear deque" << endl;
            cout << "0. Exit" << endl;
            mainMenuAction();
        } catch (const runtime_error& error) {
            cout << error.what() << endl << endl;
            mainMenu();
        }
    }

    /**
     * Действия главного меню
     */
    void mainMenuAction() {
        int action;
        cin >> action;
        switch (action) {
            case 1: pushFront(); break;
            case 2: pushBack(); break;
            case 3: popFront(); break;
            case 4: popBack(); break;
            case 5: front(); break;
            case 6: back(); break;
            case 7: clear(); break;
            case 0: cout << "Bye!" << endl; return;
            default: cout << "Wrong action, try again:" << endl;
        }
        cout << endl;
        mainMenu();
    }

    /**
     * Вставка данных в конец
     */
    void pushFront() {
        cout << "Input value:" << endl;
        T value;
        cin >> value;
        deque->push_front(value);
        cout << "Done!" << endl;
    }

    /**
     * Вставка данных в начало
     */
    void pushBack() {
        cout << "Input value:" << endl;
        T value;
        cin >> value;
        deque->push_back(value);
        cout << "Done!" << endl;
    }

    /**
     * Вырезание из конца
     */
    void popFront() {
        cout << deque->pop_front() << endl;
    }

    /**
     * Вырезание из начала
     */
    void popBack() {
        cout << deque->pop_back() << endl;
    }

    /**
     * Получение из конца
     */
    void front() {
        cout << deque->front() << endl;
    }

    /**
     * Получение из начала
     */
    void back() {
        cout << deque->back() << endl;
    }

    /**
     * Очистка
     */
    void clear() {
        deque->clear();
        cout << "Done!" << endl;
    }
};


#endif //LAB7_MENU_H
