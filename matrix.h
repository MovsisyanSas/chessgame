#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "attack.h"
#include "figure.h"

class matrix {
protected:
    const int row;
    const int column;
public:
    std::string** matrix1;
    int** matrix2;
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
    bool kingcheck(int x, int y);
    bool isfree(int x, int y);

public:
    board() = default;
    board(int a, int b);
    board(const board& obj) = default;
    board& operator=(const board& obj) = default;
    ~board() override = default;

    void print();
    void print_num();
    void set(king k);
    void set(queen q);
    void set(bishop b);
    void set(knight n);
    int condition(king k);
};
#endif  // MATRIX_H

