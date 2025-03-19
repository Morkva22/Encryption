#include "../UI/Presenter.h"
#include "../UI/View.h"
#include "../Domain/UseCases/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCase.h"
#include "../Domain/Repositories/EncryptionRepository.h"
#include "../Data/Providers/KeyProvider/KeyProvider.h"

using namespace Encryption;

int main() {
    try {
        ConsoleView view;
        InMemoryEncryptionRepository repository;
        FileKeyProvider keyProvider;

        EncryptUseCase encryptUseCase(&repository, &keyProvider);
        DecryptUseCase decryptUseCase(&repository, &keyProvider);

        Presenter presenter(&view, &encryptUseCase, &decryptUseCase, &repository);
        presenter.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }

    return 0;
}