#include "EncryptionDocument.h"

EncryptedDocument::EncryptedDocument(const std::string& originalText,
                                   const std::string& cipherType,
                                   int key,
                                   const std::string& encryptedText)
    : originalText(originalText),
      cipherType(cipherType),
      key(key),
      encryptedText(encryptedText) {}

// Гетери
std::string EncryptedDocument::getOriginalText() const {
    return originalText;
}

std::string EncryptedDocument::getEncryptedText() const {
    return encryptedText;
}

std::string EncryptedDocument::getCipherType() const {
    return cipherType;
}

int EncryptedDocument::getKey() const {
    return key;
}

// Сетери
void EncryptedDocument::setEncryptedText(const std::string& encryptedText) {
    this->encryptedText = encryptedText;
}