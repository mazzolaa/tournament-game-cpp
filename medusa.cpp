/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Source file for Medusa class.
*  Subclass to character.
***/

#include "medusa.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/***********
* 		Medusa::Medusa()
* Description: Default Constructor.
*********/
Medusa::Medusa()
{
	setType("Medusa");
	setArmor(3);
	setStrength(8);
	setDead(false);

	//Get name of char from user
	string userName;
	cout << "\n Enter a name for your " << type << ": ";
	getline(cin, userName);
	setName(userName);
}


/***********
* 		int Medusa::attack()
* Description: Calculates and returns the amount of damage
*   the character attacks for.
* Handles Glare ability.
*********/
int Medusa::attack()
{
	int roll1, roll2, result;

	//Roll 2 six sided dice.
	roll1 = rand() % 6 + 1;
	roll2 = rand() % 6 + 1;


	result = roll1 + roll2;

	if (result == 12)
	{
		cout << "Medusa's Glare turned her enemy to stone!\n";
		return 100;
	}
	else
	{
		cout << name << " attacks with " << (roll1 + roll2) << " total attack power!\n";
		return result;
	}
}


/***********
* 		void Medusa::defend()
* Description: Calculates and applies the
*    amount of damage taken from an attack.
*********/
void Medusa::defend(int attk)
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
* 		void Medusa::setName(string)
* Description: Sets name of character.
************/
void   Medusa::setName(string name)
{
	this->name = name;
}


/***********
* 		void Medusa::setType(string)
* Description: Sets type of character.
************/
void   Medusa::setType(string type)
{
	this->type = type;
}


/***********
* 		void Medusa::setArmor(int)
* Description: Sets character's armor value.
************/
void   Medusa::setArmor(int armor)
{
	this->armor = armor;
}


/***********
* 		void Medusa::setStrength(int)
* Description: Sets character's strength value.
************/
void   Medusa::setStrength(int strength)
{
	this->strength = strength;
}


/***********
* 		void Medusa::setDead(bool)
* Description: Sets character's dead value.
*              true = dead, false = alive.
************/
void   Medusa::setDead(bool dead)
{
	this->dead = dead;
}


//Return character's name
string Medusa::getName()
{
	return name;
}

//Return character's type
string Medusa::getType()
{
	return type;
}

//Return character's armor value
int    Medusa::getArmor()
{
	return armor;
}

//Return chracter's strenght value
int    Medusa::getStrength()
{
	return strength;
}

//Return character's death status
bool   Medusa::getDead()
{
	return dead;
}

//Restore characters strength points
//by half of their remaining strength points
// truncated by integer division.
void Medusa::heal()
{
	int restore = strength / 2;

	strength = strength + restore;
}