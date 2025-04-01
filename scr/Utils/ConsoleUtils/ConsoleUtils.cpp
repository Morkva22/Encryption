#include "ConsoleUtils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdlib.h>
#endif

void ConsoleUtils::initialize() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8
#else
    setlocale(LC_ALL, "en_US.utf8");
#endif
}

void ConsoleUtils::showMessage(const std::string& message, Color color) {
#ifdef _WIN32
    setWindowsColor(color);
    std::cout << message;
    setWindowsColor(WHITE);
#else
    setUnixColor(color);
    std::cout << message;
    setUnixColor(WHITE);
#endif
}

void ConsoleUtils::showError(const std::string& message) {
    showMessage("[ERROR] " + message + "\n", RED);
}

void ConsoleUtils::showSuccess(const std::string& message) {
    showMessage("[SUCCESS] " + message + "\n", GREEN);
}

void ConsoleUtils::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#ifdef _WIN32
void ConsoleUtils::setWindowsColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int winColor;
    switch(color) {
    case RED: winColor = FOREGROUND_RED; break;
    case GREEN: winColor = FOREGROUND_GREEN; break;
        // ... other colors
    default: winColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
    SetConsoleTextAttribute(hConsole, winColor);
}
#else
void ConsoleUtils::setUnixColor(int color) {
    const char* codes[] = {
        "", "\033[31m", "\033[32m", "\033[33m", 
        "\033[34m", "\033[35m", "\033[36m", "\033[37m"
    };
    std::cout << codes[color];
}
#endif