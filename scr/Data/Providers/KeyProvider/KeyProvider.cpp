
#include "KeyProvider.h"
#include <fstream>

namespace Encryption {

    class FileKeyProvider : public KeyProvider {
    public:
        string getKey(int algorithm) override {
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
    };

} // namespace Encryption