// Problem 29
// Attempt 1
// 1. Generate a vector which contains all the numbers in the sequence as strings and save this to a text file
// 2. Read the text file and sort the numbers in the sequence
// 3. Remove duplicate numbers from the sequence
// 4. Count the number of elements in the resulting vector


#include "header.h"
#include <vector>
#include <algorithm>

int main() {
	// First get our unsorted sequence of numbers
	std::vector<std::string> raw_sequence = ReadUnsortedVector();
	std::sort(raw_sequence.begin(),raw_sequence.end());
	std::vector<std::string> sequence = RemoveDuplicates(raw_sequence);
	std::cout << sequence.size() << '\n';
}