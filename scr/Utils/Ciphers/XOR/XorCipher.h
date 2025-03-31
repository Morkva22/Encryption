#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include <string>

class XorCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
    
    static std::string toPrintable(const std::string& data);
    static std::string toHex(const std::string& data);
    static std::string fromHex(const std::string& hex);
};

#endif // XOR_CIPHER_H