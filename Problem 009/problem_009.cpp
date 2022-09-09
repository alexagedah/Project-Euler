#include <iostream>
#include <math.h>

int main() {
	for (int a = 1; a <= 333; a++) {
		for (int b = a + 1; b <= 498;b++) {
			for (int c = b + 1; c <= 998; c++) {
				if (a + b + c == 1000 && pow(a,2) + pow(b,2) == pow(c,2)) {
					std::cout << a*b*c << '\n';
				}
			}
		}
	}
}