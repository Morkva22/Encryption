#ifndef CONFIG_H
#define CONFIG_H

#include "ConfigInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include <memory>
class Config : public ConfigInterface {
public:
    Config();
    bool getBool(const std::string& key) const override;
    std::string getString(const std::string& key) const override;
    std::string getLanguage() const;  // Додано новий метод

private:
    void loadConfig();
    std::unordered_map<std::string, std::string> configData;
    JsonParser parser;
};

#endif // CONFIG_H