#include "attack.h"


void attack::att_k(int x, int y, int** matrix2) {
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
void attack::att_q(int x, int y, int row, int** matrix2, std::string** matrix1) {
	for (int i = x + 1; i < row; i++)
	{
		matrix2[i][y]++;
		if (matrix1[i][y] != "__" && matrix1[i][y] != "WK")
		{
			break;
		}
	}
	for (int i = x - 1; i >= 0; i--)
	{
		matrix2[i][y]++;
		if (matrix1[i][y] != "__" && matrix1[i][y] != "WK")
		{
			break;
		}
	}
	for (int i = y + 1; i < row; i++)
	{
		matrix2[x][i]++;
		if (matrix1[x][i] != "__" && matrix1[x][i] != "WK")
		{
			break;
		}
	}
	for (int i = y - 1; i >= 0; i--)
	{
		matrix2[x][i]++;
		if (matrix1[x][i] != "__" && matrix1[x][i] != "WK")
		{
			break;
		}
	}

	int i;
	int j;

	if (x != 7 && y != 7)
	{
		i = x + 1;
		j = y + 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i++;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 0 && y != 7)
	{
		i = x - 1;
		j = y + 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i--;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 0 && y != 0)
	{
		i = x - 1;
		j = y - 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i--;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 7 && y != 0)
	{
		i = x + 1;
		j = y - 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}
}
void attack::att_b(int x, int y, int** matrix2, std::string** matrix1) {
	int i;
	int j;

	if (x != 7 && y != 7)
	{
		i = x + 1;
		j = y + 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i++;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 0 && y != 7)
	{
		i = x - 1;
		j = y + 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i--;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 0 && y != 0)
	{
		i = x - 1;
		j = y - 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i--;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 7 && y != 0)
	{
		i = x + 1;
		j = y - 1;
		do {
			matrix2[i][j]++;
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}
}

void attack::att_n(int x, int y, int** matrix2) {
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
