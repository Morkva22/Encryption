#ifndef DATA_H
#define DATA_H

#include "../lib/lib.h"

namespace Encryption {
    namespace Data {

        struct EncryptionData {
            std::string text;
            std::string key;
            int algorithm;
        };

    } // namespace Data
} // namespace Encryption

#endif