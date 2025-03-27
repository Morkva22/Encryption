#include "DecryptUseCase.h"

void DecryptUseCase::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

std::string DecryptUseCase::execute(const std::string& encryptedText, const std::string& cipherType, int key) {
    auto it = ciphers.find(cipherType);
    if (it == ciphers.end()) {
        throw std::runtime_error("Unsupported cipher type: " + cipherType);
    }
    return it->second->decrypt(encryptedText, std::to_string(key));
}