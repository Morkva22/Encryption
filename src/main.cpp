#include "../include/CaesarCipher.h"
#include "../include/Logger.h"

int main() {
    Utils::Logger logger; // Створюємо Logger

    int shift = 3; // Зсув для шифру Цезаря
    Caesar::Cipher cipher(shift); // Створюємо об'єкт шифру Цезаря

    std::string text = "Hello, World!";
    logger.log("Original text: " + text, Utils::INFO);
    // Шифруємо текст
    std::string encrypted = cipher.encrypt(text);
    logger.log("Encrypted text: " + encrypted, Utils::INFO);
    // Дешифруємо текст
    std::string decrypted = cipher.decrypt(encrypted);
    logger.log("Decrypted text: " + decrypted, Utils::INFO);
    return 0;
}