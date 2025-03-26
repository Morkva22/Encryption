#include "XorCipher.h"
#include <algorithm>

void XorCipher::validateKey(const std::string& key) const {
    if (key.empty()) {
        throw std::invalid_argument("XOR key cannot be empty");
    }
    
    if (std::all_of(key.begin(), key.end(), [](char c) { 
        return c == '\0' || c == ' '; 
    })) {
        throw std::invalid_argument("XOR key cannot consist of only spaces or null characters");
    }
}

std::string XorCipher::process(const std::string& text, const std::string& key) const {
    validateKey(key);
    
    if (text.empty()) {
        return "";
    }

    std::string result;
    result.reserve(text.size());
    
    for (size_t i = 0; i < text.size(); ++i) {
        char encryptedChar = text[i] ^ key[i % key.size()];
        
        // Перевірка на недрукувані символи (крім пробілу)
        if (encryptedChar != ' ' && (encryptedChar < 32 || encryptedChar > 126)) {
            throw std::runtime_error(
                "XOR operation produced non-printable character (code: " + 
                std::to_string(static_cast<int>(encryptedChar)) + ")");
        }
        
        result += encryptedChar;
    }
    
    return result;
}

std::string XorCipher::encrypt(const std::string& text, const std::string& key) {
    return process(text, key);
}

std::string XorCipher::decrypt(const std::string& text, const std::string& key) {
    return process(text, key); // XOR симетричний
}