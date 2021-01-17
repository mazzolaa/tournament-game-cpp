/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Header file for HarryPotter class.
*  Subclass to character.
***/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


#include "character.hpp"

class HarryPotter : public Character
{
private:
	int extraLife;   //keep track of extra life for Hogwarts ability

public:
	HarryPotter();

	int attack();
	void defend(int);
	void heal();

	void   setName(string);
	void   setType(string);
	void   setArmor(int);
	void   setStrength(int);
	void   setDead(bool);

	string getName();
	string getType();
	int    getArmor();
	int    getStrength();
	bool   getDead();
};
#endif 
