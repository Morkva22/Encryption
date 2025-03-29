#include "View.h"

#ifdef _WIN32
#include <windows.h>  // Для кольорів у Windows
#endif

View::View(std::shared_ptr<Localization> localization) 
    : localization(std::move(localization)) {}

void View::showMainMenu() {
    #ifndef _WIN32
    std::cout << "\033[1;34m";  // Жирний синій для заголовка
    #endif
    std::cout << localization->translate("main_menu") << "\n";
    
    #ifndef _WIN32
    std::cout << "\033[1;32m";  // Жирний зелений для пунктів
    #endif
    std::cout << localization->translate("encrypt_option") << "\n"
              << localization->translate("decrypt_option") << "\n"
              << localization->translate("exit_option") << "\n"
              << "\033[0m"  // Скидання кольорів
              << localization->translate("choose_option");
}

void View::showLanguageMenu() {
    #ifndef _WIN32
    std::cout << "\033[1;34m";
    #endif
    std::cout << "\n=== " << localization->translate("language_selection") << " ===\n";
    
    #ifndef _WIN32
    std::cout << "\033[1;32m";
    #endif
    std::cout << "1. English\n"
              << "2. Українська\n"
              << "3. Русский\n"
              << "\033[0m"
              << localization->translate("select_language");
}

int View::getUserChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        showError(localization->translate("invalid_input"));
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        showError(localization->translate("invalid_input"));
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return key;
}

std::string View::getCipherType() {
    std::cout << localization->translate("choose_cipher");
    std::string type;
    std::cin >> type;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (type != "caesar" && type != "xor") {
        showError(localization->translate("invalid_cipher"));
        throw std::invalid_argument("Invalid cipher type");
    }
    
    return type;
}

void View::showResult(const std::string& result) {
    #ifndef _WIN32
    std::cout << "\033[1;32m";
    #endif
    std::cout << localization->translate("result") << result << "\n\033[0m";
}

void View::showError(const std::string& message) {
    #ifndef _WIN32
    std::cerr << "\033[1;31m";
    #endif
    std::cerr << localization->translate("error") << message << "\n\033[0m";
}

void View::setLanguage(const std::string& language) {
    localization->setLanguage(language);
    #ifndef _WIN32
    std::cout << "\033[1;32m";
    #endif
    std::cout << localization->translate("language_set") << "\n\033[0m";
}

// Windows-версія кольорів
#ifdef _WIN32
void View::setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#endif