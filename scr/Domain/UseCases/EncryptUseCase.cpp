#include "EncryptUseCase.h"
#include <memory> // Для std::unique_ptr

namespace Encryption {

    EncryptUseCase::EncryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider)
        : repository(repository), keyProvider(keyProvider) {}

    std::string EncryptUseCase::encrypt(const Data::EncryptionData& data) {
        std::string key = keyProvider->getKey(data.algorithm);
        std::unique_ptr<Cipher> cipher;

        switch (data.algorithm) {
        case 1:
            cipher = std::make_unique<CaesarCipher>();
            break;
        case 2:
            cipher = std::make_unique<XorCipher>();
            break;
        default:
            return "Invalid algorithm";
        }

        return cipher->encrypt(data.text, key);
    }

} // namespace Encryption