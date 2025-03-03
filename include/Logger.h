#ifndef LOGGER_H
#define LOGGER_H
#include "../include/lib.h"
namespace Utils {
    // Перелік рівнів логування
    enum LogLevel {
        INFO,    // Загальні повідомлення
        WARNING, // Попередження
        ERROR    // Помилки
    };

    class Logger {
    private:
        std::string logFile; // Назва файлу для логування
        std::ofstream fileStream; // Потік для запису у файл
        bool printToConsole; // Чи виводити повідомлення на екран

        // Метод для отримання рядкового представлення рівня логування
        std::string getLogLevelString(LogLevel level);

    public:
        // Конструктор (за замовчуванням файл — "log.txt", вивід на екран — увімкнено)
        Logger(const std::string& logFile = "log.txt", bool printToConsole = true);

        // Деструктор (закриває файл)
        ~Logger();

        // Метод для запису повідомлення з рівнем логування
        void log(const std::string& message, LogLevel level = INFO);
    };
}

#endif // LOGGER_H