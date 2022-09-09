#include <iostream>

void PrintGrid(int grid[1001][1001]) {
	for (int i = 0;i < 1001;i++) {
		for (int j = 0;j < 1001;j++) {
			std::cout << grid[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void GenerateNumbers(int (&grid)[1001][1001]) {
	int grid_size = 1001;
	int centre = (grid_size - 1)/2;

	int squares = grid_size*grid_size; // The number of squares in the grid

	int current_row = centre; // Store the row location in the grid in this variable
	int current_column = centre; // Store the column location in the grid in this variable

	char direction = 'R'; // Variable to keep track of the direction we should step in
	int steps = 1; // Variable to keep track of how many steps to take
	int count = 0; // Variable to track when we should increment the numnber of steps
	int number = 1; // Variable to track what number to put in the grid

	grid[current_row][current_column] = number;
	number++;
	while(number <= grid_size*grid_size) {
		for (int i = 0; i < steps;i++) {
			switch(direction) {
				case 'R':
					current_column++;
					grid[current_row][current_column]  = number;
					break;
				case 'L':
					current_column--;
					grid[current_row][current_column] = number;
					break;
				case 'D':
					current_row++;
					grid[current_row][current_column] = number;
					break;
				case 'U':
					current_row--;
					grid[current_row][current_column] = number;
					break;
			}
			number++;
		}
		count++;
		if (count % 2 == 0) { // Condition to increment the number of steps
			steps++;
			count = 0;
		}
		switch(direction) {
			case 'R':
				direction = 'D';
				break;
			case 'D':
				direction = 'L';
				break;
			case 'L':
				direction = 'U';
				break;
			case 'U':
				direction = 'R';
				break;
		}
	}
}

int SumDiagonals(int grid[1001][1001]) {
	int total = 0;
	for (int i = 0;i < 1001;i++) {
		for (int j = 0;j < 1001;j++) {
			if (i == j) {
				total+= grid[i][j];
			}
			else if (i == 1000 - j) {
				total+= grid[i][j];
			}
		}
	}
	return total;
}