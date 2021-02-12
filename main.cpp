/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Main file for Project 3.
***/


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "menu.hpp"
#include "game.hpp"

#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"


using std::cout;
using std::cin;
using std::endl;

int main()
{
	//set up random number generator
	unsigned seed;
	seed = time(0);
	srand(seed);



	int x = menu();    //Play game or exit
	while (x == 1)
	{
		Game g1;       //Creates the game object

		g1.battle();

		x = menu();
	}

	cout << "\nThank you for playing! Goodbye.\n";

	//system("pause");
	return 0;
}
