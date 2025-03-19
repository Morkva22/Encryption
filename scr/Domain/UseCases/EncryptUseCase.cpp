#include "EncryptUseCase.h"
#include <iomanip>
#include <sstream>

namespace Encryption {

    EncryptUseCase::EncryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    std::string EncryptUseCase::encrypt(const Data::EncryptionData& data) { // Використовуємо Data::EncryptionData
        std::string key = keyProvider->getKey(data.algorithm);
        Cipher* cipher;
        switch (data.algorithm) {
        case 1:
            cipher = new CaesarCipher();
            break;
        case 2:
            cipher = new XorCipher();
            break;
        case 3:
            cipher = new AesCipher();
            break;
        default:
            return "Invalid algorithm";
        }

        std::string encryptedText = cipher->encrypt(data.text, key);
        delete cipher;
        return encryptedText;
    }

} // namespace Encryption