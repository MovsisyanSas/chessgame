#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class figure {
protected:
    const std::string white = "W";
    const std::string black = "B";

    bool inBoard(int x, int y);

public:
    virtual ~figure() {}
};

class king : public figure {
public:
    int x = 0, y = 0;
    std::string name;

    king() = delete;
    king(std::string col, int r, int c);
};

class queen : public figure {
public:
    int x = 0, y = 0;
    std::string name;

    queen() = delete;
    queen(std::string col, int r, int c);
};

class bishop : public figure {
public:
    int x = 0, y = 0;
    std::string name;

    bishop() = delete;
    bishop(std::string col, int r, int c);
};

class knight : public figure {
public:
    int x = 0, y = 0;
    std::string name;

    knight() = delete;
    knight(std::string col, int r, int c);
};

#endif  // FIGURE_H
