#include "XorCipher.h"

namespace Encryption {

    string XorCipher::encrypt(const string& text, const string& key) {
        string result = "";
        for (size_t i = 0; i < text.length(); ++i) {
            result += text[i] ^ key[i % key.length()];
        }
        return result;
    }

    string XorCipher::decrypt(const string& text, const string& key) {
        return encrypt(text, key);
    }

} // namespace Encryption