// scr/Data/Providers/FileSystemProvider.h

#ifndef FILE_SYSTEM_PROVIDER_H
#define FILE_SYSTEM_PROVIDER_H

#include "../../../lib/lib.h"

namespace Encryption {

    class FileSystemProvider {
    public:
        virtual ~FileSystemProvider() = default;
        virtual string readFile(const string& filename) = 0;
        virtual void writeFile(const string& filename, const string& content) = 0;
    };

} // namespace Encryption

#endif