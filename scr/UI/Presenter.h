#ifndef PRESENTER_H
#define PRESENTER_H

#include "../Domain/UseCases/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCase.h"
#include "../Domain/Repositories/EncryptionRepository.h"
#include "../UI/View.h"

namespace Encryption {

    class Presenter {
    public:
        Presenter(View* view, EncryptUseCase* encryptUseCase, 
                  DecryptUseCase* decryptUseCase, EncryptionRepository* repository);
        void run();

    private:
        View* view;
        EncryptUseCase* encryptUseCase;
        DecryptUseCase* decryptUseCase;
        EncryptionRepository* repository;
    };

} // namespace Encryption

#endif