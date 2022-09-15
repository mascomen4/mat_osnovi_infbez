//
// Created by pi on 15.09.2022.
//

#include <iostream>
#include "../include/CipherHelper.h"

int main(){

    // Caesar part

    std::string msg1 = "HELLO WORLD";
    std::string msg2 = "I LIKE CATS";
    std::string msg3 = "INFBEZ KAIF";

    std::string enc1 = "", enc2 = "", enc3 = "";
    std::string dec1 = "", dec2 = "", dec3 = "";

    CipherCaesar::cipher(msg1, 3, enc1);
    CipherCaesar::cipher(msg2, 3, enc2);
    CipherCaesar::cipher(msg3, 3, enc3);

    CipherCaesar::decipher(enc1, 3, dec1);
    CipherCaesar::decipher(enc2, 3, dec2);
    CipherCaesar::decipher(enc3, 3, dec3);

    std::cout << enc1 << std::endl;
    std::cout << enc2 << std::endl;
    std::cout << enc3 << std::endl << std::endl;

    std::cout << dec1 << std::endl;
    std::cout << dec2 << std::endl;
    std::cout << dec3 << std::endl << std::endl;

    // Atbash part
    enc1 = "", enc2 = "", enc3 = "";
    dec1 = "", dec2 = "", dec3 = "";

    CipherAtbash::cipher(msg1, enc1);
    CipherAtbash::cipher(msg2, enc2);
    CipherAtbash::cipher(msg3, enc3);

    std::cout << enc1 << std::endl;
    std::cout << enc2 << std::endl;
    std::cout << enc3 << std::endl << std::endl;

    CipherAtbash::cipher(enc1, dec1);
    CipherAtbash::cipher(enc2, dec2);
    CipherAtbash::cipher(enc3, dec3);

    std::cout << dec1 << std::endl;
    std::cout << dec2 << std::endl;
    std::cout << dec3 << std::endl << std::endl;




}

