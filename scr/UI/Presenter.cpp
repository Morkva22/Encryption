// scr/UI/Presenter.cpp

#include "Presenter.h"
#include <iomanip>
#include <sstream>

namespace Encryption {

    Presenter::Presenter(View* view) : view(view) {}

    void Presenter::run() {
        string text = view->getText();
        string key = view->getKey();
        int algorithm = view->getAlgorithm();

        Cipher* cipher;
        switch (algorithm) {
        case 1:
            cipher = new CaesarCipher();
            break;
        case 2:
            cipher = new XorCipher();
            break;
        default:
            cout << "Invalid algorithm" << endl;
            return;
        }

        string encryptedText = cipher->encrypt(text, key);
        string decryptedText = cipher->decrypt(encryptedText, key);

        // Виводимо результат у форматі "Algorithm Encrypted: ... Decrypted: ..."
        cout << (algorithm == 1 ? "Caesar" : algorithm == 2 ? "XOR" : "AES") << " Encrypted: " << encryptedText << endl;
        cout << (algorithm == 1 ? "Caesar" : algorithm == 2 ? "XOR" : "AES") << " Decrypted: " << decryptedText << endl;

        delete cipher;
    }

} // namespace Encryption