// Problem 23
/*
Any number greater than 28123 can be written as the sum of two abundant numbers
Numbers less than or equal to 23 cannot be written as the sum of two abundant numbers
So all I need to do is find the numbers from 24 to 28123 that cannot be written as
the sum of two abundant numbers
*/
// First get all the abundant numbers
// Then find which numbers can't be written as the sum of 2 abundant numbers
// Note my checksum function breaks when i put in 28123 but i have no idea why?

#include <iostream>
#include "functions.h"

int main() {
	std::vector<int> abundants; // Vector to store abundant numbers
	std::vector<int> numbers; // Vector to store numbers that cannot be written as the sum of two abundants
	int sum = 0;

	for (int i = 2; i <= 28123;i++) {
		if (IsAbundant(i)) {
			abundants.push_back(i);
		}
	}
	std::cout << CheckSum(28123,abundants) << '\n';

	
	// abundants now contains the abundants up to 14062
	for (int i = 1; i <= 28123;i++) { // For each number from 1 to 28123
		if (!CheckSum(i,abundants)) {
			sum += i;
		}
	}
	
	std::cout << sum << '\n';

	return 0;
}