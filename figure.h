#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class figure {
protected:
    const std::string white = "W";
    const std::string black = "B";

    bool inBoard(int x, int y);
public:
    int x = 0, y = 0;
    std::string name;

    virtual ~figure() {}
};

class king : public figure {
public:
    king() = delete;
    king(std::string col, int r, int c);
    ~king() override {};
};

class queen : public figure {
public:
    queen() = delete;
    queen(std::string col, int r, int c);
    ~queen() override {};
};

class bishop : public figure {
public:
    bishop() = delete;
    bishop(std::string col, int r, int c);
    ~bishop() override {};
};

class knight : public figure {
public:
    knight() = delete;
    knight(std::string col, int r, int c);
    ~knight() override {};
};

#endif  // FIGURE_H
