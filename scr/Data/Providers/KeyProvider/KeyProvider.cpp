#include "KeyProvider.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace Encryption;

KeyProvider::KeyProvider() {
    std::string folderPath = "keys";

    // Створюємо папку, якщо її немає (кросплатформний спосіб)
    #ifdef _WIN32
        system(("mkdir " + folderPath).c_str());
    #else
        system(("mkdir -p " + folderPath).c_str());
    #endif

    // Створюємо файли з ключами, якщо вони відсутні
    createKeyFileIfNotExists("caesar.key", "3");       // Дефолтний ключ для Caesar
    createKeyFileIfNotExists("xor.key", "defaultxor"); // Дефолтний ключ для XOR
}

std::string KeyProvider::getKey(int algorithm) {
    std::string filename;

    // Визначаємо ім'я файлу за алгоритмом
    switch (algorithm) {
        case 1: filename = "caesar.key"; break;
        case 2: filename = "xor.key"; break;
        default: throw std::invalid_argument("Invalid algorithm");
    }

    // Повний шлях до файлу
    std::string filepath = "keys/" + filename;

    // Перевіряємо, чи існує файл
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Key file not found: " + filepath);
    }

    // Зчитуємо ключ з файлу
    std::string key;
    std::getline(file, key);

    // Перевіряємо, чи ключ не порожній
    if (key.empty()) {
        throw std::runtime_error("Key file is empty: " + filepath);
    }

    // Для Caesar cipher перевіряємо, чи ключ є числом
    if (algorithm == 1) {
        try {
            std::stoi(key); // Перевіряємо, чи ключ є числом
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Invalid key format for Caesar cipher: " + filepath);
        }
    }

    return key;
}

void KeyProvider::createKeyFileIfNotExists(const std::string& filename, const std::string& defaultKey) {
    std::string filepath = "keys/" + filename;

    // Перевіряємо, чи існує файл
    std::ifstream file(filepath);
    if (!file.good()) {
        std::ofstream outFile(filepath);
        if (outFile.is_open()) {
            outFile << defaultKey; // Записуємо дефолтний ключ
            outFile.close();
        } else {
            throw std::runtime_error("Failed to create key file: " + filepath);
        }
    }
}