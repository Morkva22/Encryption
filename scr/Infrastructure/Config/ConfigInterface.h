#ifndef CONFIG_INTERFACE_H
#define CONFIG_INTERFACE_H

#include <string>

class ConfigInterface {
public:
    virtual ~ConfigInterface() = default;
    virtual bool getBool(const std::string& key) const = 0;
    virtual std::string getString(const std::string& key) const = 0;
    virtual std::string getLanguage() const = 0;
    
    // Додано нові методи для роботи з конфігурацією
    virtual int getInt(const std::string& key) const = 0;
    virtual double getDouble(const std::string& key) const = 0;
    virtual void reload() = 0;
};

#endif // CONFIG_INTERFACE_H