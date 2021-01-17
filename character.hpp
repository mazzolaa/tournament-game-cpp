/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Header file for Character class.
***/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;
#include <cstdlib>
#include <ctime>

class Character
{
protected:
	string type;     //hold type of character
	string name;     //hold name of character
	int armor;       //damage resistance
	int strength;    //health points
	bool dead;       //true if dead
public:
	Character();
	~Character();
	virtual int attack() = 0;			//pure virtual attack function
	virtual void defend(int) = 0;	//pure virtual defense function
	virtual void heal() = 0;

	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int    getArmor() = 0;
	virtual int    getStrength() = 0;
	virtual bool   getDead() = 0;

	virtual void   setName(string) = 0;
	virtual void   setType(string) = 0;
	virtual void   setArmor(int) = 0;
	virtual void   setStrength(int) = 0;
	virtual void   setDead(bool) = 0;
};
#endif
