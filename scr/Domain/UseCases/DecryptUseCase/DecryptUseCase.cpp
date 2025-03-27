#include "DecryptUseCase.h"

void DecryptUseCase::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

std::string DecryptUseCase::execute(const EncryptionData& data) {
    auto it = ciphers.find(data.cipherType);
    if (it != ciphers.end()) {
        return it->second->decrypt(data.encryptedText, std::to_string(data.key));
    }
    throw std::runtime_error("Unsupported cipher type: " + data.cipherType);
}