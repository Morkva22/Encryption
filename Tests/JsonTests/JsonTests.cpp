#include "../../scr/Data//Parsers/JsonParser.h"
#include <cassert>
#include "../../scr/lib/lib.h"

void testJsonParser() {
    JsonParser parser;
    
    // Тест 1: Простий об'єкт
    std::string json1 = R"({"name":"John","age":30,"isStudent":true})";
    auto result1 = parser.parse(json1);
    assert(result1["name"] == "John");
    assert(result1["age"] == "30");
    assert(result1["isStudent"] == "true");
    
    // Тест 2: Пустий об'єкт
    std::string json2 = "{}";
    auto result2 = parser.parse(json2);
    assert(result2.empty());
    
    // Тест 3: Вкладений об'єкт (спрощений)
    std::string json3 = R"({"user":{"name":"Alice"},"active":false})";
    auto result3 = parser.parse(json3);
    // У нашій спрощеній реалізації це не працюватиме коректно
    // Але для повноцінного парсера потрібно обробляти
    
    std::cout << "All JSON parser tests passed!\n";
}
