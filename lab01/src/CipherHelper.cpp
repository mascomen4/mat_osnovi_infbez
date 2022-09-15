#include "../include/CipherHelper.h"

#include <iostream>

//const std::string CipherHelper::engAlphabetLower = "abcdefghijklmnopqrstuvwxyz";
const std::string CipherHelper::engAlphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

void CipherCaesar::cipher(const std::string& message, int Key, std::string& encrypted){
    // char with index j => char with index (j + k) / mod 26
    if (!encrypted.empty()){
        throw std::invalid_argument( "encrypted is not empty!" );
    }

    if (!message.empty()){
        for (auto character : message){
            // test it, if it returns right index
            auto index = engAlphabetUpper.find(character);
            encrypted += engAlphabetUpper[(index + Key) % engAlphabetUpper.size()];
        }
    }
    else{
        encrypted = "";
    }
}

void CipherCaesar::decipher(const std::string &message, int Key, std::string &decrypted) {
    if (!decrypted.empty()){
        throw std::invalid_argument( "decrypted is not empty!" );
    }

    if (!message.empty()){
        for (auto character : message){
            auto index = engAlphabetUpper.find(character);
            decrypted += engAlphabetUpper[ (engAlphabetUpper.size() +  (index - Key)) % engAlphabetUpper.size() ];
        }
    }
    else{
        decrypted = "";
    }
}

void CipherAtbash::cipher(const std::string &message, std::string &encrypted) {
    if (!encrypted.empty()){
        throw std::invalid_argument( "encrypted is not empty!" );
    }

    if (!message.empty()){
        for (auto character : message){
            // test it, if it returns right index
            auto index = engAlphabetUpper.find(character);
            encrypted += engAlphabetUpper[engAlphabetUpper.size() - 1 - index];
        }
    }
    else{
        encrypted = "";
    }
}

//void CipherAtbash::decipher(const std::string &message, int Key, std::string &decrypted) {
//    if (!decrypted.empty()){
//        throw std::invalid_argument( "decrypted is not empty!" );
//    }
//
//    if (!message.empty()){
//        for (auto character : message){
//            auto index = engAlphabetUpper.find(character);
//            decrypted += engAlphabetUpper[engAlphabetUpper.size() - 1 - index];
//        }
//    }
//    else{
//        decrypted = "";
//    }
//}