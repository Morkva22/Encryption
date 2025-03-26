#include "JsonParser.h"

namespace {
    void throwParseError(const std::string& message, size_t pos) {
        throw std::runtime_error("JSON parse error at position " + 
                               std::to_string(pos) + ": " + message);
    }
}

void JsonParser::skipWhitespace(const std::string& json, size_t& pos) {
    while (pos < json.size() && isspace(json[pos])) {
        pos++;
    }
}

std::string JsonParser::parseString(const std::string& json, size_t& pos) {
    if (json[pos] != '"') {
        throwParseError("Expected '\"'", pos);
    }
    pos++;
    
    std::string result;
    while (pos < json.size() && json[pos] != '"') {
        if (json[pos] == '\\') {
            pos++;
            if (pos >= json.size()) {
                throwParseError("Unterminated escape sequence", pos);
            }
            // Проста обробка escape-послідовностей
            switch (json[pos]) {
                case '"': result += '"'; break;
                case '\\': result += '\\'; break;
                default: result += json[pos]; break;
            }
        } else {
            result += json[pos];
        }
        pos++;
    }
    
    if (pos >= json.size() || json[pos] != '"') {
        throwParseError("Unterminated string", pos);
    }
    pos++;
    
    return result;
}

std::string JsonParser::parseValue(const std::string& json, size_t& pos) {
    skipWhitespace(json, pos);
    if (pos >= json.size()) {
        throwParseError("Unexpected end of input", pos);
    }
    
    if (json[pos] == '"') {
        return parseString(json, pos);
    }
    
    // Проста обробка boolean та null значень
    if (json.substr(pos, 4) == "true") {
        pos += 4;
        return "true";
    }
    if (json.substr(pos, 5) == "false") {
        pos += 5;
        return "false";
    }
    if (json.substr(pos, 4) == "null") {
        pos += 4;
        return "null";
    }
    
    // Обробка чисел (спрощено)
    std::string number;
    while (pos < json.size() && (isdigit(json[pos]) || json[pos] == '.' || json[pos] == '-')) {
        number += json[pos++];
    }
    if (!number.empty()) {
        return number;
    }
    
    throwParseError("Unexpected token", pos);
    return "";
}

std::unordered_map<std::string, std::string> JsonParser::parse(const std::string& json) {
    std::unordered_map<std::string, std::string> result;
    size_t pos = 0;
    
    skipWhitespace(json, pos);
    if (pos >= json.size() || json[pos] != '{') {
        throwParseError("Expected '{'", pos);
    }
    pos++;
    
    while (pos < json.size()) {
        skipWhitespace(json, pos);
        if (json[pos] == '}') {
            pos++;
            break;
        }
        
        std::string key = parseString(json, pos);
        skipWhitespace(json, pos);
        
        if (pos >= json.size() || json[pos] != ':') {
            throwParseError("Expected ':'", pos);
        }
        pos++;
        
        std::string value = parseValue(json, pos);
        result[key] = value;
        
        skipWhitespace(json, pos);
        if (pos < json.size() && json[pos] == ',') {
            pos++;
        }
    }
    
    return result;
}