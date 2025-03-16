#include "EncryptionRepository.h"

namespace Encryption {

    class InMemoryEncryptionRepository : public EncryptionRepository {
    public:
        void save(const EncryptionData& data) override {
            this->data = data;
        }

        EncryptionData get() override {
            return data;
        }

    private:
        EncryptionData data;
    };

} // namespace Encryption