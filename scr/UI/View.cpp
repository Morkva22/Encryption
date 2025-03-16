
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

        void showResult(const string& result) override {
            cout << "Result: " << result << endl;
        }
    };

} // namespace Encryption