#include "EncryptionRepository.h"

using namespace Encryption;

InMemoryEncryptionRepository::InMemoryEncryptionRepository() 
    : data{"", "", 0} {
}

void InMemoryEncryptionRepository::save(const Data::EncryptionData& data) {
    this->data = data;
}

Data::EncryptionData InMemoryEncryptionRepository::get() {
    return data;
}