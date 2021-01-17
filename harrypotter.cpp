/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Source file for HarryPotter class.
*  Subclass to character.
***/

#include "harrypotter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

/***********
* 		HarryPotter::HarryPotter()
* Description: Default Constructor.
*********/
HarryPotter::HarryPotter()
{
	setType("Harry Potter");
	setArmor(0);
	setStrength(10);
	setDead(false);

	extraLife = 1;

	//Get name of char from user
	string userName;
	cout << "\n Enter a name for your " << type << ": ";
	getline(cin, userName);
	setName(userName);
}


/***********
* 		int HarryPotter::attack()
* Description: Calculates and returns the amount of damage
*   the character attacks for.
*********/
int HarryPotter::attack()
{
	int roll1, roll2;

	//Roll 2 six sided dice.
	roll1 = rand() % 6 + 1;
	roll2 = rand() % 6 + 1;

	cout << name << " attacks with " << (roll1 + roll2) << " total attack power!\n";

	return (roll1 + roll2);
}


/***********
* 		void HarryPotter::defend()
* Description: Calculates and applies the
*    amount of damage taken from an attack.
*********/
void HarryPotter::defend(int attk)
{
	int result, roll1, roll2;

	//Roll 2 six sided dice.
	roll1 = rand() % 6 + 1;
	roll2 = rand() % 6 + 1;

	result = roll1 + roll2;
	cout << name << " defends with a roll of " << result << endl;


	int dmg = attk - result - armor;

	if (dmg < 0)  //cannnot gain health from attack
	{
		dmg = 0;
	}
	cout << name << " takes " << dmg << " points of damage.\n";


	strength = strength - dmg;   //apply the damage to hp

								 //Hogwarts ability
								 //spend extra life and set strength to 20
	if ((strength <= 0) && (extraLife == 1))
	{
		extraLife = 0;
		strength = 20;
		cout << "Harry Potter has been defeated.\n";
		cout << "But wait! Harry Potter is resurrected with 20 health points!\n";
	}
	else if ((strength <= 0) && (extraLife == 0))
	{
		dead = true;
		cout << name << " has been defeated in battle.\n";
	}
	else
	{
		cout << name << " has " << strength << " strength points remaining.\n";
	}

}


/***********
* 		void HarryPotter::setName(string)
* Description: Sets name of character.
************/
void   HarryPotter::setName(string name)
{
	this->name = name;
}


/***********
* 		void HarryPotter::setType(string)
* Description: Sets type of character.
************/
void   HarryPotter::setType(string type)
{
	this->type = type;
}


/***********
* 		void HarryPotter::setArmor(int)
* Description: Sets character's armor value.
************/
void   HarryPotter::setArmor(int armor)
{
	this->armor = armor;
}


/***********
* 		void HarryPotter::setStrength(int)
* Description: Sets character's strength value.
************/
void   HarryPotter::setStrength(int strength)
{
	this->strength = strength;
}


/***********
* 		void HarryPotter::setDead(bool)
* Description: Sets character's dead value.
*              true = dead, false = alive.
************/
void   HarryPotter::setDead(bool dead)
{
	this->dead = dead;
}


//Return character's name
string HarryPotter::getName()
{
	return name;
}

//Return character's type
string HarryPotter::getType()
{
	return type;
}

//Return character's armor value
int    HarryPotter::getArmor()
{
	return armor;
}

//Return chracter's strenght value
int    HarryPotter::getStrength()
{
	return strength;
}

//Return character's death status
bool   HarryPotter::getDead()
{
	return dead;
}

//Restore characters strength points
//by half of their remaining strength points
// truncated by integer division.
void HarryPotter::heal()
{
	int restore = strength / 2;

	strength = strength + restore;
}