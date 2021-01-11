#include "stdafx.h"
#include "Functions.h"
#include "StackDA.h"
#include "StackLL.h"
#include "Exceptions.h"
#include "StackMenuFunctions.h"

StackDA<int> stackDA(10);	  // This list is a global variable because StackDAUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data
StackLL<int> stackLL(10);	  // This list is a global variable because StackLLUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data

void StackDAHC()	// Hard-coded examples of stack functionality (Dynamic Array version)
{
	StackDA<int> stack(10);

	cout << "Integer Stack (Dynamic Array version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (stack.empty() == 1)														// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push x6 ---" << endl << endl;

	stack.push(87);																// examples of push
	stack.push(45);
	stack.push(38);
	stack.push(52);
	stack.push(10);
	stack.push(98);

	stack.printAsLine();														// example of printAsLine

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << stack.getSize() << endl << endl;						// example of getSize

	cout << "--- Pop x2 ---" << endl << endl;

	stack.pop();																// example of pop
	stack.pop();

	stack.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << stack.getSize() << endl << endl;

	cout << "--- Top ---" << endl << endl;

	cout << stack.top() << endl << endl;										// example of top

	cout << "--- Empty ---" << endl << endl;

	if (stack.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Stack_DA();
}

void StackDAUI()	// User interaction of stack to test functionality (Dynamic Array version)
{
	cout << "Stack (Dynamic Array version)" << endl << endl;
	cout << "This stack will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if stack is empty." << endl;
		cout << "2. Get size of stack." << endl;
		cout << "3. Push a value onto the stack." << endl;
		cout << "4. Pop a value off of the stack." << endl;
		cout << "5. Get the last value on the stack (top value)." << endl;
		cout << "6. Print the stack." << endl;
		cout << "7. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			StackDAUI();
		}

		switch (choice)
		{
		case 1:						// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (stackDA.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:						// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << stackDA.getSize() << endl << endl;
			system("pause");
			break;
		}
		case 3:						// example of push
		{
			cout << "--- Push ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the stack?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			stackDA.push(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 4:						// example of pop
		{
			cout << "--- Pop ---" << endl << endl;
			try
			{
				cout << "Popped: " << stackDA.top() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackDAUI();
			}
			stackDA.pop();
			system("pause");
			break;
		}
		case 5:						// example of top
		{
			cout << "--- Top ---" << endl << endl;
			try
			{
				cout << "Top Value: " << stackDA.top() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackDAUI();
			}
			system("pause");
			break;
		}
		case 6:						// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				stackDA.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackDAUI();
			}
			system("pause");
			break;
		}
		case 7:						// return to stack dynamic array version menu 
		{
			Stack_DA();
			validInput = true;
			break;
		}
		default:					// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			StackDAUI();
		}
		}
	}
}

void StackLLHC()	// Hard-coded examples of stack functionality (Linked List version)
{
	StackLL<char> stack;

	cout << "Char Stack (Linked List version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (stack.empty() == 1)														// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push x5 ---" << endl << endl;

	stack.push('K');															// example of push
	stack.push('Y');
	stack.push('P');
	stack.push('E');
	stack.push('O');

	stack.printAsLine();														// example of printAsLine

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << stack.getSize() << endl << endl;						// example of getSize

	cout << "--- Pop x3 ---" << endl << endl;

	stack.pop();																// example of pop
	stack.pop();
	stack.pop();

	stack.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << stack.getSize() << endl << endl;

	cout << "--- Top ---" << endl << endl;

	cout << stack.top() << endl << endl;										// example of top

	cout << "--- Empty ---" << endl << endl;

	if (stack.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Stack_LL();
}

void StackLLUI()	// User interaction of stack to test functionality (Linked List version)
{
	cout << "Stack (Linked List version)" << endl << endl;
	cout << "This stack will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if stack is empty." << endl;
		cout << "2. Get size of stack." << endl;
		cout << "3. Push a value onto the stack." << endl;
		cout << "4. Pop a value off of the stack." << endl;
		cout << "5. Get the last value on the stack (top value)." << endl;
		cout << "6. Print the stack." << endl;
		cout << "7. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			StackLLUI();
		}

		switch (choice)
		{
		case 1:						// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (stackLL.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:						// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << stackLL.getSize() << endl << endl;
			system("pause");
			break;
		}
		case 3:						// example of push
		{
			cout << "--- Push ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the stack?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			stackLL.push(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 4:						// example of pop
		{
			cout << "--- Pop ---" << endl << endl;
			try
			{
				cout << "Popped: " << stackLL.top() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackLLUI();
			}
			stackLL.pop();
			system("pause");
			break;
		}
		case 5:						// example of top
		{
			cout << "--- Top ---" << endl << endl;
			try
			{
				cout << "Top Value: " << stackLL.top() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackLLUI();
			}
			system("pause");
			break;
		}
		case 6:						// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				stackLL.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				StackLLUI();
			}
			system("pause");
			break;
		}
		case 7:						// return to stack linked list version menu
		{
			Stack_LL();
			validInput = true;
			break;
		}
		default:					// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			StackLLUI();
		}
		}
	}
}

void Stack_DA()	// Choices for user to test stack (Dynamic Array version) functionality
{
	cout << "--- Stack (Dynamic Array Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Stack? (Enter a number)" << endl << endl;

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
			StackDAHC();
			validInput = true;
			break;
		case 2:
			StackDAUI();
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
			Stack_DA();
		}
	}
}

void Stack_LL()	// Choices for user to test stack (Linked List version) functionality
{
	cout << "--- Stack (Linked List Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Stack? (Enter a number)" << endl << endl;

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
			StackLLHC();
			validInput = true;
			break;
		case 2:
			StackLLUI();
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
			Stack_LL();
		}
	}
}

void StackMenu()	// Choices for user to test stack functionality
{
	cout << "--- Stack Menu ---" << endl << endl;
	cout << "How would you like to view the Stack? (Enter a number)" << endl << endl;

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
			Stack_DA();
			validInput = true;
			break;
		case 2:
			Stack_LL();
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
			StackMenu();
		}
	}
}