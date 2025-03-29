#include "FileStorageAdapter.h"
#include <fstream>
#include <stdexcept>

FileStorageAdapter::FileStorageAdapter(const std::string& filePath) 
    : filePath(filePath) {
    ensureFileExists();
}

void FileStorageAdapter::ensureFileExists() const {
    std::ifstream test(filePath.c_str());
    if (!test) {
        std::ofstream create(filePath.c_str());
        if (!create) throw std::runtime_error("Failed to create file");
    }
}

void FileStorageAdapter::save(const EncryptedDocument& document) {
    auto dto = EncryptionMapper::toDTO(document);
    std::ofstream file(filePath.c_str(), std::ios::app);
    if (!file) throw std::runtime_error("Failed to open file");
    file << EncryptionMapper::toStorageString(dto) << "\n";
}

std::vector<EncryptedDocument> FileStorageAdapter::loadAll() {
    std::ifstream file(filePath.c_str());
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

std::vector<std::string> FileStorageAdapter::readLines(const std::string& filePath) {
    std::ifstream file(filePath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

void FileStorageAdapter::writeLines(const std::string& filePath, const std::vector<std::string>& lines) {
    std::ofstream file(filePath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filePath);
    }

    for (const auto& line : lines) {
        file << line << "\n";
    }
}

void FileStorageAdapter::deleteFile(const std::string& filePath) {
    if (remove(filePath.c_str()) != 0) {
        throw std::runtime_error("Failed to delete file: " + filePath);
    }
}

bool FileStorageAdapter::fileExists(const std::string& filePath) const {
    std::ifstream file(filePath.c_str());
    return file.good();
}