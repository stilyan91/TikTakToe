#include <sstream>

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

