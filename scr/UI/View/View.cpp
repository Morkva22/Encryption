#include "View.h"
#include <limits>

View::View(shared_ptr<Localization> localization) 
    : localization(localization) {}

void View::showMainMenu() {
    cout << localization->translate("main_menu") << endl;
    cout << localization->translate("encrypt_option") << endl;
    cout << localization->translate("decrypt_option") << endl;
    cout << localization->translate("exit_option") << endl;
}

int View::getUserChoice() {
    int choice;
    while(!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        showError(localization->translate("invalid_choice"));
    }
    return choice;
}

string View::getInputText() {
    string input;
    cout << localization->translate("enter_text") << ": ";
    cin.ignore();
    getline(cin, input);
    return input;
}

int View::getEncryptionKey() {
    int key;
    cout << localization->translate("enter_key") << ": ";
    while(!(cin >> key)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        showError(localization->translate("invalid_key"));
    }
    return key;
}

string View::getCipherType() {
    string type;
    cout << localization->translate("select_cipher") << ": ";
    cin >> type;
    return type;
}

void View::showResult(const string& result) {
    cout << localization->translate("result") << ": " << result << endl;
}

void View::showError(const string& message) {
    cerr << message << endl;
}

void View::showLanguageMenu() {
    cout << localization->translate("select_language") << endl;
    cout << "1. English" << endl;
    cout << "2. Українська" << endl;
}

void View::setLanguage(const string& language) {
    localization->setLanguage(language);
}