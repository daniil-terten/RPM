/**
 * @file main.cpp
 * @author Тертень Даниил
 * @brief Лабораторная работа №3
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/**
 * @brief структура для хранения операций
 */
struct Operation
{
    int number = 0;
    string action;
    string type;
    string first;
    string second;
    string result_type;
};

/**
 * @brief получение операции из файла
 * @param operation стрктура, в которую сохраняется операция
 * @param line входной файл
 */
void getOperation(Operation &operation, ifstream &line)
{
    line >> operation.number;
    line >> operation.action;
    line >> operation.type;
    line >> operation.first;
    line >> operation.second;
    line >> operation.result_type;
}

/**
 * @brief произвести указанную операцию (сложение, вычитание и т.д.)
 * @param first первый операнд
 * @param second второй операнд
 * @param action операция
 * @return результат выполнения операции
 */
template <typename A>
A doOperation(const A& first, const A& second, const string& action)
{
    A result;

    if (action == "+") {
        result = first + second;
    } else if (action == "-") {
        result = first - second;
    } else if (action == "*") {
        result = first * second;
    } else if (action == "/") {
        if (second == 0) {
            throw runtime_error("division by zero");
        }
        result = first / second;
    } else if (action == "pow") {
        result = pow(first, second);
    } else {
        throw runtime_error("unknown action");
    }

    return result;
}

/**
 * @brief перегруженная функция doOperation для строк
 * @param first первый операнд
 * @param second второй операнд
 * @param action операция
 * @return результат выполнения операции
 */
string doOperation(const string& first, const string& second, const string& action)
{
    string result;

    if (action == "+") {
        result = first + second;
    } else {
        throw runtime_error("unknown action");
    }

    return result;
}

/**
 * @brief сохранение результатов операций в файл
 * @param result Результат операции
 * @param operation Операция
 * @param output Выходной файл
 */
template <typename A>
void saveOperation(A result, Operation &operation, ofstream &output)
{
    if (operation.result_type == "int") {
        result = (int) result;
    }
    output << operation.number << " " << result << " " << operation.result_type << endl;
}

/**
 * @brief перегруженная функция сохранения результатов операций в файл для строк
 * @param result Результат операции
 * @param operation Операция
 * @param output Выходной файл
 */
void saveOperation(const string &result, Operation &operation, ofstream &output)
{
    output << operation.number << " " << result << " " << operation.result_type << endl;
}

/**
 * @brief запуск функций для получения и сохранения результата для разных типов данных
 * @param operation операция
 * @param output выходной файл
 */
void doAndSaveOperation(Operation &operation, ofstream &output)
{
    try {
        if (operation.type == "int") {
            int first = stoi(operation.first);
            int second = stoi(operation.second);
            int result = doOperation(first, second, operation.action);
            saveOperation(result, operation, output);
        } else if (operation.type == "float") {
            float first = stof(operation.first);
            float second = stof(operation.second);
            float result = doOperation(first, second, operation.action);
            saveOperation(result, operation, output);
        } else if (operation.type == "string") {
            string result = doOperation(operation.first, operation.second, operation.action);
            saveOperation(result, operation, output);
        } else {
            throw runtime_error("unknown type");
        }
    } catch (exception &e) {
        string error(e.what());
        saveOperation(error, operation, output);
    }
}

/**
 * @brief Точка входа в программу, открытие файлов, запуск обработки каждой строки
 * @return 0
 */
int main()
{
    ifstream input;
    ofstream output;
    input.open("../input.txt", ios::in);
    output.open("../output.txt", ios::out);

    if (!input.is_open()) {
        cout << "File cannot be opened ";
        input.close();
        output.close();
        return 0;
    }

    while (!input.eof()) {
        Operation operation;
        getOperation(operation, input);
        doAndSaveOperation(operation, output);
    }

    input.close();
    output.close();
    return 0;
}
