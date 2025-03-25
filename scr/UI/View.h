#ifndef VIEW_H
#define VIEW_H

#include <string>

namespace Encryption {

    class View {
    public:
        virtual ~View() = default;
        virtual std::string getText() = 0;
        virtual std::string getKey() = 0;
        virtual int getAlgorithm() = 0;
        virtual void showResult(const std::string& encryptedResult, const std::string& decryptedResult) = 0;
        virtual bool askToContinue() = 0;
        virtual void showError(const std::string& errorMessage) = 0; // Новий метод для виведення помилок
    };

    class ConsoleView : public View {
    public:
        std::string getText() override;
        std::string getKey() override;
        int getAlgorithm() override;
        void showResult(const std::string& encryptedResult, const std::string& decryptedResult) override;
        bool askToContinue() override;
        void showError(const std::string& errorMessage) override; // Реалізація для ConsoleView
    };

} // namespace Encryption

#endif // VIEW_H