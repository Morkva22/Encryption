#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "../Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
};

#endif