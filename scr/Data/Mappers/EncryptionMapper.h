// scr/Data/Mappers/EncryptionMapper.h

#ifndef ENCRYPTION_MAPPER_H
#define ENCRYPTION_MAPPER_H

#include "../../Data/"
#include "../../Domain/Entities/EncryptionData.h"

namespace Encryption {

    class EncryptionMapper {
    public:
        static EncryptionData mapToDomain(const Data::EncryptionData& data);
        static Data::EncryptionData mapToData(const EncryptionData& data);
    };

} // namespace Encryption

#endif