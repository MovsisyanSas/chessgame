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
	const int column = 8;
	int cond = -1;
	const int row = 8;
	board b{row,column};
	int x = 0, y = 0;
private:
	std::vector<std::string> figurecords = { "WKh1","BKH3","BNa3","BBA7","BQh8" };
	std::vector<figure*> figures;
	void parser();
	void deleter();
	void m1();
public:
	chessminigame() = default;
	void start() override;
	void finish()  override;
};


#endif  // GAME_H
