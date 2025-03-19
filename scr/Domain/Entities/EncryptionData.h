// EncryptionData.h
#ifndef ENCRYPTION_DATA_H
#define ENCRYPTION_DATA_H

#include "../../lib/lib.h"
#include "../../Data/Data.h"

namespace Encryption {

    class EncryptionData {
    public:
        EncryptionData(string text, string key, int algorithm);
        string getText() const;
        string getKey() const;
        int getAlgorithm() const; // Додано публічний метод

    private:
        string text;
        string key;
        int algorithm;
    };

} // namespace Encryption

#endif