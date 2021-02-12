/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Header file for Game class.
***/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "menu.hpp"
#include "character.hpp"

#include "barbarian.hpp"
#include "bluemen.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include "doublelink.hpp"


using std::cout;
using std::cin;


class Game
{
private:
	DoubleLink team1;  //containers for team1, team2, and losers. (hold pointer to characters)
	DoubleLink team2;
	DoubleLink losers;

	int numFighters;    //number of characters on each team

	Character* player1;
	Character* player2;

public:
	Game();
	~Game();
	void battle();
};
#endif
