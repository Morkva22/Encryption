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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ios_base::sync_with_stdio(false);
    wcout.imbue(locale(""));
    wcin.imbue(locale(""));
    #else
    setlocale(LC_ALL, "en_US.utf8");
    #endif
}

shared_ptr<Localization> initializeLocalization(const Config& config) {
    const string localesPath = "scr/Infrastructure/Localization/locales/";
    
    try {
        auto loc = make_shared<Localization>(localesPath, config.getLanguage());
        cout << loc->translate("language_set") << endl;
        return loc;
    } catch (const exception& e) {
        cerr << "Localization error: " << e.what() << endl;
        
        try {
            auto loc = make_shared<Localization>(localesPath, "en");
            cerr << "Falling back to English localization" << endl;
            return loc;
        } catch (...) {
            throw runtime_error("Critical: Failed to load any localization");
        }
    }
}

int main() {
    initializeConsole();

    try {
        Config config;
        auto localization = initializeLocalization(config);
        auto view = make_unique<View>(localization);
        auto fileAdapter = make_unique<FileStorageAdapter>("encrypted_data.txt");
        
        auto caesar = make_shared<CaesarCipher>();
        auto xorCipher = make_shared<XorCipher>();
        
        auto encryptor = make_unique<EncryptUseCase>();
        encryptor->registerCipher("caesar", caesar);
        encryptor->registerCipher("xor", xorCipher);
        
        auto decryptor = make_unique<DecryptUseCase>();
        decryptor->registerCipher("caesar", caesar);
        decryptor->registerCipher("xor", xorCipher);
        
        auto presenter = PresenterFactory::create(
            move(encryptor),
            move(decryptor),
            move(fileAdapter),
            move(view),
            config
        );
        
        presenter->run();

    } catch (const exception& e) {
        cerr << "\nFATAL ERROR: " << e.what() << endl;
        cerr << "Possible solutions:" << endl;
        cerr << "1. Check 'locales' folder exists with translation files" << endl;
        cerr << "2. Verify file permissions" << endl;
        cerr << "3. Check config.json exists with valid settings" << endl;
        return 1;
    }
    
    return 0;
}