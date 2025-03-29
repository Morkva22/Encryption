#ifndef VIEW_H
#define VIEW_H

#include <memory>
#include <string>
#include "../../Infrastructure/Localization/Localization.h"

class View {
public:
    explicit View(std::shared_ptr<Localization> localization);
    
    void showMainMenu();
    int getUserChoice();
    std::string getInputText();
    int getEncryptionKey();
    std::string getCipherType();
    void showResult(const std::string& result);
    void showError(const std::string& message);
    void showLanguageMenu();
    void setLanguage(const std::string& language);

private:
    std::shared_ptr<Localization> localization;

#ifdef _WIN32
    void setConsoleColor(int color);
#else
    void setTextColor(const std::string& ansiCode);
#endif
    
    void resetConsoleColor();
};

#endif // VIEW_H