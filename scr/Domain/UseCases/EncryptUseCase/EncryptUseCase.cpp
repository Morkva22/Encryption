#include "EncryptUseCase.h"

void EncryptUseCase::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

std::string EncryptUseCase::execute(const EncryptionData& data) {
    auto it = ciphers.find(data.cipherType);
    if (it != ciphers.end()) {
        return it->second->encrypt(data.text, std::to_string(data.key));
    }
    throw std::runtime_error("Unsupported cipher type: " + data.cipherType);
}