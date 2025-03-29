#ifndef CONFIG_H
#define CONFIG_H

#include "ConfigInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include "../../lib/lib.h"
#include <unordered_map>

class Config : public ConfigInterface {
public:
    Config();
    bool getBool(const std::string& key) const override;
    std::string getString(const std::string& key) const override;
    std::string getLanguage() const override;
    int getInt(const std::string& key) const override;
    double getDouble(const std::string& key) const override;
    void reload() override;

    std::string getColor(const std::string& name) const;
    void setTemporaryValue(const std::string& key, const std::string& value);
    void clearTemporaryValues();

private:
    void loadConfig();
    std::unordered_map<std::string, std::string> configData;
    std::unordered_map<std::string, std::string> colors;
    std::unordered_map<std::string, std::string> tempValues;
    JsonParser parser;
};

#endif // CONFIG_H