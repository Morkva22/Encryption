// scr/Data/Parsers/JsonParser.cpp

#include "JsonParser.h"
#include <sstream>
#include <vector>

namespace Encryption {

    Data::EncryptionData JsonParser::parse(const string& data) {
        Data::EncryptionData result;
        stringstream ss(data);
        string token;
        vector<string> tokens;

        // Розбиваємо рядок на токени
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Перевірка на коректну кількість токенів
        if (tokens.size() < 6) {
            throw invalid_argument("Invalid JSON format");
        }

        // Очищуємо токени від зайвих символів
        for (string& token : tokens) {
            token.erase(remove(token.begin(), token.end(), '{'), token.end());
            token.erase(remove(token.begin(), token.end(), '}'), token.end());
            token.erase(remove(token.begin(), token.end(), '"'), token.end());
            token.erase(remove(token.begin(), token.end(), ':'), token.end());
        }

        // Заповнюємо результат
        result.text = tokens[1];
        result.key = tokens[3];
        result.algorithm = stoi(tokens[5]);

        return result;
    }

    string JsonParser::serialize(const Data::EncryptionData& data) {
        return "{\"text\":\"" + data.text + "\",\"key\":\"" + data.key + "\",\"algorithm\":" + to_string(data.algorithm) + "}";
    }

} // namespace Encryption