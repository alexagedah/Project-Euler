#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> Primes(long int x); // Returns primes up to x

int main() {
	long int number = 600851475143;
	int max_factor = sqrt(number); // This is the maximum number we have to get primes up to
	std::vector<int> primes = Primes(max_factor); // Vector of the primes
	int largest_prime_factor;

	for (int i = 0; i < primes.size();i++) { // For each prime
		if (number % primes[i] == 0) { // If the number is divisible by a prime
			largest_prime_factor = primes[i];
		}
	}
	std::cout << largest_prime_factor << '\n';
}

std::vector<int> Primes(long int x) {
	std::vector<int> primes;
	primes.push_back(2);
	int count = 3;

	while (count <= x) {
		for (int i = 0; i < primes.size();i++) { // For each prime we have
			if (count % primes[i] == 0) { // If the number is divisible by a prime
				count += 2;
				break;
			}
			else if (count % primes[i] != 0 && i == primes.size() - 1) { // If the number is not divisible by the last prime
				primes.push_back(count);
				count += 2;
				break;
			}
		}
	}
	return primes;
}