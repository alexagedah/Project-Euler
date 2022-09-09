// Problem 4

#include <iostream>
#include <cmath>
#include <vector>

bool IsPalindrome(int number); // Function to determine if a number is a palindrome
void GetDigits(std::vector<int> &number_vector, int number); // This function takes in the number and changes the vector input into
// A vector containing each digit in the number

int main() {
	std::vector<int> palindromes;
	for (int i = 999; i >= 100; i--) {
		for (int j = 999; j >= 100; j--) {
			if (IsPalindrome(j*i)) {
				palindromes.push_back(j*i);
			}
		}
	}
	int largest = 0;
	for (int i = 0; i < palindromes.size();i++) {
		if (palindromes[i] > largest) {
			largest = palindromes[i];
		}
	}
	std::cout << largest << '\n';
}

bool IsPalindrome(int number) {
	int digits = log10(number) + 1; // Number of digits in the number
	std::vector<int> number_vector;
	GetDigits(number_vector, number);
	int final_index = number_vector.size() - 1;
	for (int i = 0; i < final_index; i++) {
		if (number_vector[i] != number_vector[final_index - i]) {
			return false;
		}
	}
	return true;
}

void GetDigits(std::vector<int> &number_vector, int number) {
	int digits = log10(number) + 1;
	for (int i = 0; i < digits; i++) {
		number_vector.push_back(number%10); // Put in the least significant digit
		number = number / 10; // Remove a digit from the number
	}
}