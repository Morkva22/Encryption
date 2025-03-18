// scr/Domain/UseCases/EncryptUseCase.cpp

#include "EncryptUseCase.h"
#include <iomanip>
#include <sstream>

namespace Encryption {

    EncryptUseCase::EncryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    string EncryptUseCase::encrypt(const Data::EncryptionData& data) { // Заміна execute на encrypt
        string key = keyProvider->getKey(data.algorithm);
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

        string encryptedText = cipher->encrypt(data.text, key);
        delete cipher;
        return encryptedText;
    }

} // namespace Encryption