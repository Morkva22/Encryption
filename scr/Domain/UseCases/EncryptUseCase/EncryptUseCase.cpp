#include "EncryptUseCase.h"

void EncryptUseCase::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

std::string EncryptUseCase::execute(const std::string& text, const std::string& cipherType, int key) {
    auto it = ciphers.find(cipherType);
    if (it == ciphers.end()) {
        throw std::runtime_error("Unsupported cipher type: " + cipherType);
    }
    return it->second->encrypt(text, std::to_string(key));
}