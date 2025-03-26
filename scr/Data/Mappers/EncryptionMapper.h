#ifndef ENCRYPTION_MAPPER_H
#define ENCRYPTION_MAPPER_H

#include "../../Domain/Entities/EncryptionData.h"
#include "../../lib/lib.h"
class EncryptionMapper {
public:
    static std::string toStorageFormat(const EncryptionData& data);
    static EncryptionData fromStorageFormat(const std::string& storageString);
};

#endif // ENCRYPTION_MAPPER_H