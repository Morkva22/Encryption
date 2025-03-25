#ifndef ENCRYPT_USE_CASE_H
#define ENCRYPT_USE_CASE_H

#include "../Repositories/EncryptionRepository.h"
#include "../../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../../Utils/Ciphers/XOR/XorCipher.h"
#include "../../Data/Providers/KeyProvider/KeyProvider.h"
#include "../../Data/Data.h"

namespace Encryption {

    class EncryptUseCase {
    public:
        EncryptUseCase(EncryptionRepository* repository, KeyProvider* keyProvider);
        string encrypt(const Data::EncryptionData& data);

    private:
        EncryptionRepository* repository;
        KeyProvider* keyProvider;
    };

} // namespace Encryption

#endif