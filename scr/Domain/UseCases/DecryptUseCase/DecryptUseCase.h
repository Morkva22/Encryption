#ifndef DECRYPT_USE_CASE_H
#define DECRYPT_USE_CASE_H

#include "../Entities/EncryptionData.h"
#include "../../Utils/Ciphers/Cipher.h"
#include "../../lib/lib.h"

class DecryptUseCase {
public:
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    std::string execute(const EncryptionData& data);

private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
};

#endif // DECRYPT_USE_CASE_H