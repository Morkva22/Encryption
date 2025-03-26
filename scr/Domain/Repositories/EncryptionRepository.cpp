#include "EncryptionRepository.h"
#include "../../Data/Mappers/EncryptionMapper.h"

EncryptionRepository::EncryptionRepository(const std::string& filename) 
    : filename(filename) {
    std::ifstream testFile(filename);
    if (!testFile.good()) {
        std::ofstream createFile(filename);
        if (!createFile) throw std::runtime_error("Cannot create file");
    }
}

void EncryptionRepository::save(const EncryptionData& data) const
{
    std::ofstream file(filename, std::ios::app);
    if (!file) throw std::runtime_error("Cannot open file");
    file << EncryptionMapper::toStorageFormat(data) << "\n";
}

std::vector<EncryptionData> EncryptionRepository::loadAll() const {
    std::vector<EncryptionData> result;
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file");
    
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            result.push_back(EncryptionMapper::fromStorageFormat(line));
        }
    }
    return result;
}