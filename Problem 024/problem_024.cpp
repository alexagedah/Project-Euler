// Problem 24
/* First I will create an vector containing all possible permutations
Then I will sort the vector
Then I will find the millionth permutation
Note that the way I found the permutations, I can actually get the answer directly
from the for loop since I find them in order anyway
*/

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>


int main() {
	std::vector<long long int> numbers; // Vector to store the numbers
	int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1,h = 1, i = 1, j = 1;
	int z = 0; // z stores the permutation we are on

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			if (b == a) {

			} else {
				for (int c = 0; c < 10; c++) {
					if (c == a || c == b) {

					} else {
						for (int d = 0; d < 10; d++) {
							if (d == a || d == b || d == c) {

							} else {
								for (int e = 0; e < 10; e++) {
									if (e == a || e == b || e == c || e == d) {

									} else {
										for (int f = 0; f < 10; f++) {
											if (f == a || f == b || f == c || f == d || f == e) {

											} else {
												for (int g = 0; g < 10; g++) {
													if (g == a || g == b || g == c || g == d || g == e || g == f) {

													} else {
														for (int h = 0; h < 10; h++) {
															if (h == a || h == b || h == c || h == d || h == e || h == f || h == g) {

															} else {
																for (int i = 0; i < 10; i++) {
																	if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h) {

																	} else {
																		for (int j = 0; j < 10; j++) {
																			if (j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h || j == i) {

																			} else {
																				numbers.push_back(a*std::pow(10,9) + b*std::pow(10,8) + c*std::pow(10,7) + d*std::pow(10,6) + e*std::pow(10,5) + f*std::pow(10,4) + g*std::pow(10,3) + h*std::pow(10,2) + i*std::pow(10,1) + j);
																				if (z == 999999) {
																					std::cout << a << b << c << d << e << f << g << h << i << j << '\n';
																				}
																				z++;

																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}		
					}
				}
			}
		}
	}
	std::sort(numbers.begin(),numbers.end());
	std::cout << numbers[999999] << '\n';
}
