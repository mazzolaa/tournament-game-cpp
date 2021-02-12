/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Source file for Barbarian class.
*  Subclass to character.
***/

#include "barbarian.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/***********
* 		Barbarian::Barbarian()
* Description: Default Constructor.
*********/
Barbarian::Barbarian()
{
	setType("Barbarian");
	setArmor(0);
	setStrength(12);
	setDead(false);

	//Get name of char from user
	string userName;
	cout << "\n Enter a name for your " << type << ": ";
	getline(cin, userName);
	setName(userName);
}


/***********
* 		int Barbarian::attack()
* Description: Calculates and returns the amount of damage
*   the character attacks for.
*********/
int Barbarian::attack()
{
	int roll1, roll2;

	//Roll 2 six sided dice.
	roll1 = rand() % 6 + 1;
	roll2 = rand() % 6 + 1;

	cout << name << " attacks with " << (roll1 + roll2) << " total attack power!\n";

	return (roll1 + roll2);
}


/***********
* 		void Barbarian::defend()
* Description: Calculates and applies the
*    amount of damage taken from an attack.
*********/
void Barbarian::defend(int attk)
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

	if (strength <= 0)
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
* 		void Barbarian::setName(string)
* Description: Sets name of character.
************/
void   Barbarian::setName(string name)
{
	this->name = name;
}


/***********
* 		void Barbarian::setType(string)
* Description: Sets type of character.
************/
void   Barbarian::setType(string type)
{
	this->type = type;
}


/***********
* 		void Barbarian::setArmor(int)
* Description: Sets character's armor value.
************/
void   Barbarian::setArmor(int armor)
{
	this->armor = armor;
}


/***********
* 		void Barbarian::setStrength(int)
* Description: Sets character's strength value.
************/
void   Barbarian::setStrength(int strength)
{
	this->strength = strength;
}


/***********
* 		void Barbarian::setDead(bool)
* Description: Sets character's dead value.
*              true = dead, false = alive.
************/
void   Barbarian::setDead(bool dead)
{
	this->dead = dead;
}


//Return character's name
string Barbarian::getName()
{
	return name;
}

//Return character's type
string Barbarian::getType()
{
	return type;
}

//Return character's armor value
int    Barbarian::getArmor()
{
	return armor;
}

//Return chracter's strenght value
int    Barbarian::getStrength()
{
	return strength;
}

//Return character's death status
bool   Barbarian::getDead()
{
	return dead;
}

//Restore characters strength points
//by half of their remaining strength points
// truncated by integer division.
void Barbarian::heal()
{
	int restore = strength / 2;

	strength = strength + restore;
}
