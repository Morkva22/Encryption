#include "EncryptionMapper.h"

std::string EncryptionMapper::toStorageFormat(const EncryptionData& data) {
    std::ostringstream oss;
    oss << data.text << "|"
        << data.encryptedText << "|"
        << data.key << "|"
        << data.cipherType;
    return oss.str();
}

EncryptionData EncryptionMapper::fromStorageFormat(const std::string& storageString) {
    istringstream iss(storageString);
    EncryptionData data;
    string token;
    
    getline(iss, data.text, '|');
    getline(iss, data.encryptedText, '|');
    
    getline(iss, token, '|');
    data.key = std::stoi(token);
    
    getline(iss, data.cipherType, '|');
    
    return data;
}