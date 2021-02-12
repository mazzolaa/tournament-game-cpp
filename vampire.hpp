/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Header file for Vampire class.
*  Subclass to character.
***/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP


#include "character.hpp"

class Vampire : public Character
{
private:

public:
	Vampire();

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
