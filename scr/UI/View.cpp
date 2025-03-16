// scr/UI/View.cpp

#include "View.h"

namespace Encryption {

    class ConsoleView : public View {
    public:
        string getText() override {
            cout << "Enter text: ";
            string text;
            getline(cin, text);
            return text;
        }

        string getKey() override {
            cout << "Enter key: ";
            string key;
            getline(cin, key);
            return key;
        }

        int getAlgorithm() override {
            cout << "Choose algorithm (1 - Caesar, 2 - XOR, 3 - AES): ";
            int algorithm;
            cin >> algorithm;
            cin.ignore(); // Consume newline
            return algorithm;
        }

        void showResult(const string& encryptedResult, const string& decryptedResult) override {
            cout << "Encrypted: " << encryptedResult << endl;
            cout << "Decrypted: " << decryptedResult << endl;
        }

        bool askToContinue() override {
            cout << "Continue? (y/n): ";
            char answer;
            cin >> answer;
            cin.ignore(); // Consume newline
            return answer == 'y';
        }
    };

} // namespace Encryption