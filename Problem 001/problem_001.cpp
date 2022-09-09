// Problem 1

#include <iostream>

int main()
{
	int total = 0;
	for (int i = 3; i < 1000;i++)
	{
		if (i % 3 == 0 || i % 5 == 0) // If it is a multiple of 3 or 5
		{
			total += i;
		}
	}
	std::cout << total << '\n';
}