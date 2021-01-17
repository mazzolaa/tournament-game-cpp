/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Header file for Barbarian class.
*  Subclass to character.
***/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP


#include "character.hpp"

class Barbarian : public Character
{
private:

public:
	Barbarian();

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
#endif // !BARBARIAN_HPP
