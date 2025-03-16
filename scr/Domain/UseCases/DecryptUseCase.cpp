// scr/Domain/UseCases/DecryptUseCase.cpp

#include "DecryptUseCase.h"

namespace Encryption {

    DecryptUseCase::DecryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    string DecryptUseCase::execute(EncryptionData data) {
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

        string decryptedText = cipher->decrypt(data.getText(), key);
        delete cipher;
        return decryptedText;
    }

} // namespace Encryption