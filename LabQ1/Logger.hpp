#include <list>

using namespace std;

/**
 * @file Logger.hpp
 * @author Тертень Даниил
 * @brief Система логгирования
 */

class Logger
{
private:
    Logger() {}
    Logger( const Logger&);
    Logger& operator=( Logger& );
    list<Loggable*> loggables;
    void log(string what, int level)
    {
        /**
         * @brief Оповестить о событии подписанные средства логгирования
         * @param what Сообщение ошибки
         * @param level Уровень ошибки
         */
        for(list<Loggable*>::iterator iter = loggables.begin(); iter != loggables.end(); iter++)
            (*iter)->log(what, level);
    }
public:
    static Logger& getInstance()
    {
        /**
         * @brief Получить экземпляр класса-одиночки
         * @return Всегда один и тот же экземпляр класса
         */
        static Logger instance;
        return instance;
    }
    void addLogger(Loggable *logger)
    {
        /**
         * @brief Подписывает средство логгирования на события
         * @param logger Указатель на средство логгирования
         */
        loggables.push_back(logger);
    }
    void notice(string what)
    {
        /**
         * @brief Уведомление нулевого уровня
         * @param what Сообщение
         */
        log(what, 0);
    }
    void info(string what)
    {
        /**
         * @brief Уведомление первого уровня
         * @param what Сообщение
         */
        log(what, 1);
    }
    void warning(string what)
    {
        /**
         * @brief Уведомление второго уровня
         * @param what Сообщение
         */
        log(what, 2);
    }
    void error(string what)
    {
        /**
         * @brief Уведомление третьего уровня
         * @param what Сообщение
         */
        log(what, 3);
    }
    void critical(string what)
    {
        /**
         * @brief Уведомление четвёртого уровня
         * @param what Сообщение
         */
        log(what, 4);
    }
    void fatal(string what)
    {
        /**
         * @brief Уведомление пятого уровня
         * @param what Сообщение
         */
        log(what, 5);
    }
};
