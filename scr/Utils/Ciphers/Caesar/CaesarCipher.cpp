#include "CaesarCipher.h"
int CaesarCipher::parseKey(const std::string& key) const {
    if (key.empty()) {
        throw std::invalid_argument("Caesar cipher key cannot be empty");
    }
    
    try {
        return std::stoi(key);
    } catch (const std::exception&) {
        throw std::invalid_argument("Caesar cipher key must be a valid integer");
    }
}

char CaesarCipher::shiftChar(char c, int shift) const {
    if (!isalpha(c)) {
        return c;
    }
    
    // Нормалізація зсуву
    shift %= 26;
    if (shift < 0) {
        shift += 26;
    }
    
    char base = isupper(c) ? 'A' : 'a';
    return (c - base + shift) % 26 + base;
}

std::string CaesarCipher::encrypt(const std::string& text, const std::string& key) {
    int shift = parseKey(key);
    
    if (text.empty()) {
        return "";
    }

    std::string result;
    result.reserve(text.size());
    
    for (char c : text) {
        result += shiftChar(c, shift);
    }
    
    return result;
}

std::string CaesarCipher::decrypt(const std::string& text, const std::string& key) {
    int shift = parseKey(key);
    return encrypt(text, std::to_string(-shift)); // Інвертуємо зсув
}