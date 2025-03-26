#ifndef KEY_PROVIDER_H
#define KEY_PROVIDER_H

#include "../../../lib/lib.h"

class KeyProvider {
public:
    explicit KeyProvider(const std::string& filename);
    void saveKey(const std::string& cipherName, int key);
    int loadKey(const std::string& cipherName);

private:
    std::string filename;
};

#endif // KEY_PROVIDER_H