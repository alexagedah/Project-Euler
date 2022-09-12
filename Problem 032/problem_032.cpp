/*
Problem 32
The goal is to find a * b = c such that
abc is pandigital (abc is the numbers concatenated, not the product of the numbers)

- The key components of this problem are:
1. Writing a function which can determine if a number is pandigital
2. Being able to limit the search space for a and b. To do this we realise that
we don't need to search past 4 digit numbers. This is because is if a is 5 digits, the
product is 5 digits and so b can't be chosen.
- We also limit the search space by checking if a and b are numbers which consist of unique
digits since this is a necessary condition for abc to be a 1 through 9 pandigital
- We also check a and b do not contain 0's 

3. We can also speed up things by looking at additional condtions on c and the identity
- c must contain unique digits and no 0's
- the total number of digits in a, b and c must sum to 9
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

bool IntInVector(std::vector<int> vec, int x); // This function checks if x is in the vector
int CountDigits(int x); // This function counts the number of digits in a number
bool IsPandigital(int x); // This function checks if the number is pandigital
std::vector<int> NumToVec(int x); // The function turns an integer into a vector where each element is a digit
int VecToInt(std::vector<int> x); // This function turns a vector of digits into an integer
int IntConcat(int a, int b); // This function concatenates 2 integers into a single number
bool UniqueDigits(int x); // This function determines if a number consists of unique digits
bool ContainsZero(int x); // This function determines if a number contains a 0

int main() {
	std::vector<int> products; // Vector to store all the products
	int sum = 0; // The sum of all the products
	int identity; // abc concatenated
	int c; // a*b = c
	int a_digits, b_digits, c_digits, total_digits; // Number of digits

	for (int a = 1; a < 9877; a++) {
		if (!UniqueDigits(a) || ContainsZero(a)) {
			// Skip if a does not consist of unique digits or contains a 0
			continue;
		} 
		for (int b = a; b < 9877; b++) {
			if (!UniqueDigits(b) || ContainsZero(b)) {
				// Skip if b does not consist of unique digits or contains a 0
				continue;
			}
			c = a * b;
			a_digits = CountDigits(a);
			b_digits = CountDigits(b);
			c_digits = CountDigits(c);
			total_digits = a_digits + b_digits + c_digits;
			if (!UniqueDigits(c) || ContainsZero(c) || total_digits != 9) {
				// Skip if c does not consist of unique digits, has more than 9 digits or contains a 0
				continue;
			}
			identity = IntConcat(IntConcat(a, b),c);
			if (ContainsZero(identity)) {
				// Skip if the identity contains a 0
				continue;
			}
			if (IsPandigital(identity) ){
				// If the identity is Pandigital
				if (!IntInVector(products, c)) {
					// Add the product if it is not in the ve
					products.push_back(c);
					sum += c;
				}
				products.push_back(c);
			}
		}
	}
	std::cout << sum << '\n';
}

bool IntInVector(std::vector<int> vec, int x) {
	for (int i = 0; i < vec.size(); i++) {
		if (x == vec[i]) {
			return true;
		}
	}
	return false;
}

int CountDigits(int x) {
	int digits = 0; // The total number of digits in the number
	while (x > 0) {
		digits += 1;
		x /= 10;
	}
	return digits;
}
bool IsPandigital(int x) {
	std::vector<int> digits = NumToVec(x);
	std::sort(digits.begin(), digits.end());
	for (int i = 0; i <digits.size(); i++) {
		if (digits[i] == i + 1) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}
std::vector<int> NumToVec(int x) {
	std::vector<int> digits;
	while (x > 0) {
		digits.push_back(x % 10);
		x /= 10;
	}
	return digits;
}
int IntConcat(int a, int b) {
	int b_digits = CountDigits(b);
	int result = a*std::pow(10, b_digits) + b;
	return result;
}
bool UniqueDigits(int x) {
	int digits[10] = {0};
	int digit;
	while (x > 0) {
		digit = x % 10;
		x /= 10;
		if (digits[digit] > 1) {
			return false;
		} else {
			digits[digit] += 1;
		}
	}
	return true;
}
bool ContainsZero(int x) {
	int digit;
	while (x > 0) {
		digit = x % 10;
		x /= 10;
		if (digit == 0) {
			return true;
		}
	}
	return false;
}



