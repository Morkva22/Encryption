#include "View.h"
#include <iostream>
#include <limits> // Для numeric_limits

using namespace Encryption;
using namespace std;

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
    return key;
}

int ConsoleView::getAlgorithm() {
    int algorithm;
    while (true) {
        cout << "Choose algorithm (1 - Caesar, 2 - XOR): ";
        if (cin >> algorithm && (algorithm == 1 || algorithm == 2)) {
            cin.ignore(); // Consume newline
            return algorithm;
        } else {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter 1 or 2.\n";
        }
    }
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

void ConsoleView::showError(const std::string& errorMessage) {
    cerr << "Error: " << errorMessage << endl; // Виводимо помилку в stderr
}