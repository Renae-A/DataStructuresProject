#include "stdafx.h"
#include "Functions.h"
#include "DynamicArray.h"

DynamicArray<int> arr(10);

void DynamicArrayHC()	// Hard-coded examples of dynamic array functionality 
{
	DynamicArray<int> arr(8);

	cout << "Dynamic Integer Array" << endl << endl;

	cout << "Used: " << arr.getSize() << endl;								// example of getSize()
	cout << "Allocated: " << arr.getCapacity() << endl << endl;				// example of getCapacity()

	arr.push(4);															// examples of push(value)
	arr.push(1);
	arr.push(2);
	arr.push(6);
	arr.push(3);
	arr.push(4);
	arr.push(8);
	arr.push(7);
	arr.push(9);															// example of resize(newAllocatedElements) - increasing allocated space

	arr.printAsLine();														// example of printAsLine()

	arr.printAsList();														// example of printAsList()

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Erase Index: 3 ---" << endl << endl;
	arr.erase(3, false);													// example of erase(index, ordered) - unordered

	arr.printAsLine();

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Pop ---" << endl << endl;
	arr.pop();																// example of pop();

	arr.printAsLine();

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Array resize(5) ---" << endl << endl;
	arr.resize(5);															// example of resize(newAllocatedElements) - reducing allocated space

	arr.printAsLine();

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Search for 1 ---" << endl << endl;

	if (arr.search(1, false))												// example of search(value, ordered) - unordered 'found' result
		cout << "Found" << endl << endl;
	else
		cout << "Not found" << endl << endl;

	cout << "--- Search for 0 ---" << endl;

	if (arr.search(0, false))												// example of search(value, ordered) - unordered 'not found' result
		cout << "Found" << endl << endl;
	else
		cout << "Not found" << endl << endl;

	cout << "--- Replace 1 with 0 ---" << endl << endl;

	arr.replace(1, 0);														// example of replace()

	arr.printAsLine();

	cout << "--- Bubble Sort ---" << endl << endl;

	arr.bubbleSort();														// example of sort()

	arr.printAsLine();

	cout << "--- Get Element ---" << endl << endl;

	cout << "Element at index 4 is " << arr.getElement(4) << endl << endl;	// example of getElement(index)

	cout << "--- Insert 8 at index 2 ---" << endl << endl;

	arr.insert(2, 8);														// example of insert(index, value)

	arr.printAsLine();

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Insert 1 2 3 at index 5 ---" << endl << endl;

	const int basicArray[3] = { 1, 2, 3 };

	arr.insertMultiple(5, basicArray, 3);									// example of insertMultiple(index, item[], length)

	arr.printAsLine();

	cout << "Used: " << arr.getSize() << endl;
	cout << "Allocated: " << arr.getCapacity() << endl << endl;

	cout << "--- Sort ---" << endl << endl;

	arr.bubbleSort();

	arr.printAsLine();

	cout << "--- Erase Index: 1 ---" << endl << endl;
	arr.erase(1, true);														// example of erase(index, ordered) - ordered

	arr.printAsLine();

	cout << "--- Search for 9 ---" << endl << endl;

	if (arr.search(9, true))												// example of search(value, ordered) - ordered
		cout << "Found" << endl << endl;
	else
		cout << "Not found" << endl << endl;

	cout << "--- Copy Constructor ---" << endl << endl;

	DynamicArray<int> arrB(arr);											// Copy Constructor
	arrB.printAsLine();

	cout << "--- Copy Constructor ---" << endl << endl;

	DynamicArray<int> arrC = arr;											// Still using copy constructor because the assignment is happening during the construction
	arrC.printAsLine();

	cout << "--- Assignment Operator = ---" << endl << endl;

	arr.push(13);															// Assignment operator
	arr.push(100);
	arr.push(999);

	arrC = arr;																// This is using assignment operator

	arr.clear();															// example of clear()

	arrC.printAsLine();														// This should still have all the elements from the assignment

	cout << "--- Assignment Operator [] ---" << endl << endl;

	cout << "Index 5: " << arrC[5] << endl;

	cout << "Capacity: " << arrC.getCapacity() << endl << endl;

	cout << "--- Exception Try and Catch ---" << endl << endl;

	try
	{
		cout << arrC[25] << endl;
	}
	catch (Exception)										
	{
		cout << "Error: Invalid index" << endl << endl;
	}

	cout << "--- Shuffle ---" << endl << endl;

	arrC.shuffle();															// example of shuffle()

	arrC.printAsLine();

	cout << "--- Concatenate ---" << endl << endl;

	arrB.printAsLine();

	cout << "+" << endl << endl;

	arrC.printAsLine();

	cout << "=" << endl << endl;

	arrB.operator+=(arrC);

	arrB.printAsLine();

	system("pause");
	DynamicArrayMenu();
}

void DynamicArrayUI()	// User interaction of dynamic array to test functionality 
{
	cout << "Dynamic Array" << endl << endl;
	cout << "This dynamic array will be taking intergers." << endl << endl;

	bool validInput = false;
	int choice;

	while (validInput == false)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1. Check if dynamic array is empty." << endl;
		cout << "2. Get size of dynamic array." << endl;
		cout << "3. Get capacity of dynamic array." << endl;
		cout << "4. Push a value onto the dynamic array." << endl;
		cout << "5. Pop a value off of the dynamic array." << endl;
		cout << "6. Replace a value in the dynamic array with a new value." << endl;
		cout << "7. Insert a value at an index." << endl;
		cout << "8. Insert multiple values at an index." << endl;
		cout << "9. Erase a value at an index." << endl;
		cout << "10. Clear whole dynamic array." << endl;
		cout << "11. Get element at index." << endl;
		cout << "12. Bubble sort the dynamic array." << endl;
		cout << "13. Insertion sort the dynamic array." << endl;
		cout << "14. Merge sort the dynamic array." << endl;
		cout << "15. Quick sort the dynamic array." << endl;
		cout << "16. Search the dynamic array for value." << endl;
		cout << "17. Shuffle the elements in the dynamic array." << endl;
		cout << "18. Print the dynamic array as a list." << endl;
		cout << "19. Print the dynamic array as a line." << endl;
		cout << "20. Exit." << endl;

		cin >> choice; cout << endl << endl;

		if (cin.fail())
		{
			cout << "Invalid Input Entered." << endl << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			DynamicArrayUI();
		}

		switch (choice)
		{
		case 1:		// example of empty
		{
			cout << "--- Empty ---" << endl << endl;
			cout << "Empty: ";
			if (arr.empty() == 1)
				cout << "True" << endl << endl;
			else
				cout << "False" << endl << endl;
			system("pause");
			break;
		}
		case 2:		// example of getSize
		{
			cout << "--- Get Size ---" << endl << endl;
			cout << "Size: " << arr.getSize() << endl << endl;
			system("pause");
			break;
		}
		case 3:		// example of getCapacity
		{
			cout << "--- Get Capacity ---" << endl << endl;
			cout << "Capacity: " << arr.getCapacity() << endl << endl;
			system("pause");
			break;
		}
		case 4:		// example of push
		{
			cout << "--- Push ---" << endl << endl;
			bool input = false;
			int decision;
			while (input == false)
			{
				cout << "What number would you like to push onto the dynamic array?" << endl;
				cin >> decision; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}

			arr.push(decision);
			cout << "Pushed: " << decision << endl;
			system("pause");
			break;
		}
		case 5:		// example of pop
		{
			cout << "--- Pop ---" << endl << endl;
			try
			{
				cout << "Popped: " << arr.getElement((arr.getSize() - 1)) << endl;
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			arr.pop();
			system("pause");
			break;
		}
		case 6: 	// example of replace
		{
			cout << "--- Replace ---" << endl << endl;
			bool input = false;
			int index;
			int value;
			while (input == false)
			{
				cout << "What index value would you like to replace?" << endl;
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
			try
			{
				cout << "Old Value: " << arr.getElement(index) << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			cout << "New Value: " << value << endl;
			arr.replace(index, value);
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
			try
			{
				arr.insert(index, value);
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			cout << "Index: " << index << endl;
			cout << "Value: " << value << endl;
			system("pause");
			break;
		}
		case 8:		// example of insertMultiple
		{
			cout << "--- Insert Multiple ---" << endl << endl;
			bool input = false;
			int length;
			int index;
			int value;
			while (input == false)
			{
				cout << "How many values would you like to insert?" << endl;
				cin >> length; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
				{
					DynamicArray<int> newArr(length);
					bool input1 = false;
					while (input1 == false)
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
							bool input2 = false;
							while (input2 == false)
							{
								cout << "What numbers would you like to use? (Type number and press Enter for each number)" << endl;
								cout << "Note: The order you enter the numbers will be reversed." << endl;
								for (int i = 0; i < length; i++)
								{
									cin >> value; cout << endl;
									if (cin.fail())
									{
										cin.clear();
										cin.ignore();
									}
									else
									{
										newArr.push(value);
									}
								}
								cout << endl;
								try
								{
									arr.insertMultiple(index, newArr, length);
								}
								catch (Exception)
								{
									cout << "Error: Invalid index" << endl << endl;
									system("pause");
									DynamicArrayUI();
								}
								input1 = true;
								input2 = true;
							}
						}
					}
				}
				input = true;
			}
			system("pause");
			break;
		}
		case 9:		// example of erase
		{
			cout << "--- Erase ---" << endl << endl;
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
			cout << "Index Erased: " << decision << endl;
			try
			{
				cout << "Value Erased: " << arr.getElement(decision) << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			arr.erase(decision);
			system("pause");
			break;
		}
		case 10: 	// example of clear
		{
			cout << "--- Clear ---" << endl << endl;
			arr.clear();
			system("pause");
			break;
		}
		case 11:	// example of getElement
		{
			cout << "--- Get Element ---" << endl << endl;
			bool input = false;
			int index;
			while (input == false)
			{
				cout << "Which index would you like to get element?" << endl;
				cin >> index; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			cout << "Index: " << index << endl;
			try
			{
				cout << "Value: " << arr.getElement(index) << endl;
			}
			catch (Exception)
			{
				cout << "Error: Invalid index" << endl << endl;
				DynamicArrayUI();
				system("pause");
			}
			system("pause");
			break;
		}
		case 12:	// example of bubbleSort 
		{
			cout << "--- Bubble Sort ---" << endl << endl;
			try
			{
				arr.bubbleSort();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 13:	// example of insertionSort
		{
			cout << "--- Insertion Sort ---" << endl << endl;
			try
			{
				arr.insertionSort();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 14:	// example of mergeSort
		{
			cout << "--- Merge Sort ---" << endl << endl;
			int startIdx = 0;
			int endIdx = (arr.getSize() - 1);
			try
			{
				arr.mergeSort(startIdx, endIdx);
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 15:	// example of quickSort
		{
			cout << "--- Quick Sort ---" << endl << endl;
			int left = 0;
			int right = (arr.getSize() - 1);
			try
			{
				arr.quickSort(left, right);
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 16: 	// example of search
		{
			cout << "--- Search ---" << endl << endl;
			bool input = false;
			int value;
			while (input == false)
			{
				cout << "What value do you want to search for?" << endl;
				cin >> value; cout << endl << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
				else
					input = true;
			}
			if (arr.search(value))
				cout << "Found: " << value << endl << endl;
			else
				cout << "Not found: " << value << endl << endl;
			system("pause");
			break;
		}
		case 17: 	// example of shuffle
		{
			cout << "--- Shuffle ---" << endl << endl;
			try
			{
				arr.shuffle();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 18: 	// example of printAsList
		{
			cout << "--- Print As List ---" << endl << endl;
			try
			{
				arr.printAsList();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 19:	// example of printAsLine
		{
			cout << "--- Print As Line ---" << endl << endl;
			try
			{
				arr.printAsLine();
			}
			catch (Exception)
			{
				cout << "Error: No Data" << endl << endl;
				system("pause");
				DynamicArrayUI();
			}
			system("pause");
			break;
		}
		case 20:	// return to dynamic array menu
		{
			DynamicArrayMenu();
			validInput = true;
			break;
		}
		default:	// default response
		{
			cout << "Invalid Input Entered." << endl;
			system("pause");
			cout << endl;
			DynamicArrayUI();
		}
		}
	}
}

void DynamicArrayMenu()	// The dynamic array menu to decide on how the user wants to view the examples
{
	cout << "--- Dynamic Array Menu ---" << endl << endl;
	cout << "How would you like to view the Dynamic Array? (Enter a number)" << endl << endl;

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
			DynamicArrayHC();
			validInput = true;
			break;
		case 2:
			DynamicArrayUI();
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
			DynamicArrayMenu();
		}
	}
}