#ifndef PRESENTER_H
#define PRESENTER_H

#include "View.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../Utils/Ciphers/XOR/XorCipher.h"


namespace Encryption {

    class Presenter {
    public:
        Presenter(View* view);
        void run();

    private:
        View* view;
    };

} // namespace Encryption

#endif