#ifndef GAME_H
#define GAME_H

// Game class declaration

class Game
{
private:
	char choice;
	int playerWins;
	int computerChoice;
	int computerWins;
	int result;

public:
	bool exit = false;
	int chooseAgain = 0;
	Game(); // constructor
	void getName();
	void getChoice();
	void getResult();
	void dispResult();
	void dispScore();
	~Game(); // destructor
};

#endif