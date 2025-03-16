#ifndef ENCRYPTION_REPOSITORY_H
#define ENCRYPTION_REPOSITORY_H

#include "../Entities/EncryptionData.h"

namespace Encryption {

    class EncryptionRepository {
    public:
        virtual ~EncryptionRepository() = default;
        virtual void save(const EncryptionData& data) = 0;
        virtual EncryptionData get() = 0;
    };

} // namespace Encryption

#endif