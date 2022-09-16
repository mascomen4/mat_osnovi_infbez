//
// Created by pi on 15.09.2022.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <complex>
#include <random>
#include "../include/CipherHelper2.h"

const std::string CipherHelper2::rusAlphabetLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const std::string CipherHelper2::rusAlphabetUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

void CipherPath::cipher(const std::string &msg, const std::string &pwd, std::string &encrypted) {
    if (!encrypted.empty()){
        throw std::invalid_argument( "encrypted is not empty !" );
    }

    if (!msg.empty()){
        std::string pwdSorted = pwd;
        std::sort(pwdSorted.begin(), pwdSorted.end());

        // cols is actually the length of the pwd
        const uint cols = pwd.size();
        uint rows;
        std::string msgAligned = msg;
        if (msg.size() % cols == 0){
            rows = msg.size() / cols;
        }
        else{
            rows = msg.size() / cols + 1;
            // if the string is too small to complete the last block, add the random characters to the end.
            for (int i = 0; i < (cols - msg.size() % cols ); i++){
                msgAligned += "b";
            }
        }

        // for debugging purposes
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                std::cout << msgAligned[i*cols + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::string(cols*2, '-') << std::endl;
        for (auto c: pwd){
            std::cout << c << " ";
        }
        std::cout << std::endl << std::endl;
        // end debugging output

        // we actually don't have to create a big matrix of the message. we can just take the indexes corresponding to the
        // column of the password
        for (int i = 0; i < pwd.size(); i++){
            auto index = pwd.find(pwdSorted[i]);
            for (int j = 0; j < rows; j++){
                encrypted += msgAligned[j*cols + index];
            }
        }
    }
}

void CipherPath::decipher(const std::string &msg, const std::string &pwd, std::string &decrypted) {
    if (!decrypted.empty()){
        throw std::invalid_argument( "decrypted is not empty!" );
    }

    if (!msg.empty()){
        std::string pwdSorted = pwd;
        std::sort(pwdSorted.begin(), pwdSorted.end());
        // we need to know what index of pwd corresponds to index in pwdSorted, because we're reconstructing the string
        // starting from the original first element of the password
        std::map<uint, uint> pwd2pwdSorted;
        const uint cols = pwd.size();
        const uint rows = msg.size() / cols;
        for (int i = 0; i < pwd.size(); i++){
            pwd2pwdSorted[i] = pwdSorted.find(pwd[i]);
        }

        // the formula was just derived from my observations.
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                decrypted += msg[pwd2pwdSorted[col] * rows + row];
            }
        }
    }
}

CipherLattice::indexes_pwdAligned CipherLattice::cipher(const std::string &msg, const std::string& pwd,
                                        const int k, std::string &encrypted, const int tolerance, char fill) {
    if (!encrypted.empty()){
        throw std::invalid_argument( "encrypted is not empty! ");
    }
    const auto k_squared = (int)std::pow(k, 2);
    auto diff = (int)pwd.size() - (int)std::pow(k, 2);

    std::string pwdAligned = pwd;
    if ( abs(diff) > tolerance){
        std::string error = "tolerance is: " + std::to_string(tolerance) +
                " but the diff k^2 - pwd.size() is: " + std::to_string(diff);
        throw std::invalid_argument ( error );
    }
    // if diff > 0 => password size is bigger than k^2 => need to reduce
    else if (diff > 0){
        for (int i = 0; i < diff; i++){
            pwdAligned.pop_back();
        }
    }
    // if diff < 0 => password size if smaller than k^2 => need to add more
    else if (diff < 0){
        for (int i = 0; i > diff; i--){
            pwdAligned += fill;
        }
    }

    Eigen::MatrixXi block(k, k);
    // fill the block
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            block(i, j) = (i*k + j) + 1;
        }
    }

    Eigen::MatrixXi table(k*2, k*2);
    // fill the table
    table.block(0, 0, k, k) = block;
    auto block90 = rotate(block);
    table.block(0, k, k, k) = block90;
    auto block180 = rotate(block90);
    table.block(k, 0, k, k) = block180;
    auto block270 = rotate(block180);
    table.block(k, k, k, k) = block270;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 3);
    std::vector<uint> indexes;
    for (int i = 0; i < k_squared; i++){
        auto chosen_part = distr(gen);

    }




    // TODO: Random cell selection
}

void CipherLattice::decipher(const std::string &msg, const CipherLattice::indexes_pwdAligned& i_pwd,
                             std::string &decrypted) {

}