#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "../../lib/lib.h"

class JsonParser {
public:
    std::unordered_map<std::string, std::string> parse(const std::string& json);
    
private:
    void skipWhitespace(const std::string& json, size_t& pos);
    std::string parseString(const std::string& json, size_t& pos);
    std::string parseValue(const std::string& json, size_t& pos);
};

#endif // JSON_PARSER_H