// Problem 22
/*
First read all the names into a vector and store them as vectors
There are quoation marks at the start and end of each name so remove those
Then sort the vectors alphabetically
*/

#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int name_score(std::string name,int position); // Function to compute name scores given the position

int main() {
	std::ifstream file("names.txt");
	if (!file.is_open()) {
		return 0;
	}

	std::vector<std::string> names_vector; // Vector storing neames with the quotation marks
	std::string line;
	while (getline(file,line,',')) { 
		names_vector.push_back(line);
	}

	std::string name;
	for (int i = 0; i < names_vector.size();i++) { // For each name
		for (int j = 1; j < names_vector[i].length() - 1;j++) { // For each letter in a name exclduing start an end
			name += names_vector[i][j];
		}
		names_vector[i] = name;
		name = ""; // Reset name to empty string
	}
	sort(names_vector.begin(),names_vector.end()); // Sort the vectors into alphabetical order

	int total_name_score = 0;
	for (std::vector<std::string>::size_type i = 0; i < names_vector.size();i++) {
		total_name_score += name_score(names_vector[i],i);
	}
	std::cout << total_name_score << '\n';
	return 0;
}

int name_score(std::string name, int position) {
	int value = 0;
	for (int i = 0; i < name.size();i++) {
		value += name[i] - 'A' + 1;
	}
	return value*position;
}