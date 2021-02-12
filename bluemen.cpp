/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Source file for BlueMen class.
*  Subclass to character.
***/

#include "bluemen.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/***********
* 		BlueMen::BlueMen()
* Description: Default Constructor.
*********/
BlueMen::BlueMen()
{
	setType("Blue Men");
	setArmor(3);
	setStrength(12);
	setDead(false);

	//Get name of char from user
	string userName;
	cout << "\n Enter a name for your " << type << ": ";
	getline(cin, userName);
	setName(userName);
}


/***********
* 		int BlueMen::attack()
* Description: Calculates and returns the amount of damage
*   the character attacks for.
*********/
int BlueMen::attack()
{
	int roll1, roll2;

	//Roll 2 ten sided dice.
	roll1 = rand() % 10 + 1;
	roll2 = rand() % 10 + 1;

	cout << name << " attacks with " << (roll1 + roll2) << " total attack power!\n";

	return (roll1 + roll2);
}


/***********
* 		void BlueMen::defend()
* Description: Calculates and applies the
*    amount of damage taken from an attack.
* Includes special ability Mob.
*********/
void BlueMen::defend(int attk)
{
	int result, roll1, roll2, roll3;


	//if else structure for Mob ability
	//lose defense die every 4 strength points lost
	if (strength >= 9)
	{
		//Roll 3 six sided dice.
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;
		roll3 = rand() % 6 + 1;

		result = roll1 + roll2 + roll3;

		cout << name << " defends with a roll (3 dice) of " << result << endl;
	}
	else if ((strength <= 8) && (strength >= 5))
	{
		//Roll 2 six sided dice.
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;

		result = roll1 + roll2;

		cout << name << " defends with a roll (2 dice) of " << result << endl;
	}
	else if (strength <= 4)
	{
		//Roll 1 six sided dice.
		roll1 = rand() % 6 + 1;

		result = roll1;

		cout << name << " defend with a roll (1 die) of " << result << endl;
	}


	//calculate damage done
	int dmg = attk - result - armor;

	if (dmg < 0)  //cannnot gain health from attack
	{
		dmg = 0;
	}
	cout << name << " take " << dmg << " points of damage.\n";

	strength = strength - dmg;   //apply the damage to hp

	if (strength <= 0)
	{
		dead = true;
		cout << name << " have been defeated in battle.\n";
	}
	else
	{
		cout << name << " have " << strength << " strength points remaining.\n";
	}
}


/***********
* 		void BlueMen::setName(string)
* Description: Sets name of character.
************/
void   BlueMen::setName(string name)
{
	this->name = name;
}


/***********
* 		void BlueMen::setType(string)
* Description: Sets type of character.
************/
void   BlueMen::setType(string type)
{
	this->type = type;
}

//Return character's type
string BlueMen::getType()
{
	return type;
}

/***********
* 		void BlueMen::setArmor(int)
* Description: Sets character's armor value.
************/
void   BlueMen::setArmor(int armor)
{
	this->armor = armor;
}


/***********
* 		void BlueMen::setStrength(int)
* Description: Sets character's strength value.
************/
void   BlueMen::setStrength(int strength)
{
	this->strength = strength;
}


/***********
* 		void BlueMen::setDead(bool)
* Description: Sets character's dead value.
*              true = dead, false = alive.
************/
void   BlueMen::setDead(bool dead)
{
	this->dead = dead;
}


//Return character's name
string BlueMen::getName()
{
	return name;
}

//Return character's armor value
int    BlueMen::getArmor()
{
	return armor;
}

//Return chracter's strenght value
int    BlueMen::getStrength()
{
	return strength;
}

//Return character's death status
bool   BlueMen::getDead()
{
	return dead;
}

//Restore characters strength points
//by half of their remaining strength points
// truncated by integer division.
void BlueMen::heal()
{
	int restore = strength / 2;

	strength = strength + restore;
}
