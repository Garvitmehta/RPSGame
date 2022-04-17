#include <iostream>
#include <bits/stdc++.h>
#include "game.h"

using namespace std;

int main()
{
	// Initialize variables

	Game play;


	//Initial prompt
	play.getName();

	while (true)
	{

		// Get choice

		play.getChoice();

		// Check for quit
		if (play.exit) return 0;
		if (play.chooseAgain == 1) {
			play.chooseAgain = 0;
			continue;
		}

		// Get results
		play.getResult();

		// Display results
		play.dispResult();

		// Get score
		play.dispScore();
	}

	return 0;
}