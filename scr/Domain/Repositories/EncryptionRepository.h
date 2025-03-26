#ifndef ENCRYPTION_REPOSITORY_H
#define ENCRYPTION_REPOSITORY_H

#include "../Entities/EncryptionData.h"
#include "../../lib/lib.h"

class EncryptionRepository {
public:
    explicit EncryptionRepository(const std::string& filename);
    void save(const EncryptionData& data) const;
    std::vector<EncryptionData> loadAll() const;

private:
    std::string filename;
    void ensureFileExists() const;
};

#endif // ENCRYPTION_REPOSITORY_H