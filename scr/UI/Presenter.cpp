// scr/UI/Presenter.cpp

#include "Presenter.h"

namespace Encryption {

    Presenter::Presenter(View* view, EncryptUseCase* encryptUseCase, DecryptUseCase* decryptUseCase, EncryptionRepository* repository)
        : view(view), encryptUseCase(encryptUseCase), decryptUseCase(decryptUseCase), repository(repository) {}

    void Presenter::run() {
        while (true) {
            int algorithm = view->getAlgorithm();
            string text = view->getText();
            string key = view->getKey();

            EncryptionData data(text, key, algorithm);
            repository->save(data);

            string encryptedText = encryptUseCase->execute(data);
            string decryptedText = decryptUseCase->execute(data);

            view->showResult(encryptedText, decryptedText);

            if (!view->askToContinue()) {
                break;
            }
        }
    }

} // namespace Encryption