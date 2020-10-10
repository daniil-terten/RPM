/**
 * Список кандидатов
 * @file CandidateList.h
 * @author Даниил Тертень
 */

#ifndef LAB8_CANDIDATELIST_H
#define LAB8_CANDIDATELIST_H

#include <queue>
#include "Candidate.h"
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * Список кандидатов
 */
class CandidateList {
private:
    /**
     * Список кандидатов
     */
    priority_queue<Candidate> list;
    /**
     * Буфер
     */
    priority_queue<Candidate> buf;

    /**
     * Перенос из буфера обратно в список
     */
    void fromBufToList() {
        while (!buf.empty()) {
            list.push(buf.top());
            buf.pop();
        }
    }
public:
    /**
     * Добавить кандидата
     * @param name
     * @param birth_date
     * @param birth_place
     * @param popularity
     */
    void add(string& name, string& birth_date, string& birth_place, int popularity) {
        Candidate candidate;
        candidate.name = name;
        candidate.birth_date = birth_date;
        candidate.birth_place = birth_place;
        candidate.popularity = popularity;
        list.push(candidate);
    }
    /**
     * Убрать кандидата по имени
     * @param name
     */
    void remove(string name) {
        Candidate candidate;
        bool deleted = false;
        while (!list.empty()) {
            candidate = list.top();
            list.pop();
            if (candidate.name != name) {
                buf.push(candidate);
            } else {
                deleted = true;
                break;
            }
        }
        fromBufToList();
        if (!deleted) {
            throw runtime_error("Candidate not found");
        }
    }
    /**
     * Вывести список
     */
    void print() {
        cout << "Candidates: " << endl;
        Candidate candidate;
        while (!list.empty()) {
            candidate = list.top();
            buf.push(candidate);
            cout << "-------" << endl;
            cout << candidate << endl;
            list.pop();
        }
        fromBufToList();
    }
};

#endif //LAB8_CANDIDATELIST_H
