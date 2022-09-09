#include <vector>

std::vector<int> GetProperDivisors(int x) {
	std::vector<int> proper_divisors;
	for (int i = 1; i <= x/2;i++) {
		if (x % i == 0) {
			proper_divisors.push_back(i);
		}
	}
	return proper_divisors;
}

int Sum(const std::vector<int> &numbers) {
	int sum = 0;
	for (std::vector<int>::size_type i = 0; i < numbers.size();i++) {
		sum += numbers[i];
	}
	return sum;
}

bool IsAbundant(int x) {
	std::vector<int> proper_divisors = GetProperDivisors(x);
	if (Sum(proper_divisors) > x) {
		return true;
	} else {
		return false;
	}
}

bool CheckSum(int x,const std::vector<int>& numbers) {
	std::vector<int>::size_type i = 0;
	std::vector<int>::size_type j = 0;

	while (i < numbers.size()) {
		if (numbers[i] >= x) {
			break;
		}

		while (j < numbers.size()) {
			if (numbers[j] >= x) {
				j = i;
				break;
			} else if (numbers[i] + numbers[j] == x) {
				return true;
			} else {
				j++;
			}
		}
		i++;
	}

	return false;
}
