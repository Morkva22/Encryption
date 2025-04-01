#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include <string>
#include <locale>
#include <codecvt>

class XorCipher : public Cipher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
    
    static std::string toPrintable(const std::string& data);
    static std::string toHex(const std::string& data);
    static std::string fromHex(const std::string& hex);

private:
    static std::wstring string_to_wstring(const std::string& str);
    static std::string wstring_to_string(const std::wstring& wstr);
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
};

#endif 