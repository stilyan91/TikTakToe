#ifndef BOARD_H
#define BOARD_H

#include <stdexcept>
#include <iostream>

#include "Player.h"

class Board {
public:
	static const int boardSize = 9;


private:
	char board[boardSize] = { ' ', ' ', ' ',
							  ' ', ' ', ' ', 
							  ' ', ' ', ' ' };
public:
	Board() = default;

	static Board& getInstance() {
		static Board instance;
		return instance;
	}
	// Iterator
	class Iterator {
	public:
		Board& board;
		int idx;

		Iterator(Board& board, int idx) : board(board), idx(idx) {}

		//Operator Increment prefix
		Iterator& operator*() { idx++; return *this; }

		// Operator Not Equal 

		bool operator!=(const Iterator& other) const { return idx != other.idx; }

		// Operator Equal

		bool operator==(const Iterator& other) const { return idx == other.idx; }

		// Operator deference

		char& operator*() const { return board.board[idx]; }
	};

	// Operator Begin
	Iterator begin() { return Iterator(*this, 0); }
	// Operator End
	Iterator end() { return Iterator(*this, 9); }

	// Operator []
	char& operator[](int idx) {
		if (idx < 0 || idx >= boardSize)
			throw std::out_of_range("Index out of range");
		else
			return board[idx];
	}

	// COPY CONSTRUCTOR DISSAWOLLED
	Board(const Board& other) = delete;
	// MOVE CONSTRUCTOR DISSAWOLLED
	Board(Board&& other) = delete;

	// DISSAWOLLED copy/move assignment operators
	Board& operator=(const Board& other) = delete;
	Board& operator=(Board&& other) = delete;

	friend std::ostream& operator<<(std::ostream& oStr, const Board& b);

	friend std::istream& operator>>(std::istream & iStr, Board& b);

	const char* getBoard () {
		return board;
	}

	char getBoardIndex(int index) const ;
	
	void setCharToIndex(int index, char c);

	bool checkDiagonals() const;

	bool checkVerticals() const;

	bool checkHorizontals() const;

	bool checkForWin(Player& p) const ;

	bool isNewGame();
};



#endif // !BOARD_H

