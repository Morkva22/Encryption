#include "EncryptionData.h"

using namespace Encryption;

EncryptionData::EncryptionData(std::string text, std::string key, int algorithm)
    : text(text), key(key), algorithm(algorithm) {}

std::string EncryptionData::getText() const {
    return text;
}

std::string EncryptionData::getKey() const {
    return key;
}

int EncryptionData::getAlgorithm() const {
    return algorithm;
}