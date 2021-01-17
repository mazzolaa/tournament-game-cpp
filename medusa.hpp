/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Header file for Medusa class.
*  Subclass to character.
***/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP


#include "character.hpp"

class Medusa : public Character
{
private:

public:
	Medusa();

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
