// scr/Utils/Ciphers/AES/AesCipher.cpp

        #include "AesCipher.h"
        #include "../../Utils.h"
        #include <cryptopp/aes.h>
        #include <cryptopp/modes.h>
        #include <cryptopp/filters.h>
        #include <cryptopp/base64.h>

        namespace Encryption {

        string AesCipher::encrypt(const string& text, const string& key) {
            try {
                CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];
                memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);

                CryptoPP::AES::Encryption aesEncryption((CryptoPP::byte *)key.c_str(), key.length());
                CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

                string ciphertext;
                CryptoPP::StreamTransformationFilter stf(cbcEncryption, new CryptoPP::StringSink(ciphertext));
                stf.Put(reinterpret_cast<const CryptoPP::byte *>(text.c_str()), text.length() + 1);
                stf.MessageEnd();

                string encoded;
                CryptoPP::StringSource ss(ciphertext, true, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(encoded)));
                return encoded;
            } catch (const CryptoPP::Exception& e) {
                cerr << e.what() << endl;
                return "";
            }
        }

        string AesCipher::decrypt(const string& text, const string& key) {
            try {
                string decoded;
                CryptoPP::StringSource ss(text, true, new CryptoPP::Base64Decoder(new CryptoPP::StringSink(decoded)));

                CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];
                memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);

                CryptoPP::AES::Decryption aesDecryption((CryptoPP::byte *)key.c_str(), key.length());
                CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

                string plaintext;
                CryptoPP::StreamTransformationFilter stf(cbcDecryption, new CryptoPP::StringSink(plaintext));
                stf.Put(reinterpret_cast<const CryptoPP::byte *>(decoded.c_str()), decoded.length());
                stf.MessageEnd();

                return plaintext;
            } catch (const CryptoPP::Exception& e) {
                cerr << e.what() << endl;
                return "";
            }
        }

        } // namespace Encryption