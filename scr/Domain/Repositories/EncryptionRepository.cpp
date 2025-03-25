#include "EncryptionRepository.h"

namespace Encryption {

    InMemoryEncryptionRepository::InMemoryEncryptionRepository()
        : data("", "", 0) {}  
    void InMemoryEncryptionRepository::save(const EncryptionData& newData) {
        data = newData;  
    }

    EncryptionData InMemoryEncryptionRepository::get() {
        return data;  
    }

} 