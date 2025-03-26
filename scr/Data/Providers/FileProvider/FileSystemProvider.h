#ifndef FILE_SYSTEM_PROVIDER_H
#define FILE_SYSTEM_PROVIDER_H

#include "../../../lib/lib.h"

class FileSystemProvider {
public:
    virtual void saveEncryptionResult(const std::string& encryptedText) = 0;
    virtual void saveDecryptionResult(const std::string& decryptedText) = 0;
};

#endif // FILE_SYSTEM_PROVIDER_H
