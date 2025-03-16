// scr/Domain/Entities/EncryptionData.h

#ifndef ENCRYPTION_DATA_H
#define ENCRYPTION_DATA_H

#include "../../lib/lib.h"

namespace Encryption {

    class EncryptionData {
    public:
        EncryptionData(string text, string key, int algorithm);
        string getText();
        string getKey();
        int getAlgorithm();

    private:
        string text;
        string key;
        int algorithm;
    };

} // namespace Encryption

#endif