// scr/Utils/Ciphers/XOR/XorCipher.h

#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"

namespace Encryption {

    class XorCipher : public Cipher {
    public:
        string encrypt(const string& text, const string& key) override;
        string decrypt(const string& text, const string& key) override;
    };

} // namespace Encryption

#endif