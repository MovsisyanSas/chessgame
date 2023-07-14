#pragma once
#include <iostream>
#include "figure.cpp"


class board {
	const int row;
	const int column;
	std::string** matrix1;
	int** matrix2;
private:
	void init() {
		matrix1 = new std::string * [row];
		matrix2 = new int* [row];

		for (int i = 0; i < row; i++)
		{
			matrix1[i] = new std::string[column];
			matrix2[i] = new int[column];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				matrix1[i][j] = "__";
				matrix2[i][j] = 0;
			}
		}
	}
	bool kingcheck(int x, int y) {
		if (y != 0 && y != 7)
		{
			if (x != 0 && x != 7)
			{
				if (matrix1[x][y + 1] == "WK" || matrix1[x][y - 1] == "WK" || matrix1[x + 1][y + 1] == "WK" || matrix1[x - 1][y - 1] == "WK" || matrix1[x - 1][y + 1] == "WK" || matrix1[x + 1][y - 1] == "WK" || matrix1[x + 1][y] == "WK" || matrix1[x - 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y + 1] == "BK" || matrix1[x][y - 1] == "BK" || matrix1[x + 1][y + 1] == "BK" || matrix1[x - 1][y - 1] == "BK" || matrix1[x - 1][y + 1] == "BK" || matrix1[x + 1][y - 1] == "BK" || matrix1[x + 1][y] == "BK" || matrix1[x - 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
			else if (x == 0) {
				if (matrix1[x][y + 1] == "WK" || matrix1[x][y - 1] == "WK" || matrix1[x + 1][y + 1] == "WK" || matrix1[x + 1][y - 1] == "WK" || matrix1[x + 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y + 1] == "BK" || matrix1[x][y - 1] == "BK" || matrix1[x + 1][y + 1] == "BK" || matrix1[x + 1][y - 1] == "BK" || matrix1[x + 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
			else if (x == 7) {
				if (matrix1[x][y + 1] == "WK" || matrix1[x][y - 1] == "WK" || matrix1[x - 1][y - 1] == "WK" || matrix1[x - 1][y + 1] == "WK" || matrix1[x - 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y + 1] == "BK" || matrix1[x][y - 1] == "BK" || matrix1[x - 1][y - 1] == "BK" || matrix1[x - 1][y + 1] == "BK" || matrix1[x - 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
		}
		else if (y == 0)
		{
			if (x == 0) {

				if (matrix1[x][y + 1] == "WK" || matrix1[x + 1][y + 1] == "WK" || matrix1[x + 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y + 1] == "BK" || matrix1[x + 1][y + 1] == "BK" || matrix1[x + 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
			else if (x == 7) {

				if (matrix1[x][y + 1] == "WK" || matrix1[x - 1][y + 1] == "WK" || matrix1[x - 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y + 1] == "BK" || matrix1[x - 1][y + 1] == "BK" || matrix1[x - 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
		}
		else if (y == 7) {
			if (x == 0) {

				if (matrix1[x][y - 1] == "WK" || matrix1[x + 1][y - 1] == "WK" || matrix1[x + 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y - 1] == "BK" || matrix1[x + 1][y - 1] == "BK" || matrix1[x + 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
			else if (x == 7) {

				if (matrix1[x][y - 1] == "WK" || matrix1[x - 1][y - 1] == "WK" || matrix1[x - 1][y] == "WK")
				{
					return false;
				}
				else if (matrix1[x][y - 1] == "BK" || matrix1[x - 1][y - 1] == "BK" || matrix1[x - 1][y] == "BK")
				{
					return false;
				}
				return true;
			}
		}
		return true;
	}
	bool isfree(int x, int y) {
		if (matrix1[x][y] == "__")
		{
			return true;
		}
		return false;
	}
	void att_k(int x, int y) {
		matrix2[x][y]++;
		if (y != 0 && y != 7)
		{
			if (x != 0 && x != 7)
			{
				matrix2[x][y + 1]++;
				matrix2[x][y - 1]++;
				matrix2[x + 1][y + 1]++;
				matrix2[x - 1][y - 1]++;
				matrix2[x - 1][y + 1]++;
				matrix2[x + 1][y - 1]++;
				matrix2[x + 1][y]++;
				matrix2[x - 1][y]++;
			}
			if (x == 0)
			{
				matrix2[x][y + 1]++;
				matrix2[x + 1][y + 1]++;
				matrix2[x + 1][y]++;
				matrix2[x + 1][y - 1]++;
				matrix2[x][y - 1]++;
			}
			else if (x == 7) {
				matrix2[x][y + 1]++;
				matrix2[x - 1][y + 1]++;
				matrix2[x - 1][y]++;
				matrix2[x - 1][y - 1]++;
				matrix2[x][y - 1]++;
			}
		}
		else if (y == 0)
		{
			if (x != 0 && x != 7)
			{
				matrix2[x][y + 1]++;
				matrix2[x + 1][y + 1]++;
				matrix2[x - 1][y + 1]++;
				matrix2[x + 1][y]++;
				matrix2[x - 1][y]++;
			}
			if (x == 0)
			{
				matrix2[x][y + 1]++;
				matrix2[x + 1][y + 1]++;
				matrix2[x + 1][y]++;
			}
			else if (x == 7) {
				matrix2[x][y + 1]++;
				matrix2[x - 1][y + 1]++;
				matrix2[x - 1][y]++;
			}
		}
		else if (y == 7)
		{
			if (x != 0 && x != 7)
			{
				matrix2[x][y + 1]++;
				matrix2[x + 1][y + 1]++;
				matrix2[x - 1][y + 1]++;
				matrix2[x + 1][y]++;
				matrix2[x - 1][y]++;
			}
			if (x == 0)
			{
				matrix2[x][y - 1]++;
				matrix2[x + 1][y - 1]++;
				matrix2[x + 1][y]++;
			}
			else if (x == 7) {
				matrix2[x][y - 1]++;
				matrix2[x - 1][y - 1]++;
				matrix2[x - 1][y]++;
			}
		}
	}
	void att_q(int x, int y, std::string name) {
		matrix2[x][y] -= 4;
		for (int i = x; i < row; i++)
		{
			if (matrix1[i][y] != "__" && matrix1[i][y] != name && matrix1[i][y] != "WK")
			{
				break;
			}
			matrix2[i][y]++;
		}
		for (int i = x; i >= 0; i--)
		{
			if (matrix1[i][y] != "__" && matrix1[i][y] != name && matrix1[i][y] != "WK")
			{
				break;
			}
			matrix2[i][y]++;
		}
		for (int i = 0; i < row; i++)
		{
			if (matrix1[x][i] != "__" && matrix1[x][i] != name && matrix1[x][i] != "WK")
			{
				break;
			}
			matrix2[x][i]++;
		}
		for (int i = 0; i >= 0; i--)
		{
			if (matrix1[x][i] != "__" && matrix1[x][i] != name && matrix1[x][i] != "WK")
			{
				break;
			}
			matrix2[x][i]++;
		}

		int i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i++;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i--;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i--;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}
	void att_b(int x, int y, std::string name) {
		matrix2[x][y] -= 3;
		int i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i++;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i--;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i--;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);

		i = x, j = y;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != name && matrix1[i][j] != "WK") {
				break;
			}
			matrix2[i][j]++;
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	void att_n(int x, int y) {
		matrix2[x][y]++;
		if (x != 1 && x != 0 && x != 6 && x != 7)
		{
			if (y == 1) {
				matrix2[x - 2][y + 1]++;
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y + 2]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y + 2]++;

			}
			else if (y == 6) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x - 2][y + 1]++;
				matrix2[x - 1][y + 2]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y - 2]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
			}
			else {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y - 2]++;
				matrix2[x - 1][y + 2]++;
			}
		}
		else if (x == 0) {
			if (y == 1) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y + 2]++;
			}
			else if (y == 6) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
			}
			else {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x + 1][y - 2]++;
			}
		}
		else if (x == 7) {
			if (y == 1) {
				matrix2[x - 2][y + 1]++;
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 6) {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x - 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x - 2][y + 1]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 1][y - 2]++;
			}
			else {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x - 1][y + 2]++;
				matrix2[x - 1][y - 2]++;
			}
		}
		else if (x == 1) {
			if (y == 1) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 6) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
		}
		else if (x == 1) {
			if (y == 1) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 6) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else {
				matrix2[x + 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
				matrix2[x + 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
		}
		else if (x == 6) {
			if (y == 1) {
				matrix2[x - 2][y + 1]++;
				matrix2[x - 2][y - 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 6) {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else if (y == 0) {
				matrix2[x - 2][y + 1]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
			else if (y == 7) {
				matrix2[x - 2][y - 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
			}
			else {
				matrix2[x - 2][y - 1]++;
				matrix2[x - 2][y + 1]++;
				matrix2[x + 1][y - 2]++;
				matrix2[x - 1][y - 2]++;
				matrix2[x + 1][y + 2]++;
				matrix2[x - 1][y + 2]++;
			}
		}

	}
public:
	board() : row(8), column(8) {
		init();
		print();
	}
	board(const board& obj) : row(obj.row), column(obj.column) {
		this->matrix1 = new std::string * [row];
		this->matrix2 = new int* [row];

		for (int i = 0; i < row; i++) {
			matrix1[i] = new std::string[column];
			matrix2[i] = new int[column];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				matrix1[i][j] = obj.matrix1[i][j];
				matrix2[i][j] = obj.matrix2[i][j];
			}
		}
	}
	board& operator = (const board& obj) {
		if (this != &obj)
		{
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					this->matrix1[i][j] = obj.matrix1[i][j];
					this->matrix2[i][j] = obj.matrix2[i][j];
				}
			}
		}
		return *this;
	}

	~board() {
		for (int i = 0; i < row; i++)
		{
			delete[] matrix1[i];
			delete[] matrix2[i];
		}
		delete[] matrix1;
		delete[] matrix2;

		std::cout << "Board deleted" << std::endl;
	}
public:
	void print() {
		std::cout << "  1   2   3   4   5   6   7   8   (x)" << std::endl;
		for (int i = 0; i < row; i++)
		{
			std::cout << i + 1 << ' ';
			for (int j = 0; j < column; j++)
			{
				std::cout << matrix1[i][j] << "  ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		std::cout << "(y)" << std::endl;
		std::cout << std::endl;
	}
	void print_num() {
		std::cout << " 1  2  3  4  5  6  7  8  (x)" << std::endl;
		for (int i = 0; i < row; i++)
		{
			std::cout << i + 1 << ' ';
			for (int j = 0; j < column; j++)
			{
				std::cout << matrix2[i][j] << "  ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		std::cout << "(y)" << std::endl;
		std::cout << std::endl;
	}
	void set(king k) {

		if (isfree(k.x, k.y) && kingcheck(k.x, k.y))
		{
			matrix1[k.x][k.y] = k.name;
			if (k.name == "BK")
			{
				att_k(k.x, k.y);
			}
		}
		else if (!isfree(k.x, k.y)) {
			std::cout << "Error: cordinates are already in use" << std::endl;
			abort();
		}
		else if (!kingcheck(k.x, k.y)) {
			std::cout << "Error: kings must be far at least by one cell" << std::endl;
			abort();
		}
	}
	void set(queen q) {
		if (isfree(q.x, q.y))
		{
			matrix1[q.x][q.y] = q.name;
			att_q(q.x, q.y, q.name);
		}
	}
	void set(bishop b) {
		if (isfree(b.x, b.y))
		{
			matrix1[b.x][b.y] = b.name;
			att_b(b.x, b.y, b.name);
		}
	}
	void set(knight n) {
		if (isfree(n.x, n.y))
		{
			matrix1[n.x][n.y] = n.name;
			att_n(n.x, n.y);
		}
	}
	int condition(king k) {
		int count = 8;
		int min = 0;
		int x = k.x;
		int y = k.y;
		if (y != 0 && y != 7)
		{
			if (x != 0 && x != 7)
			{
				if (matrix2[x][y + 1] != 0 && matrix1[x][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y + 1] >= 2 && matrix1[x][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y + 1] != 0 && matrix1[x + 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y + 1] >= 2 && matrix1[x + 1][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y] != 0 && matrix1[x + 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y] >= 2 && matrix1[x + 1][y] != "__") {
					count--;
				}

				if (matrix2[x + 1][y - 1] != 0 && matrix1[x + 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y - 1] >= 2 && matrix1[x + 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x][y - 1] != 0 && matrix1[x][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y - 1] >= 2 && matrix1[x][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y - 1] != 0 && matrix1[x - 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y - 1] >= 2 && matrix1[x - 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y] != 0 && matrix1[x - 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y] >= 2 && matrix1[x - 1][y] != "__") {
					count--;
				}

				if (matrix2[x - 1][y + 1] != 0 && matrix1[x - 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y + 1] >= 2 && matrix1[x - 1][y + 1] != "__") {
					count--;
				}
			}
			else if (x == 0) {
				min = 3;
				if (matrix2[x][y + 1] != 0 && matrix1[x][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y + 1] >= 2 && matrix1[x][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y + 1] != 0 && matrix1[x + 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y + 1] >= 2 && matrix1[x + 1][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y] != 0 && matrix1[x + 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y] >= 2 && matrix1[x + 1][y] != "__") {
					count--;
				}

				if (matrix2[x + 1][y - 1] != 0 && matrix1[x + 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y - 1] >= 2 && matrix1[x + 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x][y - 1] != 0 && matrix1[x][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y - 1] >= 2 && matrix1[x][y - 1] != "__") {
					count--;
				}
			}
			else if (x == 7) {
				min = 3;
				if (matrix2[x][y - 1] != 0 && matrix1[x][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y - 1] >= 2 && matrix1[x][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y - 1] != 0 && matrix1[x - 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y - 1] >= 2 && matrix1[x - 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y] != 0 && matrix1[x - 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y] >= 2 && matrix1[x - 1][y] != "__") {
					count--;
				}

				if (matrix2[x - 1][y + 1] != 0 && matrix1[x - 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y + 1] >= 2 && matrix1[x - 1][y + 1] != "__") {
					count--;
				}

				if (matrix2[x][y + 1] != 0 && matrix1[x][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y + 1] >= 2 && matrix1[x][y + 1] != "__") {
					count--;
				}
			}
		}
		else if (y == 0)
		{
			min = 5;
			if (x == 0)
			{
				if (matrix2[x][y + 1] != 0 && matrix1[x][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y + 1] >= 2 && matrix1[x][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y + 1] != 0 && matrix1[x + 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y + 1] >= 2 && matrix1[x + 1][y + 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y] != 0 && matrix1[x + 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y] >= 2 && matrix1[x + 1][y] != "__") {
					count--;
				}
			}
			else if (x == 7) {
				if (matrix2[x][y + 1] != 0 && matrix1[x][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y + 1] >= 2 && matrix1[x][y + 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y + 1] != 0 && matrix1[x - 1][y + 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y + 1] >= 2 && matrix1[x - 1][y + 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y] != 0 && matrix1[x - 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y] >= 2 && matrix1[x - 1][y] != "__") {
					count--;
				}
			}
		}
		else if (y == 7)
		{
			min = 5;
			if (x == 0)
			{
				if (matrix2[x][y - 1] != 0 && matrix1[x][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y - 1] >= 2 && matrix1[x][y - 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y - 1] != 0 && matrix1[x + 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y - 1] >= 2 && matrix1[x + 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x + 1][y] != 0 && matrix1[x + 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x + 1][y] >= 2 && matrix1[x + 1][y] != "__") {
					count--;
				}
			}
			else if (x == 7) {
				if (matrix2[x][y - 1] != 0 && matrix1[x][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x][y - 1] >= 2 && matrix1[x][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y - 1] != 0 && matrix1[x - 1][y - 1] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y - 1] >= 2 && matrix1[x - 1][y - 1] != "__") {
					count--;
				}

				if (matrix2[x - 1][y] != 0 && matrix1[x - 1][y] == "__")
				{
					count--;
				}
				else if (matrix2[x - 1][y] >= 2 && matrix1[x - 1][y] != "__") {
					count--;
				}
			}
		}

		if (min == 0)
		{
			if (count == 0)
			{
				if (matrix2[x][y] > 0)
				{
					return 1; //mate
				}
				else if (matrix2[x][y] == 0)
				{
					return 2; //stalemate
				}
			}
			else {
				return 3;
			}
		}
		else if (min == 5) {
			if (count == 5)
			{
				if (matrix2[x][y] > 0)
				{
					return 1; //mate
				}
				else if (matrix2[x][y] == 0)
				{
					return 2; //stalemate
				}
			}
			else {
				return 3;
			}
		}
		else if (min == 3) {
			if (count == 3)
			{
				if (matrix2[x][y] > 0)
				{
					return 1; //mate
				}
				else if (matrix2[x][y] == 0)
				{
					return 2; //stalemate
				}
			}
			else {
				return 3;
			}
		}
	}
};