#ifndef FILE_STORAGE_ADAPTER_H
#define FILE_STORAGE_ADAPTER_H

#include "../../Domain/Repositories/Repository.h"
#include "../../Data/Mappers/EncryptionMapper.h"
#include <string>
#include <vector>

class FileStorageAdapter : public Repository {
public:
    explicit FileStorageAdapter(const std::string& filePath);
    void save(const EncryptedDocument& document) override;
    std::vector<EncryptedDocument> loadAll() override;
    std::string getFilePath() const override;

    // Додано нові методи для роботи з файлами
    std::vector<std::string> readLines(const std::string& filePath);
    void writeLines(const std::string& filePath, const std::vector<std::string>& lines);
    void deleteFile(const std::string& filePath);
    bool fileExists(const std::string& filePath) const;

private:
    std::string filePath;
    void ensureFileExists() const;
};

#endif // FILE_STORAGE_ADAPTER_H