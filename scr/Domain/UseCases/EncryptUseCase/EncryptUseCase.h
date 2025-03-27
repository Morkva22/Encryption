#ifndef ENCRYPT_USE_CASE_H
#define ENCRYPT_USE_CASE_H

#include <string>
#include <memory>
#include <map>
#include "../../../Utils/Ciphers/Cipher.h"

class EncryptUseCase {
public:
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    std::string execute(const std::string& text, const std::string& cipherType, int key);

private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
};

#endif // ENCRYPT_USE_CASE_H
