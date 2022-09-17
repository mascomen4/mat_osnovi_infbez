//
// Created by pi on 15.09.2022.
//

#ifndef LAB02_CIPHERHELPER2_H
#define LAB02_CIPHERHELPER2_H

#include "../../lab01/include/CipherHelper.h"
#include <vector>
#include <eigen3/Eigen/Core>
#include <map>

class CipherHelper2 : public CipherHelper {
public:
    static const std::string rusAlphabetLower;
    static const std::string rusAlphabetUpper;
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
    static void rotate(Eigen::MatrixXi& input){
        Eigen::MatrixXi res = input;
//        std::cout << "Before reverse: " << std::endl << input << std::endl;
//        std::cout << "input before reverse: " << std::endl << input << std::endl;
        // read about Eigens' aliasing: https://eigen.tuxfamily.org/dox/group__TopicAliasing.html and why to use .eval()
        input = input.colwise().reverse().eval();
//        std::cout << "input after reverse: " << std::endl << input << std::endl;
//        std::cout << "After reverse: "<<  std::endl << input << std::endl;
//        std::cout << "res: " << std::endl << res << std::endl;
//        std::cout << "output: " << std::endl << input << std::endl;
        for (int i = 0; i < input.rows(); i++){
            res.row(i) = input.col(i);
        }
        input = res;
//        std::cout << "resulting matrix: " << std::endl << res << std::endl;
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
    const static std::vector<std::string> cipherRusTable, cipherEngTable;
    static void cipher(const std::string& msg, const std::string& pwd, std::string& encrypted);
    static void decipher(const std::string& msg, const std::string& pwd, std::string& decrypted);

};




#endif //LAB02_CIPHERHELPER2_H
