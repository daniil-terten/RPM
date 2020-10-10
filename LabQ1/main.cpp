/**
 * @file main.cpp
 * @author Тертень Даниил
 * @brief Лабораторная работа 1
 */

#include <iostream>
#include <time.h>
#include <fstream>

#include "Loggable.hpp"
#include "Logger.hpp"
#include "LoggableFactory.hpp"

int main()
{
    Logger& logger = Logger::getInstance();
    LoggableFileFactory fileFactory;
    LoggableConsoleFactory consoleFactory;

    logger.addLogger(consoleFactory.createLoggable("console", 1, 5));
    logger.addLogger(fileFactory.createLoggable("error", 3, 5));
    logger.addLogger(fileFactory.createLoggable("all", 0, 5));
    logger.addLogger(fileFactory.createLoggable("critical", 4, 4));

    logger.notice("Notice");
    logger.warning("Warning");
    logger.info("Information");
    logger.error("Error");
    logger.critical("Critical error");
    logger.fatal("Fatal error");
    return 0;
}
