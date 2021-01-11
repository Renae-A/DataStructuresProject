#include "stdafx.h"
#include "Functions.h"
#include "QueueDA.h"
#include "QueueLL.h"
#include "QueueMenuFunctions.h"

QueueDA<int> queueDA(10);	// This list is a global variable because QueueDAUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data
QueueLL<int> queueLL(10);	// This list is a global variable because QueueLLUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data


void QueueDAHC()	// Hard-coded examples of queue functionality (Dynamic Array version)
{
	QueueDA<char> queue(10);

	cout << "Char Queue (Dynamic Array version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (queue.empty() == 1)														// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push x6 ---" << endl << endl;

	queue.push('R');															// example of push
	queue.push('L');
	queue.push('I');
	queue.push('M');
	queue.push('E');
	queue.push('S');

	queue.printAsLine();														// example of printAsLine

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << queue.getSize() << endl << endl;						// example of getSize

	cout << "--- Pop x1 ---" << endl << endl;

	queue.pop();																// example of pop

	queue.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << queue.getSize() << endl << endl;

	cout << "--- Front ---" << endl << endl;

	cout << queue.front() << endl << endl;										// example of front

	cout << "--- Back ---" << endl << endl;

	cout << queue.back() << endl << endl;										// example of back

	cout << "--- Empty ---" << endl << endl;

	if (queue.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Queue_DA();
}

void QueueDAUI()	// User interaction of queue to test functionality (Dynamic Array version)
{
	cout << "Queue (Dynamic Array version)" << endl << endl;
	cout << "This queue will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if queue is empty." << endl;
		cout << "2. Get size of queue." << endl;
		cout << "3. Push a value onto the queue." << endl;
		cout << "4. Pop a value off of the queue." << endl;
		cout << "5. Get the front value of the queue (bottom value)." << endl;
		cout << "6. Get the back value of the queue (top value)." << endl;
		cout << "7. Print the queue." << endl;
		cout << "8. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			QueueDAUI();
		}

		switch (choice)
		{
		case 1:						// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (queueDA.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:						// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << queueDA.getSize() << endl << endl;
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
				cout << "What number would you like to push onto the queue?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			queueDA.push(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		cout << "--- Pop ---" << endl << endl;
		case 4:						// example of pop
		{
			try
			{
				cout << "Popped: " << queueDA.front() << endl;
			}
			catch (Exception )
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueDAUI();
			}
			queueDA.pop();
			system("pause");
			break;
		}
		case 5:						// example of front
		{
			cout << "--- Front ---" << endl << endl;
			try
			{
				cout << "Front Value: " << queueDA.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueDAUI();
			}
			system("pause");
			break;
		}
		case 6:						// example of back
		{
			cout << "--- Back ---" << endl << endl;
			try
			{
				cout << "Back Value: " << queueDA.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueDAUI();
			}
			system("pause");
			break;
		}
		case 7:						// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				queueDA.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueDAUI();
			}
			system("pause");
			break;
		}
		case 8:						// return to queue dynamic array version menu
		{
			Queue_DA();
			validInput = true;
			break;
		}
		default:					// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			QueueDAUI();
		}
		}
	}
}

void QueueLLHC()	// Hard-coded examples of queue functionality (Linked List version)
{
	QueueLL<int> queue;

	cout << "Int Queue (Linked List version)" << endl << endl;

	cout << "--- Empty ---" << endl << endl;

	if (queue.empty() == 1)														// example of empty
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Push x5 ---" << endl << endl;

	queue.push(3);																// example of push
	queue.push(8);
	queue.push(1);
	queue.push(2);
	queue.push(2);

	queue.printAsLine();														// example of printAsLine

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << queue.getSize() << endl << endl;						// example of getSize

	cout << "--- Pop x3 ---" << endl << endl;

	queue.pop();																// example of pop
	queue.pop();
	queue.pop();

	queue.printAsLine();

	cout << "--- Size ---" << endl << endl;

	cout << "Size: " << queue.getSize() << endl << endl;

	cout << "--- Front ---" << endl << endl;

	cout << queue.front() << endl << endl;										// example of front

	cout << "--- Back ---" << endl << endl;

	cout << queue.back() << endl << endl;										// example of back

	cout << "--- Empty ---" << endl << endl;

	if (queue.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	system("pause");
	cout << endl;
	Queue_LL();
}

void QueueLLUI()	// User interaction of queue to test functionality (Linked List version)
{
	cout << "Queue (Linked List version)" << endl << endl;
	cout << "This queue will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if queue is empty." << endl;
		cout << "2. Get size of queue." << endl;
		cout << "3. Push a value onto the queue." << endl;
		cout << "4. Pop a value off of the queue." << endl;
		cout << "5. Get the front value of the queue (bottom value)." << endl;
		cout << "6. Get the back value of the queue (top value)." << endl;
		cout << "7. Print the queue." << endl;
		cout << "8. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			QueueLLUI();
		}

		switch (choice)
		{
		case 1:						// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (queueLL.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:						// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << queueLL.getSize() << endl << endl;
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
				cout << "What number would you like to push onto the queue?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			queueLL.push(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 4:						// example of pop
		{
			cout << "--- Pop ---" << endl << endl;
			try
			{
				cout << "Popped: " << queueLL.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueLLUI();
			}
			queueLL.pop();
			system("pause");
			break;
		}
		case 5:						// example of front
		{
			cout << "--- Front ---" << endl << endl;
			try
			{
				cout << "Front Value: " << queueLL.front() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueLLUI();
			}
			system("pause");
			break;
		}
		case 6:						// example of back
		{
			cout << "--- Back ---" << endl << endl;
			try
			{
				cout << "Back Value: " << queueLL.back() << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueLLUI();
			}
			system("pause");
			break;
		}
		case 7:						// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				queueLL.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				QueueLLUI();
			}
			system("pause");
			break;
		}
		case 8:						// return to queue linked list version menu
		{
			Queue_LL();
			validInput = true;
			break;
		}
		default:					// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			QueueLLUI();
		}
		}
	}
}

void Queue_DA()	// Choices for user to test queue (Dynamic Array version) functionality
{
	cout << "--- Queue (Dynamic Array Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Queue? (Enter a number)" << endl << endl;

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
			QueueDAHC();
			validInput = true;
			break;
		case 2:
			QueueDAUI();
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
			Queue_DA();
		}
	}
}

void Queue_LL()	// Choices for user to test queue (Linked List version) functionality
{
	cout << "--- Queue (Linked List Version) Menu ---" << endl << endl;
	cout << "How would you like to view the Queue? (Enter a number)" << endl << endl;

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
			QueueLLHC();
			validInput = true;
			break;
		case 2:
			QueueLLUI();
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
			Queue_LL();
		}
	}
}

void QueueMenu()	// Choices for user to test queue functionality
{
	cout << "--- Queue Menu ---" << endl << endl;
	cout << "How would you like to view the Queue? (Enter a number)" << endl << endl;

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
			Queue_DA();
			validInput = true;
			break;
		case 2:
			Queue_LL();
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
			QueueMenu();
		}
	}
}