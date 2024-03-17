

class Board {

	static const int boardSize = 9;



private:
	char board[9];


public:
	Board() = default;

	static Board& getInstance() {
		static Board instance;
		return instance;
	}

	// COPY CONSTRUCTOR DISSAWOLLED
	Board(const Board& other) = delete;
	// MOVE CONSTRUCTOR DISSAWOLLED
	Board(Board&& other) = delete;

	// DISSAWOLLED copy/move assignment operators
	Board& operator=(const Board& other) = delete;
	Board& operator=(Board&& other) = delete;

};