/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Source file for Game class.
***/

#include "game.hpp"
using std::endl;

/***********
* 		Game::Game()
* Description: Default Constructor.
* Initialize characters with the players' choices.
*********/
Game::Game()
{	
	//Establish number of fighters each team will have
	cout << "\nHow many fighters will be on each team? Enter an integer in the range 1-20\n";
	numFighters = validation(1, 20);
	
	//Add fighters to team1
	for (int i = 0; i < numFighters; i++)
	{
		cout << "\nCreate fighter #" << i + 1 << " for Team 1\n";
		int charChoice1 = charMenu();

		//if-then structure to initialize character of chosen type
		if (charChoice1 == 1)
		{
			player1 = new Vampire;
		}
		else if (charChoice1 == 2)
		{
			player1 = new Barbarian;
		}
		else if (charChoice1 == 3)
		{
			player1 = new BlueMen;
		}
		else if (charChoice1 == 4)
		{
			player1 = new Medusa;
		}
		else if (charChoice1 == 5)
		{
			player1 = new HarryPotter;
		}

		//add character to team1 linked list
		team1.addNode_Tail(player1);
	}
	cout << "\nTeam 1: \n";
	team1.traverseFwd();
	cout << endl;

	//Add fighters to team2
	for (int i = 0; i < numFighters; i++)
	{
		cout << "\nCreate fighter  #" << i + 1 << " for Team 2\n";
		int charChoice2 = charMenu();

		//if-then structure to initialize character of chosen type
		if (charChoice2 == 1)
		{
			player2 = new Vampire;
		}
		else if (charChoice2 == 2)
		{
			player2 = new Barbarian;
		}
		else if (charChoice2 == 3)
		{
			player2 = new BlueMen;
		}
		else if (charChoice2 == 4)
		{
			player2 = new Medusa;
		}
		else if (charChoice2 == 5)
		{
			player2 = new HarryPotter;
		}

		//add character to team1 linked list
		team2.addNode_Tail(player2);
	}
	cout << "\nTeam 2: \n";
	team2.traverseFwd();
	cout << endl;
}


/***********
* 		Game::~Game()
* Description: Destructor
*    Free dynamically allocated memory.
*********/
Game::~Game()
{
	//delete player1;
	//delete player2;
}



/***********
* 		void Game::battle()
* Description: Handle the battle between the chosen characters.
* Battle ends when one of the teams has no fighters remaining.
*********/
void Game::battle()
{

	//battles and node placement take place until one list is empty

	while ((team1.isEmpty() == false) && (team2.isEmpty() == false))
	{
		//Set player1 to team1's front fighter; player2 to team2's front
		player1 = team1.getFirstChar();
		player2 = team2.getFirstChar();

		while ((player2->getDead() == false) && (player1->getDead() == false))
		{
			//Player 1 attacks Player 2
			cout << "Player 1's " << player1->getName() << " attacks Player 2's " << player2->getName() << endl;
			cout << "Player 2 has " << player2->getStrength() << " strength points and " << player2->getArmor() << " armor.\n";
			player2->defend(player1->attack());
			cout << endl;

			if (player2->getDead() == true)
			{
				break;
			}

			//Player 2 attacks Player 1
			cout << "Player 2's " << player2->getName() << " attacks Player 1's " << player1->getName() << endl;
			cout << "Player 1 has " << player1->getStrength() << " strength points and " << player1->getArmor() << " armor.\n";
			player1->defend(player2->attack());
			cout << endl;
		}
		system("pause");


		int winner;
		if (player2->getDead() == true)
		{
			cout << "Player 1 wins the battle!\n\n";
			winner = 1;
		}
		else if (player1->getDead() == true)
		{
			cout << "Player 2 wins the battle!\n\n";
			winner = 2;
		}


		//winner to back of team's list, loser to front of losers list
		if (winner == 1)
		{
			//recover health for winning character
			player1->heal();

			//send winner to back of team's list
			team1.addNode_Tail(player1);
			team1.deleteFirst();


			//send loser to front of losers list
			losers.addNode_Head(player2);
			team2.deleteFirst();

			//print teams after moving characters
			cout << "\nTeam 1: \n";
			team1.traverseFwd();
			cout << "\nTeam2: \n";
			team2.traverseFwd();
			cout << endl;

		}
		else if (winner == 2)
		{
			//recover health for winning character
			player2->heal();

			//send winner to back of team's list
			team2.addNode_Tail(player2);
			team2.deleteFirst();


			//send loser to front of losers list
			losers.addNode_Head(player1);
			team1.deleteFirst();

			//print teams after moving characters
			cout << "\nTeam 1: \n";
			team1.traverseFwd();
			cout << "\nTeam2: \n";
			team2.traverseFwd();
			cout << endl;
		}
		system("pause");
	}

	//announce tournament winner
	if (team1.isEmpty() == true)
	{
		cout << "\nAll of Team 1's fighters have been defeated.\n";
		cout << "The tournament winner is Team 2!\n\n";
	}
	else
	{
		cout << "\nAll of Team 2's fighters have been defeated.\n";
		cout << "The tournament winner is Team 1!\n\n";
	}

	//Print defeated character list
	cout << "\nDefeated characters: \n";
	losers.traverseFwd();

	//delete player1;
	//delete player2;
}
