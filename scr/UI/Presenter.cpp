#include "Presenter.h"
#include "../Domain/Repositories/EncryptionRepository.h"
#include "../Data/Data.h"

using namespace Encryption;

Presenter::Presenter(View* view, EncryptUseCase* encryptUseCase, DecryptUseCase* decryptUseCase, EncryptionRepository* repository)
    : view(view), encryptUseCase(encryptUseCase), decryptUseCase(decryptUseCase), repository(repository) {}

void Presenter::run() {
    // Приклад використання правильного типу
    Data::EncryptionData data{"some text", "some key", 1};
    repository->save(data); // Тепер передається правильний тип
}