#include "CaesarCipher.h"

const vector<string> UKR_LETTERS = {
    "а","б","в","г","д","е","є","ж","з","и","і","ї","й","к","л","м","н",
    "о","п","р","с","т","у","ф","х","ц","ч","ш","щ","ь","ю","я"
};

string CaesarCipher::encrypt(const string& text, const string& key) {
    int shift = stoi(key);
    string result;
    
    for (size_t i = 0; i < text.size(); ) {
        if (i + 1 < text.size() && (text[i] & 0x80)) { 
            string symbol = text.substr(i, 2);
            auto it = find(UKR_LETTERS.begin(), UKR_LETTERS.end(), symbol);
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

string CaesarCipher::decrypt(const string& text, const string& key) {
    int shift = UKR_LETTERS.size() - (stoi(key) % UKR_LETTERS.size());
    return encrypt(text, to_string(shift));
}