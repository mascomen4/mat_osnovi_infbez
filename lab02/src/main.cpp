#include <iostream>
#include "../include/CipherHelper2.h"

int main() {
//    std::setlocale(LC_ALL, "RUS");
    std::string test1 = "nelzya nedoocenivat protivnika";
    std::string test2 = "hello world! Kulyabov is THE BEST";
    std::string test3 = "kriptographia seryoznaya nauka";
    std::wstring test4(reinterpret_cast<const wchar_t *>("КРИПТОГРАФИЯ СЕРЬЕЗНАЯ НАУКА"));
    std::wstring pwd4(reinterpret_cast<const wchar_t *>("МАТЕМАТИКА"));
    std::wstring enc4;
    std::string enc1, enc2, enc3;
    std::string dec1, dec2, dec3;

    CipherPath::cipher(test1, "parol", enc1);
    std::cout << enc1 << std::endl;
    CipherPath::decipher(enc1, "parol", dec1);
    std::cout << dec1 << std::endl << std::endl << std::endl;

    // we can't input the word which repeats at least one character inside
    CipherPath::cipher(test2, "pasword", enc2);
    std::cout << enc2 << std::endl;
    CipherPath::decipher(enc2, "pasword", dec2);
    std::cout << dec2 << std::endl << std::endl << std::endl;

    enc1 = "";
    std::cout << "CipherLattice: " << std::endl;
    CipherLattice::cipher(test1, "paroli", 2, enc1);
    std::cout << enc1 << std::endl << std::endl;

    std::cout << "Cipher Vigenere Table: " << std::endl;
    std::string pwd3 = "matematika";
//    std::cout << pwd3.size() << std::endl;
    CipherVigenereTable::cipher(test3, pwd3, enc3);
    std::cout << enc3 << std::endl << std::endl;

    return 0;
}
