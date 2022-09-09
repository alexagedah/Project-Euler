// Problem 25
/* Create a function that can add numbers in strings
Use the function to compute the fib numbers
Note that all numbers will be written backwards when in strings
*/

#include <iostream>

std::string Add(std::string x, std::string y); // x is the bigger y is the smaller numbers

int main() {
	std::string next = "2";
	std::string current = "1";
	std::string previous = "1";

	int index = 2; // Index of the current fib number

	while (next.length() < 1000) {
		std::cout << index << ": " << current << '\n';

		next = Add(current,previous);
		previous = current;
		current = next;
		index++;
	}
	std::cout << index << '\n';


}
std::string Add(std::string x, std::string y) {
	std::string z = "";

	int remainder = 0;
	int count = 0; // Number to count the number of digits we have looped through
	int digit; // Number to store sums
	int j; // Stores the index we are on for the 2nd number
	int length_diffence = x.size() - y.size();

	for (std::string::size_type i = 0;i < x.size();i++) {
		if (i < y.size()) { // If we haven't looped through all the x numbers
			digit = x[i] - '0' + y[i] - '0' + remainder;
			z += std::to_string(digit%10);
			remainder = digit/ 10;
		} else {
			digit = x[i] - '0' + remainder;
			z += std::to_string(digit%10);
			remainder = digit / 10;
		}
	}

	while (remainder > 0 ) {
		z += std::to_string(remainder%10);
		remainder /= 10;
	}
	return z;
}

/*
std::string Add(std::string x, std::string y) {
	std::string z;

	int remainder = 0;
	int count = 0; // Number to count the number of digits we have looped through
	int digit; // Number to store sums
	int j; // Stores the index we are on for the 2nd number
	int length_diffence = x.size() - y.size();

	for (std::string::size_type i = (x.size() - 1);i >= 0;i--) {
		if (count < y.size()) { // If we haven't looped through all the x numbers
			j = i - length_diffence;
			digit = x[i] - '0' + y[j] - '0' + remainder;
			z += to_string(digit%10);
			remainder /= 10;
		} else {
			digit = x[i] - ''
		}
		count++;
	}
	return z;
}
*/