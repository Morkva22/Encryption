#pragma once
#include <string>

struct EncryptionData {
    std::string text;
    std::string encryptedText;
    int key;
    std::string cipherType;
};
