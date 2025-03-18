#ifndef ENCRYPTION_DATA_H
#define ENCRYPTION_DATA_H

#include "../../lib/lib.h"

namespace Encryption {

    class EncryptionData {
    public:
        EncryptionData(std::string text, std::string key, int algorithm);
        string getText() const;
        string getKey() const;
        int getAlgorithm() const;

    private:
        string text;
        string key;
        int algorithm;
    };

} // namespace Encryption

#endif