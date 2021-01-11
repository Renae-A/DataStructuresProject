#pragma once
#include <algorithm>
#include "Exceptions.h"

#define GROWTH_FACTOR 2		// Set growth factor to 2

using namespace std;

template <typename T>
class QueueDA
{
public:
	QueueDA(unsigned int initialAllocated)		// Constructor takes in the number of items the user wishes to allocate to the queue initially
	{
		data = nullptr;
		allocateQueueData(initialAllocated);
	}

	~QueueDA()									// Destructor calls freeQueueData()
	{
		freeQueueData();
	}

	bool empty()								// empty() returns true if the queue is empty or false for if it is not empty 
	{
		if (size <= 0)
			return true;
		return false;
	}

	int getSize()								// Returns size of queue
	{
		return size;
	}

	void push(T value)									// Pushes a value onto the back of the queue
	{
		if (size >= allocated)							// If the allocated space of the queue is less than the size, resize is called
			resize(getCapacity() * GROWTH_FACTOR);
		*(data + size++) = value;
	}

	void pop()											// Removes the first element and shifts the rest of the data forwards
	{
		if (size <= 0)									// Check size of queue in case there is no data
		{
			throw QUEUE_IS_EMPTY;
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

	T front()									// Returns the value at the front of the queue
	{
		if (size <= 0)							// Check size of queue in case there is no data
		{
			throw QUEUE_IS_EMPTY;
		}
		return data[0];
	}

	T back()									// Returns the value at the back of the queue
	{
		if (size <= 0)							// Check size of queue in case there is no data
		{
			throw QUEUE_IS_EMPTY;
		}
		return data[(size - 1)];
	}

	void printAsLine()							// Prints out each element in the queue in a line separated by spaces
	{
		if (size <= 0)							// Check size of deque in case there is no data
		{
			throw QUEUE_IS_EMPTY;
		}
		for (unsigned int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl; cout << endl;
	}

private:
	T * data;									// The data contained in the queue
	unsigned int size;							// Size of queue
	unsigned int allocated;						// Allocated space for queue

	void allocateQueueData(unsigned int newAllocated)		// Clears any current data and allocates space for queue
	{
		freeQueueData();

		allocated = newAllocated;
		data = new T[allocated];

		size = 0;
	}

	void resize(unsigned int newAllocatedElements)			// Resizes the allocated space for queue (current capacity x growth factor of 2)
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

	void freeQueueData()									// Deletes all the data contained in the queue
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	unsigned int getCapacity()								// Returns amount of space allocated of array
	{
		return allocated;
	}
};