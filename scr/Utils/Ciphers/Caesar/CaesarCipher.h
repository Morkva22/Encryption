#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "../Cipher.h"

namespace Encryption {

    class CaesarCipher : public Cipher {
    public:
        string encrypt(const string& text, const string& key) override;
        string decrypt(const string& text, const string& key) override;
    };

} // namespace Encryption

#endif