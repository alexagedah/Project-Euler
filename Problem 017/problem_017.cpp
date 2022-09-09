// Problem 17
/* 
First create an array with the lengths of the numbers from 1 to 99
Then do simple multiplication to 
*/

#include <iostream>

int main() {
	int number_lengths[1001] = {0}; // Array to store lengths of first 100 numbers

	std::string ones[20] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	std::string tens[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

	for (int i = 1; i <= 19; i++) { // For each number from 0 to 19
		number_lengths[i] = ones[i].length();
	}

	for (int i = 20; i<= 99; i++) { // For each number from 20 to 99
		number_lengths[i] = tens[i/10].length() + ones[i%10].length();
	}

	for (int i = 100; i <= 999; i++) {
		std::string hundred = ones[i/100]; // This is the hundred we are on
		int hundred_letters = 7; // 7 letters in the word hundred
		int and_letters = 3; // 3 letters in the word and
		number_lengths[i] = hundred.length() + hundred_letters + and_letters + number_lengths[i%100];
		if (i % 100 == 0) { // If it is a multiple of a hundred
			number_lengths[i] -= 3;  // Remove 3 because there is no and
		}
	}

	int thousand_letters = 8; // 8 letters in the word thousand
	number_lengths[1000] = thousand_letters + 3;
	for (int i = 0; i <= 1000; i++) {
		std::cout << i << '\t' << number_lengths[i] << '\n';
	}

	int total =0;
	for (int i = 0; i <= 1000; i++) {
		total+= number_lengths[i];
	}
	std::cout << total << '\n';

}