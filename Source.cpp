#include <iostream>
#include "Board.h"

int main() {
	std::string play = "Y";
	while (play == "Y") {
		int num, size;
		std::cout << "Enter the num to win ";
		std::cin >> num;
		std::cout << std::endl;
		std::cout << "Enter the size of Board ";
		std::cin >> size;
		std::cout << std::endl;
		Board board(num, size);

		bool turn = false;
		Player p;
		int row, col;

		while (board.check() == "") {
			std::cout.flush();
			turn = !turn;
			board.printBoard();
			if (turn) {
				p = board.p1;
			}
			else {
				p = board.p2;
			}

			std::cout << "Enter row and col for " << p.symbol << std::endl;
			std::cin >> row >> col;
			std::cout << std::endl;

			board.fillSquare(row, col, p);
		}

		board.printBoard();

		std::cout << "Winner is " << p.symbol << std::endl;

		std::cout << "\nNew Game? (Y or N) " << std::endl;
		std::cin >> play;
	}
}