/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Source file for Vampire class.
*  Subclass to character.
***/

#include "vampire.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/***********
* 		Vampire::Vampire()
* Description: Default Constructor.
*********/
Vampire::Vampire()
{
	setType("Vampire");
	setArmor(1);
	setStrength(18);
	setDead(false);

	//Get name of char from user
	string userName;
	cout << "\n Enter a name for your " << type << ": ";
	getline(cin, userName);
	setName(userName);
}


/***********
* 		int Vampire::attack()
* Description: Calculates and returns the amount of damage
*   the character attacks for.
*********/
int Vampire::attack()
{
	int roll1;

	//Roll 1 twelve sided die.
	roll1 = rand() % 12 + 1;

	cout << name << " attacks with " << roll1 << " total attack power!\n";

	return roll1;
}


/***********
* 		void Vampire::defend()
* Description: Calculates and applies the
*    amount of damage taken from an attack.
*   Includes Charm ability.
*********/
void Vampire::defend(int attk)
{
	int result, roll1;

	//Roll 1 six sided die.
	roll1 = rand() % 6 + 1;

	result = roll1;
	cout << name << " defends with a roll of " << result << endl;


	int dmg = attk - result - armor;

	if (dmg < 0)  //cannnot gain health from attack
	{
		dmg = 0;
	}

	//Roll for charm integer, 50% chance to charm opponent
	int charm = rand() % 6 + 1;
	if (charm < 4)
	{
		strength = strength - dmg;   //apply the damage to hp
		cout << name << " takes " << dmg << " points of damage.\n";
	}
	else
	{
		cout << "Vampire charmed the opponent out of attacking. (No damage to Vampire)\n";
	}


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
* 		void Vampire::setName(string)
* Description: Sets name of character.
************/
void   Vampire::setName(string name)
{
	this->name = name;
}


/***********
* 		void Vampire::setType(string)
* Description: Sets type of character.
************/
void   Vampire::setType(string type)
{
	this->type = type;
}


/***********
* 		void Vampire::setArmor(int)
* Description: Sets character's armor value.
************/
void   Vampire::setArmor(int armor)
{
	this->armor = armor;
}


/***********
* 		void Vampire::setStrength(int)
* Description: Sets character's strength value.
************/
void   Vampire::setStrength(int strength)
{
	this->strength = strength;
}


/***********
* 		void Vampire::setDead(bool)
* Description: Sets character's dead value.
*              true = dead, false = alive.
************/
void   Vampire::setDead(bool dead)
{
	this->dead = dead;
}


//Return character's name
string Vampire::getName()
{
	return name;
}

//Return character's type
string Vampire::getType()
{
	return type;
}

//Return character's armor value
int    Vampire::getArmor()
{
	return armor;
}

//Return chracter's strenght value
int    Vampire::getStrength()
{
	return strength;
}

//Return character's death status
bool   Vampire::getDead()
{
	return dead;
}

//Restore characters strength points
//by half of their remaining strength points
// truncated by integer division.
void Vampire::heal()
{
	int restore = strength / 2;

	strength = strength + restore;
}
