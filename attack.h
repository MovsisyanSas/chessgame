#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <string>

class attack {
public:
    void att_k(int x, int y, int** matrix2);
    void att_q(int x, int y, int row, std::string name, int** matrix2, std::string** matrix1);
    void att_b(int x, int y, std::string name, int** matrix2, std::string** matrix1);
    void att_n(int x, int y, int** matrix2);
};

#endif  // ATTACK_H

