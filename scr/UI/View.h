#ifndef VIEW_H
#define VIEW_H

#include "../lib/lib.h"

namespace Encryption {

    class View {
    public:
        virtual ~View() = default;
        virtual string getText() = 0;
        virtual string getKey() = 0;
        virtual int getAlgorithm() = 0;
        virtual void showResult(const string& result) = 0;
    };

} // namespace Encryption

#endif