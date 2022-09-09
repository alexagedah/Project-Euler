#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

std::string Add(std::string y,std::string x) {
	std::string longer;
	std::string shorter;
	if (x.size() > y.size()) {
		longer = x;
		shorter = y;
	} else {
		longer = y;
		shorter = x;
	}
	std::string result = "";
	int digit = 0;
	int digit_to_add;
	int remainder = 0;
	for (int i = 0; i < shorter.size();i++) { // First add numbers where there are 2 to add
		digit += remainder;
		digit += (longer[i] - '0') + (shorter[i] - '0');
		digit_to_add = digit % 10;
		remainder = digit / 10;
		result += std::to_string(digit_to_add);
		digit = 0;
	}

	for (int i = shorter.size(); i < longer.size();i++) { // If one number is longer, we have to add some more numbers
		digit += remainder;
		digit += (longer[i] - '0');
		digit_to_add = digit % 10;
		remainder = digit / 10;
		result += std::to_string(digit_to_add);
		digit = 0;
	}

	while (remainder > 0) { // If there is a remainder, add some more
		digit_to_add = remainder % 10;
		result += std::to_string(digit_to_add);
		remainder /= 10;
	}
	return result;
}

std::string Multiply(std::string y,std::string x) {
	std::string longer;
	std::string shorter;
	if (x.size() > y.size()) {
		longer = x;
		shorter = y;
	} else {
		longer = y;
		shorter = x;
	}

	std::string result = ""; 
	std::string line = "";
	int digit = 0;
	int digit_to_add;
	int remainder = 0;
	for (int j = 0; j < shorter.size(); j++) { // j iterates over the bottom number
		std::string zeroes(j,'0');
		line += zeroes;
		for (int i = 0; i < longer.size(); i++) { // Iterate over the top number
			digit += remainder;
			digit += (shorter[j] - '0')*(longer[i] - '0');
			// std::cout << "Digit: " << digit << '\n';
			digit_to_add = digit % 10;
			// std::cout << digit_to_add << '\n';
			remainder = digit / 10;
			line += std::to_string(digit_to_add);
			// std::cout << "Line: " << line << '\n';
			// std::cout << "Remainder: " << remainder << '\n';
			digit = 0;
		}
		while(remainder > 0) {
			digit_to_add = remainder % 10;
			line += std::to_string(digit_to_add);
			remainder /= 10;
		}
		// std::cout << line << '\n';
		result = Add(result,line);
		line = "";
	}
	return result;
}


std::string SubtractOne(std::string num) {
	// std::cout << "Original Number: " << num << '\n';
	std::string result;
	int new_digit;
	std::string before_new_digit;
	std::string after_new_digit;
	int unit_subtracted;
	for (int i = 0; i < num.size(); i++) {
		// std::cout << "i: " << i << '\n';
		if (num[i] - '0' > 0) { // Find the first digit which isn't a 0 and subtract 1
			// std::cout << "String new digit: " << num[i] << '\n';
			before_new_digit = num.substr(0,i);
			new_digit = (num[i] - '0') - 1;
			after_new_digit = num.substr(i+1,(num.size() - 1));
			// std::cout << "Before new digit: " << before_new_digit << '\n';
			// std::cout << "New digit: " << new_digit << '\n';
			// std::cout << "After new digit: " << after_new_digit << '\n';
			
			result = before_new_digit + std::to_string(new_digit) + after_new_digit;
			unit_subtracted = i;
			// std::cout << "Unit subtracted: " << unit_subtracted << '\n';
			break;
		}
	}
	// If the first digit was a 0, then we subtracted 10, 100, 1000 etc... So we need to add on 9, 99, 999 etc...
	// std::cout << "Result pre remainder: " << result << '\n';
	std::string remainder(unit_subtracted,'9');
	result = Add(remainder,result);
	// std::cout << "Result pre clean: " << result << '\n';
	// Now we want to remove the 0's from the end of the string
	int result_length = result.size();
	while (result_length> 1 && result[result_length-1] == '0') {
		for (int i = result.size() - 2;i >= 0;i--) {
			if ((result[i] - '0') != 0) {
				result = result.substr(0,i+1);
				break;
			}
		}
	}
	// std::cout << "Result post clean: " << result << '\n';
	return result;
}


std::string Power(std::string a, std::string b) {
	std::string result;
	if (b != "1") {
		return Multiply(a,Power(a,SubtractOne(b)));
	} else {
		return a;
	}
}

void GenerateArray(std::string (&numbers)[99]) {
	std::cout << "Generating array... " << '\n';
	std::string number;
	for (int i = 2; i < 101;i++) {
		if (i < 10) {
			numbers[i-2] = std::to_string(i);
		} else {
			number = std::to_string(i);
			std::reverse(number.begin(),number.end());
			numbers[i-2] = number;
		}
	}
}

void GenerateSequence() {
	std::string integers[99];
	std::vector<std::string> sequence;
	GenerateArray(integers);
	for (int a = 0; a < 99;a++) {
		std::cout << a << '\n';
		for (int b = 0; b < 99;b++) {
			sequence.push_back(Power(integers[a],integers[b]));
		}
	}
	std::ofstream file_object;
	file_object.open("unsorted_sequence.txt");
	if (!file_object.is_open()) {
		return;
	}
	for (int i = 0; i < sequence.size();i++) {
		file_object << sequence[i] << '\n';
	}
	file_object.close();
}

std::vector<std::string> ReadUnsortedVector() {
	std::vector<std::string> result;

	std::ifstream file_object("unsorted_sequence.txt");
	if (!file_object.is_open()) {
		std::cout << "There was a problem opening the file." << '\n';
		return result;
	}
	std::string number;
	while (file_object >> number) {
		result.push_back(number);
	}
	file_object.close();
	return result;
}

std::vector<std::string> RemoveDuplicates(std::vector<std::string> sequence) {
	std::vector<std::string> result;
	for (int i = 0; i < (sequence.size()-1);i++) {
		if (sequence[i] != sequence[i+1]) {
			result.push_back(sequence[i]);
		}
	}
	if (sequence[sequence.size()-1] !=sequence[sequence.size()-2]) {
		result.push_back(sequence[sequence.size()-1]);
	}
	return result;
}