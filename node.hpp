/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/06/2019
* Description: Header file for Node class.
***/

#ifndef NODE_HPP
#define NODE_HPP

#include "character.hpp"

class Node
{
private:
	Node* next;  //pointer to next Node object
	Node* prev;  //pointer to previous Node object

	Character* charPtr;  //pointer to character object held by node

	friend class DoubleLink;
	friend class Game;
public:
	Node();
	Node(Character*);
	~Node();
};
#endif
