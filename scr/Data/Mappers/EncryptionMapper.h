#ifndef _ENCRYPTIONMAPPER_H
#define _ENCRYPTIONMAPPER_H

#include "../DTO/EncryptionData.h"
#include "../../Domain/Entities/EncryptionDocument.h"
#include "../../lib/lib.h"

class EncryptionMapper {
public:
    static EncryptionData toDTO(const EncryptedDocument& document);
    static EncryptedDocument toDomain(const EncryptionData& dto);
    static std::string toStorageString(const EncryptionData& dto);
    static EncryptionData fromStorageString(const std::string& raw);
};

#endif // _ENCRYPTIONMAPPER_H
