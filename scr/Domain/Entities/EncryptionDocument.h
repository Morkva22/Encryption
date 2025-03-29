#ifndef ENCRYPTED_DOCUMENT_H
#define ENCRYPTED_DOCUMENT_H

#include <string>

class EncryptedDocument {
public:
    EncryptedDocument(const std::string& originalText,
                     const std::string& cipherType,
                     int key,
                     const std::string& encryptedText = "");

    // Гетери
    std::string getOriginalText() const;
    std::string getEncryptedText() const;
    std::string getCipherType() const;
    int getKey() const;

    // Сетери
    void setEncryptedText(const std::string& encryptedText);

private:
    std::string originalText;
    std::string encryptedText;
    std::string cipherType;
    int key;
};

#endif // ENCRYPTED_DOCUMENT_H
