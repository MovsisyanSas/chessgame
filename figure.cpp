#include "figure.h"

bool figure::inBoard(int x, int y) {
    if (x <= 8 && x > 0 && y <= 8 && y > 0) {
        return true;
    }
    return false;
}

void figure::set(int X, int Y) {
    if (figure::inBoard(X + 1, Y + 1))
    {
        figure::x = X;
        figure::y = Y;
    }
}
king::king(std::string col, int r, int c) {
    if (figure::inBoard(r, c)) {
        if (col == figure::black || col == figure::white) {
            figure::name = col + "K";
            figure::x = c - 1;
            figure::y = r - 1;
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
            figure::name = col + "Q";
            figure::x = c - 1;
            figure::y = r - 1;
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
            figure::name = col + "B";
            figure::x = c - 1;
            figure::y = r - 1;
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
            figure::name = col + "N";
            figure::x = c - 1;
            figure::y = r - 1;
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
