#include <iostream>

#include "Board.h"

void playerMove(Board& board, Player& p) {
	std::cout << p.getName() << " is on turn" << std::endl;
	bool isValidMove = false;
	int move;
	while (!isValidMove) {
		try {
			std::cout << "1-9 for your move." << std::endl;
			std::cout << board;
			if (!(std::cin >> move) || move < 1 || move > 9) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::out_of_range("Move must be between 1-9!");
			}
			if (board[move - 1] != ' ')
				throw std::logic_error("This space is already occupied!");

			board.setCharToIndex(move - 1, p.getChar());
			isValidMove = true;
			system("cls");
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}


int main() {

	Board& board = Board::getInstance();

	Player player1 = Player();
	Player player2 = Player();

	if (player1.getChar() == player2.getChar())
		player2.setChar('O');

	while (true) {

	std::cout << "Wellcome, to my Tik Tak Toe game." << std::endl
		<< "Enter the name for player 1: " << std::endl;
	std::string name;
	std::cin >> player1;
	std::cout << "Enter the name for player 2: " << std::endl;
	std::cin >> player2;
	std::cout << "The game is starting." << std::endl;

		while (true) {
			
			
			playerMove(board, player1);

			playerMove(board, player2);

		}
	}

	
	
}