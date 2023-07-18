#include "matrix.h"

bool board::kingcheck(int x, int y) {
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
void board::set(king k) {

	if (isfree(k.x, k.y) && kingcheck(k.x, k.y))
	{
		matrix1[k.x][k.y] = k.name;
		if (k.name == "BK")
		{
			att.att_k(k.x, k.y, matrix2);
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
void board::set(queen q) {
	if (isfree(q.x, q.y))
	{
		matrix1[q.x][q.y] = q.name;
		att.att_q(q.x, q.y, row, q.name, matrix2, matrix1);
	}
}
void board::set(bishop b) {
	if (isfree(b.x, b.y))
	{
		matrix1[b.x][b.y] = b.name;
		att.att_b(b.x, b.y, b.name, matrix2, matrix1);
	}
}
void board::set(knight n) {
	if (isfree(n.x, n.y))
	{
		matrix1[n.x][n.y] = n.name;
		att.att_n(n.x, n.y, matrix2);
	}
}
int board::condition(king k) {
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