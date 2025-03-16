// scr/Utils/Ciphers/AES/AesCipher.h

#ifndef AES_CIPHER_H
#define AES_CIPHER_H

#include "../Cipher.h"

namespace Encryption {

    class AesCipher : public Cipher {
    public:
        string encrypt(const string& text, const string& key) override;
        string decrypt(const string& text, const string& key) override;
    };

} // namespace Encryption

#endif