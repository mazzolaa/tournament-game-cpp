/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Header file for BlueMen class.
*  Subclass to character.
***/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include "character.hpp"

class BlueMen : public Character
{
private:

public:
	BlueMen();

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
