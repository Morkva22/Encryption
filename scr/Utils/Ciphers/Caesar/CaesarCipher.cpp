// scr/Utils/Ciphers/Caesar/CaesarCipher.cpp

#include "CaesarCipher.h"

namespace Encryption {

    string CaesarCipher::encrypt(const string& text, const string& key) {
        int shift = stoi(key);
        string result = "";
        for (char c : text) {
            if (isalpha(c)) {
                char base = islower(c) ? 'a' : 'A';
                result += (c - base + shift) % 26 + base;
            } else {
                result += c;
            }
        }
        return result;
    }

    string CaesarCipher::decrypt(const string& text, const string& key) {
        int shift = stoi(key);
        return encrypt(text, to_string(26 - shift));
    }

} // namespace Encryption