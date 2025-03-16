// scr/Data/Providers/FileSystemProvider.cpp

#include "FileSystemProvider.h"

namespace Encryption {

    class ConcreteFileSystemProvider : public FileSystemProvider {
    public:
        string readFile(const string& filename) override {
            ifstream file(filename);
            if (file.is_open()) {
                string content((istreambuf_iterator<char>(file)),
                                 (istreambuf_iterator<char>()));
                return content;
            }
            return "";
        }

        void writeFile(const string& filename, const string& content) override {
            ofstream file(filename);
            if (file.is_open()) {
                file << content;
            }
        }
    };

} // namespace Encryption