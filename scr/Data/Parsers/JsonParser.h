// scr/Data/Parsers/JsonParser.h

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "ParserInterface.h"
#include "../../lib/lib.h"

namespace Encryption {

    class JsonParser : public ParserInterface {
    public:
        Data::EncryptionData parse(const string& data) override;
        string serialize(const Data::EncryptionData& data) override;
    };

} // namespace Encryption

#endif