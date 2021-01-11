#include "stdafx.h"
#include "Functions.h"
#include "HashingMenuFunctions.h"
#include <string>

void HashingHC()	// Hard-coded hash examples
{
	cout << "Hashing (Hard-coded)" << endl << endl;
	cout << "Data: 'This is my hash'" << endl;
	cout << "Length: 15" << endl;
	cout << "Default: secondHash" << endl << endl;

	cout << "firstHash: " << HashFunction::firstHash("This is my hash", 15) << endl << endl;			// example of firstHash
	cout << "secondHash: " << HashFunction::secondHash("This is my hash", 15) << endl << endl;			// example of secondHash
	cout << "thirdHash: " << HashFunction::thirdHash("This is my hash", 15) << endl << endl;			// example of thirdHash

	cout << "DefaultHashFunction: " << HashFunction::DefaultHashFunction("This is my hash", 15) << endl << endl;	// example of DefaultHashFunction

	system("pause");
	cout << endl;
	HashingMenu();
}

void HashingUI()	// User interaction examples of hashing
{
	cout << "Hashing (User Interaction)" << endl << endl;

	string toHash;
	int length;

	cout << "Enter a string: ";
	cin >> toHash; 

	cout << endl << endl;
	length = toHash.length();
	const char *str = toHash.c_str();

	cout << "Which hash code would you like to use? (Enter a number)" << endl << endl;

	cout << "1. firstHash" << endl;
	cout << "2. secondHash" << endl;
	cout << "3. thirdHash" << endl; 
	cout << "4. DefaultHashFunction" << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}

		switch (choice)
		{
		case 1:		// example of firstHash
			cout << "firstHash: " << HashFunction::firstHash(str, length) << endl << endl;
			validInput = true;
			break;
		case 2:		// example of secondHash
			cout << "secondHash: " << HashFunction::secondHash(str, length) << endl << endl;
			validInput = true;
			break;
		case 3:		// example of thirdHash
			cout << "thirdHash: " << HashFunction::thirdHash(str, length) << endl << endl;
			validInput = true;
			break;
		case 4:		// example of DefaultHashFunction
			cout << "DefaultHashFunction: " << HashFunction::DefaultHashFunction(str, length) << endl << endl;
			validInput = true;
			break;
		default:	// default response
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			HashingUI();
		}
	}

	system("pause");
	cout << endl;
	HashingMenu();
}

void HashingMenu()	// The hashing menu to decide on how the user wants to view the examples 
{
	cout << "--- Hashing Menu ---" << endl << endl;
	cout << "How would you like to view Hashing? (Enter a number)" << endl << endl;

	cout << "1. Hard-coded Example" << endl;
	cout << "2. User Interaction Example" << endl;
	cout << "3. Return to Main Menu" << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}

		switch (choice)
		{
		case 1:
			HashingHC();	// Hard-coded hash examples
			validInput = true;
			break;
		case 2:
			HashingUI();	// User interaction examples of hashing
			validInput = true;
			break;
		case 3:
			menu();			// Returns to main menu
			validInput = true;
			break;
		default:			// Default response
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			HashingMenu();
		}
	}
}