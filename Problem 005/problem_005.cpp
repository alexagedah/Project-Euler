// Problem 5

#include<iostream>

int main() {
	long int count = 20;
	while(true) {
		if (count % 20 == 0) {
			if (count % 19 == 0) {
				if (count % 18 == 0) {
					if (count % 17 == 0) {
						if (count % 16 == 0) {
							if (count % 15 == 0) {
								if (count % 14 == 0) {
									if (count % 13 == 0) {
										if (count % 12 == 0) {
											if (count % 11 == 0) {
												break;
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
		count++;
	}
	std::cout << count << '\n';
}