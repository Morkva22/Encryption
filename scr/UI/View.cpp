// scr/UI/View.cpp

#include "View.h"

using namespace Encryption;

string ConsoleView::getText() {
    cout << "Enter text: ";
    string text;
    getline(cin, text);
    return text;
}

string ConsoleView::getKey() {
    cout << "Enter key: ";
    string key;
    getline(cin, key);

    // Перевірка на пустий ключ
    if (key.empty()) {
        throw invalid_argument("Key cannot be empty");
    }

    return key;
}

int ConsoleView::getAlgorithm() {
    cout << "Choose algorithm (1 - Caesar, 2 - XOR, 3 - AES): ";
    int algorithm;
    cin >> algorithm;

    // Перевірка на коректність алгоритму
    if (algorithm < 1 || algorithm > 3) {
        throw invalid_argument("Invalid algorithm");
    }

    cin.ignore(); // Consume newline
    return algorithm;
}

void ConsoleView::showResult(const string& encryptedResult, const string& decryptedResult) {
    cout << "Encrypted: " << encryptedResult << endl;
    cout << "Decrypted: " << decryptedResult << endl;
}

bool ConsoleView::askToContinue() {
    cout << "Continue? (y/n): ";
    char answer;
    cin >> answer;
    cin.ignore(); // Consume newline
    return answer == 'y';
}