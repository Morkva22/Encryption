#ifndef FILE_STORAGE_ADAPTER_H
#define FILE_STORAGE_ADAPTER_H

#include "../../Domain/Repositories/Repository.h"
#include <string>

class FileStorageAdapter : public Repository {
public:
    explicit FileStorageAdapter(const std::string& filePath);
    void save(const EncryptedDocument& document) override;
    std::vector<EncryptedDocument> loadAll() override;
    std::string getFilePath() const override;

private:
    std::string filePath;
    void ensureFileExists() const;
};

#endif // FILE_STORAGE_ADAPTER_H