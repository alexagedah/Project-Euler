// Problem 31
// Use a brute force method with for loops to try all the possible combinations of coins
// Speed up the process by using continue statements when we have combinations of coins that either 
// add up to £2 or are greater than £2.

#include <iostream>

bool CoinCheck(int coins[8], int &ways); // This function checks if the sum of the coins is 200 and increments ways if it is
bool TooBigCheck(int coins[8]); // This function checks if the sum of the coins is above 200

int main() {
	int ways = 0;
	int coins[8] = {0};
	for (int a = 200; a >= 0; a -= 200) {
		coins[0] = a;
		if (CoinCheck(coins, ways)) {
			continue;
		}
		for (int b = 200; b >= 0; b -= 100) {
			coins[1] = b;
			if (CoinCheck(coins, ways)) {
				continue;
			}
			for (int c = 200; c >= 0; c -= 50) {
				coins[2] = c;
				if (CoinCheck(coins, ways)) {
					continue;
				}
				for (int d = 200; d >= 0; d -= 20) {
					coins[3] = d;
					if (CoinCheck(coins, ways)) {
						continue;
					}
					for (int e = 200; e >= 0; e -= 10) {
						coins[4] = e;
						if (CoinCheck(coins, ways)) {
							continue;
						}
						for (int f = 200; f >= 0; f -= 5) {
							coins[5] = f;
							if (CoinCheck(coins, ways)) {
								continue;
							}
							for (int g = 200; g >= 0; g -= 2) {
								coins[6] = g;
								if (CoinCheck(coins, ways)) {
									continue;
								}
								for (int h = 200; h >= 0; h -=1) {
									coins[7] = h;
									if (CoinCheck(coins, ways)) {
										continue;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	std::cout << "ways: " << ways << '\n';
}

bool CoinCheck(int coins[8], int &ways) {
	/*
	This function checks if the sum of the coins is 200.
	and checks if the sum of the coins is above 200
	It also edits increments the number of ways we have found if the sum of the coins is 200.
		Parameters:
			coins: An array containing the total value of coins 
			ways: The number of ways we have created 200p so far
		Returns:
			true if the coins add up to 200p and increments way
			true if the coins sum is above 200p
			false otherwise
	*/
	int sum = 0;
	for (int i = 0; i < 8; i ++) {
		sum += coins[i];
	}
	if (sum > 200) {
		return true;
	}
	else if (sum == 200) {
		ways += 1;
		return true;
	} else {
		return false;
	}
}
