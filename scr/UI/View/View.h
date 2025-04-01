#ifndef VIEW_H
#define VIEW_H

#include "../../Infrastructure/Localization/Localization.h"
#include "../../Utils/ConsoleUtils/ConsoleUtils.h"
#include <memory>

class View {
public:
    explicit View(std::shared_ptr<Localization> localization);
    
    void displayHeader();
    void showMainMenu();
    int getUserChoice();
    std::string getInputText();
    int getEncryptionKey();
    std::string getCipherType();
    void showResult(const std::string& result);
    void showError(const std::string& message);
    void showLanguageMenu();

private:
    std::shared_ptr<Localization> localization;
    
    void displayCentered(const std::string& text);
    void displayDivider(char symbol = '=');
};
#endif