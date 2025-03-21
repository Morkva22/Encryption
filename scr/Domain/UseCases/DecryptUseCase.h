#ifndef DECRYPT_USE_CASE_H
#define DECRYPT_USE_CASE_H

#include "../Repositories/EncryptionRepository.h"
#include "../../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../../Utils/Ciphers/XOR/XorCipher.h"
#include "../../Utils/Ciphers/AES/AesCipher.h"
#include "../../Data/Providers/KeyProvider/KeyProvider.h"
#include "../../Data/Data.h"

namespace Encryption {

    class DecryptUseCase {
    public:
        DecryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider);
        string decrypt(const Data::EncryptionData& data);

    private:
        EncryptionRepository* repository;
        KeyProvider* keyProvider;
    };

} // namespace Encryption

#endif