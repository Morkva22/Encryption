#include "../Utils/Ciphers/AES/AesCipher.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../lib/lib.h"
#include "../UI/View.h"
#include "../UI/Presenter.h"
using namespace Encryption;

int main()
{
    // Caesar Cipher
    CaesarCipher caesarCipher;
    string caesarEncryptedText = caesarCipher.encrypt("Hello, world!", "3");
    string caesarDecryptedText = caesarCipher.decrypt(caesarEncryptedText, "3");
    cout << "Caesar Encrypted: " << caesarEncryptedText << endl;
    cout << "Caesar Decrypted: " << caesarDecryptedText << endl;
    
        View view;
        Presenter presenter(&view);
        presenter.run();
        return 0;
    return 0;
}