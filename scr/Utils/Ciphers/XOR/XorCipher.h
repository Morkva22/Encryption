#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include "../../../lib/lib.h"


class XorCipher : public Cipher {
public:
    string encrypt(const string& text, const string& key) override;
    string decrypt(const string& text, const string& key) override;
    static string toPrintable(const string& data);
    static string toHex(const string& data);
    static string fromHex(const string& hex);
};

#endif