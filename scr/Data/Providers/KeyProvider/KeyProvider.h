#ifndef KEY_PROVIDER_H
#define KEY_PROVIDER_H

#include "../../../lib/lib.h"

namespace Encryption {

    class KeyProvider {
    public:
        virtual ~KeyProvider() = default;
        virtual string getKey(int algorithm) = 0;
    };

} // namespace Encryption

#endif