#ifndef CONFIG_H
#define CONFIG_H

#include "ConfigInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include <unordered_map>

class Config : public ConfigInterface {
public:
    Config();
    bool getBool(const std::string& key) const override;
    std::string getString(const std::string& key) const override;
    std::string getLanguage() const override;

    std::string getColor(const std::string& name) const;

private:
    void loadConfig();
    std::unordered_map<std::string, std::string> configData;
    std::unordered_map<std::string, std::string> colors;
    JsonParser parser;
};

#endif // CONFIG_H