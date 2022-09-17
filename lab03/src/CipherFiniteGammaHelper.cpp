//
// Created by pi on 17.09.2022.
//

#include "../include/CipherFiniteGammaHelper.h"

std::string CipherFiniteGammaHelper::engAlphabetLower = "abcdefghijklmnopqrstuvwxyz !,";
std::string CipherFiniteGammaHelper::engAlphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ !,";
std::vector<std::string> CipherFiniteGammaHelper::rusAlphabetLower = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к",
                                                "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц",
                                                "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};
std::vector<std::string> CipherFiniteGammaHelper::rusAlphabetUpper = {"А","Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К",
                                                                   "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц",
                                                                   "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"};

template <typename T>
void CipherFiniteGammaHelper::cipher(const T &msg, const T &pwd, T &encrypted){
    int modulo = 26;
    char msgIndexes[msg.size()], pwdIndexes[pwd.size()];
    for (int i = 0; i < msg.size(); i++){
        msgIndexes[i] = engAlphabetLower.find(msg[i]);
    }
    for (int i = 0; i < pwd.size(); i++){
        pwdIndexes[i] = engAlphabetLower.find(pwd[i]);
    }

    for (int i = 0; i < msg.size(); i++){
        int index = (msgIndexes[i] + pwdIndexes[i % pwd.size()]) % modulo;
        encrypted[i] = engAlphabetLower[index];
    }
}

template <typename T>
void CipherFiniteGammaHelper::decipher(const T &enc, const T &pwd, T &decr) {
    cipher(enc, pwd, decr);
}


// so, this is as an easy fix. but if so, you need to list all the possible usages. Let's say that it's ok. By now
// the program was tested with vectors and string. You can always switch back to the template definition inside .h file
// then you don't need these lines.
template void CipherFiniteGammaHelper::cipher(const std::string &msg, const std::string &pwd, std::string &encrypted);
template void CipherFiniteGammaHelper::decipher(const std::string &enc, const std::string &pwd, std::string &decr);
template void CipherFiniteGammaHelper::cipher(const std::vector<char> &msg, const std::vector<char> &pwd, std::vector<char> &encrypted);