#include "stdafx.h"
#include "Functions.h"
#include "DequeDA.h"
#include "DequeLL.h"
#include <string>
#include "DequeMenuFunctions.h"

DequeDA<int> dequeDA(10);	// This list is a global variable because DequeDAUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data
DequeLL<int> dequeLL(10);	// This list is a global variable because DequeLLUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data


void DequeDAHC()	// Hard-coded examples of deque functionality (Dynamic Array version)
{
	DequeDA<string> deque(10);	

	cout << "String Deque (Dynamic Array version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (deque.empty() == 1)													// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push Back x8 ---" << endl << endl;

	deque.pushBack("Red");													// examples of pushBack
	deque.pushBack("Orange");
	deque.pushBack("Yellow");
	deque.pushBack("Green");
	deque.pushBack("Blue");
	deque.pushBack("Purple");

	deque.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;					// example of getSize

	cout << "--- Pop Front x1 ---" << endl << endl;

	deque.popFront();														// example of popFront

	deque.printAsLine();													// example of printAsLine

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;

	cout << "--- Front ---" << endl << endl;

	cout << deque.front() << endl << endl;									// example of front

	cout << "--- Back ---" << endl << endl;

	cout << deque.back() << endl << endl;									// example of back

	cout << "--- Pop Back x2 ---" << endl << endl;

	deque.popBack();														// examples of popBack
	deque.popBack();

	deque.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;	


	cout << "--- Push Front x3 ---" << endl << endl;

	deque.pushFront("Black");												// examples of pushFront
	deque.pushFront("Grey");
	deque.pushFront("White");

	deque.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (deque.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Deque_DA();
}

void DequeDAUI()	// User interaction of deque to test functionality (Dynamic Array version)
{
	cout << "Deque (Dynamic Array version)" << endl << endl;
	cout << "This deque will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if deque is empty." << endl;
		cout << "2. Get size of deque." << endl;
		cout << "3. Push a value onto the front of the deque." << endl;
		cout << "4. Push a value onto the back of the deque." << endl;
		cout << "5. Pop a value off of the front of the deque." << endl;
		cout << "6. Pop a value off of the back deque." << endl;
		cout << "7. Get the front value of the deque (bottom value)." << endl;
		cout << "8. Get the back value of the deque (top value)." << endl;
		cout << "9. Print the deque." << endl;
		cout << "10. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			DequeDAUI();
		}

		switch (choice)
		{
		case 1:			// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (dequeDA.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:			// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << dequeDA.getSize() << endl << endl;
			system("pause");
			break;
		}
		case 3:			// example of pushFront
		{
			cout << "--- Push Front ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto front of the deque?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			dequeDA.pushFront(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 4:			// example of pushBack
		{
			cout << "--- Push Back ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the back of the deque?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			dequeDA.pushBack(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 5:			// example of popFront
		{
			cout << "--- Pop Front ---" << endl << endl;
			try
			{
				cout << "Popped Front: " << dequeDA.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeDAUI();
			}
			dequeDA.popFront();
			system("pause");
			break;
		}
		case 6:			// example of popBack
		{
			cout << "--- Pop Back ---" << endl << endl;
			try
			{
				cout << "Popped Back: " << dequeDA.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeDAUI();
			}
			dequeDA.popBack();
			system("pause");
			break;
		}
		case 7:			// example of front
		{
			cout << "--- Front ---" << endl << endl;
			try
			{
				cout << "Front Value: " << dequeDA.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeDAUI();
			}
			system("pause");
			break;
		}
		case 8:			// example of back
		{
			cout << "--- Back ---" << endl << endl;
			try
			{
				cout << "Back Value: " << dequeDA.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeDAUI();
			}
			system("pause");
			break;
		}
		case 9:			// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				dequeDA.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeDAUI();
			}
			system("pause");
			break;
		}
		case 10:			// return to dynamic array menu 
		{
			Deque_DA();
			validInput = true;
			break;
		}
		default:			// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			DequeDAUI();
		}
		}
	}
}

void DequeLLHC()	// Hard-coded examples of deque functionality (Linked List version)
{
	DequeLL<float> deque;

	cout << "Float Deque (Linked List version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;									

	if (deque.empty() == 1)														// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push Front x5 ---" << endl << endl;							

	deque.pushFront(0.993f);													// examples of pushFront
	deque.pushFront(0.758f);
	deque.pushFront(1.765f);
	deque.pushFront(2.213f);
	deque.pushFront(4.224f);

	deque.printAsLine();														// example of printAsLine

	cout << "--- Size ---" << endl << endl;
	
	cout << "Size: " << deque.getSize() << endl << endl;						// example of getSize

	cout << "--- Pop Back x2 ---" << endl << endl;
	
	deque.popBack();															// examples of popBack									
	deque.popBack();															

	deque.printAsLine();														

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;

	cout << "--- Front ---" << endl << endl;									

	cout << deque.front() << endl << endl;										// example of front

	cout << "--- Back ---" << endl << endl;										

	cout << deque.back() << endl << endl;										// example of back

	cout << "--- Push Back x2 ---" << endl << endl;							

	deque.pushBack(0.147f);														// examples of pushBack	
	deque.pushBack(4.238f);

	deque.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;

	cout << "--- Pop Front x2 ---" << endl << endl;
	
	deque.popFront();															// example of popFront
	deque.popFront();

	deque.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << deque.getSize() << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (deque.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Deque_LL();
}

void DequeLLUI()	// User interaction of deque to test functionality (Linked List version)
{
	cout << "Deque (Linked List version)" << endl << endl;
	cout << "This deque will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if deque is empty." << endl;
		cout << "2. Get size of deque." << endl;
		cout << "3. Push a value onto the front of the deque." << endl;
		cout << "4. Push a value onto the back of the deque." << endl;
		cout << "5. Pop a value off of the front of the deque." << endl;
		cout << "6. Pop a value off of the back deque." << endl;
		cout << "7. Get the front value of the deque (bottom value)." << endl;
		cout << "8. Get the back value of the deque (top value)." << endl;
		cout << "9. Print the deque." << endl;
		cout << "10. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			DequeLLUI();
		}

		switch (choice)
		{
		case 1:			// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (dequeLL.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:			// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << dequeLL.getSize() << endl << endl;
			system("pause");
			break;
		}
		case 3:			// example of pushFront
		{
			cout << "--- Push Front ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto front of the deque?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			dequeLL.pushFront(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 4:			// example of pushBack
		{
			cout << "--- Push Back ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the back of the deque?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			dequeLL.pushBack(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 5:			// example of popFront
		{
			cout << "--- Pop Front ---" << endl << endl;
			try
			{
				cout << "Popped Front: " << dequeLL.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeLLUI();
			}
			dequeLL.popFront();
			system("pause");
			break;
		}
		case 6:			// example of popBack
		{
			cout << "--- Pop Back ---" << endl << endl;
			try
			{
				cout << "Popped Back: " << dequeLL.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeLLUI();
			}
			dequeLL.popBack();
			system("pause");
			break;
		}
		case 7:			// example of front
		{
			cout << "--- Front ---" << endl << endl;
			try
			{
				cout << "Front Value: " << dequeLL.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeLLUI();
			}
			system("pause");
			break;
		}
		case 8:			// example of back
		{
			cout << "--- Back ---" << endl << endl;
			try
			{
				cout << "Back Value: " << dequeLL.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeLLUI();
			}
			system("pause");
			break;
		}
		case 9:			// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				dequeLL.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DequeLLUI();
			}
			system("pause");
			break;
		}
		case 10:			// return to deque linked list menu
		{
			Deque_LL();
			validInput = true;
			break;
		}
		default:			// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			DequeLLUI();
		}
		}
	}
}

void Deque_DA()	// Choices for user to test deque (Dynamic Array version) functionality
{
	cout << "--- Deque (Dynamic Array Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Deque? (Enter a number)" << endl << endl;

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
			DequeDAHC();
			validInput = true;
			break;
		case 2:
			DequeDAUI();
			validInput = true;
			break;
		case 3:
			menu();
			validInput = true;
			break;
		default:
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			Deque_DA();
		}
	}
}

void Deque_LL()	// Choices for user to test deque (Linked List version) functionality
{
	cout << "--- Deque (Linked List Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Deque? (Enter a number)" << endl << endl;

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
			DequeLLHC();
			validInput = true;
			break;
		case 2:
			DequeLLUI();
			validInput = true;
			break;
		case 3:
			menu();
			validInput = true;
			break;
		default:
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			Deque_LL();
		}
	}
}

void DequeMenu()	// Choices for user to test deque functionality
{
	cout << "--- Deque Menu ---" << endl << endl;
	cout << "How would you like to view the Deque? (Enter a number)" << endl << endl;

	cout << "1. Dynamic Array Version" << endl;
	cout << "2. Linked List Version" << endl;
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
			Deque_DA();
			validInput = true;
			break;
		case 2:
			Deque_LL();
			validInput = true;
			break;
		case 3:
			menu();
			validInput = true;
			break;
		default:
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			DequeMenu();
		}
	}
}