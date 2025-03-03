#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "lib.h"

namespace Caesar {
    class Cipher {
    private:
        int shift; // Зсув (ключ)

    public:
        // Конструктор (приймає зсув)
        Cipher(int shift);

        // Метод для шифрування тексту
        std::string encrypt(const std::string& text);

        // Метод для дешифрування тексту
        std::string decrypt(const std::string& text);
    };
}

#endif // CAESARCIPHER_H