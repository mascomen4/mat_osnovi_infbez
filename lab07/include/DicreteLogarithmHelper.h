//
// Created by pi on 18.09.2022.
//

#ifndef LAB07_DICRETELOGARITHMHELPER_H
#define LAB07_DICRETELOGARITHMHELPER_H

#include <functional>
#include "../../lab05/inlcude/PrimeNumbersHelper.h"

class DicreteLogarithmHelper {
public:

    /***
     * param(p) - простое число
     * param(a) - число а порядка r по модулю p
     * param(b) - целое число b, 1 < b < p
     * param(mapping) - должно обладать сжимающими свойствами и сохранять вычислимость логарифма
     * return(x) - показатель x для которого a^x % p = b, если такой показатель существует
    ***/
    static int pPollardLogarithm(int p, int a, int b, std::function<int (int)> mapping ){
        // TODO: perform the check of p. It has to be prime
        int u = PrimeNumbersHelper::randN(0, 100);
        int v = PrimeNumbersHelper::randN(0, 100);
        int c = std::pow(a, u) % p;
        int d = c;
        while (c % p != d){
            c = mapping(c) % p;
            d = mapping(mapping(d)) % p;
            // TODO: ????
            // TODO: read it carefully and see how to solve it.
        }
    }
};


#endif //LAB07_DICRETELOGARITHMHELPER_H
