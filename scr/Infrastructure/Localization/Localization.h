#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <string>
#include <unordered_map>

class Localization {
public:
    explicit Localization(const std::string& defaultLanguage);
    std::string translate(const std::string& key) const;
    void setLanguage(const std::string& language);
    
private:
    std::unordered_map<std::string, std::string> translations;
    std::string currentLanguage;
    
    void loadTranslations(const std::string& language);
    std::string getLocaleFilePath(const std::string& language) const;
};

#endif // LOCALIZATION_H