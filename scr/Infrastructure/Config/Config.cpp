#include "Config.h"
#include <fstream>

Config::Config() {
    loadConfig();
}

void Config::loadConfig() {
    std::ifstream file("config.json");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file");
    }
    
    std::string content((std::istreambuf_iterator<char>(file)), 
                       std::istreambuf_iterator<char>());
    configData = parser.parse(content);
}

bool Config::getBool(const std::string& key) const {
    auto it = configData.find(key);
    if (it == configData.end()) {
        throw std::runtime_error("Config key not found: " + key);
    }
    return it->second == "true";
}

std::string Config::getString(const std::string& key) const {
    auto it = configData.find(key);
    if (it == configData.end()) {
        throw std::runtime_error("Config key not found: " + key);
    }
    return it->second;
}
std::string Config::getLanguage() const {
    return getString("ui.language");
}