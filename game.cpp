#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//****************************************************************
// Definition of Game. Constructor.								*
//****************************************************************

Game::Game()
{
	computerWins = 0;
	result = -1;
	choice = 'A';
	playerWins = 0;
	computerChoice = -1;
	chooseAgain = 0;
	srand(time(0));
}

//****************************************************************
// This will be the initial prompt for the user					*
//****************************************************************

void Game::getName()
{
	// Ask user for name
	cout << "Please Enter your name\n";
	string name;
	cin >> name;


	cout << "Hello " << name << ", Welcome to Rock, Paper and Scissors Game !\n";

	cout << "Choose one of the following option \n";

	cout << "(R) for rock " << endl << "(P) for paepr " << endl << "(S) for scissors " << endl;

	return;
}

//****************************************************************
// Definition of getChoice. Function that gets the players		*
// choice and sets the computer choice.							*
//****************************************************************

void Game::getChoice()
{
	// Get computer choice
	computerChoice = 1 + rand() % 3;

	// Prompt user for choice


	cout << "Rock, Paper or Scissors? (R, P, S, Q to quit): ";
	cin >> choice;

	// Check for quit
	if (choice == 'Q')
	{
		exit = true;
		return;
	}
	else if (choice != 'P' && choice != 'S' && choice != 'R') {
		cout << "Invalid choice, choose again" << endl;
		chooseAgain = 1;
		return;
	}
}

//****************************************************************
// Definition of getResults. Function that gets the result and	*
// updates the number of wins.									*
//****************************************************************

void Game::getResult()
{
	// Determine winner
	switch (choice) {
	case 'R':
		switch (computerChoice) {
		case 1:
			result = 0;
			break;
		case 2:
			result = 1;
			computerWins++;
			break;
		case 3:
			result = 2;
			playerWins++;
			break;
		}
		break;
	case 'P':
		switch (computerChoice) {
		case 1:
			result = 2;
			playerWins++;
			break;
		case 2:
			result = 0;
			break;
		case 3:
			result = 1;
			computerWins++;
			break;
		}
		break;
	case 'S':
		switch (computerChoice) {
		case 1:
			result = 1;
			computerWins++;
			break;
		case 2:
			result = 2;
			playerWins++;
			break;
		case 3:
			result = 0;
		}
		break;
	}
}

//****************************************************************
// Definition of dispResult. Function that displays what was	*
// chosen by the computer and the player. Then displays result.	*
//****************************************************************

void Game::dispResult()
{
	// Display results
	switch (computerChoice) {
	case 1:
		switch (choice) {
		case 'R':
			cout << "Computer has chosen: Rock, Player has chosen: Rock" << endl;
			break;
		case 'P':
			cout << "Computer has chosen: Rock, Player has chosen: Paper" << endl;
			break;
		case 'S':
			cout << "Computer chose: Rock, Player has chosen: Scissors" << endl;
			break;
		}
		break;
	case 2:
		switch (choice) {
		case 'R':
			cout << "Computer has chosen: Paper, Player has chosen: Rock" << endl;
			break;
		case 'P':
			cout << "Computer has chosen: Paper, Player has chosen: Paper" << endl;
			break;
		case 'S':
			cout << "Computer has chosen: Paper, Player has chosen: Scissors" << endl;
			break;
		}
		break;
	case 3:
		switch (choice) {
		case 'R':
			cout << "Computer has chosen: Scissors, Player has chosen: Rock" << endl;
			break;
		case 'P':
			cout << "Computer has chosen: Scissors, Player has chosen: Paper" << endl;
			break;
		case 'S':
			cout << "Computer has chosen: Scissors, Player has chosen: Scissors" << endl;
			break;
		}
		break;
	}

	// Determine result
	switch (result) {
	case 0:
		cout << "Tie!" << endl;
		break;
	case 1:
		cout << "Computer wins!" << endl;
		break;
	case 2:
		cout << "You win!" << endl;
		break;
	}
}

//****************************************************************
// Definition of dispScore. Function that displays total score.	*
//****************************************************************

void Game::dispScore()
{

	cout << "computer has won : " << computerWins << " times" << endl;
	cout << "Player has won : " << playerWins << " times" << endl;
}

//****************************************************************
// Definition of ~Game. Destructor prints exit message.			*
//****************************************************************

Game::~Game()
{
	cout << "\nGreat Game... Bye";
}