// scr/Data/Mappers/EncryptionMapper.cpp

#include "EncryptionMapper.h"

using namespace Encryption;

    EncryptionData EncryptionMapper::mapToDomain(const Data::EncryptionData& data) {
        return EncryptionData(data.text, data.key, data.algorithm);
    }

    Data::EncryptionData EncryptionMapper::mapToData(const EncryptionData& data) {
        Data::EncryptionData result;
        result.text = data.getText();
        result.key = data.getKey();
        result.algorithm = data.getAlgorithm();
        return result;

}