#include <vector>
#include <cmath>

int Quadratic(int a,int b, int n) {
	return (n*n + a*n + b);
}

bool IsPrime(int x) {
	if (x <= 1) {
		return false;
	}

	int max = std::sqrt(x) + 1;
	for (int i = 2; i <= max;i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
