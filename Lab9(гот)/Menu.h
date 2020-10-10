/**
 * Меню для списка
 * @file Menu.h
 * @author Даниил Тертень
 */

#ifndef LAB8_MENU_H
#define LAB8_MENU_H

#include <iostream>
#include "CandidateList.h"
#include <string>

using namespace std;

/**
 * Меню
 */
class Menu {
public:
    /** Создание новой картотеки */
    Menu() {
        list = new CandidateList;
    }

    /**
     * Показать главное меню
     */
    void show() {
        try {
            cout << endl;
            cout << "1. Add candidate" << endl;
            cout << "2. Remove candidate" << endl;
            cout << "3. Show list" << endl;
            cout << "0. Exit" << endl;
            mainMenuAction();
        } catch (const runtime_error &error) {
            cout << error.what() << endl;
            mainMenuAction();
        }
    }

private:
    /** Картотека */
    CandidateList *list;

    /**
     * Действия главного меню
     */
    void mainMenuAction() {
        int action;
        cin >> action;
        if (action == 1) {
            addCandidate();
        } else if (action == 2) {
            removeCandidate();
        } else if (action == 3) {
            printList();
        } else if (action == 0) {
            cout << "Bye!";
            return;
        } else {
            cout << "Wrong action, try again:" << endl;
        }
        show();
    }

    /**
     * Добавить кандидата
     */
    void addCandidate() {
        string name, birth_date, birth_place;
        int popularity;
        cout << "Input name:" << endl;
        cin >> name;
        cout << "Input birth date:" << endl;
        cin >> birth_date;
        cout << "Input birth place:" << endl;
        cin >> birth_place;
        cout << "Select popularity:" << endl;
        cout << "1. Podderzhan prezidentom (70)" << endl;
        cout << "2. Podderzhan oppozizionnoy partiey (15)" << endl;
        cout << "3. Oppozizionniy candidat, kotoriy snimaet svou candidaturu v polzu candidata #1 (10)" << endl;
        cout << "4. Prockie (5)" << endl;
        popularity = getPopularity();
        list->add(name, birth_date, birth_place, popularity);
        cout << "Done!" << endl;
    }

    /**
     * Получить индекс популярности
     * @return
     */
    int getPopularity() {
        int num;
        cin >> num;
        switch (num) {
            case 1:
                return 70;
            case 2:
                return 15;
            case 3:
                return 10;
            case 4:
                return 5;
            default:
                cout << "Wrong number, try again:" << endl;
                return getPopularity();
        }
    }

    /**
     * Убрать кандидата
     */
    void removeCandidate() {
        string name;
        cout << "Input name:" << endl;
        cin >> name;
        list->remove(name);
    }

    /**
     * Вывести список кандидатов
     */
    void printList() {
        list->print();
    }
};


#endif //LAB8_MENU_H
