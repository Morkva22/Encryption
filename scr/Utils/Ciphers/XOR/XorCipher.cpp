#include "XorCipher.h"
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <locale>
#include <codecvt>

using namespace std;

// Конвертація між string та wstring
static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

wstring string_to_wstring(const string& str) {
    return converter.from_bytes(str);
}

string wstring_to_string(const wstring& wstr) {
    return converter.to_bytes(wstr);
}

string XorCipher::encrypt(const string& text, const string& key) {
    if (key.empty()) throw runtime_error("Encryption key cannot be empty");
    
    wstring wtext = string_to_wstring(text);
    wstring wkey = string_to_wstring(key);
    wstring result;
    
    for (size_t i = 0; i < wtext.size(); ++i) {
        wchar_t encrypted = wtext[i] ^ wkey[i % wkey.size()];
        result += encrypted;
    }
    
    return wstring_to_string(result);
}

string XorCipher::decrypt(const string& text, const string& key) {
    return encrypt(text, key); // XOR - симетричний алгоритм
}

string XorCipher::toPrintable(const string& data) {
    try {
        wstring wdata = string_to_wstring(data);
        string result;
        
        for (wchar_t c : wdata) {
            if (c >= 32 && c <= 126) { // ASCII символи
                result += static_cast<char>(c);
            } else {
                // Для кирилиці та інших Unicode
                wstring ws(1, c);
                result += converter.to_bytes(ws);
            }
        }
        return result;
    } catch (...) {
        string result;
        for (unsigned char c : data) {
            result += static_cast<char>(c);
        }
        return result;
    }
}

string XorCipher::toHex(const string& data) {
    ostringstream oss;
    for (unsigned char c : data) {
        oss << hex << setw(2) << setfill('0') << static_cast<int>(c);
    }
    return oss.str();
}

string XorCipher::fromHex(const string& hex) {
    string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byte = hex.substr(i, 2);
        result += static_cast<char>(stoi(byte, nullptr, 16));
    }
    return result;
}