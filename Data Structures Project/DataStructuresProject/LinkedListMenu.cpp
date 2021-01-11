#include "stdafx.h"
#include "Functions.h"
#include "LinkedList.h"
#include <string>

LinkedList<int> list;	// This list is a global variable because LinkedListUI() will be call multiple times within the same function and otherwise it will not be able to read the previous data

void LinkedListHC()		// Hard-coded examples of linked list functionality 
{
	LinkedList<string> list;

	cout << "Linked List with Strings" << endl << endl;

	cout << "--- Empty ---" << endl << endl;								// example of empty() true

	if (list.empty() == 1)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "Size: " << list.count() << endl << endl;						// example of count()

	cout << "--- Push Front x3 ---" << endl << endl;

	list.pushFront("John");													// examples of pushFront(value)
	list.pushFront("Max");
	list.pushFront("Ruth");

	list.printAsList();														// example of printAsList();

	list.printAsLine();														// example of PrintAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Erase Iterator Placement - begin() ---" << endl << endl;

	auto it = list.begin();													// example of begin();

	list.erase(it);															// example of erase(iterator)

	list.printAsLine();														// example of printAsLine()

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Pop Front x1 ---" << endl << endl;

	list.popBack();															// example of popFront();

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Push Back x2 ---" << endl << endl;

	list.pushBack("Peter");													// examples of pushBack(value)
	list.pushBack("Eliza");

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Pop Back x2 ---" << endl << endl;

	list.popBack();															// example of popBack();
	list.popBack();

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Push Back x5 ---" << endl << endl;

	list.pushBack("Simon");
	list.pushBack("Frank");
	list.pushBack("Steven");
	list.pushBack("Luke");
	list.pushBack("Penny");

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Insert Kylie at ListNode 4 ---" << endl << endl;

	it = list.setIteratorByIndex(4);										// example of setIteratorByIndex(index)

	list.insert(it, "Kylie");												// example of insert(iterator, data)

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Erase Iterator Placement - end() ---" << endl << endl;

	it = list.end();														// example of end();

	list.erase(it);

	list.printAsLine();

	cout << "--- Search Simon and Return Placement ---" << endl << endl;

	cout << "Simon is at location: " << list.search("Simon") << endl << endl;// example of search(value) existing

	cout << "--- First in LinkedList ---" << endl << endl;

	cout << list.first() << endl << endl;									// example of first()

	cout << "--- Last in LinkedList ---" << endl << endl;

	cout << list.last() << endl << endl;									// example of last()

	cout << "--- Search Poppy ---" << endl << endl;

	list.search("Poppy");													// example of search(value) non existing

	cout << "--- Empty ---" << endl << endl;

	if (list.empty() == 1)													// example of empty() false
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;

	cout << "--- Remove Frank ---" << endl << endl;

	string toRemove = "Frank";

	list.remove(toRemove);

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Insert Yilmaz at Kylie ---" << endl << endl;

	it = list.setIteratorByData("Kylie");									// example of setIteratorByIndex(index)

	list.insert(it, "Yilmaz");

	list.printAsLine();

	cout << "Size: " << list.count() << endl << endl;

	cout << "--- Bubble Sort ---" << endl << endl;

	list.bubbleSort();

	list.printAsLine();

	cout << "--- Clear LinkedList ---" << endl << endl;

	list.clear();															// example of clear()

	cout << "Size: " << list.count() << endl << endl;

	system("pause");
	cout << endl;
	LinkedListMenu();
}

void LinkedListUI()		// User interaction of linked list to test functionality 
{
	cout << "Linked List" << endl << endl;
	cout << "This linked list will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if linked list is empty." << endl;
		cout << "2. Get size of linked list." << endl;
		cout << "3. Push a value onto the front of the dynamic array." << endl;
		cout << "4. Push a value onto the back of the dynamic array." << endl;
		cout << "5. Pop a value off of the front of the dynamic array." << endl;
		cout << "6. Pop a value off of the back of the dynamic array." << endl;
		cout << "7. Insert a value at an index." << endl;
		cout << "8. Erase a value at an index." << endl;
		cout << "9. Remove all nodes of certain value in linked list." << endl;
		cout << "10. Clear whole linked list." << endl;
		cout << "11. Get iterator to start of linked list." << endl;
		cout << "12. Get iterator to end of linked list." << endl;
		cout << "13. Return the first value of the linked list." << endl;
		cout << "14. Return the last value of the linked list." << endl;
		cout << "15. Set iterator by index." << endl;
		cout << "16. Set iterator by value." << endl;
		cout << "17. Search value in linked list." << endl;
		cout << "18. Bubble sort the linked list." << endl;
		cout << "19. Insertion sort the linked list." << endl;
		cout << "20. Print the dynamic array as a list." << endl;
		cout << "21. Print the dynamic array as a line." << endl;
		cout << "22. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			LinkedListUI();
		}

		switch (choice)
		{
		case 1:		// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (list.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:		// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << list.count() << endl << endl;
			system("pause");
			break;
		}
		case 3:		// example of pushFront
		{
			cout << "--- Push Front ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the front of the linked list?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			list.pushFront(decision);
			cout << "Pushed Front: " << decision << endl;
			system("pause");
			break;
		}
		case 4:		// example of pushBack
		{
			cout << "--- Push Back ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the back of the linked list?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			list.pushBack(decision);
			cout << "Pushed Back: " << decision << endl;
			system("pause");
			break;
		}
		case 5:		// example of popFront
		{
			cout << "--- Pop Front ---" << endl << endl;
			try
			{
				cout << "Popped Front: " << list.first() << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			list.popFront();
			system("pause");
			break;
		}
		case 6:		// example of popBack
		{
			cout << "--- Pop Back ---" << endl << endl;
			try
			{
				cout << "Popped Back: " << list.last() << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			list.popBack();
			system("pause");
			break;
		}
		case 7:		// example of insert
		{
			cout << "--- Insert ---" << endl << endl;
			bool input = false;
			int index;
			int value;
			while (input == false)
			{
				cout << "What index value would you like to insert into?" << endl;
				cin >> index; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
				{
					bool input1 = false;
					while (input1 == false)
					{
						cout << "What value would you like to use?" << endl;
						cin >> value; cout << endl << endl;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore();
						}
						else
						{
							input1 = true;
						}

					}
				}
				input = true;
			}
			cout << "Index: " << index << endl;
			cout << "Value: " << value << endl;
			try
			{
				list.setIteratorByIndex(index);
			}
			catch (Exception)										
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			auto it = list.setIteratorByIndex(index);
			list.insert(it, value);
			system("pause");
			break;
		}
		case 8:		// example of erase index
		{
			cout << "--- Erase By Index ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What index would you like to erase?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			try 
			{
				list.setIteratorByIndex(decision);
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			cout << "Index Erased: " << decision << endl;
			auto it = list.setIteratorByIndex(decision);
			list.erase(it);
			system("pause");
			break;
		}
		case 9:		// example of erase value
		{
			cout << "--- Erase By Value ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What value would you like to erase from the linked list?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			cout << "Value Removed: " << decision << endl;
			cout << "Amount of Value in Linked List: " << list.remove(decision) << endl;
			system("pause");
			break;
		}
		case 10:		// example of clear
		{
			cout << "--- Clear ---" << endl << endl;
			list.clear();
			system("pause");
			break;
		}
		case 11:		// example of begin
		{
			cout << "--- Begin ---" << endl << endl;
			try
			{
				list.begin();
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 12:		// example of end
		{
			cout << "--- End ---" << endl << endl;
			try
			{
				list.end();
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 13:		// example of first
		{
			cout << "--- First ---" << endl << endl;
			try
			{
				cout << "First Value in Linked List: " << list.first() << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 14:		// example of last
		{
			cout << "--- Last ---" << endl << endl;
			try
			{
				cout << "Last Value in Linked List: " << list.last() << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 15:		// example of setIteratorByIndex
		{
			cout << "--- Set Iterator By Index ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What index would you like to set iterator to?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			try
			{
				list.setIteratorByIndex(decision);
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			cout << "Index: " << decision << endl;
			system("pause");
			break;
		}
		case 16:		// example of setIteratorByValue
		{
			cout << "--- Set Iterator By Value ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What value would you like to set iterator to?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			list.setIteratorByData(decision);
			cout << "Value: " << decision << endl;
			system("pause");
			break;
		}
		case 17:		// example of search
		{
			cout << "--- Search ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What value would you like to search for?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			cout << "Value: " << decision << endl;
			cout << "Index: " << list.search(decision) << endl;
			system("pause");
			break;
		}
		case 18:		// example of bubbleSort
		{
			cout << "--- Bubble Sort ---" << endl << endl;
			try
			{
				list.bubbleSort();
			}
			catch (Exception)
			{
				cout << "Error: No data" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 19:		// example of insertionSort
		{
			cout << "--- Insertion Sort ---" << endl << endl;
			try
			{
				list.insertionSort();
			}
			catch (Exception)
			{
				cout << "Error: No data" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 20:		// example of printAsList
		{
			cout << "--- Print As List ---" << endl << endl;
			try
			{
				list.printAsList();
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 21:		// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				list.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				LinkedListUI();
			}
			system("pause");
			break;
		}
		case 22:		// returns to linked list menu
		{
			LinkedListMenu();
			validInput = true;
			break;
		}
		default:		// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			LinkedListUI();
		}
		}
	}
}

void LinkedListMenu()	// The linked list menu to decide on how the user wants to view the examples
{
	cout << "--- Linked List Menu ---" << endl << endl;
	cout << "How would you like to view the Linked List? (Enter a number)" << endl << endl;

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
			LinkedListHC();
			validInput = true;
			break;
		case 2:
			list.clear();
			LinkedListUI();
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
			LinkedListMenu();
		}
	}
}