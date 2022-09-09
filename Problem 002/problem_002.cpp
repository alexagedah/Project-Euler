// Problem 2
#include<iostream>

int main() {
	int total = 0;
	int next_fibonnaci = 0;
	int current_fibonnaci = 2;
	int previous_fibonnaci = 1;
	
	while (current_fibonnaci < 4000000) {
		if (current_fibonnaci % 2 == 0) { // If divisible by 2
			total += current_fibonnaci;
		}
		next_fibonnaci = current_fibonnaci + previous_fibonnaci;
		previous_fibonnaci = current_fibonnaci;
		current_fibonnaci = next_fibonnaci;
	}
	std::cout << total << '\n';
}