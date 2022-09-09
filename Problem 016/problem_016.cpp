#include <iostream>
#include <vector>


int main() {
	std::vector< std::vector<int> > powers(1001); // Vector storing the powers of 2. Each element representing a power of 2 is a vector
	// The numbers are stored so the 1's are in index 0, 10's in index 1 etc...
	powers[0].push_back(1);


	int current_digit_value = 0; // Storage variable for the long multiplication
	int remainder = 0; 
	for (int i = 1; i <= 1000;i++) { // For each power of 2 from 1 to 1000
		for (int j = 0; j < powers[i-1].size();j++) { // For each digit in the previous power of 2
			current_digit_value = powers[i-1][j] * 2; // Multiply the digit by 2
			// std::cout << "Current digit value: "<< current_digit_value << '\n';
			current_digit_value += remainder; // Add on the remainder from previous multiplications
			// std::cout << "Current digit value + remainder: " << current_digit_value << '\n';
			powers[i].push_back(current_digit_value%10); // Add the relevant digit to the next power of 2
			remainder = current_digit_value / 10; // Get the remainder that is used next time
			// std::cout << "Remainder: " << remainder << '\n';
		}
		while (remainder != 0) {
			powers[i].push_back(remainder%10);
			remainder /= 10;
		}
	}
	int sum = 0;
	for (int i = 0; i < powers[1000].size();i++) {
		sum += powers[1000][i];
	}
	std::cout << sum << '\n';
}