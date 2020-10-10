/**
 * @file LoggableFactory.hpp
 * @author Тертень Даниил
 * @brief Фабрика средств логгирования
 */

class LoggableFactory
{
public:
    virtual Loggable* createLoggable(string name, int minLevel, int maxLevel)=0;
};

class LoggableConsoleFactory: public LoggableFactory
{
public:
    LoggableConsole* createLoggable(string name, int minLevel, int maxLevel) override
    {
        /**
         * @brief Создание нового средства ызаписи в консоль
         * @param name Имя средства
         * @param minLevel Минимальный уровень срабатывания
         * @param maxLevel Максимальный уровень срабатывания
         */
        LoggableConsole *newLoggable = new LoggableConsole();
        newLoggable->setBounds(minLevel, maxLevel);
        return newLoggable;
    }
};

class LoggableFileFactory: public LoggableFactory
{
public:
    LoggableFile* createLoggable(string name, int minLevel, int maxLevel) override
    {
        /**
         * @brief Создание нового средства записи в файл
         * @param name Имя средства
         * @param minLevel Минимальный уровень срабатывания
         * @param maxLevel Максимальный уровень срабатывания
         */
        LoggableFile *newLoggable = new LoggableFile();
        newLoggable->setBounds(minLevel, maxLevel);
        newLoggable->setFileName(name);
        return newLoggable;
    }
};
