#include "Config.h"
#include <fstream>
#include <stdexcept>

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
    
    try {
        auto parsed = parser.parse(content);
        configData = parsed;
        
        // Завантаження кольорів
        colors["primary"] = getString("ui.colors.primary");
        colors["secondary"] = getString("ui.colors.secondary");
        colors["error"] = getString("ui.colors.error");
        colors["background"] = getString("ui.colors.background");
        colors["text"] = getString("ui.colors.text");
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Config parse error: ") + e.what());
    }
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

std::string Config::getColor(const std::string& name) const {
    auto it = colors.find(name);
    return it != colors.end() ? it->second : "#000000";
}