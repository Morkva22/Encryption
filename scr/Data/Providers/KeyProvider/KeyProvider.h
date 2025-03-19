#ifndef KEY_PROVIDER_H
#define KEY_PROVIDER_H

#include <string>

namespace Encryption {

    class FileKeyProvider {
    public:
        FileKeyProvider();
        std::string getKey(int algorithm);
    private:
        void createKeyFileIfNotExists(const std::string& filename, const std::string& defaultKey);
    };

} // namespace Encryption

#endif // KEY_PROVIDER_H