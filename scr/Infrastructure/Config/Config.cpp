#include "Config.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

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
    auto it = tempValues.find(key);
    if (it != tempValues.end()) {
        return it->second == "true";
    }

    it = configData.find(key);
    if (it == configData.end()) {
        throw std::runtime_error("Config key not found: " + key);
    }
    return it->second == "true";
}

std::string Config::getString(const std::string& key) const {
    auto it = tempValues.find(key);
    if (it != tempValues.end()) {
        return it->second;
    }

    it = configData.find(key);
    if (it == configData.end()) {
        throw std::runtime_error("Config key not found: " + key);
    }
    return it->second;
}

std::string Config::getLanguage() const {
    return getString("ui.language");
}

int Config::getInt(const std::string& key) const {
    std::string value = getString(key);
    try {
        return std::stoi(value);
    } catch (...) {
        throw std::runtime_error("Invalid integer value for key: " + key);
    }
}

double Config::getDouble(const std::string& key) const {
    std::string value = getString(key);
    try {
        return std::stod(value);
    } catch (...) {
        throw std::runtime_error("Invalid double value for key: " + key);
    }
}

void Config::reload() {
    loadConfig();
}

std::string Config::getColor(const std::string& name) const {
    auto it = colors.find(name);
    return it != colors.end() ? it->second : "#000000";
}

void Config::setTemporaryValue(const std::string& key, const std::string& value) {
    tempValues[key] = value;
}

void Config::clearTemporaryValues() {
    tempValues.clear();
}