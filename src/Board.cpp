#include <sstream>
#include <algorithm>

#include "Board.h"
#include "Player.h"



std::ostream& operator<<(std::ostream & oStr, const Board& b) {
	oStr << "   |   |   \n"
		<< " " << b.board[0] << " |" << " " << b.board[1] << " |" << " " << b.board[2] << " \n"
		<< "___|___|___\n"
		<< "   |   |   \n"
		<< " " << b.board[3] << " |" << " " << b.board[4] << " |" << " " << b.board[5] << " \n"
		<< "___|___|___\n"
		<< "   |   |   \n"
		<< " " << b.board[6] << " |" << " " << b.board[7] << " |" << " " << b.board[8] << " \n"
		<< "___|___|___" << std::endl;
	return oStr;
}

std::istream& operator>>(std::istream& iStr, Board& b) {

	return iStr;
}


char Board::getBoardIndex(int index) const {
	if (index < 0 || index > 8)
		throw std::out_of_range("Index out of range");
	else
		return board[index];
}

void Board::setCharToIndex(int index,char c) {
	board[index] = c;
}


bool Board::checkDiagonals() const {
	if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]
		|| board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
		return true;
	return false;
}

bool Board::checkVerticals() const {
	for (int i = 0; i < 3; i++) {
		if (board[i] == board[i + 3] && board[i+3] == board[i+6] && board[i] != ' ')
			return true;
	}
	return false;
}
bool Board::checkHorizontals() const {
	for (int i = 0; i < 3; i+=3) {
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ')
			return true;
	}
	return false;

}

bool Board::checkForWin(Player& p) const {
	if (checkDiagonals())
	{
		p.incrementWin();
		return true;
	}

	if (checkVerticals()) {
		p.incrementWin();
		return true;
	}

	if (checkHorizontals()) {
		p.incrementWin();
		return true;
	}

	return false;
	}

bool Board::isNewGame() {
	int answer;
	std::cin >> answer;
	if (answer == 1)
	{
		std::cout << "Starting new game" << std::endl;
		std::fill(std::begin(board), std::end(board), ' ');
		return true;
	}
	std::cout << "Exiting from the game." << std::endl;
	return false;
}