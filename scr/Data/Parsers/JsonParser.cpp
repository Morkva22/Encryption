#include "JsonParser.h"

void JsonParser::throwParseError(const std::string& message, size_t pos) const {
    throw std::runtime_error("JSON parse error at position " + 
                           std::to_string(pos) + ": " + message);
}

void JsonParser::skipWhitespace(const std::string& json, size_t& pos) {
    while (pos < json.size() && (isspace(json[pos]) || json[pos] == '\n' || json[pos] == '\r')) {
        pos++;
    }
}

std::string JsonParser::parseString(const std::string& json, size_t& pos)
{
    if (pos >= json.size() || json[pos] != '"') {
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
            switch (json[pos]) {
                case '"': result += '"'; break;
                case '\\': result += '\\'; break;
                case '/': result += '/'; break;
                case 'b': result += '\b'; break;
                case 'f': result += '\f'; break;
                case 'n': result += '\n'; break;
                case 'r': result += '\r'; break;
                case 't': result += '\t'; break;
                default: throwParseError("Invalid escape sequence", pos);
            }
        } else {
            if (json[pos] == '\n' || json[pos] == '\r') {
                throwParseError("Unterminated string", pos);
            }
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
    
    // Обробка чисел
    if (json[pos] == '-' || isdigit(json[pos])) {
        std::string number;
        bool hasDecimal = false;
        while (pos < json.size()) {
            if (isdigit(json[pos])) {
                number += json[pos++];
            } else if (json[pos] == '.' && !hasDecimal) {
                hasDecimal = true;
                number += json[pos++];
            } else if (json[pos] == '-') {
                number += json[pos++];
            } else {
                break;
            }
        }
        return number;
    }
    
    throwParseError("Unexpected token '" + std::string(1, json[pos]) + "'", pos);
    return "";
}

std::unordered_map<std::string, std::string> JsonParser::parse(const std::string& json) {
    std::unordered_map<std::string, std::string> result;
    size_t pos = 0;
    parseObject(json, pos, "", result);
    return result;
}

void JsonParser::parseObject(const std::string& json, size_t& pos, 
                           const std::string& currentPath,
                           std::unordered_map<std::string, std::string>& result) {
    skipWhitespace(json, pos);
    if (pos >= json.size() || json[pos] != '{') {
        throwParseError("Expected '{'", pos);
    }
    pos++;
    
    while (pos < json.size()) {
        skipWhitespace(json, pos);
        if (json[pos] == '}') {
            pos++;
            return;
        }
        
        std::string key = parseString(json, pos);
        std::string fullKey = currentPath.empty() ? key : currentPath + "." + key;
        
        skipWhitespace(json, pos);
        if (pos >= json.size() || json[pos] != ':') {
            throwParseError("Expected ':'", pos);
        }
        pos++;
        skipWhitespace(json, pos);
        
        if (json[pos] == '{') {
            parseObject(json, pos, fullKey, result);
        } else {
            result[fullKey] = parseValue(json, pos);
        }
        
        skipWhitespace(json, pos);
        if (pos < json.size() && json[pos] == ',') {
            pos++;
        }
    }
}