// Solve this using brute force. 
// Go through all the possible quadratics and increment n
// Find which one has the highest n

#include "functions_header.h"
#include <iostream>
#include <cmath>

int main() {
	int n;
	int max_n = 0;
	int max_a;
	int max_b;

	for (int a = -999; a < 1000; a++) {
		for (int b = -1000;b < 1001; b++) {
			n = 0;
			while(IsPrime(Quadratic(a,b,n))) {
				n++;
			}
			n--;
			if (n >= max_n) {
				max_n = n;
				max_a = a;
				max_b = b;
			}
		}
	}
	std::cout << "Maximum n: " << max_n << '\n';
	std::cout << "Maximum a: " << max_a << '\n';
	std::cout << "Maximum b: " << max_b << '\n';
	std::cout << "Product: " << max_a*max_b << '\n';
}