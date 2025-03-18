// scr/Utils/Ciphers/AES/AesCipher.h

#ifndef AES_CIPHER_H
#define AES_CIPHER_H

#include "../Cipher.h"
#include <array>
#include <vector>

namespace Encryption {

    class AesCipher : public Cipher {
    public:
        AesCipher();
        string encrypt(const string& text, const string& key) override;
        string decrypt(const string& text, const string& key) override;

    private:
        static constexpr int BLOCK_SIZE = 16; // 128 біт (16 байт)
        static constexpr int ROUNDS = 10;     // 10 раундів для AES-128

        // Таблиця S-Box для SubBytes
        static const std::array<uint8_t, 256> S_BOX;

        // Таблиця InvS-Box для InvSubBytes
        static const std::array<uint8_t, 256> INV_S_BOX;

        // Таблиця Rcon для Key Expansion
        static const std::array<uint8_t, 11> RCON;

        // Основні операції AES
        void subBytes(std::array<uint8_t, BLOCK_SIZE>& state);
        void shiftRows(std::array<uint8_t, BLOCK_SIZE>& state);
        void mixColumns(std::array<uint8_t, BLOCK_SIZE>& state);
        void addRoundKey(std::array<uint8_t, BLOCK_SIZE>& state, const std::array<uint8_t, BLOCK_SIZE>& roundKey);

        // Зворотні операції AES
        void invSubBytes(std::array<uint8_t, BLOCK_SIZE>& state);
        void invShiftRows(std::array<uint8_t, BLOCK_SIZE>& state);
        void invMixColumns(std::array<uint8_t, BLOCK_SIZE>& state);

        // Key Expansion
        std::vector<std::array<uint8_t, BLOCK_SIZE>> expandKey(const std::array<uint8_t, BLOCK_SIZE>& key);

        // Допоміжні функції
        uint8_t gmul(uint8_t a, uint8_t b); // Множення в полі Галуа
    };

} // namespace Encryption

#endif