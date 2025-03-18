// scr/Data/Parsers/ParserInterface.h

#ifndef PARSER_INTERFACE_H
#define PARSER_INTERFACE_H

#include "../Data.h"

namespace Encryption {

    class ParserInterface {
    public:
        virtual ~ParserInterface() = default;
        virtual Data::EncryptionData parse(const string& data) = 0;
        virtual string serialize(const Data::EncryptionData& data) = 0;
    };

} // namespace Encryption

#endif