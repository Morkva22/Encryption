// scr/Domain/domain.h

#ifndef DOMAIN_H
#define DOMAIN_H

#include "../lib/lib.h"

namespace Encryption {

    // Основні сутності
    class EncryptionData; // Оголошення класу EncryptionData

    // Репозиторії
    class EncryptionRepository; // Оголошення інтерфейсу репозиторію
    class InMemoryEncryptionRepository; // Оголошення конкретної реалізації репозиторію

    // Use Cases
    class EncryptUseCase; // Оголошення Use Case для шифрування
    class DecryptUseCase; // Оголошення Use Case для дешифрування

} // namespace Encryption

#endif