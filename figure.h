#pragma once
#include <iostream>

class figure {
protected:
	const std::string white = "W";
	const std::string black = "B";

	bool inBoard(int x, int y) {
		if (x <= 8 && x >= 0 && y <= 8 && y >= 0)
		{
			return true;
		}
		return false;
	}
public:
	virtual ~figure() {};
};

class king : public figure {
public:
	int x = 0, y = 0;
	std::string name;
	king() = delete;
	king(std::string col,int r,int c){
		if (figure::inBoard(r,c))
		{
			if (col == figure::black || col == figure::white)
			{
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
};

class queen : public figure {
public:
	int x = 0, y = 0;
	std::string name;
	queen() = delete;
	queen(std::string col, int r, int c) {
		if (figure::inBoard(r, c))
		{
			if (col == figure::black || col == figure::white)
			{
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
};

class bishop : public figure {
public:
	int x = 0, y = 0;
	std::string name;
	bishop() = delete;
	bishop(std::string col, int r, int c) {
		if (figure::inBoard(r, c))
		{
			if (col == figure::black || col == figure::white)
			{
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
};

class knight : public figure {
public:
	int x = 0, y = 0;
	std::string name;
	knight() = delete;
	knight(std::string col, int r, int c) {
		if (figure::inBoard(r, c))
		{
			if (col == figure::black || col == figure::white)
			{
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
};