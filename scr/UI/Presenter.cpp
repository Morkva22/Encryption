#include "Presenter.h"
#include "../Data/Data.h"

namespace Encryption {

    Presenter::Presenter(View* view, 
                       EncryptUseCase* encryptUseCase,
                       DecryptUseCase* decryptUseCase,
                       EncryptionRepository* repository)
        : view(view),
          encryptUseCase(encryptUseCase),
          decryptUseCase(decryptUseCase),
          repository(repository) {}

    void Presenter::run() {
        try {
            while (true) {
                int algorithm = view->getAlgorithm();
                std::string text = view->getText();
                std::string key = view->getKey();

                EncryptionData domainData(text, key, algorithm);
                repository->save(domainData);

                Data::EncryptionData useCaseData;
                useCaseData.text = domainData.getText(); // Використання геттера
                useCaseData.key = domainData.getKey();   // Використання геттера
                useCaseData.algorithm = domainData.getAlgorithm(); // Геттер

                std::string encrypted = encryptUseCase->encrypt(useCaseData);
                std::string decrypted = decryptUseCase->decrypt(useCaseData);

                view->showResult(encrypted, decrypted);

                if (!view->askToContinue()) break;
            }
        } catch (const std::exception& e) {
            view->showError(e.what());
        }
    }

} // namespace Encryption