#include "View.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

View::View(std::shared_ptr<Localization> localization) 
    : localization(std::move(localization)) {}

#ifdef _WIN32
void View::setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
void View::setTextColor(const std::string& ansiCode) {
    std::cout << ansiCode;
}
#endif

void View::resetConsoleColor() {
    #ifdef _WIN32
    setConsoleColor(15);
    #else
    std::cout << "\033[0m";
    #endif
}

void View::showMainMenu() {
    #ifdef _WIN32
    setConsoleColor(9);
    #else
    setTextColor("\033[1;34m");
    #endif
    
    std::cout << localization->translate("main_menu") << "\n";
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    std::cout << localization->translate("encrypt_option") << "\n"
              << localization->translate("decrypt_option") << "\n"
              << localization->translate("exit_option") << "\n";
    
    resetConsoleColor();
    std::cout << localization->translate("choose_option");
}

void View::showLanguageMenu() {
    #ifdef _WIN32
    setConsoleColor(9);
    #else
    setTextColor("\033[1;34m");
    #endif
    
    std::cout << "\n=== " << localization->translate("language_selection") << " ===\n";
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    std::cout << "1. English\n"
              << "2. Українська\n"
              << "3. Русский\n";
    
    resetConsoleColor();
    std::cout << localization->translate("select_language");
}

int View::getUserChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');  // Замість numeric_limits
        showError(localization->translate("invalid_input"));
    }
    std::cin.ignore(10000, '\n');
    return choice;
}

std::string View::getInputText() {
    std::cout << localization->translate("enter_text");
    std::string text;
    std::getline(std::cin, text);
    return text;
}

int View::getEncryptionKey() {
    std::cout << localization->translate("enter_key");
    int key;
    while (!(std::cin >> key)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        showError(localization->translate("invalid_input"));
    }
    std::cin.ignore(10000, '\n');
    return key;
}

std::string View::getCipherType() {
    std::cout << localization->translate("choose_cipher");
    std::string type;
    std::cin >> type;
    std::cin.ignore(10000, '\n');

    if (type != "caesar" && type != "xor") {
        showError(localization->translate("invalid_cipher"));
        throw std::invalid_argument("Invalid cipher type");
    }
    return type;
}

void View::showResult(const std::string& result) {
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    std::cout << localization->translate("result") << result << "\n";
    resetConsoleColor();
}

void View::showError(const std::string& message) {
    #ifdef _WIN32
    setConsoleColor(12);
    #else
    setTextColor("\033[1;31m");
    #endif
    
    std::cerr << localization->translate("error") << message << "\n";
    resetConsoleColor();
}

void View::setLanguage(const std::string& language) {
    localization->setLanguage(language);
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    std::cout << localization->translate("language_set") << "\n";
    resetConsoleColor();
}