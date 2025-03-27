#ifndef DECRYPT_USE_CASE_H
#define DECRYPT_USE_CASE_H

#include <string>
#include <memory>
#include <map>
#include "../../../Utils/Ciphers/Cipher.h"

class DecryptUseCase {
public:
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    std::string execute(const std::string& encryptedText, const std::string& cipherType, int key);

private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
};

#endif // DECRYPT_USE_CASE_H