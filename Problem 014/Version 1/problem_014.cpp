// Problem 14
/* If we get to 13, we know it takes 9 more numbers for the sequence to terminate. This means instead of calculating chains for every number,
once we get to 13, we can stop and simply add 9
If we know the number of numbers it takes for the sequence to terminate from a certain point, we can use this to save time
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> chain_length(2000000,0); // We will store the length of the chains here. The index will correspond to the starting number

	chain_length[1] = 1; // The length when you start at 1 is 1

	for (int i = 2; i <= 20000;i++) { // i is the starting values we will loop through

		std::vector<int> current_chain; // We will store the chain in this vector. Use a vector since we do not know the size
		current_chain.push_back(i); // Add the starting number to the chain 
		int current_number = i; // We will store the current number in the chain here. 
		int current_length = 1; // Stores the length of the current chain we are looking at

		while (current_number != 1) { // While not at the end of the chain
			if (chain_length[current_number] != 0) { // Check if we know the chain length from that number onwards.
				current_length += chain_length[current_number] - 1; // We minus 1 so we don't double count
				break;
			}
			else if (current_number % 2 == 0) { // If the current number is even
				current_number /= 2;
				current_chain.push_back(current_number); // Add the number to the chain
				current_length++;
			} else { // If the current number is odd
				current_number = 3*current_number + 1;
				current_chain.push_back(current_number); // Add the number to the chain
				current_length++;
			}
		} // Current chain now either has a full chain
		// Or current chain has a chain up to the value where we know the length of the remaining chain
		
		for (int i = 0; i < current_chain.size();i++) { // For each number in current chain
			int chain_element = current_chain[i];
			chain_length[chain_element] = current_length - i;
		}
		
		// Chain length is now populated with the correct lengths
	}
	
	int max_chain_length_index = std::max_element(chain_length.begin(),chain_length.end()) - chain_length.begin();
	int max_chain_length = *std::max_element(chain_length.begin(), chain_length.end());
	std::cout << "Max element index: " << max_chain_length_index << '\n';
	std::cout << "Max chain length: " << max_chain_length << '\n';

}


