/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/06/2019
* Description: Source file for DoubleLink class functions.
***/

#include "doublelink.hpp"
#include <iostream>
using std::cout;

/******
* 		 DoubleLink::DoubleLink()
* 	Description: Constructor. Sets head and tail ptr's to null.
*****/
DoubleLink::DoubleLink()
{
	head = NULL;
	tail = NULL;
}

// DoubleLink::~DoubleLink()
// Destructor
DoubleLink::~DoubleLink()
{
	Node* nodePtr = head;
	while (nodePtr != NULL)
	{
		Node* garbage = nodePtr;

		nodePtr = nodePtr->next;
		delete garbage->charPtr;
		delete garbage;
	}
}




/******
* 		void DoubleLink::addNode_Head()
* 	Description: Add a new Node to the head of the list.
*****/
void DoubleLink::addNode_Head(Character* n)
{
	Node* newNode = new Node(n);

	if (head == NULL)      //if list is empty
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}
}


/******
* 		void DoubleLink::addNode_Tail()
* 	Description: Add a new Node to the tail of the list.
*****/
void DoubleLink::addNode_Tail(Character* n)
{
	Node* newNode = new Node(n);
	newNode->next = NULL;
	newNode->charPtr = n;

	if (head == NULL)      //if list is empty
	{
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* temp = head;

		while ((temp->next) != NULL) //search for end of list
		{
			temp = temp->next;
		}
		temp->next = newNode;
		tail = newNode;
		newNode->prev = temp;
	}
}


/******
* 		void DoubleLink::deleteFirst()
* 	Description: Remove the first node in the list
*****/
void DoubleLink::deleteFirst()
{
	if (head == NULL)   //empty list
	{
		cout << "\nError: The list is empty\n";
	}
	else if (head == tail)   //only one node
	{
		Node* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}
}

/******
* 		void DoubleLink::deleteLast()
* 	Description: Remove the last node in the list
*****/
void DoubleLink::deleteLast()
{
	if (head == NULL)   //empty list
	{
		cout << "\nError: The list is empty\n";
	}
	else if (head == tail)   //only one node
	{
		Node* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else
	{
		Node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;

		delete temp;
	}
}


/******
* 		void DoubleLink::traverseBack()
* 	Description: Print the list in reverse order.
*****/
void DoubleLink::traverseBack()
{
	if (head == NULL)   //empty list
	{
		cout << "\nThe list is empty.\n";
	}
	else
	{
		Node* temp = tail;

		cout << "\nBackwards Linked List is: ";
		cout << temp->charPtr->getName() << " ";

		while ((temp->prev) != NULL) //search for start of list
		{
			cout << temp->prev->charPtr->getName() << "  ";
			temp = temp->prev;
		}
	}
}


/******
* 		void DoubleLink::traverseFwd()
* 	Description: Print the list.
*****/
void DoubleLink::traverseFwd()
{
	if (head == NULL)   //empty list
	{
		cout << "\n";
	}
	else
	{
		Node* temp = head;

		//cout << "\nLinked List is: ";
		cout << temp->charPtr->getType() << ":";
		cout << temp->charPtr->getName() << "   ";

		while ((temp->next) != NULL) //search for end of list
		{
			cout << temp->next->charPtr->getType() << ":";
			cout << temp->next->charPtr->getName() << "   ";
			temp = temp->next;
		}
		cout << "\n";
	}
}


/******
* 		void DoubleLink::printHeadVal()
* 	Description: Print the value in the node head is pointing to.
*****/
void DoubleLink::printHeadVal()
{
	if (head == NULL)
	{
		cout << "\nEmpty list. No value to print.\n";
	}
	else
	{
		cout << "\nThe first value in the list is: ";
		cout << head->charPtr->getName();
	}
}


/******
* 		void DoubleLink::printTailVal()
* 	Description: Print the value in the node tail is pointing to.
*****/
void DoubleLink::printTailVal()
{
	if (head == NULL)
	{
		cout << "\nEmpty list. No value to print.\n";
	}
	else
	{
		cout << "\nThe last value in the list is: ";
		cout << tail->charPtr->getName();
	}
}


//Return the first character in the linked list
Character* DoubleLink::getFirstChar()
{
	return head->charPtr;
}

//Return true if list is empty, otherwise false
bool DoubleLink::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
