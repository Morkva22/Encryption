#include "Presenter.h"

Presenter::Presenter(
    std::unique_ptr<EncryptUseCase> encryptor,
    std::unique_ptr<DecryptUseCase> decryptor,
    std::unique_ptr<EncryptionRepository> repo,
    std::unique_ptr<View> view,
    ConfigInterface& config
) : encryptUseCase(std::move(encryptor)),
    decryptUseCase(std::move(decryptor)),
    repository(std::move(repo)),
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
    
    EncryptionData data{text, key, "", cipherType};
    data.encryptedText = encryptUseCase->execute(data);
    repository->save(data);
    view->showResult(data.encryptedText);
}

void Presenter::handleDecryption() {
    auto text = view->getInputText();
    auto key = view->getEncryptionKey();
    auto cipherType = view->getCipherType();
    
    EncryptionData data{"", key, text, cipherType};
    data.text = decryptUseCase->execute(data);
    view->showResult(data.text);
}