// Problem 14

#include <iostream>

int main() {
	int max_chain_length = 0;
	int max_chain_length_starting_number = 1;

	for (int starting = 1; starting < 1000000; starting++) { // For each starting number
		long long int current_number = starting;
		int current_chain_length = 1;
		while (current_number != 1) {
			if (current_number % 2 == 0) {
				current_number /= 2;
				current_chain_length++;
			} else {
				current_number = 3*current_number + 1;
				current_chain_length++;
			}
		}
		if (current_chain_length > max_chain_length) { // If the chain is the longest
			max_chain_length = current_chain_length;
			max_chain_length_starting_number = starting;
		}
	}
	std::cout << "Max chain length: " << max_chain_length << '\n';
	std::cout << "Starting nummber: " << max_chain_length_starting_number << '\n';
}