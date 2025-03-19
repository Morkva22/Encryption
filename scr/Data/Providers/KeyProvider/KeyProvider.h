#ifndef FILE_KEY_PROVIDER_H
#define FILE_KEY_PROVIDER_H

#include <string>

namespace Encryption {

    class FileKeyProvider {
    public:
        FileKeyProvider();
        std::string getKey(int algorithm);

    private:
        void createKeyFileIfNotExists(const std::string& filename);
    };

} // namespace Encryption

#endif // FILE_KEY_PROVIDER_H