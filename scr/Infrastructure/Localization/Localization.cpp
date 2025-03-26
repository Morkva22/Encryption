#include "Localization.h"
#include <fstream>
#include <algorithm>

Localization::Localization(const std::string& defaultLanguage) {
    setLanguage(defaultLanguage);
}

void Localization::setLanguage(const std::string& language) {
    currentLanguage = language;
    loadTranslations(language);
}

std::string Localization::getLocaleFilePath(const std::string& language) const {
    return "locales/" + language + ".json";
}

void Localization::loadTranslations(const std::string& language) {
    std::string filePath = getLocaleFilePath(language);
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open locale file: " + filePath);
    }
    
    translations.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t delimiter = line.find(':');
        if (delimiter != std::string::npos) {
            std::string key = line.substr(0, delimiter);
            std::string value = line.substr(delimiter + 1);
            
            // Trim
            auto trim = [](std::string& s) {
                s.erase(0, s.find_first_not_of(" \t\""));
                s.erase(s.find_last_not_of(" \t\",") + 1);
            };
            
            trim(key);
            trim(value);
            translations[key] = value;
        }
    }
}

std::string Localization::translate(const std::string& key) const {
    auto it = translations.find(key);
    return it != translations.end() ? it->second : "[" + key + "]";
}