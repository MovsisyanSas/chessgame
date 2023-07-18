#include "figure.h"

bool figure::inBoard(int x, int y) {
    if (x <= 8 && x >= 0 && y <= 8 && y >= 0) {
        return true;
    }
    return false;
}

king::king(std::string col, int r, int c) {
    if (figure::inBoard(r, c)) {
        if (col == figure::black || col == figure::white) {
            name = col + "K";
            x = c - 1;
            y = r - 1;
        }
        else {
            std::cout << "Error: wrong color entered" << std::endl;
            abort();
        }
    }
    else {
        std::cout << "Error: can't use cell out of board" << std::endl;
        abort();
    }
}

queen::queen(std::string col, int r, int c) {
    if (figure::inBoard(r, c)) {
        if (col == figure::black || col == figure::white) {
            name = col + "Q";
            x = c - 1;
            y = r - 1;
        }
        else {
            std::cout << "Error: wrong color entered" << std::endl;
            abort();
        }
    }
    else {
        std::cout << "Error: can't use cell out of board" << std::endl;
        abort();
    }
}

bishop::bishop(std::string col, int r, int c) {
    if (figure::inBoard(r, c)) {
        if (col == figure::black || col == figure::white) {
            name = col + "B";
            x = c - 1;
            y = r - 1;
        }
        else {
            std::cout << "Error: wrong color entered" << std::endl;
            abort();
        }
    }
    else {
        std::cout << "Error: can't use cell out of board" << std::endl;
        abort();
    }
}

knight::knight(std::string col, int r, int c) {
    if (figure::inBoard(r, c)) {
        if (col == figure::black || col == figure::white) {
            name = col + "N";
            x = c - 1;
            y = r - 1;
        }
        else {
            std::cout << "Error: wrong color entered" << std::endl;
            abort();
        }
    }
    else {
        std::cout << "Error: can't use cell out of board" << std::endl;
        abort();
    }
}
