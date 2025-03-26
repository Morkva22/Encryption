#include "View.h"

View::View(std::shared_ptr<Localization> localization) 
    : localization(localization) {}

void View::showMainMenu() {
    std::cout << localization->translate("main_menu") << "\n"
              << localization->translate("encrypt_option") << "\n"
              << localization->translate("decrypt_option") << "\n"
              << localization->translate("exit_option") << "\n"
              << localization->translate("choose_option");
}

void View::showLanguageMenu() {
    std::cout << "\n=== Language Selection ===\n"
              << "1. English\n"
              << "2. Українська\n"
              << "3. Русский\n"
              << "Select language: ";
}

int View::getUserChoice() {
    int choice;
    std::cin >> choice;
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
    std::cin >> key;
    return key;
}

std::string View::getCipherType() {
    std::cout << localization->translate("choose_cipher");
    std::string type;
    std::cin >> type;
    
    if (type != "caesar" && type != "xor") {
        throw std::runtime_error(localization->translate("invalid_cipher"));
    }
    
    return type;
}

void View::showResult(const std::string& result) {
    std::cout << localization->translate("result") << result << "\n";
}

void View::showError(const std::string& message) {
    std::cerr << localization->translate("error") << message << "\n";
}

void View::setLanguage(const std::string& language) {
    localization->setLanguage(language);
    std::cout << localization->translate("language_set") << "\n";
}