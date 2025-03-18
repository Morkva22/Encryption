// scr/Domain/UseCases/DecryptUseCase.cpp

#include "DecryptUseCase.h"

namespace Encryption {

    DecryptUseCase::DecryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    string DecryptUseCase::decrypt(const Data::EncryptionData& data) { // Заміна execute на decrypt
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

        string decryptedText = cipher->decrypt(data.text, key);
        delete cipher;
        return decryptedText;
    }

} // namespace Encryption