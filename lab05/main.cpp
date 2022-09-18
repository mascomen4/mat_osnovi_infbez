#include <iostream>
#include "inlcude/PrimeNumbersHelper.h"

int main() {
    int a = 127;

    std::cout << std::endl << "true - probably prime number, false - composite number" << std::endl << std::string(55, '-') << std::endl;
    std::cout << PrimeNumbersHelper::FermatTest(a) << std::endl;
    std::cout << PrimeNumbersHelper::SolovayStrassenTest(a) << std::endl;
    std::cout << PrimeNumbersHelper::millerRabinTest(a) << std::endl;

    return 0;
}
