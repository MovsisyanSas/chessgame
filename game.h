#ifndef GAME_H
#define GAME_H

#include "matrix.h"
#include <vector>

class game {
protected:
	int converter(char c);
public:
	game() = default;
	virtual void start() = 0;
	virtual void finish() = 0;
};

class chessgame :public game {
public:
	chessgame() = default;
	void start() override = 0;
	void finish() override = 0;
};

class chessminigame : public chessgame {
	std::vector<std::string> figures = { "WK11","BK13","BN33","BB88","BQ18"};
	const int row = 8;
	const int column = 8;
	int cond;
	board b{row,column};
	int x = 0, y = 0;
	//void passer(std::vector<std::string> vect);
public:
	chessminigame() = default;
	void start() override;
	void finish()  override;
};


#endif  // GAME_H
