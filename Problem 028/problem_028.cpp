// Problem 028
// To solve this, we first generate a grid of the numbers and then sum the diagonals

#include <iostream>
#include "functions_header.h"

int grid[1001][1001] = {0};

int main() {
	GenerateNumbers(grid);
	std::cout << SumDiagonals(grid) << '\n';
	return 0;
}