#ifndef CONFIG_INTERFACE_H
#define CONFIG_INTERFACE_H

#include <string>

class ConfigInterface {
public:
    virtual ~ConfigInterface() = default;
    virtual bool getBool(const std::string& key) const = 0;
    virtual std::string getString(const std::string& key) const = 0;
    virtual std::string getLanguage() const = 0; // Додано метод
};

#endif // CONFIG_INTERFACE_H