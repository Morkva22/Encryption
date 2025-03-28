#include "PresenterFactory.h"
#include "../Presenter/Presenter.h"

std::unique_ptr<Presenter> PresenterFactory::create(
    std::unique_ptr<EncryptUseCase> encryptor,
    std::unique_ptr<DecryptUseCase> decryptor,
    std::unique_ptr<FileStorageAdapter> repo, // Змінено на FileStorageAdapter
    std::unique_ptr<View> view,
    ConfigInterface& config
) {
    return std::make_unique<Presenter>(
        std::move(encryptor),
        std::move(decryptor),
        std::move(repo),
        std::move(view),
        config
    );
}
