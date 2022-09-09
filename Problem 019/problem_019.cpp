// Problem 19
/*

*/

#include <iostream>

int main() {
	int year = 1900;

	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int current_month = 0;
	int day_of_week = 0;
	int day_of_month = 1;
	int total = 0;

	while (year <= 2000) {
		if (day_of_week == 6 && day_of_month == 1 && year >= 1901) { // If Sunday and first day of month
			total += 1;
		}

		if (day_of_week == 6) { // If a Sunday
			day_of_week = 0;
		} else { // If it is not a Sunday, Add 1 to day of the week
			day_of_week++;
		}

		if (day_of_month == months[current_month]) { // If last day of the month

			day_of_month = 1; // Make first day of the month
			if (current_month == 11) { // If December
				current_month = 0; // Make January
				year++; // Increment the year
			} else {
				current_month++;
			}
		} else {
			day_of_month++;
		}
	}
	std::cout << total << '\n';
}