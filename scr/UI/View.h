// scr/UI/View.h

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
        virtual void showResult(const string& encryptedResult, const string& decryptedResult) = 0;
        virtual bool askToContinue() = 0;
    };

    class ConsoleView : public View {
    public:
        string getText() override;
        string getKey() override;
        int getAlgorithm() override;
        void showResult(const string& encryptedResult, const string& decryptedResult) override;
        bool askToContinue() override;
    };

} // namespace Encryption

#endif