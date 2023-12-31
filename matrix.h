#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "attack.h"
#include "figure.h"

class matrix {
protected:
    const int row;
    const int column;
public:
    std::string** matrix1;
    int** matrix2;
    int** matrix3;
private:
    void init();

public:
    matrix() = delete;
    matrix(int a, int b);
    matrix(const matrix& obj);
    matrix& operator=(const matrix& obj);
    virtual ~matrix();
};

class board : public matrix {
    attack att;
private:
    bool isfree(int x, int y,board temp);
    bool isfree(int x, int y);
public:
    board() = default;
    board(int a, int b);
    board(const board& obj) = default;
    board& operator=(const board& obj) = default;
    ~board() override = default;

    void print();
    void print_num_w();
    void print_num_b();
    void nameplacer(std::vector<figure*> vect);
    void Att(std::vector<figure*> vect);
    int condition(figure* k);
    double distance(int x1, int y1, int x2, int y2);
    figure* find_m1(std::vector<figure*> vect,board b_2);
    void clear();
};
#endif  // MATRIX_H

