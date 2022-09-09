#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> Primes(); // Returns primes up to x

int main() {
	std::vector<int> primes = Primes();
	std::cout << primes[primes.size() - 1] << '\n';
}

std::vector<int> Primes() {
	std::vector<int> primes;
	primes.push_back(2);
	int check_if_prime = 3;

	while (primes.size() <= 10000) {
		for (int i = 0; i < primes.size();i++) { // For each prime we have
			if (check_if_prime % primes[i] == 0) { // If the number is divisible by a prime
				check_if_prime += 2;
				break;
			}
			else if (check_if_prime % primes[i] != 0 && i == primes.size() - 1) { // If the number is not divisible by the last prime
				primes.push_back(check_if_prime);
				check_if_prime += 2;
				break;
			}
		}
	}
	return primes;
}