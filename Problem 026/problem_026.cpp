# include <iostream>

bool IsRecurring(std::string x);

int RecurringLength(double x);

int main() {
	double fraction;
	for (double i = 2;i < 1000;i++) {
		fraction = 1/i;
		// std::cout << std::to_string(fraction) << '\t';
		std::cout << fraction << '\t';
		if ((int)i % 10 == 0) {
			std::cout << '\n';
		}
	}
}

bool IsRecurring(std::string x) {
}