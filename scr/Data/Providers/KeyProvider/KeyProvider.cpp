#include "KeyProvider.h"
#include <filesystem>
#include <fstream>
#include <stdexcept>

using namespace Encryption;
namespace fs = std::filesystem;

FileKeyProvider::FileKeyProvider() {
    if (!fs::exists("keys")) {
        fs::create_directory("keys");
    }

    createKeyFileIfNotExists("caesar.key", "1");
    createKeyFileIfNotExists("xor.key", "defaultxor");
    createKeyFileIfNotExists("aes.key", "defaultaes");
}

std::string FileKeyProvider::getKey(int algorithm) {
    std::string filename;

    switch (algorithm) {
    case 1: filename = "caesar.key"; break;
    case 2: filename = "xor.key"; break;
    case 3: filename = "aes.key"; break;
    default: throw std::invalid_argument("Invalid algorithm");
    }

    std::string filepath = "keys/" + filename;

    if (!fs::exists(filepath)) {
        throw std::runtime_error("Key file not found: " + filepath);
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open key file: " + filepath);
    }

    std::string key;
    std::getline(file, key);

    if (key.empty()) {
        throw std::runtime_error("Key file is empty: " + filepath);
    }

    if (algorithm == 1) {
        try {
            std::stoi(key);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Invalid key format for Caesar cipher: " + filepath);
        }
    }

    return key;
}

void FileKeyProvider::createKeyFileIfNotExists(const std::string& filename, const std::string& defaultKey) {
    std::string filepath = "keys/" + filename;

    if (!fs::exists(filepath)) {
        std::ofstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to create key file: " + filepath);
        }

        file << defaultKey;
    }
}