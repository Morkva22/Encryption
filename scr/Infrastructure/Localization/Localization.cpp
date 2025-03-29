// Localization.cpp
#include "Localization.h"
#include <fstream>
#include <stdexcept>

void createDefaultLocaleFile(const std::string& filePath, const std::string& lang) {
    std::ofstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to create locale file: " + filePath);
    }

    if (lang == "uk") {
        file << R"({
  "main_menu": "=== Головне меню ===",
  "encrypt_option": "1. Шифрування",
  "decrypt_option": "2. Дешифрування",
  "exit_option": "3. Вихід",
  "language_set": "Мову встановлено на українську"
})";
    } else { // en.json as default fallback
        file << R"({
  "main_menu": "=== Main Menu ===",
  "encrypt_option": "1. Encrypt",
  "decrypt_option": "2. Decrypt",
  "exit_option": "3. Exit",
  "language_set": "Language set to English"
})";
    }
}

Localization::Localization(const std::string& basePath, const std::string& defaultLanguage)
    : basePath(basePath) {
    setLanguage(defaultLanguage);
}

std::shared_ptr<Localization> Localization::createWithFallback(
    const std::string& basePath,
    const std::string& preferredLang,
    const std::string& fallbackLang)
{
    try {
        // Try preferred language
        std::string prefPath = basePath + preferredLang + ".json";
        std::ifstream test(prefPath);
        if (!test) {
            std::cerr << "Creating default " << preferredLang << " locale file..." << std::endl;
            createDefaultLocaleFile(prefPath, preferredLang);
        }

        auto loc = std::make_shared<Localization>(basePath, preferredLang);
        std::cout << loc->translate("language_set") << std::endl;
        return loc;
    } catch (const std::exception& e) {
        std::cerr << "Error with preferred language: " << e.what() << std::endl;

        try {
            // Try fallback language
            std::string fallbackPath = basePath + fallbackLang + ".json";
            std::ifstream test(fallbackPath);
            if (!test) {
                std::cerr << "Creating default " << fallbackLang << " locale file..." << std::endl;
                createDefaultLocaleFile(fallbackPath, fallbackLang);
            }

            auto loc = std::make_shared<Localization>(basePath, fallbackLang);
            std::cerr << "Using fallback language: " << fallbackLang << std::endl;
            return loc;
        } catch (const std::exception& e) {
            throw std::runtime_error("All localization attempts failed: " + std::string(e.what()));
        }
    }
}

void Localization::setLanguage(const std::string& language) {
    currentLanguage = language;
    loadTranslations(language);
}

void Localization::loadTranslations(const std::string& language) {
    std::string filePath = basePath + language + ".json";
    std::ifstream file(filePath);

    if (!file) {
        throw std::runtime_error("Cannot open locale file: " + filePath);
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());

    try {
        translations = parser.parse(content);
    } catch (const std::exception& e) {
        throw std::runtime_error("Invalid JSON in " + filePath + ": " + e.what());
    }
}

std::string Localization::translate(const std::string& key) const {
    auto it = translations.find(key);
    return it != translations.end() ? it->second : "[" + key + "]";
}