#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
	static inline int nextId = 1;
	int id, wins;
	mutable std::string name;
	char c;

public:
	Player() : id(nextId++),
		name("Player " + std::to_string(id)),
		wins(0),
		c('X') {}

	std::string getName() const { return name; }

	int getWins() const { return wins; }

	char getChar() const { return c; }
	void incrementWin() { wins++; }

	void setChar(char x) { c = x; }
	void setName(std::string newName) { name = newName; }



	friend std::istream& operator>>(std::istream &iStr, Player& p);
	friend std::ostream& operator<<(std::ostream &oStr, const Player& p);
};
inline std::istream& operator>>(std::istream &iStr, Player& p)
{
	std::string newName;
	getline(iStr, newName);
	p.setName(newName);
	return iStr;
}


#endif