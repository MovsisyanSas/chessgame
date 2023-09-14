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
		x = full[2] <= 90 ? full[2] - 64 : full[2] - 96;
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
	for (int i = 0; i < figures.size(); i++) {
		figures[i] = nullptr;
		delete figures[i];
	}
}

void chessminigame::m1() {
	std::vector<figure*> figures_c(figures.begin(), figures.end());
	figure* mate_figure = b.find_m1(figures_c,b);
	if (mate_figure != nullptr)
	{
		char c = mate_figure->y + 65;
		std::cout << "Mate from 1: " << mate_figure->name <<"->" << c << mate_figure->x + 1 << "(x,y)" << std::endl;
		
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
		//b.print_num_b();
		m1();
		break;
	case 3:
		std::cout << "No win or draw condition(check) " << std::endl;
		//b.print_num_b();
		m1();
		break;
	case 4:
		std::cout << "No win or draw condition " << std::endl;
		//b.print_num_b();
		m1();
		break;
	default:
		std::cout << "Error " << std::endl;
		break;
	}
	deleter();
}

std::string chessgame::txtReader(std::string line) {
	std::string result = "";

	if (line.find("Black") != std::string::npos) {
		result += "B";
	}
	else if (line.find("White") != std::string::npos) {
		result += "W";
	}

	if (line.find("King") != std::string::npos) {
		result += "K";
	}
	else if (line.find("Queen") != std::string::npos) {
		result += "Q";
	}
	else if (line.find("Bishop") != std::string::npos) {
		result += "B";
	}
	else if (line.find("Knight") != std::string::npos) {
		result += "N";
	}

	result += line[line.length() - 2];
	result += line[line.length() - 1];

	return result;
}


chessminigame::chessminigame() {
	std::string line;
	while (std::getline(txt, line))
	{
		figurecords.push_back(chessgame::txtReader(line));
	}
}

void chessminigame::add_figure(std::string s) {
	try {
		if (s.length() < 4)
		{
			throw("Unsuitable form of string");
		}
		int	y = game::converter(s[3]);
		int x = s[2] <= 90 ? s[2] - 64 : s[2] - 96;
		if (x < 0 || x > 8 || y < 0 || y > 8)
		{
			throw("Coords are out of the board");
		}
		std::string color;
		color = s[0];

		if (color == "W")
			throw("White figure addition is temporary unavailable");

		char name = s[1];
		figure* Figure;
		switch (name)
		{
		case 'K':
			throw("Only one king of each side is allowed to be on the board");
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
		b.clear();
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
	catch (std::string s) {
		std::cout << s << std::endl;
	}
	catch (...) {
		std::cout << "unexpected error" << std::endl;
	}
}