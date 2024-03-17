#include <iostream>

#include "Board.h"

int main() {

	Board& board = Board::getInstance();

	for (int i = 0; i < 9; i++) {
		std::cout << board[i] << std::endl;
	}
}