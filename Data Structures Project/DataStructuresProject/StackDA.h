#pragma once
#include <algorithm>

#define GROWTH_FACTOR 2		// Set growth factor to 2

using namespace std;

template <typename T>
class StackDA
{
public:
	StackDA(unsigned int initialAllocated)					// Constructor takes in the number of items the user wishes to allocate to the stack initially
	{
		data = nullptr;
		allocateStackData(initialAllocated);
	}

	~StackDA()												// Destructor calls freeStackData()
	{
		freeStackData();
	}

	bool empty()											// empty() returns true if the stack is empty or false for if it is not empty
	{
		if (size <= 0)
			return true;
		return false;
	}

	int getSize()											// Returns the size of stack
	{
		return size;
	}

	void push(T value)										// Pushes a value onto the back of the stack
	{
		if (size >= allocated)								// If the allocated space of the stack is less than the size, resize is called
			resize(getCapacity() * GROWTH_FACTOR);
		*(data + size++) = value;
	}

	void pop()												// Removes the last element
	{
		if (size <= 0)										// Check size of stack in case there is no data
		{
			throw STACK_IS_EMPTY;
		}
		*(data + --size);
	}

	T top()													// Returns the last element value	
	{
		if (size <= 0)										// Check size of stack in case there is no data
		{
			throw STACK_IS_EMPTY;
		}
		return data[size - 1];
	}

	void printAsLine()										// Prints out each element in the stack line separated by spaces
	{
		if (size <= 0)										// Check size of stack in case there is no data
		{
			throw STACK_IS_EMPTY;
		}
		for (unsigned int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl; cout << endl;
	}

private:
	T * data;												// The data contained in the stack
	unsigned int size;										// Size of stack
	unsigned int allocated;									// Allocated space for stack

	void allocateStackData(unsigned int newAllocated)		// Clears any current data and allocates space for stack
	{
		freeStackData();

		allocated = newAllocated;
		data = new T[allocated];

		size = 0;
	}

	void resize(unsigned int newAllocatedElements)			// Resizes the allocated space for stack (current capacity x growth factor of 2)
	{
		if (newAllocatedElements < 1)
			newAllocatedElements = 1;

		T* temp = new T[newAllocatedElements];

		if (data != nullptr)
		{
			unsigned int minAllocatedElements = std::min(allocated, newAllocatedElements);
			for (unsigned int i = 0; i < minAllocatedElements; i++)
			{
				temp[i] = data[i];
			}
		}
		data = temp;
		allocated = newAllocatedElements;
	}

	void freeStackData()									// Deletes all the data contained in the stack
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	unsigned int getCapacity()								// Returns amount of space allocated of stack
	{
		return allocated;
	}
};