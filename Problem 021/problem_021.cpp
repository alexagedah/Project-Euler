// Problem 21

#include <iostream>
#include <math.h>
#include <vector>

int d(int n); // Number returns the sum of the proper divisors of n

int main() {
	std::vector<int> amicable_numbers;
	int a = 0;
	int b = 0;

	// std::cout << d(220) << '\n';
	// std::cout << d(284) << '\n';
	
	for (int i = 1; i < 10000; i++) {
		b = d(i);
		a = d(b);
		// std::cout << "b: " << b << '\n';
		// std::cout << "a: " << a << '\n';
		if (a != b && a == i) {
			amicable_numbers.push_back(a);
			amicable_numbers.push_back(b);
		}
	}

	int sum = 0;
	for (int i = 0; i < amicable_numbers.size();i++) {
		sum += amicable_numbers[i];
	}
	std::cout << sum/2 << '\n'; // We divide by 2 at the end because we double counted
	
}

int d(int n) {
	std::vector<int> divisors;

	for (int i = 1; i < n;i++) {
		if (n % i == 0) {
			divisors.push_back(i);
		}
	}

	int sum = 0;
	for (int i = 0; i < divisors.size();i++) {
		// std::cout << divisors[i] << '\n';
		sum += divisors[i];
	}
	return sum;
}