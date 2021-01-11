#pragma once
#include <algorithm>
#include <memory>
#include "Exceptions.h"

using namespace std;

template <typename T>
class QueueLL
{
private:
	class QueueNode
	{
	public:
		QueueNode(T data, shared_ptr<QueueNode> next, shared_ptr<QueueNode> previous)	// Creates a new QueueNode
		{
			this->data = data;							// Sets this new QueueNode's data to the data passed in 
			this->next = next;							// Sets this new QueueNode's next to the next (QueueNode) passed in 
			this->previous = previous;					// Sets this new QueueNode's previous to the previous (QueueNode) passed in 
		}

		~QueueNode()									// Shared pointers automatically are deleted when the reference number hits 0
		{

		}

		T data;											// QueueNode's data
		shared_ptr<QueueNode> next;						// Reference to QueueNode's next QueueNode
		shared_ptr<QueueNode> previous;					// Reference to QueueNode's previous QueueNode
	};
public:

	class Iterator
	{
	public:
		Iterator(shared_ptr<QueueNode> node = nullptr)	// Creates a new Iterator
		{
			this->node = node;							// Sets the node the Iterator is pointing to, to the QueueNode passed in
		}

		T& getData() const								// Returns the data of QueueNode that the Iterator is pointing to
		{
			if (node == nullptr)
			{
				throw NO_DATA;
			}
			return node->data;
		}

		Iterator next()									// Sets the node the Iterator is pointing to, to the next QueueNode and returns it
		{
			Iterator it(node);
			it++;
			return it;
		}

		Iterator previous()								// Sets the node the Iterator is pointing to, to the previous QueueNode and returns it
		{
			Iterator it(node);
			it--;
			return it;
		}

		Iterator& operator++(int index)					// Sets the node the Iterator is pointing to, to the next QueueNode and returns it
		{
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		Iterator& operator--(int index)					// Sets the node the Iterator is pointing to, to the previous QueueNode and returns it
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
		friend class QueueLL;							// Allows Queue to access Iterator information
		shared_ptr<QueueNode> node;						// Pointer at QueueNode (the Iterator points to this node at all times)
	};
public:
	QueueLL(unsigned int size = 0)
	{
		head = nullptr;
		tail = nullptr;
	}
	~QueueLL()
	{
		clear();
	}

	bool empty() const									// Returns true if Queue is empty and false if otherwise
	{
		if (head == nullptr && tail == nullptr)
			return true;
		else
			return false;
	}

	int getSize()	const								// Returns the size of the Queue (number of nodes)
	{
		return size;
	}

	void push(const T& data)			// Creates a QueueNode and sets it's data to the data provided, sets next to the first QueueNode prior the creation of this new node and next is set to null 
	{
		shared_ptr<QueueNode> n(new QueueNode(data, nullptr, tail));

		if (tail != nullptr)			// If tail contains data
			tail->next = n;				// Set tail's previous to new QueueNode n
		tail = n;						// Set tail pointer to n
		if (head == nullptr)			// If head does not contain data
			head = n;					// Set head's pointer to n
		size++;							// Increase size of Queue by 1
	}


	void pop()							// Remove the last node from the Queue
	{
		if (tail == nullptr)			// If tail does not contain data
			throw NO_DATA;

		shared_ptr<QueueNode> n = tail;	// Create a QueueNode pointer to tail

		if (tail == head)				// If tail is equal to head
			tail = head = nullptr;		// Set tail and head nullptr (Empty Queue)
		else
		{
			tail = tail->previous;		// Set tail to the current tail's previous node
			tail->next = nullptr;		// Set tail's next to nullptr
		}
		size--;							// Decrease size of Queue by 1
	}

	T& front() const					// Returns the front node of the Queue
	{
		if (tail == nullptr)
			throw NO_DATA;
		return tail->data;
	}

	T& back() const						// Returns the back node of the Queue
	{
		if (head == nullptr)
			throw NO_DATA;
		return head->data;
	}
		
	void printAsLine()					// Prints each QueueNode's data in a line
	{
		if (size <= 0)
		{
			throw QUEUE_IS_EMPTY;
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

private:
	shared_ptr<QueueNode> head;									// Pointer to starting node
	shared_ptr<QueueNode> tail;									// Pointer to ending node
	unsigned int size;											// Number of QueueNodes within Queue

	void clear()												// Removes all elements from the Queue
	{
		shared_ptr<QueueNode> n = head;
		shared_ptr<QueueNode> nToRemove;
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
};