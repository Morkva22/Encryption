#include "../include/Logger.h"
#include <iostream>

namespace Utils {
    // Конструктор
    Logger::Logger(const std::string& logFile, bool printToConsole)
        : logFile(logFile), printToConsole(printToConsole) {
        fileStream.open(logFile, std::ios::app);
        if (!fileStream.is_open()) {
        std::cerr << "Error opening log file: " << logFile << std::endl;
        }
    }

    // Деструктор
    Logger::~Logger() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }

    // Метод для отримання рядкового представлення рівня логування
    std::string Logger::getLogLevelString(LogLevel level) {
        switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
        }
    }

    // Метод для запису повідомлення
    void Logger::log(const std::string& message, LogLevel level) {
        // Отримуємо поточний час
        std::time_t now = std::time(0);
        char buffer[26]; // Буфер для зберігання часу
        ctime_s(buffer, sizeof(buffer), &now); // Використовуємо ctime_s
        std::string timestamp(buffer);
        timestamp.pop_back(); // Видаляємо символ нового рядка

        // Формуємо повне повідомлення
        std::string fullMessage = "[" + timestamp + "] [" + getLogLevelString(level) + "] " + message;

        // Записуємо повідомлення у файл
        if (fileStream.is_open()) {
            fileStream << fullMessage << std::endl;
        } else {
        std::cerr << "Error: log file is not open!" << std::endl;
        }

        // Виводимо повідомлення на екран (якщо потрібно)
        if (printToConsole) {
            std::cout << fullMessage << std::endl;
        }
    }
}