#include "stdafx.h"
#include "HashingMenuFunctions.h" 

namespace HashFunction {

	unsigned int firstHash(const char* data, unsigned int length)	// firstHash takes in data and the length of the data and then returns a hash value
	{
		unsigned int hash = length;

		for (unsigned int i = 0; i < length; ++data, ++i)
		{
			hash += (data[i] + (*data) ^ (hash >> 6) * length);
			hash *= length;
		}

		return hash;
	}

	unsigned int secondHash(const char* data, unsigned int length)	// secondHash takes in data and the length of the data and then returns a hash value
	{
		unsigned int hash = length;
		int num = 0.00003;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash += ((length % data[i] * num) ^ 3);
			hash *= data[i];
		}

		return hash;
	}

	unsigned int thirdHash(const char * data, unsigned int length)	// thirdHash takes in data and the length of the data and then returns a hash value
	{
		unsigned int hash = length;
		int num = 0.00027;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash += ((length % data[1] + (num * data[i] % 2)) ^ 3);
			hash *= data[i];
		}

		return hash;
	}
}