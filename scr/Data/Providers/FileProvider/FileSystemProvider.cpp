#include "FileSystemProvider.h"

using namespace std;

class FileSystemProviderImpl : public FileSystemProvider {
private:
    string encryptionFileName = "encryption_results.txt";
    string decryptionFileName = "decryption_results.txt";

public:
    void saveEncryptionResult(const string& encryptedText) override {
        ofstream file(encryptionFileName, ios::app);  // Відкриваємо файл для додавання результатів
        if (file.is_open()) {
            file << "Encrypted: " << encryptedText << endl;
            file.close();
        } else {
            cout << "Unable to open file for encryption result." << endl;
        }
    }

    void saveDecryptionResult(const string& decryptedText) override {
        ofstream file(decryptionFileName, ios::app);  // Відкриваємо файл для додавання результатів
        if (file.is_open()) {
            file << "Decrypted: " << decryptedText << endl;
            file.close();
        } else {
            cout << "Unable to open file for decryption result." << endl;
        }
    }
};
