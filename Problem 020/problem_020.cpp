// Problem 20
/* First write the first 100 factorials in a file (the numbers are written in reverse in the file)
Then read the file and add up the numbers
*/

#include <iostream>
#include <vector>
#include <fstream>

void Factorial(int n); // This function produces a file with factorials from 1 to 100

int main() {
	Factorial(100);
	std::string number; // Variable to store 100 factorial
	std::ifstream file("factorials.txt");
	if (!file.is_open()) {
		return 0;
	}

	std::string line;
	int line_number = 1;
	while(getline(file,line)) {
		if(line_number == 100) {
			number = line;
		} else {
			line_number++;
		}
	}

	int sum = 0;
	for (int i = 0; i < number.length() ; i++) {
		sum += number[i] - '0';
	}
	std::cout << sum << '\n';
}

void Factorial(int n) {
	std::ofstream file("factorials.txt");

	if (!file.is_open()) {
		return;
	}

	std::vector<int> previous_factorial; // Vector to store the previous factorial
	previous_factorial.push_back(1);
	file << previous_factorial[0] << '\n';

	int digit = 0;
	int remainder = 0;
	for (int i = 2; i <= n; i++) { // For each number from 2 to n
		for (int j = 0; j < previous_factorial.size();j++) { // For each digit in the previous factorial
			digit = previous_factorial[j] * i;
			digit += remainder;
			previous_factorial[j] = digit % 10;
			file << digit % 10;
			remainder = digit/10;
		}
		
		while (remainder > 0) { // If you still have a remainder and need to append the remainng numbers
			previous_factorial.push_back(remainder%10);
			file << remainder % 10;
			remainder /= 10;
		}
		
		file << '\n';
	}

	file.close();
}