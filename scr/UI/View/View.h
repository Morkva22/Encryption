#ifndef VIEW_H
#define VIEW_H

#include "../../lib/lib.h"
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
};

#endif // VIEW_H