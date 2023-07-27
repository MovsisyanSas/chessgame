#include "matrix.h"
#include <iostream>

double board::distance(int x1, int y1, int x2, int y2) {
	double X = std::pow(x1 - x2, 2);
	double Y = std::pow(y1 - y2, 2);
	return std::pow(X + Y, 0.5);
}

void board::nameplacer(std::vector<figure*> vect) {
	for (int i = 0; i < vect.size(); i++)
	{
		if (isfree(vect[i]->x,vect[i]->y))
		{
			if (vect[i]->name == "WK")
			{
				for (int j = 0; j < vect.size(); j++)
				{
					if (vect[j]->name == "BK")
					{
						if (distance(vect[i]->x, vect[i]->y, vect[j]->x, vect[j]->y) < 1)
						{
							abort();
						}
					}
				}
			}
			matrix1[vect[i]->x][vect[i]->y] = vect[i]->name;
		}
	}
}

void board::Att(std::vector<figure*> vect) {
	std::string Name;
	int X, Y;
	for (int i = 0; i < vect.size(); i++)
	{
		Name = vect[i]->name;
		X = vect[i]->x;
		Y = vect[i]->y;

		if (Name == "WK" || Name == "BK")
		{
			att.att_k(X, Y, matrix2);
		}
		else if (Name == "WQ" || Name == "BQ") {
			att.att_q(X, Y, row, Name, matrix2, matrix1);
		}
		else if (Name == "WB" || Name == "BB") {
			att.att_b(X, Y, Name, matrix2, matrix1);
		}
		else if (Name == "WQ" || Name == "BQ") {
			att.att_n(X, Y,matrix2);
		}
	}
}

bool board::isfree(int x, int y) {
	if (matrix1[x][y] == "__")
	{
		return true;
	}
	return false;
}

board::board(int a, int b) : matrix(a,b) {
	print();
}

void board::print() {
	std::cout << "  1   2   3   4   5   6   7   8   (x)" << std::endl;
	for (int i = 0; i < row; i++)
	{
		std::cout << i + 1 << ' ';
		for (int j = 0; j < column; j++)
		{
			std::cout << matrix::matrix1[i][j] << "  ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << "(y)" << std::endl;
	std::cout << std::endl;
	

}

void board::print_num() {
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

int board::condition(figure* k) {
	int count = 8;
	int min = 0;
	int x = k->x;
	int y = k->y;
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