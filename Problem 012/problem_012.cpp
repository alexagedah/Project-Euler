#include <iostream>
#include <math.h>

int Triangle(int n); // returns the nth triangle number
int Divisors(int n); // Returns the number of divsors a number has

int main() {
	int divisors = 1;
	int triangle_number;
	int i = 1;

	while (divisors <= 500) {
		triangle_number = Triangle(i);
		divisors = Divisors(triangle_number);
		i++;
	}
	std::cout << "Triangle Number: " << triangle_number << '\n';
	std::cout << "Divisors: " << divisors << '\n';

}

int Triangle(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int Divisors(int n) {
	int divisors = 0;
	int max_divisor = sqrt(n);
	for (int i = 1; i < max_divisor;i++) { // For each number below the square root
		if (n % i == 0) { // If it is divisble by the number
			divisors += 2; // Add 2 because divisors come in pairs
		}
	}
	if (n % max_divisor == 0) { // If the number is square
		divisors++; // The square root is a special divisor as it does not come in a pair so just add 1
	}
	return divisors;
}