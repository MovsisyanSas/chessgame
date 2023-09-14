#include "matrix.h"

void matrix::init() {
    matrix1 = new std::string * [row];
    matrix2 = new int* [row];
    matrix3 = new int* [row];

    for (int i = 0; i < row; i++) {
        matrix1[i] = new std::string[column];
        matrix2[i] = new int[column];
        matrix3[i] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix1[i][j] = "__";
            matrix2[i][j] = 0;
            matrix3[i][j] = 0;
        }
    }
}

matrix::matrix(int a, int b) : row(a), column(b) {
    init();
}

matrix::matrix(const matrix& obj) : row(obj.row), column(obj.column) {
    this->matrix1 = new std::string * [row];
    this->matrix2 = new int* [row];
    this->matrix3 = new int* [row];

    for (int i = 0; i < row; i++) {
        matrix1[i] = new std::string[column];
        matrix2[i] = new int[column];
        matrix3[i] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix1[i][j] = obj.matrix1[i][j];
            matrix2[i][j] = obj.matrix2[i][j];
            matrix3[i][j] = obj.matrix3[i][j];
        }
    }
}

matrix& matrix::operator=(const matrix& obj) {
    if (this != &obj) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                this->matrix1[i][j] = obj.matrix1[i][j];
                this->matrix2[i][j] = obj.matrix2[i][j];
                this->matrix3[i][j] = obj.matrix3[i][j];
            }
        }
    }
    return *this;
}

matrix::~matrix() {
    for (int i = 0; i < row; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] matrix3[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] matrix3;
}
