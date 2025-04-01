#include "XorCipher.h"

string XorCipher::encrypt(const string& text, const string& key) {
    if (key.empty()) throw runtime_error("Encryption key cannot be empty");
    
    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            result += ' ';
        } else {
            result += text[i] ^ key[i % key.size()];
        }
    }
    return result;
}

string XorCipher::decrypt(const string& text, const string& key) {
    return encrypt(text, key);
}

string XorCipher::toPrintable(const string& data) {
    string result;
    for (unsigned char c : data) {
        if (c == ' ' || isalnum(c)) {
            result += c;
        } else {
            result += '_';
        }
    }
    return result;
}

string XorCipher::toHex(const string& data) {
    ostringstream oss;
    for (unsigned char c : data) {
        if (c == ' ') {
            oss << ' ';
        } else {
            oss << hex << setw(2) << setfill('0') << static_cast<int>(c);
        }
    }
    return oss.str();
}

string XorCipher::fromHex(const string& hex) {
    string result;
    for (size_t i = 0; i < hex.length(); ) {
        if (hex[i] == ' ') {
            result += ' ';
            i++;
        } else {
            string byte = hex.substr(i, 2);
            result += static_cast<char>(stoul(byte, nullptr, 16));
            i += 2;
        }
    }
    return result;
}