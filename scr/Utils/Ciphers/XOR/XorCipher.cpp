#include "XorCipher.h"
#include "../../../lib/lib.h"
namespace Encryption {

    string XorCipher::encrypt(const string& text, const string& key) {
        stringstream result;
        int keyLength = key.length();
        for (size_t i = 0; i < text.length(); ++i) {
            result << hex << setw(2) << setfill('0') << static_cast<int>(text[i] ^ key[i % keyLength]);
        }
        return result.str();
    }

    string XorCipher::decrypt(const string& text, const string& key) {
        string result = "";
        int keyLength = key.length();
        for (size_t i = 0; i < text.length(); i += 2) {
            stringstream ss;
            ss << hex << text.substr(i, 2);
            int byte;
            ss >> byte;
            result += static_cast<char>(byte ^ key[(i / 2) % keyLength]);
        }
        return result;
    }

} // namespace Encryption