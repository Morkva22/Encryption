#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include "LocalizationInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include <unordered_map>
#include <memory>
#include <string>

class Localization : public LocalizationInterface {
public:
    Localization(const std::string& basePath, const std::string& defaultLanguage);
    
    // Новий публічний метод для безпечної ініціалізації
    static std::shared_ptr<Localization> createWithFallback(
        const std::string& basePath,
        const std::string& preferredLang,
        const std::string& fallbackLang = "en"
    );
    
    void setLanguage(const std::string& language);
    std::string translate(const std::string& key) const override;

private:
    void loadTranslations(const std::string& language);
    std::string getLocaleFilePath(const std::string& language) const;

    std::string basePath;
    std::unordered_map<std::string, std::string> translations;
    std::string currentLanguage;
    JsonParser parser;
};

#endif // LOCALIZATION_H