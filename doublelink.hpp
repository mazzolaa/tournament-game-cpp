/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Description: Header file for DoubleLink class functions.
***/

#ifndef DOUBLELINK_HPP
#define DOUBLELINK_HPP

#include "node.hpp"

class DoubleLink
{
private:
	Node* head;    //points to first node in linked list
	Node* tail;    //points to last node in linked list


public:
	DoubleLink();
	~DoubleLink();

	void addNode_Head(Character*);    //add a new Node to the head
	void addNode_Tail(Character*);    //add a new Node to the tail

	void deleteFirst();     //delete the first Node in the list
	void deleteLast();      //delete the last Node in the list

	void traverseBack();    //traverse the list in reverse order
	void traverseFwd();     //traverse the list

	void printHeadVal();	//print value in head node
	void printTailVal();    //print value in tail node

	bool isEmpty();         //true if list is empty, otherwise false

	Character* getFirstChar();
};
#endif 
