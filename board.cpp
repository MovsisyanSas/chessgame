#include "matrix.h"
#include <iostream>

double board::distance(int x1, int y1, int x2, int y2) {
	double X = std::pow(x1 - x2, 2);
	double Y = std::pow(y1 - y2, 2);
	if ((x1 - x2) == (y1 - y2)) {
		return std::pow(X + Y, 0.5) - 0.1;
	}
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

		if (Name == "BK")
		{
			att.att_k(X, Y, matrix2);
		}
		else if (Name == "BQ") {
			att.att_q(X, Y, row, matrix2, matrix1);
		}
		else if (Name == "BB") {
			att.att_b(X, Y, matrix2, matrix1);
		}
		else if (Name == "BN") {
			att.att_n(X, Y,matrix2);
		}
		else if (Name == "WK") {
			att.att_k(X, Y, matrix3);
		}
		else if (Name == "WQ") {
			att.att_q(X, Y, row, matrix3, matrix1);
		}
		else if (Name == "WB") {
			att.att_b(X, Y, matrix3, matrix1);
		}
		else if (Name == "WN") {
			att.att_n(X, Y, matrix3);
		}
	}
}

bool board::isfree(int x, int y, board temp) {
	if (temp.matrix1[x][y] == "__")
	{
		return true;
	}
	return false;
}

bool board::isfree(int x, int y) {
	if (matrix1[x][y] == "__")
	{
		return true;
	}
	return false;
}

board::board(int a, int b) : matrix(a,b) {
	
}

void board::print() {
	std::cout << "  A   B   C   D   E   F   G   H   (x)" << std::endl;
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

void board::print_num_b() {
	std::cout << "  A   B   C   D   E   F   G   H  (x)" << std::endl;
	for (int i = 0; i < row; i++)
	{
		std::cout << i + 1 << ' ';
		for (int j = 0; j < column; j++)
		{
			std::cout << matrix2[i][j] << "   ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << "(y)" << std::endl;
	std::cout << std::endl;
}

void board::print_num_w() {
	std::cout << "  A   B   C   D   E   F   G   H  (x)" << std::endl;
	for (int i = 0; i < row; i++)
	{
		std::cout << i + 1 << ' ';
		for (int j = 0; j < column; j++)
		{
			std::cout << matrix3[i][j] << "   ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << "(y)" << std::endl;
	std::cout << std::endl;
}
int board::condition(figure* k) {
	int** mat = (k->name == "WK") ? matrix2 : matrix3;

	int count = 8;
	int min = 0;
	int x = k->x;
	int y = k->y;
	bool friendly = true;

	if (y != 0 && y != 7)
	{
		if (x != 0 && x != 7)
		{
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
			if (mat[x + 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x][y - 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y] != 0)
			{
				count--;
			}
			if (mat[x - 1][y + 1] != 0)
			{
				count--;
			}
		}
		else if (x == 0) {
			min = 3;
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
			if (mat[x + 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x][y - 1] != 0)
			{
				count--;
			}
		}
		else if (x == 7) {
			min = 3;
			if (mat[x][y - 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y] != 0)
			{
				count--;
			}
			if (mat[x - 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
		}
	}
	else if (y == 0)
	{

		if (x == 0)
		{
			min = 5;
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
		}
		else if (x == 7) {
			min = 5;
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y] != 0)
			{
				count--;
			}
		}
		else
		{
			min = 3;
			if (mat[x][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
			if (mat[x - 1][y + 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y] != 0)
			{
				count--;
			}
		}
	}
	else if (y == 7)
	{

		if (x == 0)
		{
			min = 5;
			if (mat[x][y - 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
		}
		else if (x == 7) {
			min = 5;
			if (mat[x][y - 1] != 0)
			{
				count--;
			}

			if (mat[x - 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x - 1][y] != 0)
			{
				count--;
			}
		}
		else
		{
			min = 3;
			if (mat[x][y - 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y - 1] != 0)
			{
				count--;
			}
			if (mat[x + 1][y] != 0)
			{
				count--;
			}
			if (mat[x - 1][y - 1] != 0)
			{
				count--;
			}
			if (matrix2[x - 1][y] != 0)
			{
				count--;
			}
		}
	}

	if (min == 0)
	{
		if (count == 0)
		{
			if (mat[x][y] > 0)
			{
				return 1; //mate
			}
			else if (mat[x][y] == 0)
			{
				return 2; //stalemate
			}
		}
		else if (mat[x][y] > 0) {
			return 3;
		}
		return 4;
	}
	else if (min == 5) {
		if (count == 5)
		{
			if (mat[x][y] > 0)
			{
				return 1; //mate
			}
			else if (mat[x][y] == 0)
			{
				return 2; //stalemate
			}
		}
		else if(mat[x][y] > 0) {
			return 3;
		}
		return 4;
	}
	else if (min == 3) {
		if (count == 3)
		{
			if (mat[x][y] > 0)
			{
				return 1; //mate
			}
			else if (mat[x][y] == 0)
			{
				return 2; //stalemate
			}
		}
		else if (mat[x][y] > 0) {
			return 3;
		}
		return 4;
	}
	return -1;
}


void board::clear() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrix1[i][j] = "__";
			matrix2[i][j] = 0;
			matrix3[i][j] = 0;
		}
	}
}

figure* board::find_m1(std::vector<figure*> vect,board b_2) {
	board b_copy(8,8);
	possible_attack pos;
	std::vector<figure*> copy = vect;
	std::vector<std::pair<int, int>> new_coords_b;
	std::vector<std::pair<int, int>> new_coords_w;
	figure* wk_copy = vect[1];
	figure* wk_temp = vect[1];
	figure* bk_temp = vect[1];
	figure* bk_copy = vect[1];
	figure* eaten_figure = nullptr;
	figure* eaten_figure_b = nullptr;
	figure* eating_figure = nullptr;
	int first_x_b, first_y_b;
	int first_x_w, first_y_w;
	double d = 0,d2 = 0;
	int place;
	int place_b;
	int win_b, win_w;
	bool fl = false;
	bool fl2 = false;
	bool fl3 = false;

	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i]->name == "WK")
		{
			wk_copy = vect[i];
		}
		else if (vect[i]->name == "BK") {
			bk_copy = vect[i];
		}
	}

	for (int i = 0; i < vect.size(); i++)
	{
		first_y_b = copy[i]->y;
		first_x_b = copy[i]->x;
		if (copy[i]->name == "BK")
		{
			new_coords_b = pos.possible_k(copy[i]->x, copy[i]->y);
		}
		else if (copy[i]->name == "BQ")
		{	
			new_coords_b = pos.possible_q(copy[i]->x, copy[i]->y, 8, copy[i]->name, b_2.matrix1);
		}
		else if (copy[i]->name == "BB")
		{		
			new_coords_b = pos.possible_b(copy[i]->x, copy[i]->y, b_2.matrix1);
		}
		else if (copy[i]->name == "BN")
		{
			new_coords_b = pos.possible_n(copy[i]->x, copy[i]->y);
		}
		else {
			continue;
		}
		for (int j = 0; j < new_coords_b.size(); j++)
		{

			b_copy.clear();
			copy[i]->set(new_coords_b[j].first, new_coords_b[j].second);
			d = board::distance(copy[i]->x, copy[i]->y, wk_copy->x, wk_copy->y);
			if (copy[i]->name == "BK" && d < 2.0)
			{
				continue;
			}
			if (!board::isfree(copy[i]->x, copy[i]->y))
			{

				place_b = 0;
				for (auto it = copy.begin(); it != copy.end(); ++it, ++place_b)
				{
					if ((*it)->x == copy[i]->x && (*it)->y == copy[i]->y && (*it)->name != copy[i]->name)
					{
						if ((*it)->name != "WK" && (*it)->name != "BK" && (*it)->name != "BQ" && (*it)->name != "BB" && (*it)->name != "BN") {
							eaten_figure_b = *it;
							it = copy.erase(it);
							fl2 = true;
							break;
						}
					}
				}
				if (!fl2) {
					copy[i]->set(first_x_b, first_y_b);
					continue;
				}
			}
			
			b_copy.nameplacer(copy);
			b_copy.Att(copy);
			//b_copy.print();
			if (b_copy.condition(wk_copy) == 1 && b_copy.condition(bk_copy) != 1 && b_copy.condition(bk_copy) != 3)
			{
				if (copy[i]->name == "BK")
				{
					bk_temp = bk_copy;
					bk_copy = copy[i];
				}
				for (int k = 0; k < copy.size(); k++)
				{
					first_y_w = copy[k]->y;
					first_x_w = copy[k]->x;
					if (copy[k]->name == "WK")
					{
						wk_temp = wk_copy;
						wk_copy = copy[k];
						new_coords_w = pos.possible_k(copy[k]->x, copy[k]->y);
					}
					else if (copy[k]->name == "WQ")
					{
						new_coords_w = pos.possible_q(copy[k]->x, copy[k]->y, 8, copy[k]->name, b_copy.matrix1);
					}
					else if (copy[k]->name == "WB")
					{
						new_coords_w = pos.possible_b(copy[k]->x, copy[k]->y, b_copy.matrix1);
					}
					else if (copy[k]->name == "WN")
					{
						new_coords_w = pos.possible_n(copy[k]->x, copy[k]->y);
					}
					else {
						continue;
					}
					for (int l = 0; l < new_coords_w.size(); l++) {
						b_copy.clear();
						b_copy.nameplacer(copy);
						copy[k]->set(new_coords_w[l].first, new_coords_w[l].second);
						d2 = board::distance(copy[k]->x, copy[k]->y, bk_copy->x, bk_copy->y);
						if (copy[k]->name == "WK")
						{
							if (d2 < 2.0f) {
								copy[k]->set(first_x_w, first_y_w);
								continue;
							}
							wk_copy = copy[k];
						}
						if (!(board::isfree(copy[k]->x, copy[k]->y, b_copy)))
						{
							place = 0;
							for (auto it2 = copy.begin(); it2 != copy.end(); ++it2, ++place)
							{
								if ((*it2)->x == copy[k]->x && (*it2)->y == copy[k]->y && (*it2)->name != copy[k]->name)
								{
									if ((*it2)->name != "WK" && (*it2)->name != "BK" && (*it2)->name != "WQ" && (*it2)->name != "WB" && (*it2)->name != "WN") {
										eaten_figure = *it2;
										eating_figure = copy[k];
										it2 = copy.erase(it2);
										fl3 = true;
										break;
									}
								}
							}
							if (!fl3) {
								copy[k]->set(first_x_w, first_y_w);
								continue;
							}
						}
						b_copy.clear();
						b_copy.nameplacer(copy);
						b_copy.Att(copy);
						//b_copy.print();
						//b_copy.print_num_w();
						//b_copy.print_num_b();
						win_b = b_copy.condition(bk_copy);
						win_w = b_copy.condition(wk_copy);
						if (win_b != 1 && win_b != 3)
						{
							if (win_w != 1 && win_w != 3) {
								fl = true;
								bk_copy = bk_temp;
								wk_copy = wk_temp;
								
								if (fl3) {
									eating_figure->set(first_x_w, first_y_w);
									copy.insert(copy.begin() + place, eaten_figure);
									fl3 = false;
								}
								else {
									copy[k]->set(first_x_w, first_y_w);
								}								
								break;
							}
						}
						else if (win_b == 1 || win_b == 3) {
							if (win_w != 1 && win_w != 3) {
								fl = true;
								bk_copy = bk_temp;
								wk_copy = wk_temp;
								if (fl3) {
									eating_figure->set(first_x_w, first_y_w);
									copy.insert(copy.begin() + place, eaten_figure);
									fl3 = false;
								}
								else {
									copy[k]->set(first_x_w, first_y_w);
								}
								break;
							}
							
						}
						if (fl3) {
							copy.insert(copy.begin() + place, eaten_figure);
							fl3 = false;
						}
						copy[k]->set(first_x_w, first_y_w);
					}
					if (fl)
					{
						break;
					}
				}
				if (!fl)
				{
					return copy[i];
				}
				else {
					fl = false;
				}
				if (fl2) {
					copy.insert(copy.begin() + place_b, eaten_figure_b);
					fl2 = false;
				}
			}
		}
		copy[i]->set(first_x_b, first_y_b);
	}
	return nullptr;
}