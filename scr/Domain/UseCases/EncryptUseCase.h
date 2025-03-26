#ifndef ENCRYPT_USE_CASE_H
#define ENCRYPT_USE_CASE_H

#include "../Entities/EncryptionData.h"
#include "../../Utils/Ciphers/Cipher.h"
#include "../../lib/lib.h"
class EncryptUseCase {
public:
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    std::string execute(const EncryptionData& data);

private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
};

#endif // ENCRYPT_USE_CASE_H