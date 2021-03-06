// DataStructuresProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Functions.h"

using namespace std;

void menu()		// The main menu to decide what alogrithm or container to view
{
	cout << "~~~ Menu ~~~" << endl << endl;
	cout << "What would you like to view? (Enter a number)" << endl << endl;

	cout << "1. Dynamic Array" << endl;
	cout << "2. Linked List" << endl;
	cout << "3. Stack" << endl;
	cout << "4. Queue" << endl;
	cout << "5. Deque" << endl;
	cout << "6. Hashing" << endl;
	cout << "7. Exit Program" << endl;

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
			DynamicArrayMenu();			// The dynamic array menu to decide on how the user wants to view the examples
			validInput = true;			
			break;						
		case 2:
			LinkedListMenu();			// The linked list menu to decide on how the user wants to view the examples
			validInput = true;
			break;
		case 3:
			StackMenu();				// The stack menu to decide on how the user wants to view the examples
			validInput = true;
			break;
		case 4:
			QueueMenu();				// The queue menu to decide on how the user wants to view the examples
			validInput = true;
			break;
		case 5:
			DequeMenu();				// The deque menu to decide on how the user wants to view the examples
			validInput = true;
			break;
		case 6:
			HashingMenu();				// The hashing menu to decide on how the user wants to view the examples
			validInput = true;
			break;
		case 7:
			exit(0);
			validInput = true;
			break;
		default:
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			menu();
		}
	}		
}

int main()		// The welcome message and introductio to the program that then calls the main menu function
{
	cout << "Welcome to the Data Structures Project." << endl;
	cout << "This is a simple program to show examples of " << endl;
	cout << "container classes and algorithms. " << endl << endl;

	menu();

	system("pause");
    return 0;
}

