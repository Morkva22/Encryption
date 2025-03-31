#include "ConsoleUtils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

void ConsoleUtils::initialize() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8
#endif
}

void ConsoleUtils::showError(const std::string& message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // Червоний
    std::cerr << message << std::endl;
    SetConsoleTextAttribute(hConsole, 15); // Повертаємо стандартний колір
#else
    std::cerr << "\033[1;31m" << message << "\033[0m" << std::endl;
#endif
}   