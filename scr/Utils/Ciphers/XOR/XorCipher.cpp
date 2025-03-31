#include "XorCipher.h"
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <locale>
#include <codecvt>

std::string XorCipher::encrypt(const std::string& text, const std::string& key) {
    if (key.empty()) throw std::runtime_error("Encryption key cannot be empty");
    
    // Конвертуємо вхідний текст у UTF-16 для коректної обробки Unicode
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wideText = converter.from_bytes(text);
    std::wstring wideKey = converter.from_bytes(key);
    
    std::wstring result;
    result.reserve(wideText.size());
    
    for (size_t i = 0; i < wideText.size(); ++i) {
        result += wideText[i] ^ wideKey[i % wideKey.size()];
    }
    
    // Конвертуємо результат назад у UTF-8
    return converter.to_bytes(result);
}

std::string XorCipher::decrypt(const std::string& text, const std::string& key) {
    return encrypt(text, key); // XOR - симетричний алгоритм
}

std::string XorCipher::toPrintable(const std::string& data) {
    try {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(data);
        
        std::ostringstream oss;
        for (wchar_t c : wide) {
            if (c >= 32 && c <= 126) { // Друковані ASCII символи
                oss << (char)c;
            } else {
                oss << "\\u" << std::hex << std::setw(4) << std::setfill('0') << (int)c;
            }
        }
        return oss.str();
    } catch (...) {
        // Якщо конвертація не вдалася, повертаємо hex-представлення
        std::ostringstream oss;
        for (unsigned char c : data) {
            oss << "\\x" << std::hex << std::setw(2) << std::setfill('0') << (int)c;
        }
        return oss.str();
    }
}

std::string XorCipher::toHex(const std::string& data) {
    std::ostringstream oss;
    for (unsigned char c : data) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return oss.str();
}

std::string XorCipher::fromHex(const std::string& hex) {
    std::string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2);
        result += static_cast<char>(std::stoi(byte, nullptr, 16));
    }
    return result;
}