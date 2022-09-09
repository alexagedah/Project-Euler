// Problem 18
/*
Read the file as a continous string
Convert the continous string into vector
Loop through the triangle from bottom to top. The idea is to look and see which number you could get to
that would be largest from a previous number and add this to the previous number since you know that
once you get to that number, you will take the largest. You then do this from bottom to top through the
triangle and you will get the maximum total. I think this is the minimax algorithm or someting similar?
I got the idea from that.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::string ReturnTriangleString(); // This function returns the triangle as a continuous string
std::vector <std::vector<int> > ReturnTriangleVector(); // This function returns the triangle as a 2D vector
std::vector<int> TriangleNumbers(); // Returns the triangle numbers. The index corresponds to the triangle number

int main() {
	std::vector< std::vector<int> > triangle = ReturnTriangleVector(); // Vector for the triangle
	std::vector< std::vector<int> > alt_triangle = triangle; // Vector we will use to calculate the maximum
	
	// for (int row = 0; row < alt_triangle.size();row++) {
	// 	for (int col = 0; col < alt_triangle[row].size();col++) {
	// 		std::cout << alt_triangle[row][col] << ' ';
	// 	}
	// 	std::cout << '\n';
	// }

	int number = 0; // Variable to store the number we are looking at
	int left_number = 0; // Variable to store the number up and to the left
	int up_right = 0; // Variable to store the number up and to the right
	for (int row = triangle.size() - 1;row >= 1; row--) { // For each row from bottom to top
		for (int col = 1; col < triangle[row].size();col++) { // For each number excluding the ends
			number = alt_triangle[row][col]; // Current number
			left_number = alt_triangle[row][col -1]; // Number to the left
			if (number > left_number) { // If the current number is bigger
				alt_triangle[row - 1][col -1] = number + triangle[row - 1][col - 1];
			} else {
				alt_triangle[row - 1][col - 1] = left_number + triangle[row - 1][col -1];
			}
		}
	}
	std::cout << alt_triangle[0][0]<< '\n';
}

std::string ReturnTriangleString() {
	std::ifstream file("numbers.txt");
	if (!file.is_open()) {
		std::cout << "File failed to open" << '\n';
		return "";
	}

	std::string triangle = "";
	std::string number;
	while (file >> number) {
		triangle += number;
	}

	file.close();
	return triangle;
}

std::vector < std::vector<int> > ReturnTriangleVector() {
	std::vector < std::vector<int> > triangle;

	std::string string_triangle = ReturnTriangleString();
	// std::cout << string_triangle << '\n';

	std::vector<int> triangle_numbers = TriangleNumbers(); // Vector containing triangle numbers

	int count_row = 0; // The number of numbers in the previous row
	int starting_index = 0; // Starting index for number in row.
	int final_index = 0; // Final index for the number in the row
	int first_digit = 0; // Variable to store the 1st digit
	int second_digit = 0; // Variable to store the 2nd digit
	int number = 0; // Variable to store the number
	std::vector<int> row_vector; // Variable to store the vector for the current row
	for (int row = 0; row <= 14;row ++) { // For each row
		// The starting index for each row is given by the triangle number for that row*2
		// The final index for each row is given by the triangle numbr for the next row * 2 - 1
		for (int i = triangle_numbers[row]*2; i <= triangle_numbers[row+1]*2 - 1; i+=2) { // For the numbers in the row
			first_digit = string_triangle[i] - '0';
			second_digit = string_triangle[i+1] - '0';
			number = first_digit*10 + second_digit;
			row_vector.push_back(number); // Add the number to the vector
		}
		triangle.push_back(row_vector); 
		row_vector.clear(); // Clear the vector for next row
	}
	return triangle;
}

std::vector<int> TriangleNumbers() {
	std::vector<int> triangle_numbers;
	int sum = 0;
	for (int i = 0; i <= 15; i++) {
		sum += i;
		triangle_numbers.push_back(sum);
	}
	return triangle_numbers;
}