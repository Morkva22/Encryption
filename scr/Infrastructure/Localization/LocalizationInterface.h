#ifndef LOCALIZATION_INTERFACE_H
#define LOCALIZATION_INTERFACE_H

#include <string>

class LocalizationInterface {
public:
    virtual ~LocalizationInterface() = default;
    virtual std::string translate(const std::string& key) const = 0;
};

#endif // LOCALIZATION_INTERFACE_H