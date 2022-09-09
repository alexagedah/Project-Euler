// Problem 30

#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// This vector stores the numbers which can be written as the sum of fifth powers 
	// of their digits
	std::vector<int> numbers;
	int numbers_sum = 0;

	int num;
	int digit;
	int sum = 0;

	for (int i = 2; i < 10000000;i++) {
		// This for loop tests the condition for numbers up to 10 million. I am not sure how
		// to show that this is enough numbers you have to check but it works so oh well
		if (i % 1000000 == 0) {
			std::cout << "i: " << i << '\n';
		}
		num = i;

		while (num > 0) {
			// This while loop computes the sum of fifth powers of i's digits
			digit = num % 10;
			sum += pow(digit,5);
			num /= 10;
		}

		if (sum == i) {
			numbers.push_back(i);
		}
		sum = 0;
	}

	for (int i = 0; i < numbers.size();i++) {
		numbers_sum += numbers[i];
		std::cout << numbers[i] << '\n';
	}
	std::cout << numbers_sum << '\n';
}