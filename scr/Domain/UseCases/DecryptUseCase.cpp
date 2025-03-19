#include "DecryptUseCase.h"

namespace Encryption {

    DecryptUseCase::DecryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    string DecryptUseCase::decrypt(const Data::EncryptionData& data) {
        string key = keyProvider->getKey(data.algorithm);
        unique_ptr<Cipher> cipher;
        switch (data.algorithm) {
        case 1:
            cipher = make_unique<CaesarCipher>();
            break;
        case 2:
            cipher = make_unique<XorCipher>();
            break;
        case 3:
            cipher = make_unique<AesCipher>();
            break;
        default:
            return "Invalid algorithm";
        }

        return cipher->decrypt(data.text, key);
    }

} // namespace EncryptionDecryptUseCase.cpp