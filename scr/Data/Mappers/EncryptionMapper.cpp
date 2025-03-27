#include "EncryptionMapper.h"
#include <sstream>

EncryptionData EncryptionMapper::toDTO(const EncryptedDocument& doc) {
    return {
        doc.getOriginalText(),
        doc.getEncryptedText(),
        doc.getKey(),
        doc.getCipherType()
    };
}

EncryptedDocument EncryptionMapper::toDomain(const EncryptionData& dto) {
    return EncryptedDocument(
        dto.text,
        dto.cipherType,
        dto.key,
        dto.encryptedText
    );
}

std::string EncryptionMapper::toStorageString(const EncryptionData& dto) {
    std::ostringstream oss;
    oss << dto.text << "|" << dto.encryptedText << "|" 
        << dto.key << "|" << dto.cipherType;
    return oss.str();
}

EncryptionData EncryptionMapper::fromStorageString(const std::string& raw) {
    std::istringstream iss(raw);
    EncryptionData dto;
    std::string token;

    std::getline(iss, dto.text, '|');
    std::getline(iss, dto.encryptedText, '|');
    std::getline(iss, token, '|');
    dto.key = std::stoi(token);
    std::getline(iss, dto.cipherType, '|');

    return dto;
}