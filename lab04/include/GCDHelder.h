//
// Created by pi on 18.09.2022.
//

#ifndef LAB04_GCDHELDER_H
#define LAB04_GCDHELDER_H

#include <stdexcept>

class GCDHelder {
public:
    // bear in mind that user might use int32_t, int64_t, uint, char, etc...
    template<typename T>
    static void eucClassic(const T& arg1, const T& arg2, T& gcd){
        check_args(arg1, arg2);

        T a, b;
        find_init_values(arg1, arg2, a, b);

        auto r0 = a, r1 = b;
        gcd = b;
        while (true){
            gcd = r0 % r1;
            if (gcd == 0){
                break;
            }
            r0 = r1;
            r1 = gcd;
        }
    }

    template<typename T>
    static void eucBinary(const T& arg1, const T& arg2, T& gcd){
        check_args(arg1, arg2);
        T a, b;
        find_init_values(arg1, arg2, a, b);
        T g = 1;
        while ( a % 2 == 0 && b % 2 == 0 ){
            a /= 2;
            b /= 2;
            g *= 2;
        }
        T u = a, v = b;
        while (u != 0){
            while (u % 2 == 0){
                u /= 2;
            }
            while (v % 2 == 0){
                v /= 2;
            }

            if (u >= v){
                u -= v;
            }
            else{
                v -= u;
            }
        }
        gcd = g * v;
    }

    template<typename T>
    static std::pair<T, T> eucExpanded(const T& arg1, const T& arg2, T& gcd){
        check_args(arg1, arg2);
        T a, b;
        find_init_values(arg1, arg2, a, b);
        auto r0 = a, r1 = b;
        T x0 = 1, x1 = 0, y0 = 0, y1 = 1;
        gcd = b;

        while (true){
            T q;
            gcd = r0 % r1;
            if (gcd == 0){
                std::pair<T, T> res{x1, y1};
                return res;
            }
            r0 = r1;
            r1 = gcd;
            q = r0 / r1;
            T tmpX = x1, tmpY = y1;
            x1 = x0 - q * x1;
            y1 = y0 - q * y1;
            x0 = tmpX;
            y0 = tmpY;
        }
    }

    template<typename T>
    static std::pair<T, T> eucBinaryExpanded(const T& arg1, const T& arg2, T& gcd){
        check_args(arg1, arg2);
        T a, b;
        find_init_values(arg1, arg2, a, b);
        T g = 1;
        while ( a % 2 == 0 && b % 2 == 0 ){
            a /= 2;
            b /= 2;
            g *= 2;
        }

        T u = a, v = b;
        T A = 1, B = 0, C = 0, D = 1;
        while (u != 0){
            while (u % 2 == 0){
                u /= 2;
                if (A % 2 == 0 && B % 2 == 0){
                    A /= 2;
                    B /= 2;
                }
                else{
                    A = (A + b) / 2;
                    B = (B - a) / 2;
                }
            }
            while (v % 2 == 0){
                v /= 2;
                if (C % 2 == 0 && D % 2 == 0){
                    C /= 2;
                    D /= 2;
                }
                else{
                    C = (C + b) / 2;
                    D = (D - a) / 2;
                }
            }

            if (u >= v){
                u -= v;
                A -= C;
                B -= D;
            }
            else{
                v -= u;
                C -= A;
                D -= B;
            }
        }

        gcd = g * v;
        T x = C;
        T y = D;
        std::pair<T, T> xy{x, y};
        return xy;
    }

private:
    template<typename T>
    static void check_args(const T& arg1, const T& arg2){
        if (arg1 < 0 | arg2 < 0){
            auto error = "a is: " + std::to_string(arg1) + ", and b is: " + std::to_string(arg2) +
                         + ", but only values >= 0 are accepted";
            throw std::invalid_argument( error );
        }
    }

    template<typename T>
    static void find_init_values(const T& arg1, const T& arg2, T& a, T& b){
        if (arg1 >= arg2){
            a = arg1;
            b = arg2;
        }
        else{
            a = arg2;
            b = arg1;
        }
    }
};


#endif //LAB04_GCDHELDER_H
