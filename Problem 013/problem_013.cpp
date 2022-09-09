// Problem 13
/*
1. Read in the numbers from the file
2. Start from the smallest digit and add up the digits long addition style
Remember to keep the remainders from the long addition and add them on
Store the result in a vector
Print the first 10 digits of the sum
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

std::string GetNumber(); // This function reads the text file and returns the number as a continous string

int main() {
	std::string number_string = GetNumber(); // The number is stored as a 100*50 = 5000 element string

	int current_unit_sum = 0; // Store the sum of the current unit we are on in this variable
	int remainder = 0; // Store the remainder in this variable. 
	std::vector<int> result; // Store the result in this vector
	for (int unit = 1; unit <= 50; unit++) { // For each unit 
		current_unit_sum = 0;
		for (int num = 0; num <= 99; num++) { // For each number
			current_unit_sum += number_string[ (50 - unit) + 50*num] - '0';
			// std::cout << number_string[ (50 - unit) + 50*num] << '\n';
		}
		// std::cout << "Current unit sum: " << current_unit_sum << '\n';
		current_unit_sum += remainder; // Add the remainder
		result.push_back(current_unit_sum%10); // Add the relevant digit to the vector
		remainder = current_unit_sum/10; // Keep the remainder
		// std::cout << "Remainder: " << remainder << '\n';
	}
	while (remainder != 0) {
		result.push_back(remainder%10);
		remainder /= 10;
	}

	for (int i = result.size() - 1; i >= 0;i--) {
		std::cout << result[i];
	}
	std::cout << '\n';
}

std::string GetNumber() {
	std::string number; // Store the number in this string
	std::ifstream file; // Declare an instance of the file handling class for input 
	file.open("numbers.txt"); // Associate the object with the correct file

	if (!file.is_open()) {
		std::cout << "Failed to open file.\n";
		return "";
	}

	std::string line; // Store the lines from the file here
	while(std::getline(file,line)) {
		number += line;
	}

	file.close(); 
	return number;
}