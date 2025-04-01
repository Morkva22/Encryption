#include "XorCipher.h"
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cctype>

using namespace std;

wstring_convert<codecvt_utf8_utf16<wchar_t>> XorCipher::converter;

wstring XorCipher::string_to_wstring(const string& str) {
    try {
        return converter.from_bytes(str);
    } catch (const range_error&) {
        throw runtime_error("Invalid UTF-8 sequence in input string");
    }
}

string XorCipher::wstring_to_string(const wstring& wstr) {
    try {
        return converter.to_bytes(wstr);
    } catch (const range_error&) {
        throw runtime_error("Invalid wide character in input string");
    }
}

string XorCipher::encrypt(const string& text, const string& key) {
    if (key.empty()) throw runtime_error("Encryption key cannot be empty");
    if (text.empty()) return "";
    
    try {
        wstring wtext = string_to_wstring(text);
        wstring wkey = string_to_wstring(key);
        wstring result;
        
        for (size_t i = 0; i < wtext.size(); ++i) {
            // Зберігаємо пробіли незмінними
            if (wtext[i] == L' ') {
                result += L' ';
            } else {
                result += wtext[i] ^ wkey[i % wkey.size()];
            }
        }
        
        return wstring_to_string(result);
    } catch (const exception& e) {
        throw runtime_error(string("XOR encryption failed: ") + e.what());
    }
}

string XorCipher::decrypt(const string& text, const string& key) {
    return encrypt(text, key); // XOR - симетричний алгоритм
}

string XorCipher::toPrintable(const string& data) {
    try {
        wstring wdata = string_to_wstring(data);
        string result;
        
        for (wchar_t c : wdata) {
            if (c == L' ' || (c >= 32 && c <= 126)) { // Пробіли та ASCII символи
                result += static_cast<char>(c);
            } else if (c >= 0x0400 && c <= 0x04FF) { // Кирилиця
                result += converter.to_bytes(c);
            } else {
                result += '_'; // Інші символи замінюємо на _
            }
        }
        return result;
    } catch (...) {
        // Резервний варіант для не UTF-8 даних
        string result;
        for (unsigned char c : data) {
            result += (c == ' ' || isalnum(c)) ? c : '_';
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
        result += static_cast<char>(stoul(byte, nullptr, 16));
    }
    return result;
}