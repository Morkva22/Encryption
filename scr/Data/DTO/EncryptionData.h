#ifndef ENCRYPTION_DATA_H
#define ENCRYPTION_DATA_H

#include "../../lib/lib.h"

struct EncryptionData {
    std::string text;
    std::string encryptedText;
    int key;
    std::string cipherType;

    EncryptionData(const std::string& txt = "", 
                  int k = 0, 
                  const std::string& encTxt = "", 
                  const std::string& cipher = "")
        : text(txt), key(k), encryptedText(encTxt), cipherType(cipher) {}
};

#endif // ENCRYPTION_DATA_H