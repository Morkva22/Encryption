// scr/Domain/Entities/EncryptionData.cpp

#include "EncryptionData.h"

namespace Encryption {

    EncryptionData::EncryptionData(string text, string key, int algorithm) : text(text), key(key), algorithm(algorithm) {}

    string EncryptionData::getText() {
        return text;
    }

    string EncryptionData::getKey() {
        return key;
    }

    int EncryptionData::getAlgorithm() {
        return algorithm;
    }

} // namespace Encryption