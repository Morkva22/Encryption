// scr/Data/Providers/KeyProvider.cpp

#include "KeyProvider.h"
#include <fstream>

namespace Encryption {

    string FileKeyProvider::getKey(int algorithm) {
        string filename;
        switch (algorithm) {
        case 1:
            filename = "caesar.key";
            break;
        case 2:
            filename = "xor.key";
            break;
        case 3:
            filename = "aes.key";
            break;
        default:
            return "";
        }
        ifstream file("keys/" + filename);
        if (file.is_open()) {
            string key;
            getline(file, key);
            return key;
        }
        return "";
    }

} // namespace Encryption