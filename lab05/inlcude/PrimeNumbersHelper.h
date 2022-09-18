//
// Created by pi on 18.09.2022.
//

#ifndef LAB05_PRIMENUMBERSHELPER_H
#define LAB05_PRIMENUMBERSHELPER_H

#include <random>
#include <stdexcept>

class PrimeNumbersHelper {
public:
    template <typename T>
    // true - probably prime number
    // false - composite number
    static bool FermatTest(const T& n){
        if (!check_number(n, 5)){
            throw std::invalid_argument( "number must be >= 5 and odd number" );
        }
        T a = randN(2, n - 2);
        T r = (T)pow(a, n - 1) % n;
        if (r == 1){
            return true;
        }
        else{
            return false;
        }
    }

    template<typename T>
    // true - probably prime number
    // false - composite number
    static bool SolovayStrassenTest(const T& n){
        if (!check_number(n, 5)){
            throw std::invalid_argument( "number must be >= 5 and odd number" );
        }
        T a = randN(2, n - 2);
        T r = (T)pow(a, (n-1)/2) % n;
        if (r != 1 && r != (n-1)){
            return false;
        }
        T s = symbolJacobi(n, a);
        if (r % n == s){
            return false;
        }
        else{
            return true;
        }
    }

    template<typename T>
    // true - probably prime number
    // false - composite number
    static bool millerRabinTest(const T& n){
        if (!check_number(n, 5)){
            throw std::invalid_argument( "number must be >= 5 and odd number" );
        }
        T s = dividersCount(n-1, 2);
        T r = (n-1) / (T)pow(2, s);
        T a = randN(2, n-2);
        T y = (T)pow(a, r) % n;
        if (y != 1 && y != n-1){
            T j = 1;
            if (j < s - 1 && y != n - 1){
                y = y*y % n;
                if (y == 1){
                    return false;
                }
                j += 1;
            }
            if (y != n-1){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    static decltype(auto) randN(const T& low, const T& high){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(low, high);
        return distr(gen);
    }

    template<typename T>
    static decltype(auto) symbolJacobi(const T& n, const T& a){
        if (n < 3){
            throw std::invalid_argument( "number must be >= 3" );
        }
        T g = 1;
        T res, s;
        T nCopy = n;
        T aCopy = a;

        while(true){
            if (aCopy == 0){
                res = 0;
                return res;
            }
            else if (aCopy == 1){
                res = g;
                return res;
            }
            T k = dividersCount(aCopy, 2);
            T a1 = aCopy / (T)pow(2, k);
            if (k % 2 == 0){
                s = 1;
            }
            else{
                if (nCopy % 8 == 1 | nCopy % 8 == -1){
                    s = 1;
                }
                else if (nCopy % 8 == 3 | nCopy % 8 == -3){
                    s = -1;
                }
            }
            if (a1 ==1){
                res = g * s;
                return res;
            }
            if (nCopy % 4 == 3 && a1 % 4 == 3){
                s = -s;
            }
            aCopy = nCopy % a1;
            nCopy = a1;
            g = g * s;
        }

    }

    template<typename T>
    static decltype(auto) dividersCount(const T& n, const T& divider){
        int i = 0;
        T nCopy = n;
        while (nCopy % divider == 0){
            i += 1;
            nCopy /= divider;
        }
        return i;
    }

    template<typename T>
    static bool check_number(const T& n, const T& threshold){
        if (n < threshold){
            return false;
        }
        if (n % 2 == 0){
            return false;
        }
        return true;
    };
};


#endif //LAB05_PRIMENUMBERSHELPER_H
