#include "../UI/Presenter/Presenter.h"
#include "../UI/View/View.h"
#include "../Domain/UseCases/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCase.h"
#include "../Domain/Repositories/EncryptionRepository.h"
#include "../Infrastructure/Config/Config.h"
#include "../Infrastructure/Localization/Localization.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../Utils/Ciphers/XOR/XorCipher.h"
#include "../lib/lib.h"
int main() {
    try {
        // Ініціалізація компонентів
        Config config;
        auto localization = make_shared<Localization>(config.getLanguage());
        auto view = make_unique<View>(localization);
        
        auto caesar = make_shared<CaesarCipher>();
        auto xorCipher = make_shared<XorCipher>();
        
        auto encryptor = make_unique<EncryptUseCase>();
        encryptor->registerCipher("caesar", caesar);
        encryptor->registerCipher("xor", xorCipher);
        
        auto decryptor = make_unique<DecryptUseCase>();
        decryptor->registerCipher("caesar", caesar);
        decryptor->registerCipher("xor", xorCipher);
        
        auto repository = make_unique<EncryptionRepository>("data.txt");
        
        Presenter presenter(
            move(encryptor),
            move(decryptor),
            move(repository),
            move(view),
            config
        );
        
        presenter.run();
    } catch (const std::exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    return 0;
}