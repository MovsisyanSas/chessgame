#include "attack.h"

std::vector<std::pair<int, int>> possible_attack::possible_k(int x, int y) {
	std::vector<std::pair<int, int>> possible_cells;

	if (y != 0 && y != 7) {
		if (x != 0 && x != 7) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
			possible_cells.push_back(std::make_pair(x - 1, y));
		}
		if (x == 0) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
			possible_cells.push_back(std::make_pair(x + 1, y - 1));
			possible_cells.push_back(std::make_pair(x, y - 1));
		}
		else if (x == 7) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y));
			possible_cells.push_back(std::make_pair(x - 1, y - 1));
			possible_cells.push_back(std::make_pair(x, y - 1));
		}
	}
	else if (y == 0) {
		if (x != 0 && x != 7) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
			possible_cells.push_back(std::make_pair(x - 1, y));
		}
		if (x == 0) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
		}
		else if (x == 7) {
			possible_cells.push_back(std::make_pair(x, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y));
		}
	}
	else if (y == 7) {
		if (x != 0 && x != 7) {
			possible_cells.push_back(std::make_pair(x, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
			possible_cells.push_back(std::make_pair(x - 1, y));
		}
		if (x == 0) {
			possible_cells.push_back(std::make_pair(x, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y));
		}
		else if (x == 7) {
			possible_cells.push_back(std::make_pair(x, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y));
		}
	}

	return possible_cells;
}

std::vector<std::pair<int, int>> possible_attack::possible_q(int x, int y, int row, std::string name, std::string** matrix1) {
	std::vector<std::pair<int, int>> possible_cells;

	for (int i = x + 1; i < row; i++) {
		possible_cells.push_back(std::make_pair(i, y));
		if (matrix1[i][y] != "__" && matrix1[i][y] != "WK") {
			break;
		}
	}
	for (int i = x - 1; i >= 0; i--) {
		possible_cells.push_back(std::make_pair(i, y));
		if (matrix1[i][y] != "__" && matrix1[i][y] != "WK") {
			break;
		}
	}
	for (int i = y + 1; i < row; i++) {
		possible_cells.push_back(std::make_pair(x, i));
		if (matrix1[x][i] != "__" && matrix1[x][i] != "WK") {
			break;
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		possible_cells.push_back(std::make_pair(x, i));
		if (matrix1[x][i] != "__" && matrix1[x][i] != "WK") {
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
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			possible_cells.push_back(std::make_pair(i, j));
			i++;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}
	
	if (x != 0 && y != 7)
	{
		i = x - 1;
		j = y + 1;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			possible_cells.push_back(std::make_pair(i, j));
			i--;
			j++;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 0 && y != 0)
	{
		i = x - 1;
		j = y - 1;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			possible_cells.push_back(std::make_pair(i, j));
			i--;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	if (x != 7 && y != 0)
	{
		i = x + 1;
		j = y - 1;
		do {
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			possible_cells.push_back(std::make_pair(i, j));
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	return possible_cells;
}


std::vector<std::pair<int, int>> possible_attack::possible_b(int x, int y, std::string** matrix1) {
	std::vector<std::pair<int, int>> possible_cells;

	int i;
	int j;

	if (x != 7 && y != 7)
	{
		i = x + 1;
		j = y + 1;
		do {
			possible_cells.push_back(std::make_pair(i, j));
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
			possible_cells.push_back(std::make_pair(i, j));
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
			possible_cells.push_back(std::make_pair(i, j));
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
			possible_cells.push_back(std::make_pair(i, j));
			if (matrix1[i][j] != "__" && matrix1[i][j] != "WK") {
				break;
			}
			i++;
			j--;
		} while (i >= 0 && i < 8 && j >= 0 && j < 8);
	}

	return possible_cells;
}


std::vector<std::pair<int, int>> possible_attack::possible_n(int x, int y) {
	std::vector<std::pair<int, int>> possible_cells;

	if (x != 1 && x != 0 && x != 6 && x != 7) {
		if (y == 1) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
		}
		else if (y == 6) {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else if (y == 0) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
		}
		else if (y == 7) {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
		}
		else {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
	}
	else if (x == 0) {
		if (y == 1) {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
		}
		else if (y == 6) {
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
		}
		else if (y == 0) {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
		}
		else if (y == 7) {
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
		}
		else {
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
		}
	}
	else if (x == 7) {
		if (y == 1) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 6) {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else if (y == 0) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 7) {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
	}
	else if (x == 1) {
		if (y == 1) {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 6) {
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else if (y == 0) {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 7) {
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else {
			possible_cells.push_back(std::make_pair(x + 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
	}
	else if (x == 6) {
		if (y == 1) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 6) {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else if (y == 0) {
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
		}
		else if (y == 7) {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
		else {
			possible_cells.push_back(std::make_pair(x - 2, y - 1));
			possible_cells.push_back(std::make_pair(x - 2, y + 1));
			possible_cells.push_back(std::make_pair(x + 1, y - 2));
			possible_cells.push_back(std::make_pair(x + 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y + 2));
			possible_cells.push_back(std::make_pair(x - 1, y - 2));
		}
	}

	return possible_cells;
}

