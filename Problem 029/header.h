#include <iostream>

// Adds together two strings that are backwards and produces a backwards string
std::string Add(std::string y,std::string);

// Multiplies two strings that are backwards and produces a backwards string
std::string Multiply(std::string x,std::string y);

// Subtracts one from the number that is input
std::string SubtractOne(std::string num);

std::string Power(std::string a, std::string b);

// Function to generate our array
void GenerateArray(std::string (&numbers)[99]);

// Function to create an unsorted sequence save our sequence to a txt file
void GenerateSequence();

// Function to read our sequence txt file
std::vector<std::string> ReadUnsortedVector();

// Function to remove duplicates from the sequence
std::vector<std::string> RemoveDuplicates(std::vector<std::string> sequence);

