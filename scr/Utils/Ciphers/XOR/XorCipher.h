#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include "../../../lib/lib.h"
class XorCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
    
private:
    void validateKey(const std::string& key) const;
    std::string process(const std::string& text, const std::string& key) const;
};

#endif // XOR_CIPHER_H