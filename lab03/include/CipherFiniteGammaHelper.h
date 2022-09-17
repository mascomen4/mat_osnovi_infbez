//
// Created by pi on 17.09.2022.
//

#ifndef LAB03_CIPHERFINITEGAMMAHELPER_H
#define LAB03_CIPHERFINITEGAMMAHELPER_H

#include <string>
#include <vector>

class CipherFiniteGammaHelper{
public:
    // so, the user might want to insert the vector of chars, or the array of chars, or the string, or wstring.
    // so, let's use the template for these purposes
    template <typename T>
    static void cipher(const T& msg, const T& pwd, T& encrypted);
//    {
//        int modulo = 26;
//        char msgIndexes[msg.size()], pwdIndexes[pwd.size()];
//        for (int i = 0; i < msg.size(); i++){
//            msgIndexes[i] = engAlphabetLower.find(msg[i]);
//        }
//        for (int i = 0; i < pwd.size(); i++){
//            pwdIndexes[i] = engAlphabetLower.find(pwd[i]);
//        }
//
//        for (int i = 0; i < msg.size(); i++){
//            int index = (msgIndexes[i] + pwdIndexes[i % pwd.size()]) % modulo;
//            encrypted[i] = engAlphabetLower[index];
//        }
//    };

    template <typename T>
    static void decipher(const T& enc, const T& pwd, T& decr);
//    {
//        cipher(enc, pwd, decr);
//    };

    static std::string engAlphabetLower;
    static std::string engAlphabetUpper;
    static std::vector<std::string> rusAlphabetLower;
    static std::vector<std::string> rusAlphabetUpper;

//    static void find_in_rus()
};


#endif //LAB03_CIPHERFINITEGAMMAHELPER_H
