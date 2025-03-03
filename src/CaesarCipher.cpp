#include "../CaesarCipher.h"

namespace Caesar {
    // Конструктор
    Cipher::Cipher(int shift) : shift(shift) {}

    // Метод для шифрування тексту
    std::string Cipher::encrypt(const std::string& text) {
        std::string result;
        for (char ch : text) {
            if (isalpha(ch)) { // Перевіряємо, чи символ є літерою
                char base = islower(ch) ? 'a' : 'A'; // Визначаємо базовий символ (a або A)
                result += static_cast<char>((ch - base + shift) % 26 + base); // Шифруємо
            } else {
                result += ch; // Залишаємо інші символи без змін
            }
        }
        return result;
    }

    // Метод для дешифрування тексту
    std::string Cipher::decrypt(const std::string& text) {
        std::string result;
        for (char ch : text) {
            if (isalpha(ch)) { // Перевіряємо, чи символ є літерою
                char base = islower(ch) ? 'a' : 'A'; // Визначаємо базовий символ (a або A)
                result += static_cast<char>((ch - base - shift + 26) % 26 + base); // Дешифруємо
            } else {
                result += ch; // Залишаємо інші символи без змін
            }
        }
        return result;
    }
}