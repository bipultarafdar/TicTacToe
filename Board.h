#pragma once
#include "Player.h"
#include <vector>

class Board
{
public:
	int num;
	int numSquares;
	std::string **squares;
	Player p1;
	Player p2;
	bool fillSquare(int row, int col, Player p);
	std::string checkHorizontal();
	std::string checkVertical();
	std::string diagRight(int i, int j);
	std::string diagLeft(int i, int j);
	std::string checkRightDiag();
	std::string checkLeftDiag();
	std::string checkDiag();
	std::string check();
	void printBoard();
	Board(int num, int size);
	Board();
	~Board();
};

