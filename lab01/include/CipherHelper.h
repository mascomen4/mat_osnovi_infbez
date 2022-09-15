#ifndef LAB01_CIPHERHELPER_H
#define LAB01_CIPHERHELPER_H

#include <string>


class CipherHelper{
public:
    static const std::string engAlphabetLower;
    static const std::string engAlphabetUpper;
};

class CipherCaesar : CipherHelper {
public:
    static void cipher (const std::string& message, int Key, std::string& encrypted);
    static void decipher (const std::string& message, int Key, std::string& decrypted);
};

class CipherAtbash : CipherHelper {
public:
    static void cipher (const std::string& message, std::string& encrypted);
//    static void decipher (const std::string& message, int Key, std::string& decrypted);
};



#endif //LAB01_CIPHERHELPER_H
