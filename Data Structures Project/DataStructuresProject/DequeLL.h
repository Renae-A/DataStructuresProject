#pragma once
#include <algorithm>
#include <memory>
#include "Exceptions.h"

using namespace std;

template <typename T>
class DequeLL
{
private:
	class DequeNode
	{
	public:
		DequeNode(T data, shared_ptr<DequeNode> next, shared_ptr<DequeNode> previous)	// Creates a new DequeNode
		{
			this->data = data;							// Sets this new DequeNode's data to the data passed in 
			this->next = next;							// Sets this new DequeNode's next to the next (DequeNode) passed in 
			this->previous = previous;					// Sets this new DequeNode's previous to the previous (DequeNode) passed in 
		}

		~DequeNode()									// Shared pointers automatically are deleted when the reference number hits 0
		{

		}

		T data;											// DequeNode's data
		shared_ptr<DequeNode> next;						// Reference to DequeNode's next DequeNode
		shared_ptr<DequeNode> previous;					// Reference to DequeNode's previous DequeNode
	};
public:

	class Iterator
	{
	public:
		Iterator(shared_ptr<DequeNode> node = nullptr)	// Creates a new Iterator
		{
			this->node = node;							// Sets the node the Iterator is pointing to, to the DequeNode passed in
		}

		T& getData() const								// Returns the data of DequeNode that the Iterator is pointing to
		{
			if (node == nullptr)
			{
				throw NO_DATA;
			}
			return node->data;
		}

		Iterator next()									// Sets the node the Iterator is pointing to, to the next DequeNode and returns it
		{
			Iterator it(node);
			it++;
			return it;
		}

		Iterator previous()								// Sets the node the Iterator is pointing to, to the previous DequeNode and returns it
		{
			Iterator it(node);
			it--;
			return it;
		}

		Iterator& operator++(int index)					// Sets the node the Iterator is pointing to, to the next DequeNode and returns it
		{
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		Iterator& operator--(int index)					// Sets the node the Iterator is pointing to, to the previous DequeNode and returns it
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
		friend class DequeLL;							// Allows Deque to access Iterator information
		shared_ptr<DequeNode> node;						// Pointer at DequeNode (the Iterator points to this node at all times)
	};
public:
	DequeLL(unsigned int size = 0)
	{
		head = nullptr;
		tail = nullptr;
	}
	~DequeLL()
	{
		clear();
	}

	bool empty() const									// Returns true if Deque is empty and false if otherwise
	{
		if (head == nullptr && tail == nullptr)
			return true;
		else
			return false;
	}

	int getSize()	const								// Returns the size of the Deque (number of nodes)
	{
		return size;
	}

	void pushFront(const T& data)		// Creates a DequeNode and sets it's data to the data provided, sets next to the first DequeNode prior the creation of this new node and previous is set to null 
	{
		shared_ptr<DequeNode> n(new DequeNode(data, head, nullptr));

		if (head != nullptr)			// If head contains data
			head->previous = n;			// Set head's previous to new DequeNode n
		head = n;						// Set head pointer to n
		if (tail == nullptr)			// If tail does not contain data
			tail = n;					// Set tail's pointer to n
		size++;							// Increase size of Deque by 1
	}

	void pushBack(const T& data)		// Creates a DequeNode and sets it's data to the data provided, sets next to the first DequeNode prior the creation of this new node and next is set to null 
	{
		shared_ptr<DequeNode> n(new DequeNode(data, nullptr, tail));

		if (tail != nullptr)			// If tail contains data
			tail->next = n;				// Set tail's previous to new DequeNode n
		tail = n;						// Set tail pointer to n
		if (head == nullptr)			// If head does not contain data
			head = n;					// Set head's pointer to n
		size++;							// Increase size of Deque by 1
	}

	void popFront()						// Remove the first node from the Deque
	{
		if (head == nullptr)			// If head does not contain data
			throw NO_DATA;

		shared_ptr<DequeNode> n = head;	// Create a DequeNode pointer to head

		if (head == tail)				// If head is equal to tail
			head = tail = nullptr;		// Set head and tail nullptr (Empty Deque)
		else
		{
			head = head->next;			// Set head to the current head's next node
			head->previous = nullptr;	// Set head's previous to nullptr
		}
		size--;							// Decrease size of Deque by 1
	}

	void popBack()						// Remove the last node from the Deque
	{
		if (tail == nullptr)			// If tail does not contain data
			throw NO_DATA;

		shared_ptr<DequeNode> n = tail;	// Create a DequeNode pointer to tail

		if (tail == head)				// If tail is equal to head
			tail = head = nullptr;		// Set tail and head nullptr (Empty Deque)
		else
		{
			tail = tail->previous;		// Set tail to the current tail's previous node
			tail->next = nullptr;		// Set tail's next to nullptr
		}
		size--;							// Decrease size of Deque by 1
	}

	T& front() const					// Returns the front node of the Deque
	{
		if (tail == nullptr)
			throw NO_DATA;
		return tail->data;
	}

	T& back() const						// Returns the back node of the Deque
	{
		if (head == nullptr)
			throw NO_DATA;
		return head->data;
	}

	void printAsLine()					// Prints each DequeNode's data in a line
	{
		if (size <= 0)
		{
			throw DEQUE_IS_EMPTY;
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
	shared_ptr<DequeNode> head;			// Pointer to starting node
	shared_ptr<DequeNode> tail;			// Pointer to ending node
	unsigned int size;					// Number of DequeNodes within Deque

	void clear()						// Removes all elements from the Deque
	{
		shared_ptr<DequeNode> n = head;
		shared_ptr<DequeNode> nToRemove;
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