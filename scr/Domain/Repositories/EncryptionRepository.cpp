// scr/Domain/Repositories/EncryptionRepository.cpp

#include "EncryptionRepository.h"

namespace Encryption {

    InMemoryEncryptionRepository::InMemoryEncryptionRepository() {} // Виправлення конструктора

    void InMemoryEncryptionRepository::save(const EncryptionData& data) {
        this->data = data;
    }

    EncryptionData InMemoryEncryptionRepository::get() {
        return data;
    }

} // namespace Encryption