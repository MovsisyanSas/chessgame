#include "game.h"

int game::converter(char c) {
	switch (c)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 1;
		break;
	case '3':
		return 1;
		break;
	case '4':
		return 1;
		break;
	case '5':
		return 1;
		break;
	case '6':
		return 1;
		break;
	case '7':
		return 1;
		break;
	case '8':
		return 1;
		break;
	case '9':
		return 1;
		break;
	case '0':
		return 1;
		break;
	default:
		return -1;
		break;
	}
}
//void chessminigame::passer(std::vector<std::string> vect){
//	char color;
//	int x, y;
//	char name;
//	for (int i = 0; i < vect.size(); i++)
//	{
//		color = vect[i][1];
//		name = vect[i][2];
//		x = game::converter(vect[i][2]);
//		y = game::converter(vect[i][3]);
//
//		switch (name)
//		{
//		case 'K':
//			
//		default:
//			break;
//		}
//	}
//}

void chessminigame::start() {
	std::cout << "Enter position for white king(x,y): ";
	std::cin >> x >> y;
	king wk("W", x, y);
	b.set(wk);
	system("cls");
	b.print();

	std::cout << "Enter position for black king(x,y): ";
	std::cin >> x >> y;
	king bk("B", x, y);
	b.set(bk);
	system("cls");
	b.print();

	std::cout << "Enter position for black knight(x,y): ";
	std::cin >> x >> y;
	knight bn("B", x, y);
	b.set(bn);
	system("cls");
	b.print();

	std::cout << "Enter position for black queen(x,y): ";
	std::cin >> x >> y;
	queen bq("B", x, y);
	b.set(bq);
	system("cls");
	b.print();

	std::cout << "Enter position for black bishop(x,y): ";
	std::cin >> x >> y;
	bishop bb("B", x, y);
	b.set(bb);
	system("cls");
	b.print();



	//b.print_num();
	cond = b.condition(wk);
}
void chessminigame::finish() {
	switch (cond)
	{
	case 1:
		std::cout << "Mate " << std::endl;
		break;
	case 2:
		std::cout << "Stalemate " << std::endl;
		break;
	case 3:
		std::cout << "No win or draw condition " << std::endl;
		break;
	default:
		std::cout << "Error " << std::endl;
		break;
	}
}