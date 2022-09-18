//
// Created by pi on 18.09.2022.
//

#ifndef LAB06_NUMBERDECOMPOSITIONHELPER_H
#define LAB06_NUMBERDECOMPOSITIONHELPER_H

#include <functional>
#include <GCDHelder.h>

class NumberDecompositionHelper {
    // cFunc - compressFunc
    // return -1 indicates the divider is not found
    static int pPollardMethod(const int& n, const int& c, std::function<int (int, int)>& cFunc){
        int res, a, b, d;
        a = c, b = c;
        while (true){
            a = cFunc(a, n);
            b = cFunc(b, n);
            GCDHelder::eucBinary(a - b, n, d);
            if (d > 1 && d < n){
                return d;
            }
            else if (d == n){
                return -1;
            }
        }


    }

private:
    static int compressFunc(int x, int modulo){
        return (x*x + 5) % modulo;
    }
};


#endif //LAB06_NUMBERDECOMPOSITIONHELPER_H
