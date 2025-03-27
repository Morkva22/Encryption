#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../Entities/EncryptionDocument.h"
#include <vector>
#include <memory>

class Repository {
public:
    virtual ~Repository() = default;
    virtual void save(const EncryptedDocument& document) = 0;
    virtual std::vector<EncryptedDocument> loadAll() = 0;
    virtual std::string getFilePath() const = 0;
};

#endif // REPOSITORY_H