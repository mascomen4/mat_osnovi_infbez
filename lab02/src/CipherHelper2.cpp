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

    std::vector<Eigen::MatrixXi> table;
    auto rotatedBlock = block;
    // fill the table
    for (int i = 0; i <= 4; i++){
        table.push_back(rotatedBlock);
        rotatedBlock = rotate(rotatedBlock);
    }
    // by now rotatedBlock is the initial block (rotated by 360 degrees)

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 3);
    std::vector< std::pair<int, int> > indexes;
    // compose a matrix of indexes
    Eigen::MatrixXi eigenTable = Eigen::MatrixXi::Zero(k*2, k*2);
    for (int el = 0; el < k_squared; el++){
        uint chosen_part = distr(gen);
        // search for the element in the block
        std::pair<int, int> rowCol = find_element(table[chosen_part], el+1);
        // convert found index to the global index.
        if (chosen_part == 1){
            // if it's the second part, the row remains the same, but the column is skewed
            rowCol.second += k;
        }
        else if (chosen_part == 2){
            // if it's the third part, the column remains the same, but the row goes down
            rowCol.first += k;
        }
        else if (chosen_part == 3){
            // finally, if it's the fourth part, the column and the row are skewed
            rowCol.first += k;
            rowCol.second += k;
        }
        eigenTable(rowCol.first, rowCol.second) = el + 1;
        indexes.push_back(rowCol);
    }

    Eigen::Matrix<char, Eigen::Dynamic, Eigen::Dynamic> filledTable = Eigen::Matrix<char, Eigen::Dynamic, Eigen::Dynamic>::Zero(k*2, k*2);
    Eigen::MatrixXi mToRotate = rotate(eigenTable);
    // rotate matrix of indexes until the filledTable is all filled (4 times)
    // fill table the first time
    for (int i = 0; i < k_squared; i++){
        filledTable(indexes[i].first, indexes[i].second) = msg[i];
    }

    for (int i = 1; i <= 4; i++) {
        for (int el = 0; el < k_squared; el++) {
            auto elIndexes = find_element(mToRotate, el + 1);
            filledTable(elIndexes.first, elIndexes.second) = msg[i * k_squared + el];
        }
        mToRotate = rotate(mToRotate);
    } // now the matrix is considered to be filled

    // permute the columns according to the alphabetical order of the pwd
    std::string pwdSorted = pwdAligned;
    std::sort(pwdSorted.begin(), pwdSorted.end());
    std::map<uint, uint> pwdSorted2pwd;
    create_mapping(pwdSorted, pwd, pwdSorted2pwd);
    auto permTable = filledTable;

    // take the pwdSorted index, find it's corresponding index in the pwd and substitude
    // the column with that index to the index of pwdSorted
    // TODO: Create the function for permutations
    for (int i = 0; i < pwdSorted.size(); i++){
        permTable.block(0, i, filledTable.rows(), 1) =
                filledTable.block(0, pwdSorted2pwd[i], filledTable.rows(), 1);
        permTable.block(0, pwdSorted2pwd[i], filledTable.rows(), 1) =
                filledTable.block(0, i, filledTable.rows(), 1);
    }

    // now, when the columns are permuted we can write to the cipher message
    for (int col = 0; col < permTable.cols(); col++){
        for (int row = 0; row < permTable.rows(); row++){
            encrypted += permTable(row, col);
        }
    }

    CipherLattice::indexes_pwdAligned i_pwd(indexes, pwdAligned);
    return i_pwd;
}

void CipherLattice::decipher(const std::string &msg, const CipherLattice::indexes_pwdAligned& i_pwd,
                             std::string &decrypted) {

}