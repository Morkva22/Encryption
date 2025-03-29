#include "Localization.h"
#include "../../Data/Parsers/JsonParser.h"
#include <fstream>
#include <sstream>

Localization::Localization(const std::string& defaultLanguage) : parser() {
    setLanguage(defaultLanguage);
}

std::string Localization::getLocaleFilePath(const std::string& language) const {
    return "Infrastructure/Localization/locales/" + language + ".json";
}

void Localization::loadTranslations(const std::string& language) {
    std::string filePath = getLocaleFilePath(language);
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        std::ostringstream oss;
        oss << "Failed to open locale file: " << filePath;
        throw std::runtime_error(oss.str());
    }

    std::string content((std::istreambuf_iterator<char>(file)), 
                      std::istreambuf_iterator<char>());
    
    translations = parser.parse(content);
}

std::string Localization::translate(const std::string& key) const {
    auto it = translations.find(key);
    return it != translations.end() ? it->second : "[" + key + "]";
}