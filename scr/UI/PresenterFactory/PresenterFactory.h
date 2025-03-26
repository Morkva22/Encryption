#ifndef PRESENTER_FACTORY_H
#define PRESENTER_FACTORY_H
#include "../../lib/lib.h"
#include "../../Domain/UseCases/EncryptUseCase.h"
#include "../../Domain/UseCases/DecryptUseCase.h"
#include "../../Domain/Repositories/EncryptionRepository.h"
#include "../../UI/View/View.h"
#include "../../Infrastructure/Config/ConfigInterface.h"

class Presenter;

class PresenterFactory {
public:
    static std::unique_ptr<Presenter> create(
        std::unique_ptr<EncryptUseCase> encryptor,
        std::unique_ptr<DecryptUseCase> decryptor,
        std::unique_ptr<EncryptionRepository> repo,
        std::unique_ptr<View> view,
        ConfigInterface& config
    );
};

#endif // PRESENTER_FACTORY_H