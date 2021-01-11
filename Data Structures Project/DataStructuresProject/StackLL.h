#pragma once
#include <algorithm>
#include <memory>

template <typename T>
class StackLL
{
private:
	class StackNode
	{
	public:
		StackNode(T data, shared_ptr<StackNode> next, shared_ptr<StackNode> previous)	// Creates a new StackNode
		{
			this->data = data;			// Sets this new StackNode's data to the data passed in 
			this->next = next;			// Sets this new StackNode's next to the next (StackNode) passed in 
			this->previous = previous;	// Sets this new StackNode's previous to the previous (StackNode) passed in 
		}

		~StackNode()
		{

		}

		T data;							// StackNode's data
		shared_ptr<StackNode> next;		// Reference to StackNode's next StackNode
		shared_ptr<StackNode> previous;	// Reference to StackNode's previous StackNode
	};
public:

	class Iterator
	{
	public:
		Iterator(shared_ptr<StackNode> node = nullptr)	// Creates a new Iterator
		{
			this->node = node;							// Sets the node the Iterator is pointing to, to the StackNode passed in
		}

		T& getData() const								// Returns the data of StackNode that the Iterator is pointing to
		{
			if (node == nullptr)
			{
				throw NO_DATA;
			}
			return node->data;
		}

		Iterator next()									// Sets the node the Iterator is pointing to, to the next StackNode and returns it
		{
			Iterator it(node);
			it++;
			return it;
		}

		Iterator previous()								// Sets the node the Iterator is pointing to, to the previous StackNode and returns it
		{
			Iterator it(node);
			it--;
			return it;
		}

		Iterator& operator++(int index)					// Sets the node the Iterator is pointing to, to the next StackNode and returns it
		{
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		Iterator& operator--(int index)					// Sets the node the Iterator is pointing to, to the previous StackNode and returns it
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
		friend class StackLL;							// Allows Stack to access Iterator information
		shared_ptr<StackNode> node;						// Pointer at StackNode (the Iterator points to this node at all times)
	};
public:
	StackLL(unsigned int size = 0)
	{
		head = nullptr;
		tail = nullptr;
	}
	~StackLL()
	{
		clear();
	}

	bool empty() const									// Returns true if Stack is empty and false if otherwise
	{
		if (head == nullptr && tail == nullptr)
			return true;
		else
			return false;
	}

	int getSize()	const								// Returns the size of the Stack (number of nodes)
	{
		return size;
	}

	void push(const T& data)			// Creates a StackNode and sets it's data to the data provided, sets next to the first StackNode prior the creation of this new node and next is set to null 
	{
		shared_ptr<StackNode> n(new StackNode(data, nullptr, tail));

		if (tail != nullptr)			// If tail contains data
			tail->next = n;				// Set tail's previous to new StackNode n
		tail = n;						// Set tail pointer to n
		if (head == nullptr)			// If head does not contain data
			head = n;					// Set head's pointer to n
		size++;							// Increase size of Stack by 1
	}


	void pop()							// Remove the last node from the Stack
	{
		if (tail == nullptr)			// If tail does not contain data
			throw NO_DATA;

		shared_ptr<StackNode> n = tail;	// Create a StackNode pointer to tail

		if (tail == head)				// If tail is equal to head
			tail = head = nullptr;		// Set tail and head nullptr (Empty Stack)
		else
		{
			tail = tail->previous;		// Set tail to the current tail's previous node
			tail->next = nullptr;		// Set tail's next to nullptr
		}
		size--;							// Decrease size of Stack by 1
	}

	T& top() const						// Returns the top node of the Stack
	{
		if (tail == nullptr)
			throw NO_DATA;
		return tail->data;
	}

	void printAsLine()					// Prints each StackNode's data in a line
	{
		if (size <= 0)
		{
			throw STACK_IS_EMPTY;
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
	shared_ptr<StackNode> head;			// Pointer to starting node
	shared_ptr<StackNode> tail;			// Pointer to ending node
	unsigned int size;					// Number of StackNodes within LinkedList

	void clear()						// Removes all elements from the Stack
	{
		shared_ptr<StackNode> n = head;
		shared_ptr<StackNode> nToRemove;
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
