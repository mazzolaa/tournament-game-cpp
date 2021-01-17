/*******
* Author: Anthony Mazzola
* Email: mazzolaa@oregonstate.edu
* Date: 11/07/2019
* Description: Source file for menu functions.
***/

#include "menu.hpp"


/******
* 		 int menu()
* 	Description: Present menu and validate user's selection.
*****/
int menu()
{
	cout << "\nWhat would you like to do?\n";
	cout << "1.) Play Game\n";
	cout << "2.) Exit\n";

	return validation(1, 2);
}


/******
* 		 int charMenu()
* 	Description: Present menu and validate user's selection.
*         Used for character selection.
*****/
int charMenu()
{
	cout << "Select a character:\n";
	cout << "1.) Vampire\n";
	cout << "2.) Barbarian\n";
	cout << "3.) Blue Men\n";
	cout << "4.) Medusa\n";
	cout << "5.) Harry Potter\n";

	return validation(1, 5);
}


/******
* 		 int validation(int,int)
* 	Description: Checks for valid integer input within the range specifiec
*   by sent parameters. Uses string stream to check for integer input.
*   Adapted from: http://www.cplusplus.com/forum/beginner/58833/
*****/
int validation(int min, int max)
{
	string input = "";
	int intNum;

	while (true)
	{
		getline(cin, input);
		stringstream stringNum(input);

		if (!(stringNum >> intNum) || (stringNum >> intNum) || intNum < min || intNum > max)
		{
			cout << "\nPlease enter a valid integer in the specified range.\n";
		}
		else
		{
			return intNum;
		}
	}
}
