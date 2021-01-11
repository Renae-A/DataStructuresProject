#include <memory>
#include "Exceptions.h"
#pragma once

using namespace std;

template <class T>
class LinkedList
{
private:
	class ListNode
	{
	public:
		ListNode(T data, shared_ptr<ListNode> next, shared_ptr<ListNode> previous)	// Creates a new ListNode
		{
			this->data = data;			// Sets this new ListNode's data to the data passed in 
			this->next = next;			// Sets this new ListNode's next to the next (ListNode) passed in 
			this->previous = previous;	// Sets this new ListNode's previous to the previous (ListNode) passed in 
		}

		~ListNode()
		{

		}

		T data;							// ListNode's data
		shared_ptr<ListNode> next;		// Reference to ListNode's next ListNode
		shared_ptr<ListNode> previous;	// Reference to ListNode's previous ListNode
	};
public:

	class Iterator
	{
	public:
		Iterator(shared_ptr<ListNode> node = nullptr)	// Creates a new Iterator
		{
			this->node = node;							// Sets the node the Iterator is pointing to, to the ListNode passed in
		}

		T& getData() const								// Returns the data of ListNode that the Iterator is pointing to
		{
			if (node == nullptr)
			{
				throw NO_DATA;
			}
			return node->data;
		}

		Iterator next()									// Sets the node the Iterator is pointing to, to the next ListNode and returns it
		{
			Iterator it(node);
			it++;
			return it;
		}

		Iterator previous()								// Sets the node the Iterator is pointing to, to the previous ListNode and returns it
		{
			Iterator it(node);
			it--;
			return it;
		}

		Iterator& operator++(int index)					// Sets the node the Iterator is pointing to, to the next ListNode and returns it
		{
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		Iterator& operator--(int index)					// Sets the node the Iterator is pointing to, to the previous ListNode and returns it
		{
			if (node != nullptr)
				node = node->previous;
			return *this;
		}

		bool operator==(const Iterator& other) const	// Check if the Iterator is equal to another Iterator 
		{
			return (node == other.node);
		}

		bool operator!=(const Iterator& other) const	// Check if the Iterator is not equal to another Iterator 
		{
			return !operator==(other);
		}

	private:
		friend class LinkedList;		// Allows LinkedList to access Iterator information
		shared_ptr<ListNode> node;		// Pointer at ListNode (the Iterator points to this node at all times)
	};
	LinkedList()						// Creates an empty LinkedList that sets the head and tail to null pointers
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~LinkedList()						// Delete and remove all nodes from LinkedList to return to empty list
	{
		clear();
	}

	void pushFront(const T& data)		// Creates a ListNode and sets it's data to the data provided, sets next to the first ListNode prior the creation of this new node and previous is set to null 
	{
		shared_ptr<ListNode> n(new ListNode(data, head, nullptr));

		if (head != nullptr)			// If head contains data
			head->previous = n;			// Set head's previous to new ListNode n
		head = n;						// Set head pointer to n
		if (tail == nullptr)			// If tail does not contain data
			tail = n;					// Set tail's pointer to n
		size++;							// Increase size of LinkedList by 1
	}

	void pushBack(const T& data)		// Creates a ListNode and sets it's data to the data provided, sets next to the first ListNode prior the creation of this new node and next is set to null 
	{
		shared_ptr<ListNode> n(new ListNode(data, nullptr, tail));

		if (tail != nullptr)			// If tail contains data
			tail->next = n;				// Set tail's previous to new ListNode n
		tail = n;						// Set tail pointer to n
		if (head == nullptr)			// If head does not contain data
			head = n;					// Set head's pointer to n
		size++;							// Increase size of LinkedList by 1
	}

	void popFront()						// Remove the first node from the LinkedList
	{
		if (head == nullptr)			// If head does not contain data
			throw NO_DATA;

		shared_ptr<ListNode> n = head;	// Create a ListNode pointer to head

		if (head == tail)				// If head is equal to tail
			head = tail = nullptr;		// Set head and tail nullptr (Empty LinkedList)
		else
		{
			head = head->next;			// Set head to the current head's next node
			head->previous = nullptr;	// Set head's previous to nullptr
		}
		size--;							// Decrease size of LinkedList by 1
	}

	void popBack()						// Remove the last node from the LinkedList
	{
		if (tail == nullptr)			// If tail does not contain data
			throw NO_DATA;

		shared_ptr<ListNode> n = tail;	// Create a ListNode pointer to tail

		if (tail == head)				// If tail is equal to head
			tail = head = nullptr;		// Set tail and head nullptr (Empty LinkedList)
		else
		{
			tail = tail->previous;		// Set tail to the current tail's previous node
			tail->next = nullptr;		// Set tail's next to nullptr
		}
		size--;							// Decrease size of LinkedList by 1
	}

	void insert(Iterator& placement, const T& value)			// Insert a new ListNode with data into specified node place in LinkedList 
	{
		if (placement == Iterator(head))						// If Iterator is equal to head
			pushFront(value);									// Push value onto front of LinkedList
		else if (placement == Iterator(tail))					// If Iterator is equal to tail
			pushBack(value);									// Push value onto back of LinkedList

		shared_ptr<ListNode> node(new ListNode(value, nullptr, nullptr));		// Create a reference to a new ListNode with the new data

		Iterator temp1 = placement.node->previous;
		Iterator temp2 = placement.node;

		node->next = temp2.node;								// Set the new node's next to placement node 
		node->previous = temp1.node;							// Set the new node's previous to placement node's previous 
		placement.node->previous = node;						// Set placement node's previous to node 
		temp1.node->next = node;								// Set placement node's previous to node 

		size++;													// Increase size of LinkedList by 1
	}

	Iterator begin()											// Set Iterator to first place in LinkedList and returns the iterator
	{
		if (head == nullptr)									// If no head data
			throw NO_DATA;
		return Iterator(head);
	}

	Iterator end()												// Set Iterator to last place in LinkedList
	{
		if (tail == nullptr)									// If no tail data
			throw NO_DATA;
		return Iterator(tail);
	}

	int search(const T& value)									// Finds a value in the LinkedList and returns location number of the node with said data
	{
		Iterator temp = head;									// Create a new temporary Iterator
		int count = 1;											// Counter of nodes

		while (temp.node->data != value || temp.node == tail)	// Iterate through LinkedList until data is found and count how many times iteration occurs
		{
			temp++;
			count++;
			if (temp.node == tail)
			{
				break;
			}
		}

		if (temp.node->data == value)							// If the data is found within the LinkedList
			return count;										// Return location number of the node with said data

		else													// Return starting node location of the LinkedList if value is not found
		{
			cout << "Could not locate " << value << " in list." << endl << endl;
			return 0;
		}
	}

	Iterator setIteratorByIndex(unsigned int index)				// Returns Iterator placement at chosen index
	{
		if (index > size || index <= 0)							// Check if chosen index is less than/equals 0 or larger than the amount of items in the list
			throw OUT_OF_BOUNDS;
		Iterator it;
		it = begin();
		for (unsigned int i = 0; i < (index - 1); i++)
		{
			it++;
		}
		return it;
	}

	Iterator setIteratorByData(const T& value)					// Returns Iterator placement
	{
		Iterator temp = head;									// Create a new temporary Iterator

		while (temp.node->data != value || temp.node == tail)	// Iterate through LinkedList until data is found
			temp++;

		if (temp.node->data == value)							// If the data is found within the LinkedList
			return temp;										// Return the Iterator at the node placement that the data is at
			
		else													// Return the Iterator at the node placement to the starting node of the LinkedList
		{
			cout << "Could not locate " << value << " in list. Returning iterator to beginning of list." << endl;
			temp = begin();
			return temp;
		}
	}

	T& first() const											// Returns the first node of the LinkedList
	{
		if (head == nullptr)
			throw NO_DATA;
		return head->data;
	}

	T& last() const												// Returns the last node of the LinkedList
	{
		if (tail == nullptr)
			throw NO_DATA;
		return tail->data;
	}

	int count()	const											// Returns the size of the LinkedList (number of nodes)
	{
		return size;
	}

	void printAsList()											// Prints each ListNode's data in a list
	{
		if (size <= 0)
		{
			throw NO_DATA;
		}
		Iterator temp = head;
		int count = 1;

		while (temp != tail->next)
		{
			cout << "Node " << count << ": " << temp.node->data << endl;
			temp++;
			count++;
		}
		cout << endl;
	}

	void printAsLine()											// Prints each ListNode's data in a line
	{
		if (size <= 0)											// Check size of linked list in case there is no data
		{
			throw NO_DATA;
		}
		Iterator temp = head;
		int count = 1;

		while (temp != tail->next)
		{
			cout << temp.node->data << " ";
			temp++;
			count++;
		}
		cout << endl; cout << endl;
	}

	int erase(Iterator placement)
	{
		if (placement == Iterator(head))						// If Iterator is equal to head
		{
			popFront();											// Pop value off front of LinkedList
			return 0;
		}
		else if (placement == Iterator(tail))					// If Iterator is equal to tail
		{
			popBack();											// Pop value off back of LinkedList
			return 0;
		}

		Iterator temp1 = placement.node->previous;				// Previous ListNode
		Iterator temp2 = placement.node->next;					// Next ListNode

		if (temp1.node.get() != nullptr)
		{
			temp1.node->next = temp2.node;						// Previous ListNode's next to the placement ListNode's next
		}

		if (temp2.node != nullptr)
		{
			temp2.node->previous = temp1.node;					// Next ListNode's previous to the placement ListNode's previous
		}

		size--;													// Decrease size of LinkedList by 1
		return 0;
	}

	int remove(const T& value)									// Remove all elements with matching value
	{
		Iterator temp = head;									// Create temporary Iterator pointing to head
		int counter = 0;

		while (temp.node != nullptr)							// While the Iterator is still pointing to a ListNode in the LinkedList
		{
			if (temp.node->data == value)						// If the ListNode that the Iterator is pointing to has the same data as the value passed in by reference
			{
				erase(temp);									// Erase the ListNode		
				counter++;										// Increase the counter
			}
			temp++;												// Increment the Iterator
		}
		if (counter > 0)
			return counter;
		return 0;
	}

	bool empty() const											// Returns true if LinkedList is empty and false if otherwise
	{
		if (head == nullptr && tail == nullptr)
			return true;
		else
			return false;
	}

	void clear()												// Removes all elements from the LinkedList
	{
		shared_ptr<ListNode> n = head;
		shared_ptr<ListNode> nToRemove;
		while (n != nullptr)
		{
			nToRemove = n;
			n = n->next;
			nToRemove->next.reset();
			nToRemove->previous.reset();
			size--;
		}
		head.reset();
		tail.reset();
	}

	void bubbleSort()											// Sorts in ascending order using the bubble sorting algorithm
	{
		if (size <= 0)											// Check size of linked list in case there is no data					
		{
			throw NO_DATA;
		}
		bool unordered = true;
		Iterator it = head;

		while (unordered == true)
		{
			unordered = false;									
			it = begin();
			while (it.node != tail)								// For every item in the linked list
			{
				if (it.node->data > it.node->next->data)		// Check if the next item is less than the current item
				{
					auto temp = it.node->data;					// Swap the values
					auto temp2 = it.node->next->data;
					it.node->data = temp2;
					it.node->next->data = temp;
					unordered = true;
				}
				it++;
			}
		}
	}

	void insertionSort()										// Sorts in ascending order using the insertion sorting algorithm
	{
		if (size <= 0)											// Check size of linked list in case there is no data
		{
			throw NO_DATA;
		}
	
		bool unordered = true;
		while (unordered == true)								
		{
			unordered = false;									
			Iterator iterI = head; iterI++;						// Starting at the second item
			int i = 2;											
			
			for (unsigned int i = 2; i <= size; i++)						// For each item in the linked list
			{
				int key = iterI.node->data;									// Key is the current node's value
				Iterator iterJ = iterI.node->previous; int j = (i - 1);

				while (j >= 1 && iterJ.node->data > key)					// While the key's value is less than the value to its left
				{
					iterJ.node->next->data = iterJ.node->data;				// Swap the values
					iterJ.node->data = key;
					unordered = true;
				}
				iterI++;
			}
		}
	}

private:
	shared_ptr<ListNode> head;	// Pointer to starting node
	shared_ptr<ListNode> tail;	// Pointer to ending node
	unsigned int size;			// Number of ListNodes within LinkedList
};

