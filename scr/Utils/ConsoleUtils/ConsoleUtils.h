#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <string>
#include <locale>

class ConsoleUtils {
public:
    enum Color {
        RED = 1,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    static void initialize();
    static void showMessage(const std::string& message, Color color = WHITE);
    static void showError(const std::string& message);
    static void showSuccess(const std::string& message);
    static void clearScreen();
    
private:
#ifdef _WIN32
    static void setWindowsColor(int color);
#else
    static void setUnixColor(int color);
#endif
};

#endif