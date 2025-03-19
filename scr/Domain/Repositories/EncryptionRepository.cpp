#include "EncryptionRepository.h"

namespace Encryption {

    InMemoryEncryptionRepository::InMemoryEncryptionRepository() : data() {}

    void InMemoryEncryptionRepository::save(const Data::EncryptionData& data) {
        this->data = data;
    }

    Data::EncryptionData InMemoryEncryptionRepository::get() {
        return data;
    }

} // namespace Encryption