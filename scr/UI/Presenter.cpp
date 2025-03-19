#include "Presenter.h"

namespace Encryption {

    Presenter::Presenter(View* view, EncryptUseCase* encryptUseCase, DecryptUseCase* decryptUseCase, EncryptionRepository* repository)
        : view(view), encryptUseCase(encryptUseCase), decryptUseCase(decryptUseCase), repository(repository) {}

    void Presenter::run() {
        while (true) {
            int algorithm = view->getAlgorithm();
            string text = view->getText();
            string key = view->getKey();

            Data::EncryptionData data;
            data.text = text;
            data.key = key;
            data.algorithm = algorithm;

            repository->save(data);

            string encryptedText = encryptUseCase->encrypt(data);
            string decryptedText = decryptUseCase->decrypt(data);

            view->showResult(encryptedText, decryptedText);

            if (!view->askToContinue()) {
                break;
            }
        }
    }

} // namespace Encryption