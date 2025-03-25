#ifndef ENCRYPTION_DATA_H
#define ENCRYPTION_DATA_H

#include <string>

namespace Encryption {

    class EncryptionData {
    public:
        EncryptionData(std::string text, std::string key, int algorithm);
    
        // Геттери повертаються!
        std::string getText() const;
        std::string getKey() const;
        int getAlgorithm() const;

    private:
        std::string text;
        std::string key;
        int algorithm;
    };

} // namespace Encryption

#endif