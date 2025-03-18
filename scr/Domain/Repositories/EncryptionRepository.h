#ifndef ENCRYPTION_REPOSITORY_H
#define ENCRYPTION_REPOSITORY_H

#include "../../Data/Data.h"

namespace Encryption {

    class EncryptionRepository {
    public:
        virtual ~EncryptionRepository() = default;
        virtual void save(const Data::EncryptionData& data) = 0;
        virtual Data::EncryptionData get() = 0;
    };

    class InMemoryEncryptionRepository : public EncryptionRepository {
    public:
        InMemoryEncryptionRepository(); // Конструктор
        void save(const Data::EncryptionData& data) override;
        Data::EncryptionData get() override;

    private:
        Data::EncryptionData data;
    };

} // namespace Encryption

#endif // ENCRYPTION_REPOSITORY_H