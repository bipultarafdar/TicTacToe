#include "Board.h"
#include <iostream>

Board::Board(int n, int size) {
	num = n;
	numSquares = size;
	squares = new std::string*[numSquares];
	for (int i = 0; i < numSquares; i++) {
		squares[i] = new std::string[numSquares];
		for (int j = 0; j < numSquares; j++) {
			squares[i][j] = "";
		}
	}
	p1 = Player("O");
	p2 = Player("X");
}

bool Board::fillSquare(int row, int col, Player p) {
	std::string* val = &squares[row][col];
	if (*val == "O" || *val == "X") {
		return false;
	}
	else {
		*val = p.symbol;
	}
	return true;
}

std::string Board::checkVertical() {
	std::string val = "";
	int count = 1;
	for (int i = 0; i < numSquares; i++) {
		for (int j = 0; j < numSquares - 1; j++) {
			if (squares[j][i] == "O" || squares[j][i] == "X") {
				if (squares[j][i] == squares[j + 1][i]) {
					count++;
					if (count == num) {
						val = squares[j][i];
					}
				}
			}
		}
		if (count < num) {
			count = 1;
		}
	}
	return val;
}

std::string Board::checkHorizontal() {
	std::string val = "";
	int count = 1;
	for (int i = 0; i < numSquares; i++) {
		for (int j = 0; j < numSquares-1; j++) {
			if (squares[i][j] == "O" || squares[i][j] == "X") {
				if (squares[i][j] == squares[i][j + 1]) {
					count++;
					if (count == num) {
						val = squares[i][j];
					}
				}
			}
		}
		if (count < num) {
			count = 1;
		}
	}
	return val;
}

std::string Board::diagRight(int i, int j) {
	std::string val = "";
	int count = 1;
	for (; i < numSquares-1 && j < numSquares-1; i++, j++) {
		if (squares[i][j] == "O" || squares[i][j] == "X") {
			if (squares[i][j] == squares[i + 1][j + 1]) {
				count++;
				if (count == num) {
					val = squares[i][j];
				}
			}
		}
		if (count < num && i == numSquares) {
			count = 1;
		}
	}
	return val;
}

std::string Board::checkRightDiag() {
	int i = 0, j = 0;
	std::string val;
	while (i < numSquares) {
		val = diagRight(i, j);
		if (val != "") return val;
		i++;
	}
	i = 0;
	j++;
	while (j < numSquares) {
		val = diagRight(i, j);
		if (val != "") return val;
		j++;
	}
	return val;
}

std::string Board::diagLeft(int i, int j) {
	std::string val = "";
	int count = 1;
	for (; i < numSquares-1 && j >= 0; i++, j--) {
		if (squares[i][j] == "O" || squares[i][j] == "X") {
			if (squares[i][j] == squares[i + 1][j + 1]) {
				count++;
				if (count == num) {
					val = squares[i][j];
				}
			}
		}
		if (count < num && i == numSquares) {
			count = 1;
		}
	}
	return val;
}


std::string Board::checkLeftDiag() {
	int i = 0, j = numSquares-1;
	std::string val;
	while (i < numSquares) {
		val = diagLeft(i, j);
		if (val != "") return val;
		i++;
	}
	i = 0;
	j--;
	while (j >= 0) {
		val = diagLeft(i, j);
		if (val != "") return val;
		j--;
	}
	return val;
}


std::string Board::checkDiag() {
	std::string val = checkRightDiag();
	if (val == "X" || val == "O") return val;
	else return checkLeftDiag();
}

std::string Board::check() {
	std::string val = checkHorizontal();
	if (val == "X" || val == "O") return val;
	val = checkVertical();
	if (val == "X" || val == "O") return val;
	val = checkDiag();
	if (val == "X" || val == "O") return val;
	return val;
}

void Board::printBoard() {
	for (int i = 0; i < numSquares; i++) {
		for (int j = 0; j < numSquares; j++) {
			if (squares[i][j] == "") {
				std::cout << "(" << i << "," << j << ")" << ' ';
			}
			else {
				std::cout << "  " << squares[i][j] << "   ";
			}

		}
		std::cout << std::endl << std::endl;
	}
}

Board::~Board()
{
	for (int i = 0; i < numSquares; i++) {
		delete[] squares[i];
	}
	delete[] squares;
}
