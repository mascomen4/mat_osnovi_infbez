#include <iostream>
#include "include/GCDHelder.h"

int main() {
    // TODO: Check the validity of the encrypted messages
    int a, b, gcd;
    a = 105;
    b = 154;

    GCDHelder::eucClassic(a, b, gcd);
    std::cout << gcd << std::endl;
    GCDHelder::eucBinary(a, b, gcd);
    std::cout << gcd << std::endl;
    GCDHelder::eucExpanded(a, b, gcd);
    std::cout << gcd << std::endl;
    GCDHelder::eucBinaryExpanded(a, b, gcd);
    std::cout << gcd << std::endl;


    return 0;
}
