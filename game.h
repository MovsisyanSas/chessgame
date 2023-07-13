#pragma once
#include <iostream>
#include "figure.h"
#include "board.h"

int cond;

class game {
public:
	static void start() {
		board b;
		int x, y;
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

		std::cout << "Enter position for black knight(x,y): ";
		std::cin >> x >> y;
		knight bn("B", x, y);
		b.set(bn);
		system("cls");
		b.print();
		
		/*b.print_num(); */
		cond = b.condition(wk);
	}
	static void finish() {
		
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
};