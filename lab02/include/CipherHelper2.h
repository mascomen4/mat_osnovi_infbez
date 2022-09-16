//
// Created by pi on 15.09.2022.
//

#ifndef LAB02_CIPHERHELPER2_H
#define LAB02_CIPHERHELPER2_H

#include "../../lab01/include/CipherHelper.h"
#include <vector>
#include <eigen3/Eigen/Core>

class CipherHelper2 : CipherHelper {
    static const std::string rusAlphabetLower;
    static const std::string rusAlphabetUpper;
    static const std::string engAlphabetUpper;
};

class CipherPath : CipherHelper2 {
public:
    static void cipher(const std::string& msg, const std::string& pwd, std::string& encrypted);
    static void decipher(const std::string& msg, const std::string& pwd, std::string& decrypted);
};

class CipherLattice : CipherHelper2 {
public:
    // we need the pwd, and the array of indexes which contains the indexes which were cutted from the matrix.
    // to build the matrix we can use the additionally created function for reconstructing matrix from the msg and pwd
    // returns the indexes which were chosen to create the lattice.
    // tolerance is the number of cut/add characters function is allowed to cut/add to the pwd. If pwd length is 4, and
    // desired k is 3, therefore, k^2 = 9, we need to add 5 additional characters to pwd. The function will not do that
    // in case if tolerance = 2 and throw and error. Otherwise, it will fill with 'a' character by default (or cut)
    typedef std::pair<std::vector<uint>, std::string&> indexes_pwdAligned;
    static indexes_pwdAligned cipher(const std::string& msg, const std::string& pwd, int k,
                                     std::string& encrypted, int tolerance = 2, char fill = 'a');
    static void decipher(const std::string& msg, const indexes_pwdAligned& i_pwd, std::string& decrypted);

private:
    // rotates clockwise by 90 degrees => reversed columns are now rows.
    static Eigen::MatrixXi rotate(Eigen::MatrixXi& input){
        Eigen::MatrixXi res;
        std::cout << "Before reverse: " << input << std::endl;
        input.colwise().reverse();
        std::cout << "After reverse: " << input << std::endl;
        for (int i = 0; i < input.rows(); i++){
            auto col = input.block(0, i, input.rows(), 1);
            res.block(i, 0, 1, input.cols()) = col;
        }
    }
};

class CipherVigenereTable : CipherHelper2 {
public:

};




#endif //LAB02_CIPHERHELPER2_H
