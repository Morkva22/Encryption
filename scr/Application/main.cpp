#include <memory>
#include <iostream>
#include "../Infrastructure/Config/Config.h"
#include "../Infrastructure/Localization/Localization.h"
#include "../UI/View/View.h"
#include "../UI/PresenterFactory/PresenterFactory.h"
#include "../UI/Presenter/Presenter.h"
#include "../Domain/UseCases/EncryptUseCase/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCase/DecryptUseCase.h"
#include "../Infrastructure/Adapters/FileStorageAdapter.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../Utils/Ciphers/XOR/XorCipher.h"

int main() {
    try {
        // Ініціалізація конфігурації
        Config config;
        
        // Налаштування локалізації
        auto localization = std::make_shared<Localization>(config.getLanguage());
        
        // Ініціалізація компонентів
        auto view = std::make_unique<View>(localization);
        auto fileAdapter = std::make_unique<FileStorageAdapter>("data.txt");
        
        // Реєстрація шифрів
        auto caesar = std::make_shared<CaesarCipher>();
        auto xorCipher = std::make_shared<XorCipher>();
        
        auto encryptor = std::make_unique<EncryptUseCase>();
        encryptor->registerCipher("caesar", caesar);
        encryptor->registerCipher("xor", xorCipher);
        
        auto decryptor = std::make_unique<DecryptUseCase>();
        decryptor->registerCipher("caesar", caesar);
        decryptor->registerCipher("xor", xorCipher);
        
        // Створення Presenter через фабрику
        auto presenter = PresenterFactory::create(
            std::move(encryptor),
            std::move(decryptor),
            std::move(fileAdapter),
            std::move(view),
            config
        );
        
        // Запуск програми
        presenter->run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}