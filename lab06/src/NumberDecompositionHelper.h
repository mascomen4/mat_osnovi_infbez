//
// Created by pi on 18.09.2022.
//

#ifndef LAB06_NUMBERDECOMPOSITIONHELPER_H
#define LAB06_NUMBERDECOMPOSITIONHELPER_H

#include <functional>
#include <iostream>
#include <GCDHelder.h>

class NumberDecompositionHelper {
public:
    // cFunc - compressFunc
    // return -1 indicates the divider is not found
    static int pPollardMethod(const int& n, const int& c){
        int a = c, b = c, d = 1;
        while (d==1){
            a = compressFunc(a, n);
            b = compressFunc(compressFunc(b, n), n);
//            std::cout << a << " " << b << std::endl;
            GCDHelder::eucBinary(abs(a - b), n, d);
            if (d > 1 && d < n){
                return d;
            }
            if (d == n){
                return -1;
            }
        }


    }

    static int compressFunc(const int& x, const int& modulo){
        return (x*x + 5) % modulo;
    }
};


#endif //LAB06_NUMBERDECOMPOSITIONHELPER_H
