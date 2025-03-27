#pragma once
#include <string>

class EncryptedDocument {
public:
    EncryptedDocument(const std::string& originalText,
                    const std::string& cipherType,
                    int key,
                    const std::string& encryptedText = "");

    // Бізнес-методи
    bool isValid() const;
    void reencrypt(const std::string& newCipherType, int newKey);

    // Гетери
    std::string getOriginalText() const;
    std::string getEncryptedText() const;
    std::string getCipherType() const;
    int getKey() const;

private:
    std::string originalText;
    std::string encryptedText;
    std::string cipherType;
    int key;
};