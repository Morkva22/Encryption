// scr/Domain/UseCases/EncryptUseCase.cpp

#include "EncryptUseCase.h"
#include <iomanip>
#include <sstream>

namespace Encryption {

    EncryptUseCase::EncryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    string EncryptUseCase::execute(EncryptionData data) {
        string key = keyProvider->getKey(data.getAlgorithm());
        Cipher* cipher;
        switch (data.getAlgorithm()) {
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

        string encryptedText = cipher->encrypt(data.getText(), key);
        delete cipher;
        return encryptedText;
    }

} // namespace Encryption