#ifndef DATA_H
#define DATA_H

#include "../lib/lib.h"

namespace Encryption {
    namespace Data {
        struct EncryptionData {
            string text;
            string key;
            int algorithm;
        };
    } // namespace Data
} // namespace Encryption

#endif // DATA_H