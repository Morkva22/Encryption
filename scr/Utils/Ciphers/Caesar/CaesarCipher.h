#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "../Cipher.h"
#include "../../..//lib/lib.h"

class CaesarCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
    
private:
    int parseKey(const std::string& key) const;
    char shiftChar(char c, int shift) const;
};

#endif // CAESAR_CIPHER_H