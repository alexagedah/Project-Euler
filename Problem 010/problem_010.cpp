#include <vector>
#include <iostream>

int main() {
	long int total = 2;
	std::vector<int> primes; // Vector to store prime numbers
	primes.push_back(2);

	int check_if_prime = 3;
	while (check_if_prime < 10) {
		for (int i = 0; i < primes.size(); i++) { // For each prime number
			if (check_if_prime % primes[i] == 0) { // If the number we are checking is not a prime
				check_if_prime += 2;
				break;
			}
			else if (check_if_prime % primes[i] != 0 && i == primes.size() - 1) { // If the number we are checking is not a prime
				primes.push_back(check_if_prime); // Add it to our vector
				total += check_if_prime;
				std::cout << check_if_prime << '\n';
				check_if_prime += 2;
				break;
			}
		}
	}
	std::cout << total << '\n';
}