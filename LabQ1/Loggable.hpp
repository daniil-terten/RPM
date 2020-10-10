/**
 * @file Loggable.hpp
 * @author Тертень Даниил
 * @brief Средство логгирования
 */

using namespace std;

class Loggable
{
protected:
    int minLevel, maxLevel;
public:
    virtual void log(string what, int level)=0;
    void setBounds(int newMinLevel, int newMaxLevel)
    {
        /**
         * @brief Установка границ, в пределах которых средство будет реагировать
         * @param newMinLevel Минимальный уровень
         * @param newMaxLevel Максимальный уровень
         */
        minLevel=newMinLevel;
        maxLevel=newMaxLevel;
    }
};

class LoggableConsole: public Loggable
{
    void log(string what, int level) override
    {
        /**
         * @brief Запись сообщения в консоль
         * @param what Сообщение
         * @param level Уровень ошибки
         */
        if(level >= minLevel && level <= maxLevel){
            time_t seconds = time(NULL);
            cout << "Datetime: " << asctime(localtime(&seconds)) << " Level: " << level << " Message: " << what << endl;
        }
    }
};

class LoggableFile: public Loggable
{
private:
    string fileName;
    ofstream file;
public:
    void log(string what, int level) override
    {
        /**
         * @brief Запись сообщения в файл
         * @param what Сообщение
         * @param level Уровень ошибки
         */
        if(level >= minLevel && level <= maxLevel){
            file.open(fileName, std::ios::app);
            time_t seconds = time(NULL);
            file << "Datetime: " << asctime(localtime(&seconds)) << " Level: " << level << " Message: " << what << endl;
            file.close();
        }
    }
    void setFileName(string newFileName)
    {
        /**
         * @brief Установка имени файла
         * @param newFileName Новое имя файла
         */
        fileName = newFileName;
    }
};
