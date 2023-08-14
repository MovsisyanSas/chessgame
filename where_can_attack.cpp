#include "attack.h"

void where_can_attack::where_can_att_k(int x, int y) {
	std::vector<int> possible_cells;
	if (y != 0 && y != 7)
	{
		if (x != 0 && x != 7)
		{
			possible_cells.push_back();
			[x][y + 1];
			matrix2[x][y - 1]++;
			matrix2[x + 1][y + 1]++;
			matrix2[x - 1][y - 1]++;
			matrix2[x - 1][y + 1]++;
			matrix2[x + 1][y - 1]++;
			matrix2[x + 1][y]++;
			matrix2[x - 1][y]++;
		}
		else if (x == 0)
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