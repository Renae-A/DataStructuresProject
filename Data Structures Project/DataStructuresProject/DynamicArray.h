#include <algorithm>
#include "Exceptions.h"

#define MIN_CAPACITY 10								// Set min capacity to 10
#define GROWTH_FACTOR 2								// Set growth factor to 2

using namespace std;

template <typename T>
class DynamicArray
{
public:
	DynamicArray(unsigned int initialAllocated)		// Constructor takes in the number of items the user wishes to allocate to the dynamic array initially
	{
		data = nullptr;
		allocateArrayData(initialAllocated);
	}

	DynamicArray(DynamicArray& other)				// Copy Constructor takes in a dynamic array and creates a copy of the array passed in
	{
		data = nullptr;

		operator=(other);
	}

	~DynamicArray()									// Destructor calls freeArrayData()
	{
		freeArrayData();
	}

	DynamicArray& operator=(DynamicArray& other)	// Assignment operator takes in a dynamic array and creates a copy of the array passed in
	{
		allocateArrayData(other.allocated);

		copyArrayData(other);

		size = other.size;

		return *this;
	}

	T& operator[](unsigned int index) const			// Index operator takes in an index and returns the data within that index
	{
		if (index < 0 || index > size)				// Check index to see if it is larger than the allocated space of the dynamic array or less than 0
		{
			throw OUT_OF_BOUNDS;
		}
		return data[index];
	}

	void operator+=(DynamicArray& other)			// Concatenation += operator takes in another dynamic array and adds that array's elements onto the end of the first dynamic array
	{
		int duration = other.getSize();
		for (int i = 0; i < duration; i++)
		{
			push(other[i]);
		}
	}

	bool empty()									// empty() returns true if the dynamic array is empty or false for if it is not empty 
	{
		if (size <= 0)
			return true;
		return false;
	}

	void swap(int index, int index2)				// Swap function (for shuffle()) takes in two numbers to use for index value swapping
	{
		T temp1 = data[index];
		T temp2 = data[index2];

		data[index] = temp2;
		data[index2] = temp1;
	}

	void shuffle()									// shuffle() gets two indexes (1. index i that is incremented, 2. random index within size) to pass into swap and calls swap for each element
	{
		if (size <= 0)								// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		for (unsigned int i = 0; i <= (size - 1); i++)
		{
			swap(i, rand() % (size - 1));
		}
	}

	void push(T value)								// Pushes a value onto the back of the dynamic array
	{
		if (size >= allocated)						// If the allocated space of the dynamic array is less than the size, resize is called
			resize(getCapacity() * GROWTH_FACTOR);
		*(data + size++) = value;
	}

	void pop()										// Removes the last element
	{
		if (size <= 0)								// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		(data + --size);
	}

	void replace(unsigned int index, T value)		// Set array[index] to new value 
	{
		if (index < 0 || index > size)				// Check index to see if it is larger than the allocated space of the dynamic array or less than 0
		{
			throw OUT_OF_BOUNDS;
		}
		data[index] = value;
	}

	void insert(unsigned int index, const T& item)	// Insert element at array[index] and push rest of elements in array forward
	{
		if (index < 0 || index > size)				// Check index to see if it is larger than the allocated space of the dynamic array or less than 0
		{
			throw OUT_OF_BOUNDS;
		}

		if (size >= allocated)						// If the allocated space of the deque is less than the size, resize is called
		{
			resize(getCapacity() * GROWTH_FACTOR);
		}

		if (index = size)							
		{
			return push(item);
		}

		for (unsigned int i = (size - 1); i >= index; i--)
		{
			data[(i + 1)] = data[i];
		}

		data[index] = item;
		size++;
	}

	void insertMultiple(unsigned int index, const T items[], unsigned int length)		// Takes in an array of items, loops through the amount of items and calls insert for each item at index specified
	{
		for (unsigned int i = (length - 1); i >= 0; i--)
		{
			insert(index, items[i]);
			if (i == 0)
				break;
		}
	}

	void insertMultiple(unsigned int index, DynamicArray items, unsigned int length)	// Takes in a dynamic array of items, loops through the amount of items and calls insert for each item at index specified
	{
		for (unsigned int i = (length - 1); i >= 0; i--)
		{
			insert(index, items[i]);
			if (i == 0)
				break;
		}
	}

	void erase(unsigned int index, bool ordered = false)	// Remove element at array[index] and push rest of elements in array backwards
	{
		if (index < 0 || index > size)						// Check index to see if it is larger than the allocated space of the dynamic array or less than 0
		{
			throw OUT_OF_BOUNDS;
		}

		if (ordered)										// Ordered removal
		{
			for (unsigned int i = index; i < size - 1; i++)
			{
				data[i] = data[i + 1];
			}
			size--;
		}

		else if (ordered == false)							// Unordered removal
		{
			data[index] = data[size - 1];
			size--;
		}
	}

	void clear()											// Reset the array to original form (allocated space returned to 10 and size of data set to 0)
	{
		size = 0;
		allocated = MIN_CAPACITY;
	}

	void printAsList()										// Prints out Index number then the value of the data for every item on separate line
	{
		if (size <= 0)										// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		for (unsigned int i = 0; i < size; i++)
		{
			cout << "Index " << i << ": " << data[i] << endl;
		}
		cout << endl;
	}

	void printAsLine()										// Prints out each element of the dynamic array separated by spaces
	{
		if (size <= 0)										// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		for (unsigned int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl; cout << endl;
	}

	T getElement(unsigned int index)						// Takes in an index and returns the value contained at that index
	{
		if (index >= size || index < 0)						// Check index to see if it is larger than the size of the dynamic array or less than 0
		{
			throw OUT_OF_BOUNDS;
		}
		return data[index];
	}

	void bubbleSort()										// Sorts in ascending order using the bubble sorting algorithm
	{
		if (size <= 0)										// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		bool unordered = true;

		while (unordered == true)
		{
			unordered = false;
			for (unsigned int i = 0; i < size; i++)			// For every item in the dynamic array
			{
				for (unsigned int j = 0; j < (size - 1); j++)
				{
					if (data[j] > data[(j + 1)])			// Check if the next item is less than the current item
					{
						auto temp = data[j];				// Swap the values
						auto temp2 = data[(j + 1)];
						data[j] = temp2;
						data[j + 1] = temp;
						unordered = true;
					}
				}
			}
		}
	}

	void insertionSort()									// Sorts in ascending order using the insertion sorting algorithm
	{
		if (size <= 0)										// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		for (unsigned int i = 1; i < size; i++)				// Starting at the second item, for each item in the dynamic array
		{
			int key = data[i];								// Key is the current index's value
			int j = (i - 1);
			while (j >= 0 && data[j] > key)					// While the key's value is less than the value to its left
			{
				data[(j + 1)] = data[j];					// Swap the values
				j = (j - 1);
				data[(j + 1)] = key;
			}
		}
	}

	void merge(int startIdx, int midIdx, int endIdx)		// Merges all the values in the dynamic array in ascending order
	{
		int i, j, k;
		
		const int leftEnd = (midIdx - startIdx + 1);		
		const int rightEnd = (endIdx - midIdx);				
		int* L = new int[leftEnd];							// First half of the dynamic array
		int* R = new int[rightEnd];							// Second half of the dynamic array

		for (i = 0; i < leftEnd; i++)						// For every item in the first half
			L[i] = data[(startIdx + i)];					// Add item to left array
		for (j = 0; j < rightEnd; j++)						// For every item in the second half
			R[j] = data[(midIdx + j + 1)];					// Add item to right array

		i = 0;
		j = 0;

		for (k = startIdx; k <= endIdx; k++)						// For every item in the dynamic array
		{
			if (j >= rightEnd || i < leftEnd && L[i] <= R[j])		// If the (right end is empty) or (there are items in the left end and the left value is less than or equal to the right value)
			{
				data[k] = L[i];										// The current value is placed in the left array
				i = i + 1;
			}
			else
			{
				data[k] = R[j];										// The current value is placed in the right array
				j = j + 1;
			}
		}
	}

	void mergeSort(int startIdx, int endIdx)				// Sorts in ascending order using the merge sorting algorithm
	{
		if (size <= 0)										// Check size of dynamic array in case there is no data
		{
			throw ARRAY_IS_EMPTY;
		}
		if (startIdx < endIdx)
		{
			int midIdx = (startIdx + endIdx) / 2;			
			mergeSort(startIdx, midIdx);					// Sort the values in the first half of the dynamic array
			mergeSort((midIdx + 1), endIdx);				// Sort the values in the second half of the dynamic array
			merge(startIdx, midIdx, endIdx);				// Merge all the items
		}
	}

	int partition(int left, int right)						// Splits the dynamic array into sub arrays and sorts the two sub arrays via recursive calls to sort
	{
		int x = data[right];
		int i = (left - 1);
		for (int j = left; j <= (right - 1); j++)			
		{
			if (data[j] <= x)
			{
				i = i + 1;
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		i++;
		int temp = data[i];
		data[i] = data[right];
		data[right] = temp;
		return i;
	}

	void quickSort(int left, int right)						// Sorts in ascending order using the quick sorting algorithm				
	{
		if (left < right)
		{
			int mid = partition(left, right);
			quickSort(left, (mid - 1));
			quickSort((mid + 1), right);
		}
	}

	void resize(unsigned int newAllocatedElements)			//
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
		if (size > allocated)
		{
			size = allocated;
		}
	}

	bool search(T value, bool ordered = false)			// Search array for given element
	{
		if (ordered)									// Binary search
		{
			int max = size - 1;
			int min = 0;

			while (max != min)							// Check if the value is larger or smaller than the middle of the dynamic array and 
			{											// remove the half of the array that the value would not be in, repeat
				int middle = (min + max) / 2;

				if (data[middle] == value)
					return true;
				else if (data[middle] > value)
				{
					max = middle - 1;
					if (data[max] == value)
						return true;
				}
				else if (data[middle] < value)
				{
					min = middle + 1;
					if (data[min] == value)
						return true;
				}
			}
		}

		else if (ordered == false)						// Linear search
		{
			for (unsigned int i = 0; i < size; i++)		// For every item, check if it is equal to the value
			{
				if (data[i] == value)
				{
					return true;
				}
			}
		}
		cout << endl;
		return false;
	}

	unsigned int getSize()								// Returns size of array
	{
		return size;
	}

	unsigned int getCapacity()							// Returns amount of space allocated of array
	{
		return allocated;
	}

private:
	T * data;											// The data within the dynamic array
	unsigned int size;									// The amount of items in the dynamic array
	unsigned int allocated;								// The amount of allocated space for the dynamic array

	void allocateArrayData(unsigned int newAllocated)	// Clears any current data and allocates space for dynamic array
	{
		freeArrayData();

		allocated = newAllocated;
		data = new T[allocated];

		size = 0;
	}

	void copyArrayData(const DynamicArray& other)		// Copies the dynamic array data and places it into another dynamic array
	{
		unsigned int minAllocatedElements = std::min(allocated, other.allocated);
		for (unsigned int i = 0; i < minAllocatedElements; i++)
		{
			data[i] = other.data[i];
		}
	}

	void freeArrayData()								// If the dynamic array has data, delete the data 
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

};

