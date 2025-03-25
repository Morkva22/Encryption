#ifndef ENCRYPTION_REPOSITORY_H
#define ENCRYPTION_REPOSITORY_H

#include "../Entities/EncryptionData.h"

namespace Encryption {

    class EncryptionRepository {
    public:
        virtual ~EncryptionRepository() = default;
        virtual void save(const EncryptionData& newData) = 0; 
        virtual EncryptionData get() = 0;
    };

    class InMemoryEncryptionRepository : public EncryptionRepository {
    public:
        InMemoryEncryptionRepository();  
        void save(const EncryptionData& newData) override; 
        EncryptionData get() override;

    private:
        EncryptionData data;
    };

} 

#endif