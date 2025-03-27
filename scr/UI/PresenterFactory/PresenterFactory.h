#pragma once
#include <memory>
#include "../../Domain/UseCases/EncryptUseCase/EncryptUseCase.h"
#include "../../Domain/UseCases/DecryptUseCase/DecryptUseCase.h"
#include "../../Infrastructure/Adapters/FileStorageAdapter.h"
#include "../../UI/View/View.h"
#include "../../Infrastructure/Config/ConfigInterface.h"

class Presenter;

class PresenterFactory {
public:
    static std::unique_ptr<Presenter> create(
        std::unique_ptr<EncryptUseCase> encryptor,
        std::unique_ptr<DecryptUseCase> decryptor,
        std::unique_ptr<FileStorageAdapter> repo, // Змінено на FileStorageAdapter
        std::unique_ptr<View> view,
        ConfigInterface& config
    );
};