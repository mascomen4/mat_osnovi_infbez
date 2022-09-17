#include <iostream>
#include "../include/CipherFiniteGammaHelper.h"

int main() {
    std::string test1 = "hello, world!";
    std::string enc1( test1.size(), ' ');
    std::string dec1( test1.size(), ' ');
    std::string pwd1("parol");

    std::vector<char> test2 = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> enc2(test2.size(), ' ');
    std::vector<char> dec2(test2.size(), ' ');
    std::vector<char> pwd2 = {'p', 'a', 'r', 'o', 'l'};

    CipherFiniteGammaHelper::cipher(test1, pwd1, enc1);
    std::cout << enc1 << std::endl;

    CipherFiniteGammaHelper::cipher(test2, pwd2, enc2);
    for (int i = 0; i < enc2.size(); i++){
        std::cout << enc2[i];
    }
    std::cout << std::endl;

//    CipherFiniteGammaHelper::decipher(enc1, pwd1, dec1);
//    std::cout << dec1 << std::endl;


    return 0;
}
