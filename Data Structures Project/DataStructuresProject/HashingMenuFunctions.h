#pragma once
#include "stdafx.h"
#include <iostream>
#include <functional> 

void HashingHC();	// Hard-coded hash examples
void HashingUI();	// User interaction examples of hashing
void HashingMenu(); // The hashing menu to decide on how the user wants to view the examples 

namespace HashFunction {
	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;		// HashFunc is a function that will take a const char* and an unsigned int and returns an unsigned int

	unsigned int firstHash(const char* data, unsigned int length);					// firstHash takes in data and the length of the data and then returns a hash value

	unsigned int secondHash(const char* data, unsigned int length);					// secondHash takes in data and the length of the data and then returns a hash value

	unsigned int thirdHash(const char* data, unsigned int length);					// thirdHash takes in data and the length of the data and then returns a hash value

	static HashFunc DefaultHashFunction = secondHash;								// Set default to secondHash
}