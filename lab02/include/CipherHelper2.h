//
// Created by pi on 15.09.2022.
//

#ifndef LAB02_CIPHERHELPER2_H
#define LAB02_CIPHERHELPER2_H

#include "../../lab01/include/CipherHelper.h"
#include <vector>
#include <eigen3/Eigen/Core>
#include <map>

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
    typedef std::pair<std::vector<std::pair<int, int>>, std::string&> indexes_pwdAligned;
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

    // bear in mind that the numbering in matrix is from 1. The function assumes that you've taken that into account
    static std::pair<int, int> find_element(Eigen::MatrixXi& input, int element){
        for (int row = 0; row < input.rows(); row++){
            for (int col = 0; col < input.cols(); col++){
                if ( input(row, col) == element ){
                    std::pair<int, int> res(row, col);
                    return res;
                }
            }
        }
    }

    static void create_mapping(const std::string& from, const std::string& to, std::map<uint, uint>& output){
        for (int i = 0; i < from.size(); i++){
            auto index = to.find(from[i]);
            output[i] = index;
        }
    }
};

class CipherVigenereTable : CipherHelper2 {
public:

};




#endif //LAB02_CIPHERHELPER2_H
