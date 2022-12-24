//
// Created by pi on 18.09.2022.
//

#ifndef LAB07_DICRETELOGARITHMHELPER_H
#define LAB07_DICRETELOGARITHMHELPER_H

#include <functional>
#include <unordered_map>
#include <bits/stdc++.h>
#include "../../lab05/inlcude/PrimeNumbersHelper.h"

using namespace std;

class DicreteLogarithmHelper {
public:

    static int discreteLogarithm(int a, int b, int m)
    {
        int n = (int) sqrt (m) + 1;

        // Calculate a ^ n
        int an = 1;
        for (int i = 0; i<n; ++i)
            an = (an * a) % m;

        unordered_map<int, int> value;

        // Store all values of a^(n*i) of LHS
        for (int i = 1, cur = an; i<= n; ++i)
        {
            if (! value[ cur ])
                value[ cur ] = i;
            cur = (cur * an) % m;
        }

        for (int i = 0, cur = b; i<= n; ++i)
        {
            // Calculate (a ^ j) * b and check
            // for collision
            if (value[cur])
            {
                int ans = value[cur] * n - i;
                if (ans < m)
                    return ans;
            }
            cur = (cur * a) % m;
        }
        return -1;
    }

    /***
     * param(p) - простое число
     * param(a) - число а порядка r по модулю p
     * param(r) - порядок числа a
     * param(b) - целое число b, 1 < b < p
     * param(mapping) - должно обладать сжимающими свойствами и сохранять вычислимость логарифма
     * return(x) - показатель x для которого a^x % p = b, если такой показатель существует
    ***/
//    static int pPollardLogarithm(int p, int a, int r, int b, const std::function<int (int)>& mapping ){
//        // TODO: perform the check of p. It has to be prime
//        int u = PrimeNumbersHelper::randN(0, 100);
//        int v = PrimeNumbersHelper::randN(0, 100);
//        int c = (int)std::pow(a, u) * (int)std::pow(b, v) % p;
//        int d = c;
//        while ( (c - d) % p != 0){
//            c = mapping(c) % p;
//            d = mapping(mapping(d)) % p;
//            // TODO: ????
//            // TODO: read it carefully and see how to solve it.
//        }
//    }
};


#endif //LAB07_DICRETELOGARITHMHELPER_H
