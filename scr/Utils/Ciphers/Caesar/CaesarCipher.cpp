#include "CaesarCipher.h"
#include <vector>
#include <algorithm>

const std::vector<std::string> UKR_LETTERS = {
    "а","б","в","г","д","е","є","ж","з","и","і","ї","й","к","л","м","н",
    "о","п","р","с","т","у","ф","х","ц","ч","ш","щ","ь","ю","я"
};

std::string CaesarCipher::encrypt(const std::string& text, const std::string& key) {
    int shift = std::stoi(key);
    std::string result;
    
    for (size_t i = 0; i < text.size(); ) {
        if (i + 1 < text.size() && (text[i] & 0x80)) { 
            std::string symbol = text.substr(i, 2);
            auto it = std::find(UKR_LETTERS.begin(), UKR_LETTERS.end(), symbol);
            if (it != UKR_LETTERS.end()) {
                size_t pos = (it - UKR_LETTERS.begin() + shift) % UKR_LETTERS.size();
                result += UKR_LETTERS[pos];
                i += 2;
                continue;
            }
        }
        result += text[i++];
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string& text, const std::string& key) {
    int shift = UKR_LETTERS.size() - (std::stoi(key) % UKR_LETTERS.size());
    return encrypt(text, std::to_string(shift));
}