#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <string>
#include <vector>

class attack {
public:
    void att_k(int x, int y, int** matrix2);
    void att_q(int x, int y, int row, int** matrix2, std::string** matrix1);
    void att_b(int x, int y, int** matrix2, std::string** matrix1);
    void att_n(int x, int y, int** matrix2);
};

class possible_attack {
public:
    std::vector<std::pair<int, int>> possible_k(int x, int y);
    std::vector<std::pair<int, int>> possible_q(int x, int y, int row, std::string name, std::string** matrix1);
    std::vector<std::pair<int, int>> possible_b(int x, int y, std::string** matrix1);
    std::vector<std::pair<int, int>> possible_n(int x, int y);
};

#endif  // ATTACK_H

