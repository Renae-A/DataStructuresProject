#pragma once
#include <algorithm>
#include "Exceptions.h"

#define GROWTH_FACTOR 2									// Set growth factor to 2

using namespace std;

template <typename T>
class DequeDA
{
public:
	DequeDA(unsigned int initialAllocated)				// Constructor takes in the number of items the user wishes to allocate to the deque initially
	{
		data = nullptr;							
		allocateDequeData(initialAllocated);	
	}

	~DequeDA()											// Destructor calls freeDequeData()
	{
		freeDequeData();
	}

	bool empty()										// empty() returns true if the deque is empty or false for if it is not empty
	{
		if (size <= 0)
			return true;
		return false;
	}

	int getSize()										// Returns the size of deque
	{
		return size;
	}

	void pushFront(T value)								// Shifts the elements back and pushes a value onto the front of the deque
	{
		if (size >= allocated)							// If the allocated space of the deque is less than the size, resize is called
			resize(getCapacity() * GROWTH_FACTOR);		
		size++;
		for (unsigned int i = (size - 1); i >= 1; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
	}

	void pushBack(T value)								// Pushes a value onto the back of the deque
	{
		if (size >= allocated)							// If the allocated space of the deque is less than the size, resize is called
			resize(getCapacity() * GROWTH_FACTOR);
		*(data + size++) = value;
	}

	void popFront()										// Removes the first element and shifts the rest of the data forwards
	{
		if (size <= 0)									// Check size of deque in case there is no data
		{
			throw DEQUE_IS_EMPTY;
		}
		else
		{
			for (unsigned int i = 1; i <= (size - 1); i++)
			{
				data[i - 1] = data[i];
			}
		}
		size--;
	}

	void popBack()										// Removes the last element
	{
		if (size <= 0)									// Check size of deque in case there is no data
		{
			throw DEQUE_IS_EMPTY;
		}
		(data + --size);
	}

	T front()											// Returns the first element value
	{
		if (size <= 0)									// Check size of deque in case there is no data
		{
			throw DEQUE_IS_EMPTY;
		}
		return data[0];
	}

	T back()											// Returns the last element value	
	{
		if (size <= 0)									// Check size of deque in case there is no data
		{
			throw DEQUE_IS_EMPTY;
		}
		return data[(size - 1)];
	}

	void printAsLine()									// Prints out each element in the deque in a line separated by spaces
	{
		if (size <= 0)									// Check size of deque in case there is no data
		{
			throw DEQUE_IS_EMPTY;
		}
		for (unsigned int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl; cout << endl;
	}

private:
	T * data;											// The data contained in the deque
	unsigned int size;									// Size of deque
	unsigned int allocated;								// Allocated space for deque

	void allocateDequeData(unsigned int newAllocated)	// Clears any current data and allocates space for deque
	{
		freeDequeData();

		allocated = newAllocated;
		data = new T[allocated];

		size = 0;
	}

	void resize(unsigned int newAllocatedElements)		// Resizes the allocated space for deque (current capacity x growth factor of 2)
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
		
	void freeDequeData()								// Deletes all the data contained in the deque
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	unsigned int getCapacity()							// Returns the amount of allocated space for the deque
	{
		return allocated;
	}
};