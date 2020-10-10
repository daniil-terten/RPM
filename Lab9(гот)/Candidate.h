/**
 * Данные о кандидате
 * @file Candidate.h
 * @author Даниил Тертень
 */

#ifndef LAB8_CANDIDATE_H
#define LAB8_CANDIDATE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Кандидат
 */
class Candidate {
public:
    /**
     * ФИО
     */
    string name;
    /**
     * Дата рождения
     */
    string birth_date;
    /**
     * Место рождения
     */
    string birth_place;
    /**
     * Индекс популярности
     */
    int popularity;
    /**
     * Оператор сравнения
     * @param a
     * @return
     */
    friend bool operator<(const Candidate &a, const Candidate &b) {
        return a.popularity < b.popularity;
    }
    /**
     * Вывод кандидата на экран
     * @param os
     * @param candidate
     * @return
     */
    friend ostream& operator<<(ostream& os, const Candidate& candidate) {
        os << "Name: " << candidate.name << endl;
        os << "Birth date: " << candidate.birth_date << endl;
        os << "Birth place: " << candidate.birth_place << endl;
        os << "Popularity: " << candidate.popularity << endl;
        return os;
    }
};

#endif //LAB8_CANDIDATE_H
