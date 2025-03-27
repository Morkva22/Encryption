#include "FileStorageAdapter.h"
#include "../../Data/Mappers/EncryptionMapper.h"
#include <fstream>

FileStorageAdapter::FileStorageAdapter(const std::string& filePath) 
    : filePath(filePath) {
    ensureFileExists();
}

void FileStorageAdapter::save(const EncryptedDocument& document) {
    auto dto = EncryptionMapper::toDTO(document);
    std::ofstream file(filePath, std::ios::app);
    if (!file) throw std::runtime_error("Failed to open file");
    file << EncryptionMapper::toStorageString(dto) << "\n";
}

std::vector<EncryptedDocument> FileStorageAdapter::loadAll() {
    std::ifstream file(filePath);
    if (!file) throw std::runtime_error("Failed to open file");

    std::vector<EncryptedDocument> documents;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            auto dto = EncryptionMapper::fromStorageString(line);
            documents.push_back(EncryptionMapper::toDomain(dto));
        }
    }
    return documents;
}

std::string FileStorageAdapter::getFilePath() const {
    return filePath;
}

void FileStorageAdapter::ensureFileExists() const {
    std::ifstream test(filePath);
    if (!test) {
        std::ofstream create(filePath);
        if (!create) throw std::runtime_error("Failed to create file");
    }
}