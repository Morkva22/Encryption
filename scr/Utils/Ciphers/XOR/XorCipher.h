#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include <string>
#include <locale>
#include <codecvt>

class XorCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
    
    static std::string toPrintable(const std::string& data);
    static std::string toHex(const std::string& data);  // Оголошення методу
    static std::string fromHex(const std::string& hex); // Оголошення методу
};

#endif // XOR_CIPHER_H