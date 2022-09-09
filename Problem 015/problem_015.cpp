// Problem 15
/* To see how many ways there were to get to a spot on the grid, you look up and
check if there is a space above you and add 1 to the number of ways to get to the
spot above you
You then look left to see if there is a space to the left of you and add 1 to the number
of ways to get to that space.
You then add these values together
We can build a populate the grid with the of the number of ways to get to each spot
and eventually we will know how many ways there are to get to the bottom left
*/

#include <iostream>

int main() {
	long long int grid[21][21] = {}; // In this grid we put the number of ways to get to each spot
	// Eg index 0,0 has a 1 since there is 1 way to get there. Index 0,1 has a 1 since there is 1 way to get there
	// 1,1 has a 2 as there are 2 ways to get there

	for (int i = 1; i <= 20; i++) { // For each row
		grid[i][0] = 1; // Populate left coloumn
	}
	for (int j = 1; j <= 20; j++) {
		grid[0][j] = 1; // Populate top row
	}

	for (int i = 1; i <= 20;i++) { // For each row apart from the top
		for (int j = 1; j <= 20; j++) { // For each column apart from the left
			grid[i][j] += grid[i-1][j]; // Add the number of ways from the point above
			grid[i][j] += grid[i][j-1]; // Add the number of ways from the point to the left
		}
	}
	std::cout << grid[20][20] << '\n';
}