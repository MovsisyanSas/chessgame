#include "game.h"

int game::converter(char c) {
	switch (c)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case '0':
		return 0;
		break;
	default:
		return -1;
		break;
	}
}
void chessminigame::parser(){
	std::string color;
	std::string full;
	int x, y;
	char name;
	for (int i = 0; i < figurecords.size(); i++)
	{
		full = figurecords[i];
		figure* Figure;
		color = full[0];
		name = full[1];
		x = game::converter(full[2]);
		y = game::converter(full[3]);

		switch (name)
		{
		case 'K':
			Figure = new king(color, x, y);
			break;
		case 'Q':
			Figure = new queen(color, x, y);
			break;
		case 'B':
			Figure = new bishop(color, x, y);
			break;
		case 'N':
			Figure = new knight(color, x, y);
			break;
		default:
			break;
		}
		figures.push_back(Figure);
	}
}
void chessminigame::deleter() {
	for (int i = 0; i < figures.size(); i++)
	{
		delete[] figures[i];
	}
}

void chessminigame::m1() {
	std::vector<figure*> figures_c(figures.begin(), figures.end());
	figure* mate_figure = b.find_m1(figures_c,b);
	if (mate_figure)
	{
		std::cout << "Mate from 1: " << mate_figure->name <<"->" << mate_figure->y + 1 << ',' << mate_figure->x + 1 << "(x,y)" << std::endl;
	}
	else
	{
		std::cout << "There is not mate from 1 move for black side" << std::endl;
	}
	
}

void chessminigame::start() {
	parser();
	b.nameplacer(figures);
	b.Att(figures);
	system("cls");

	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->name == "WK")
		{
			cond = b.condition(figures[i]);
			break;
		}
	}
}
void chessminigame::finish() {
	b.print();
	switch (cond)
	{
	case 1:
		std::cout << "Mate" << std::endl;
		break;
	case 2:
		std::cout << "Stalemate " << std::endl;
		m1();
		break;
	case 3:
		std::cout << "No win or draw condition " << std::endl;
		m1();
		break;
	default:
		std::cout << "Error " << std::endl;
		break;
	}
	deleter();
}
