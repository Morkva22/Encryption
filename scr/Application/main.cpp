#include "../Infrastructure/Config/Config.h"
#include "../Infrastructure/Localization/Localization.h"
#include "../UI/View/View.h"
#include "../UI/PresenterFactory/PresenterFactory.h"
#include "../Domain/UseCases/EncryptUseCases/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCases/DecryptUseCase.h"
#include "../Infrastructure/Adapters/FileStorageAdapter.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../Utils/Ciphers/XOR/XorCipher.h"


void initializeConsole() {
    #ifdef _WIN32
    // Встановлюємо UTF-8 для вводу/виводу
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // Налаштовуємо буферизацію для коректного виводу UTF-8
    std::ios_base::sync_with_stdio(false);
    std::wcout.imbue(std::locale(""));
    std::wcin.imbue(std::locale(""));
    #else
    std::setlocale(LC_ALL, "en_US.utf8");
    #endif
}

std::shared_ptr<Localization> initializeLocalization(const Config& config) {
    const std::string localesPath = "scr/Infrastructure/Localization/locales/";
    
    try {
        auto loc = std::make_shared<Localization>(localesPath, config.getLanguage());
        std::cout << loc->translate("language_set") << std::endl;
        return loc;
    } catch (const std::exception& e) {
        std::cerr << "Localization error: " << e.what() << std::endl;
        
        try {
            auto loc = std::make_shared<Localization>(localesPath, "en");
            std::cerr << "Falling back to English localization" << std::endl;
            return loc;
        } catch (...) {
            throw std::runtime_error("Critical: Failed to load any localization");
        }
    }
}

int main() {
    initializeConsole();

    try {
        Config config;
        auto localization = initializeLocalization(config);
        auto view = std::make_unique<View>(localization);
        auto fileAdapter = std::make_unique<FileStorageAdapter>("encrypted_data.txt");
        
        auto caesar = std::make_shared<CaesarCipher>();
        auto xorCipher = std::make_shared<XorCipher>();
        
        auto encryptor = std::make_unique<EncryptUseCase>();
        encryptor->registerCipher("caesar", caesar);
        encryptor->registerCipher("xor", xorCipher);
        
        auto decryptor = std::make_unique<DecryptUseCase>();
        decryptor->registerCipher("caesar", caesar);
        decryptor->registerCipher("xor", xorCipher);
        
        auto presenter = PresenterFactory::create(
            std::move(encryptor),
            std::move(decryptor),
            std::move(fileAdapter),
            std::move(view),
            config
        );
        
        presenter->run();

    } catch (const std::exception& e) {
        std::cerr << "\nFATAL ERROR: " << e.what() << std::endl;
        std::cerr << "Possible solutions:" << std::endl;
        std::cerr << "1. Check 'locales' folder exists with translation files" << std::endl;
        std::cerr << "2. Verify file permissions" << std::endl;
        std::cerr << "3. Check config.json exists with valid settings" << std::endl;
        return 1;
    }
    
    return 0;
}
