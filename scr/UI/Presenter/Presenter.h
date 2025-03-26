#ifndef PRESENTER_H
#define PRESENTER_H

#include "../../lib/lib.h"
#include "../../Domain/UseCases/EncryptUseCase.h"
#include "../../Domain/UseCases/DecryptUseCase.h"
#include "../../Domain/Repositories/EncryptionRepository.h"
#include "../../UI/View/View.h"
#include "../../Infrastructure/Config/ConfigInterface.h"

class Presenter {
public:
    Presenter(
        std::unique_ptr<EncryptUseCase> encryptor,
        std::unique_ptr<DecryptUseCase> decryptor,
        std::unique_ptr<EncryptionRepository> repo,
        std::unique_ptr<View> view,
        ConfigInterface& config
    );
    
    void run();

private:
    void handleEncryption();
    void handleDecryption();
    
    std::unique_ptr<EncryptUseCase> encryptUseCase;
    std::unique_ptr<DecryptUseCase> decryptUseCase;
    std::unique_ptr<EncryptionRepository> repository;
    std::unique_ptr<View> view;
    ConfigInterface& config;
};

#endif // PRESENTER_H