#include "Presenter.h"
#include "../../Domain/Entities/EncryptionDocument.h"

Presenter::Presenter(
    std::unique_ptr<EncryptUseCase> encryptor,
    std::unique_ptr<DecryptUseCase> decryptor,
    std::unique_ptr<Repository> repository,
    std::unique_ptr<View> view,
    ConfigInterface& config
) : encryptUseCase(std::move(encryptor)),
    decryptUseCase(std::move(decryptor)),
    repository(std::move(repository)),
    view(std::move(view)),
    config(config) {}

void Presenter::run() {
    while (true) {
        view->showMainMenu();
        int choice = view->getUserChoice();
        
        try {
            switch (choice) {
            case 1: handleEncryption(); break;
            case 2: handleDecryption(); break;
            case 3: return;
            default: view->showError("Invalid choice");
            }
        } catch (const std::exception& e) {
            view->showError(e.what());
        }
    }
}

void Presenter::handleEncryption() {
    auto text = view->getInputText();
    auto key = view->getEncryptionKey();
    auto cipherType = view->getCipherType();
    
    std::string encryptedText = encryptUseCase->execute(text, cipherType, key);
    EncryptedDocument doc(text, cipherType, key, encryptedText);
    
    repository->save(doc);
    view->showResult(encryptedText);
}

void Presenter::handleDecryption() {
    auto encryptedText = view->getInputText();
    auto key = view->getEncryptionKey();
    auto cipherType = view->getCipherType();
    
    std::string decryptedText = decryptUseCase->execute(encryptedText, cipherType, key);
    view->showResult(decryptedText);
}
